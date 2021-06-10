#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

int X1, Y1, X2, Y2, Xinc = 1, Yinc = 1, click = 0, type;

void putPixel(int x, int y){
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
}

void drawLine(){
	glBegin(GL_LINES);
		glVertex2f(-1000,0);
		glVertex2f(1000,0);
		glVertex2f(0,-1000);
		glVertex2f(0,1000);
	glEnd();
	int dx = abs(X2 - X1), dy = abs(Y2 - Y1), x = X1, y = Y1, p = 0;
	switch(type){
		case 1:{
				if(dy < dx){
					p = 2 * dy - dx;
					for(int i = 0; i < dx; i++){
						putPixel(x, y);
						if(p > 0){
							y += Yinc;
							p += 2 * (dy - dx);
						}
						else{
							p += 2 * dy;
						}
						x += Xinc;
					}
				}
				else{
					p = 2 * dx - dy;
					for(int i = 0; i < dy; i++){
						putPixel(x, y);
						if(p > 0){
							x += Xinc;
							p += 2 * (dx - dy);
						}
						else{
							p += 2 * dx;
						}
						y += Yinc;
					}
				}
		}
		break;
		case 2:{
				if(dy < dx){
					p = 2 * dy - dx;
					for(int i = 0; i < dx; i++){
						if(i % 5 ==0)
							putPixel(x, y);
						if(p > 0){
							y += Yinc;
							p += 2 * (dy - dx);
						}
						else{
							p += 2 * dy;
						}
						x += Xinc;
					}
				}
				else{
					p = 2 * dx - dy;
					for(int i = 0; i < dy; i++){
						if(i % 5 == 0)
							putPixel(x, y);
						if(p > 0){
							x += Xinc;
							p += 2 * (dx - dy);
						}
						else{
							p += 2 * dx;
						}
						y += Yinc;
					}
				}
		}
		break;
		case 3:{
				if(dy < dx){
					p = 2 * dy - dx;
					for(int i = 0; i < dx; i++){
						if(i % 5 != 0)
							putPixel(x, y);
						if(p > 0){
							y += Yinc;
							p += 2 * (dy - dx);
						}
						else{
							p += 2 * dy;
						}
						x += Xinc;
					}
				}
				else{
					p = 2 * dx - dy;
					for(int i = 0; i < dy; i++){
						if(i % 5 != 0)
							putPixel(x, y);
						if(p > 0){
							x += Xinc;
							p += 2 * (dx - dy);
						}
						else{
							p += 2 * dx;
						}
						y += Yinc;
					}
				}
		}
		break;
		default:
			cout << "\nPlease select correct type.\n";
			break;
		
	}
	glFlush();
}

void init(){
	glOrtho(-1000, 1000, -1000, 1000, -1, 1);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
}

void mouse(int button, int state, int mousex, int mousey){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && click == 0){
		X1 = 2 * mousex - 1000;
		Y1 = 730 - 2 * mousey;
		click++;
		cout << "\nSet X1 = " << X1 << " and Y1 = " << Y1 << "\n";
	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && click == 1){
		X2 = 2 * mousex - 1000;
		Y2 = 730 - 2 * mousey;
		if(X1 > X2){
			Xinc = -1;
		}
		if(Y1 > Y2){
			Yinc = -1;
		}
		click++;
		cout << "\nSet X2 = " << X2 << " and Y2 = " << Y2 << "\n";
		drawLine();
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

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(500,500);
	glutCreateWindow("Bresenham's Line Drawing Algorithm");
	init();
	cout << "\nMenu\n\n1. Solid (press 's' or 'S')\n2. Dotted (press 'd' or 'D')\n3. Dashed (press 'b' or 'B')\n";
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
