
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

float _move1 = 0.0f;
float _move2 = 0.0f;
void drawScene() {
    glutSwapBuffers();
}

void drawScene1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(_move1, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.6, 0.2);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0);
    glVertex2f(-0.6, 0.0);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}
void drawScene2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(_move2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.6, 0);
    glVertex2f(0.2, 0);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();

}
void drawScene3() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, _move1, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(-0.2, -0.2);
    glVertex2f(-0.2, -0.6);
    glVertex2f(0, -0.6);
    glVertex2f(0.0, -0.2);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();

}
void drawScene4() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0.0, _move2, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0, 1, 1);
    glVertex2f(0, 0.6);
    glVertex2f(0.2, 0.6);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.0, 0.2);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    glClearColor(0.53f, 0.8f, 0.92f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    _move1 += .02;
    _move2 -= .02;
    if (_move1 > 1.3)
    {
        _move1 = -1.5;
    }

    if (_move2 < -1.5)
    {
        _move2 = 1.3;
    }


    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        glutDisplayFunc(drawScene1);
        break;
    case 'a':
        glutDisplayFunc(drawScene2);
        break;
    case 'w':
        glutDisplayFunc(drawScene3);
        break;
    case 's':
        glutDisplayFunc(drawScene4);
        break;

        glutPostRedisplay();
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Transformation");
    glutDisplayFunc(drawScene);
    gluOrtho2D(-2, 2, -2, 2);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(20, update, 0);
    glutMainLoop();
    return 0;
}


