#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int xa, ya, xb, yb;
void putpixel(int x, int y)
{
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void BresenLine(void)
{
    int x, y, xEnd;
    // Declarations and assignments
    int dx = abs(xa - xb);
    int dy = abs(ya - yb);
    int p = 2 * dy - dx; // decision parameter
    int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);
    if (xa > xb)
    {
        x = xb;
        y = yb;
        xEnd = xa;
    }
    else
    {
        x = xa;
        y = ya;
        xEnd = xb;
    }
    putpixel(x, y); //plot the starting pixel
    while (x < xEnd)
    {
        x++;
        if (p < 0)
            p = p + twoDy;
        else
            y++;
        p = p + twoDyDx;
    } // while end
    putpixel(x, y);
    glFlush();
}


void init(void)
{
    glClearColor(0, 0, 0, 0); //Window color
    glColor3f(1.0, 1.0, 0.0); //Color of the line
    gluOrtho2D(-100, 100, -100, 100);
}
int main(int argc, char **argv)
{
    printf("Enter the value of xa : ");
    scanf("%d", &xa);
    printf("Enter the value of ya : ");
    scanf("%d", &ya);
    printf("Enter the value of xb : ");
    scanf("%d", &xb);
    printf("Enter the value of yb : ");
    scanf("%d", &yb);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Algo");
    init();
    glutDisplayFunc(BresenLine);
    glutMainLoop();
    return 0;
}