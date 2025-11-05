#include <windows.h> 
#include<math.h>
#include <GL/glut.h> 


void initGL() {



    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}



void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(7.5);

    glBegin(GL_POLYGON);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.14f, 0.2f);
    glVertex2f(-0.14f, 0.1f);

    glVertex2f(-0.14f, 0.1f);
    glVertex2f(0.14f, 0.1f);

    glVertex2f(0.14f, 0.1f);
    glVertex2f(0.14f, 0.2f);

    glVertex2f(0.14f, 0.2f);
    glVertex2f(-0.14f, 0.2f);



    glEnd();
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.15f);
    glVertex2f(0.0f, 0.19f);

    glVertex2f(0.0f, 0.19f);
    glVertex2f(0.12f, 0.15f);

    glVertex2f(0.12f, 0.15f);
    glVertex2f(0.0f, 0.11f);

    glVertex2f(0.0f, 0.11f);
    glVertex2f(-0.12f, 0.15f);
    glEnd();


    glBegin(GL_POLYGON);

    float xOffset = 0.0f;
    float yOffset = 0.15f;

    for (int i = 0; i < 300; i++)
    {
        glColor3f(0.5f, 0.5f, 0.5f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.02;
        float x = r * cos(a) + xOffset;
        float y = r * sin(a) + yOffset;
        glVertex2f(x, y);
    }





    glEnd();
    glFlush();


    glEnd();




}



int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutCreateWindow("Vertex, Primitive & Color");

    glutInitWindowSize(320, 320);

    glutDisplayFunc(display);

    initGL();

    glutMainLoop();

    return 0;

}