#include <windows.h> 
#include <GL/glut.h> 


void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(1);


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);

    //H
    glVertex2f(-0.8, 0.6);
    glVertex2f(-0.8, -0.8);

    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.6, -0.8);

    glVertex2f(-0.8, 0);
    glVertex2f(-0.6, 0);


    //A
    glVertex2f(-0.2, 0.6);
    glVertex2f(-0.4, -0.8);

    glVertex2f(-0.2, 0.6);
    glVertex2f(0, -0.8);

    glVertex2f(-0.28, 0);
    glVertex2f(-0.12, 0);

    //B
    glVertex2f(0, 0.6);
    glVertex2f(0, -0.8);

    glVertex2f(0, 0.6);
    glVertex2f(0.2, 0.4);

    glVertex2f(0.2, 0.4);
    glVertex2f(0.2, 0.2);

    glVertex2f(0.2, 0.2);
    glVertex2f(0.10, 0);

    glVertex2f(0.10, 0);
    glVertex2f(0.2, -0.2);

    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, -0.4);

    glVertex2f(0.2, -0.4);
    glVertex2f(0, -0.8);

    //I
    glVertex2f(0.4, 0.6);
    glVertex2f(0.4, -0.8);

    glVertex2f(0.2, 0.6);
    glVertex2f(0.6, 0.6);

    glVertex2f(0.2, -0.8);
    glVertex2f(0.6, -0.8);

    //B
    glVertex2f(0.7, -0.8);
    glVertex2f(0.7, 0.6);

    glVertex2f(0.7, 0.6);
    glVertex2f(0.8, 0.5);

    glVertex2f(0.8, 0.1);
    glVertex2f(0.8, 0.5);

    glVertex2f(0.8, 0.1);
    glVertex2f(0.7491266196605, 0.0125389939406);

    glVertex2f(0.8, -0.1);
    glVertex2f(0.7491266196605, 0.0125389939406);

    glVertex2f(0.8, -0.1);
    glVertex2f(0.8, -0.7);

    glVertex2f(0.7, -0.8);
    glVertex2f(0.8, -0.7);







    glEnd();
    glFlush();

}


int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutCreateWindow("OpenGL Setup");

    glutInitWindowSize(5000, 4000);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}