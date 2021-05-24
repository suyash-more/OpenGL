#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdio.h>



void renderFunction()
{
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
}

void putpixel(float x, float y)
{
    glPointSize(1.0f);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}


void ddaLine(int x1,int y1,int x2,int y2)
{
float dy,dx,steps,x,y,k,Xinc,Yinc;
dx=x2-x1;
dy=y2-y1;
if(abs(dx)> abs(dy))
{
steps = abs(dx);
}
else
steps = abs(dy);
Xinc = dx/steps;
Yinc = dy/steps;
x=x1;
y=y1;
putpixel(x,y); //user defined function to plot point
    for (k=0 ;k<steps;k++)
        {
            x= x + Xinc;
            y= y + Yinc;
            putpixel(x,y);
        }
        putpixel(x,y);


glFlush();
}


void mymouse(int button, int state, int x, int y )
{
static int xst, yst, pt=0;
if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{
    if (pt == 0)
        {
        xst=x;
        yst=y;
        pt=pt+1;
        }
    else
        {
        glColor3f(1.0, 1.0, 1.0);
        printf("End of the line\n");
        printf("%d %d %d %d\n",xst,yst,x,y);
        ddaLine(xst,yst,x,y);
        xst=x;
        yst=y;
        }
}
else if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)pt=0;
//Clear Screen
glFlush();
}
void init(void)
{
glClearColor(0,0,0,0);//Window color
glColor3f(1.0,1.0,0.0); //Color of the line
gluOrtho2D(-800,800,-800,800);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Demo of Mouse Interface");
    init();
    glutDisplayFunc(renderFunction);
    glutMouseFunc(mymouse);
    glutMainLoop();
    return 0;
}