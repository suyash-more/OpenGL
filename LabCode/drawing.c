//Draw Line

#include <GL/freeglut.h>
#include <GL/gl.h>


void recfun(float x0,float y0,float x1,float y1){
    glBegin(GL_LINES);
        glVertex2f(x0,y0); 
        glVertex2f(x1,y1); 
    glEnd();
}
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    float point1[2]={0.3,-0.4};
    float point2[2]={0.3,0.0};
    float point3[2]={0.8,0.0};
    float point4[2]={0.8,-0.4};
    float point5[2]={0.55,0.3};
    float point6[2]={0.45,-0.4};
    float point7[2]={0.45,-0.2};
    float point8[2]={0.65,-0.2};
    float point9[2]={0.65,-0.4};
    float point10[2]={-0.8,0.0};
    float point11[2]={-0.3,0.8};
    float point12[2]={0.0,0.2};
    float point13[2]={0.4,0.8};
    float point14[2]={0.9,0.1};

    recfun(point1[0],point1[1],point2[0],point2[1]);

    recfun(point2[0],point2[1],point3[0],point3[1]);

    recfun(point3[0],point3[1],point4[0],point4[1]);

    recfun(point4[0],point4[1],point1[0],point1[1]);

    recfun(point2[0],point2[1],point5[0],point5[1]);

    recfun(point5[0],point5[1],point3[0],point3[1]);

    recfun(point6[0],point6[1],point7[0],point7[1]);

    recfun(point7[0],point7[1],point8[0],point8[1]);

    recfun(point8[0],point8[1],point9[0],point9[1]);

    recfun(point10[0],point10[1],point11[0],point11[1]);

    recfun(point11[0],point11[1],point12[0],point12[1]);

    recfun(point12[0],point12[1],point13[0],point13[1]);

    recfun(point13[0],point13[1],point14[0],point14[1]);



    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Scenery Drawing");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}