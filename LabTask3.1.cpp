#include <windows.h> 
#include<math.h>
#include <GL/glut.h> 



void House()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.2, 0.8);
    glVertex2f(-0.2, -0.8);
    glVertex2f(0.4, -0.8);
    glVertex2f(0.4, 0.8);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0, -0.8);
    glVertex2f(0.1, -0.8);
    glVertex2f(0.1, -0.6);
    glVertex2f(0, -0.6);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2, -0.5);
    glVertex2f(0.2, -0.6);
    glVertex2f(0.3, -0.6);
    glVertex2f(0.3, -0.5);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.4, 0.9);
    glVertex2f(0.4, 0.8);
    glVertex2f(0.2, 0.8);

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36, 1);
    glVertex2f(0.36, 0.9);
    glVertex2f(0.4, 0.9);
    glVertex2f(0.4, 1);

    glEnd();
    glFlush();

}

void window(float x, float y)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2 + x, 0.7 + y);
    glVertex2f(0.3 + x, 0.7 + y);
    glVertex2f(0.3 + x, 0.6 + y);
    glVertex2f(0.2 + x, 0.6 + y);




    glEnd();



    glFlush();

}




void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(7.5);
    House();
    window(0.0, 0.0);
    window(0.0, -0.3);
    window(0.0, -0.6);
    window(0.0, -0.9);

    glEnd();
    glEnd();
}



int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutCreateWindow("Vertex, Primitive & Color");

    glutInitWindowSize(320, 320);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}