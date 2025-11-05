#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

float c1 = 1.0f;
float c2 = 0.0f;

void drawScene() {
    glClearColor(c1, c2, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void update(int value) {
    if (c1 == 1.0f && c2 == 0.0f)
    {
        c1 = 0.0f;
        c2 = 1.0f;
    }

    else
    {
        c1 = 1.0f;
        c2 = 0.0f;
    }


    glutPostRedisplay();
    glutTimerFunc(200, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Transformation");
    glutDisplayFunc(drawScene);
    gluOrtho2D(-2, 2, -2, 2);
    glutTimerFunc(20, update, 0);
    glutMainLoop();
    return 0;
}
