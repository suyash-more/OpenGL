#include<GL/glut.h>
#include<GL/freeglut.h>
#include<stdio.h>



void renderFunction(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    int x1=0,x2=2,y1=50,y2=20;
    glBegin(GL_LINES);
        glVertex2i(x2,y2); 
        glVertex2i(x1,y1); 
    glEnd();
    glFlush();

}
int main(int argc,char** argv)
{
     glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Demo of Mouse Interface");

    glClearColor(0,0,0,0);//Window color
    glColor3f(1.0,1.0,0.0); //Color of the line
    gluOrtho2D(-100,100,-100,100);
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}