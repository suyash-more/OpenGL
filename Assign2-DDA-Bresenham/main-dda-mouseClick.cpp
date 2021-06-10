#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

float X1, Y1, X2, Y2;
int type, click = 0;

void putPixel(int x, int y){
	glPointSize(1.0);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
}

void drawLine(){
	glBegin(GL_LINES);
		glVertex2f(-1000,0);
		glVertex2f(1000,0);
		glVertex2f(0,1000);
		glVertex2f(0,-1000);
	glEnd();
	float dx = X2 - X1, dy = Y2 - Y1;
	float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float xinc = dx / steps, yinc = dy / steps;
	float x = X1, y = Y1;
	putPixel(x, y);
	switch(type){
	case 1:
		for(int i = 0; i < steps; i++){
			x += xinc;
			y += yinc;
			putPixel((int)x, (int)y);
		}
		break;
	case 2:
		for(int i = 0; i < steps; i++){
			x += xinc;
			y += yinc;
			if(i % 5 == 0)
				putPixel((int)x, (int)y);
		}
		break;
	case 3:
		for(int i = 0; i < steps; i++){
			x += xinc;
			y += yinc;
			if(i % 5 != 0)
				putPixel((int)x, (int)y);
			else{
				y += 1 * yinc;
			}
		}
		break;
	default:
		cout << "\nPlease enter correct type\n";
	}
	
	glFlush();
}

void mouse(int button, int state, int mousex, int mousey){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if(click == 0){
			X1 = 2 * mousex - 1000;
			Y1 = 730 - 2 * mousey;
			click++;
		} else if(click == 1){
			X2 = 2 * mousex - 1000;
			Y2 = 730 - 2 * mousey;
			click++;
			drawLine();
		}
	}
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 's':
			type = 1;
			break;
		case 'd':
			type = 2;
			break;
		case 'b':
			type = 3;
			break;
		default:
			cout << "\n\nPlease press a valid key\n\n";
			break;
	}
}

void init(){
	glOrtho(-1000, 1000, -1000, 1000, -1, 1);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
}

int main(int argc, char** argv){
	cout << "\nMenu\n\n1. Solid (press 's' or 'S')\n2. Dotted (press 'd' or 'D')\n3. Dashed (press 'b' or 'B')\n";
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(500,500);
	glutCreateWindow("DDA Line Drawing Algorithm");
	init();
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
