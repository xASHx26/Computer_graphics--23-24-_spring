#include <windows.h> 

#include <GL/glut.h> 


void initGL() {



    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}



void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, .0f, 0.0f);
    glVertex2f(-0.7f, 0.3f);
    glVertex2f(-0.4f, 0.3f);
    glVertex2f(-0.4f, 0.3f);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.7f, 0.1f);
    glVertex2f(-0.7f, 0.1f);
    glVertex2f(-0.7f, 0.3f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.35f, 0.15f, 0.50f);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.4f, -0.1f);
    glVertex2f(-.4f, -0.3f);
    glEnd();


    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.2f, -0.3f);
    glVertex2f(0.2f, -0.3f);
    glVertex2f(0.3f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.2f, 0.15f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.4f, 0.15f);
    glVertex2f(0.4f, 0.15f);
    glVertex2f(0.2f, 0.15f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.4f, 0.05f);

    glVertex2f(0.4f, 0.05f);
    glVertex2f(0.5001377772798, 0.1251839106838f);

    glVertex2f(0.5001377772798, 0.1251839106838f);
    glVertex2f(0.4f, 0.2f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.4f, 0.05f);
    glVertex2f(0.4f, 0.05f);
    glVertex2f(0.5001377772798, 0.1251839106838f);
    glVertex2f(0.5001377772798, 0.1251839106838f);
    glVertex2f(0.4f, 0.2f);
    glEnd();
    glFlush();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(.0f, -1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
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