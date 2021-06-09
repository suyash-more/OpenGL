#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

float X1,X2,Y1,Y2,xmax,ymax;
int choice;

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(1.0,1.0,0.0);
gluOrtho2D(0,1024,0,768);
}

void putpixel(float x, float y)
{
    glPointSize(1.0f);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}

void SimpleLine(int x1,int y1,int x2,int y2){
glBegin(GL_LINES);
        glVertex2f(x1, y1); 
        glVertex2f(x2, y2); 
    glEnd();
    glFlush();
}


void ddaLine(int x1,int y1,int x2,int y2,int dotted=0,int solid=1,int dashed=0)
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
x= x1+512;
y=y1+384;
putpixel(x,y); //user defined function to plot point
if( dotted==0 && solid==1 && dashed==0){
    for (k=0 ;k<steps;k++)
        {
            x= x + Xinc;
            y= y + Yinc;
            putpixel(x,y);
        }
}
else if(dotted==1 && solid==0 && dashed==0){
    for (k=0 ;k<steps;k++)
        {
            x= x + Xinc;
            y= y + Yinc;
            if((int)k%3){
                putpixel(x,y);
            }
        }
}
else if(dotted==0 && solid==0 && dashed==1){
    for (k=0 ;k<steps;k++)
        {
            x= x + Xinc;
            y= y + Yinc;
            if((int)k%8){
                putpixel(x,y);
            }
        }
}
glFlush();
}
void primitives(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    xmax=glutGet(GLUT_WINDOW_WIDTH);
    ymax=glutGet(GLUT_WINDOW_HEIGHT);
    ddaLine(-512,0,512,0,0,1,0); //ddaLine(0,xmax,ymax/2,ymax/2);
    ddaLine(0,-384,0,384,0,1,0); // dda
    if(choice==1)
        ddaLine(X1,Y1,X2,Y2,1,0,0);
    else if(choice==2)
        ddaLine(X1,Y1,X2,Y2,0,1,0);
    else if(choice==3)
        ddaLine(X1,Y1,X2,Y2,0,0,1);
    else if(choice==4)
        SimpleLine(X1+512,Y1+384,X2+512,Y2+384);
    else
    	printf("Wrong Input..... !!");
    glFlush();
}
int main(int argc,char **argv)
{
printf("Enter the value of x1 : ");
scanf("%f",&X1);
printf("Enter the value of y1 : ");
scanf("%f",&Y1);
printf("Enter the value of x2 : ");
scanf("%f",&X2);
printf("Enter the value of y2 : ");
scanf("%f",&Y2);
printf("Press 1 : For Dotted Line\nPress 2 : For Solid Line \nPress 3 : For Dashed Line\nPress 4 : For Simple Line\n");
printf("Choice : ");
scanf("%d",&choice);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowPosition(0,0);
glutInitWindowSize(1024,768);
glutCreateWindow("DDA Line Pattern");
init();
glutDisplayFunc(primitives);
glutMainLoop();
}