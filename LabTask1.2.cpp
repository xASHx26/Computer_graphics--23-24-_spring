

#include <windows.h>
#include <GL/glut.h>

void initGL() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glLineWidth(5);
    glColor3f(0.0f, 0.0f, 1.0f);


    glBegin(GL_POLYGON);

    glLineWidth(10);
    glColor3f(0.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.4f, 0.4f);
    glVertex2f(0.4f, 0.4f);

    glVertex2f(-0.8f, -0.4f);
    glVertex2f(-0.4f, 0.4f);

    glVertex2f(-0.8f, -0.4f);
    glVertex2f(0.8f, -0.4f);

    glVertex2f(0.8f, -0.4f);
    glVertex2f(0.4f, 0.4f);






    glEnd();

    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitWindowSize(1000, 800);

    glutCreateWindow("OpenGL Setup Test");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}


