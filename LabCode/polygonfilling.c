#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0, 640, 0, 480);
}
void boundFill(int x, int y, float *fillColor, float *bc)
{
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
    if ((color[0] != bc[0] || color[1] != bc[1] || color[2] != bc[2]) && (color[0] != fillColor[0] || color[1] != fillColor[1] || color[2] != fillColor[2]))
    {
        glColor3f(fillColor[0], fillColor[1], fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        boundFill(x + 1, y, fillColor, bc);
        boundFill(x - 2, y, fillColor, bc);
        boundFill(x, y + 2, fillColor, bc);
        boundFill(x, y - 2, fillColor, bc);
    }
}
void mouse(int btn, int state, int x, int y)
{
    y = 480 - y;
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float bCol[] =
            {1, 0, 0};                //R
        float color[] = {0, 0, 1};    //B
        boundFill(x, y, color, bCol); //x,y – starting seed point
    }
}
//Draw the Polygonal Shape to be filled
void myPoly()
{
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0); //R
    glBegin(GL_LINE);
    glVertex2i(150, 100);
    glVertex2i(300, 300);
    glVertex2i(450, 100);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Polygon Filling");
    init();
    glutDisplayFunc(myPoly);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}