#include <GL/freeglut.h>
#include <GL/glut.h>
#include<stdio.h>

int xa, ya, xb, yb;
void putpixel(int x, int y)
{
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}
void init()
{
    glClearColor(0,0,0,0);
    glColor3f(1.0, 1.0, 1.0);
    gluOrtho2D(-800, 800, -800, 800);
}
void bresengen()
{
    int x, y, xEnd;
    int dx = abs(xa - xb);
    int dy = abs(ya - yb);
    float slope = dx / dy;
    int p = 2 * dy - dx; // decision parameter
    int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx),twoDx=2*dx;
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
    putpixel(x,y);
    int steps=4*abs((dx>dy?dx:dy));
    for(int i=0;i<steps;i++)
    {
        if (slope < 0)
        {
            if (p < 0)
            {
                x++;
                p = p + twoDy;
            }else{
                y++;
                p+=twoDyDx;
            }
            putpixel(x,y);
        }else{
            if(p<0){
                y++;
                p+=twoDx;
            }else{
                x++;
                p+=twoDyDx;
            }
            putpixel(x,y);
        }
    }
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
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 100);
    glutCreateWindow("Generalized Bresenham");

    init();
    glutDisplayFunc(bresengen);
    glutMainLoop();
}