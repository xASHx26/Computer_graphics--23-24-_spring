

#include <windows.h>
#include <GL/glut.h>

void initGL() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);



    glBegin(GL_POLYGON);

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, 0.1f);

    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.1f, 0.2f);

    glVertex2f(0.1f, 0.2f);
    glVertex2f(0.0f, 0.3f);

    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.2f, 0.3f);

    glVertex2f(-0.2f, 0.3f);
    glVertex2f(-0.3f, 0.2f);

    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.3f, 0.1f);

    glVertex2f(-0.3f, 0.1f);
    glVertex2f(-0.2f, 0.0f);






    glEnd();

    glLineWidth(2);


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);


    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, 0.1f);

    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.1f, 0.2f);

    glVertex2f(0.1f, 0.2f);
    glVertex2f(0.0f, 0.3f);

    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.2f, 0.3f);

    glVertex2f(-0.2f, 0.3f);
    glVertex2f(-0.3f, 0.2f);

    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.3f, 0.1f);

    glVertex2f(-0.3f, 0.1f);
    glVertex2f(-0.2f, 0.0f);


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


