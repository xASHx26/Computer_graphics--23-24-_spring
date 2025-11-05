#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
using namespace std;



float _move = 0.0f;
float move2 = 1.0f;
void drawScene() {
    glClearColor(0.53, 0.8, 0.92f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);



    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.6, 0.2);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0);
    glVertex2f(-0.6, 0.0);
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(move2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3d(1, 1.0, 0);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.6, 0);
    glVertex2f(0.2, 0);
    glEnd();
    glPopMatrix();

    //up
    glPushMatrix();
    glTranslatef(0.0f, _move, 0.0f);
    glBegin(GL_QUADS);
    glColor3d(0.58, 0.8, 0.7);
    glVertex2f(-0.2, -0.2);
    glVertex2f(-0.2, -0.6);
    glVertex2f(0, -0.6);
    glVertex2f(0.0, -0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, move2, 0.0f);
    glBegin(GL_QUADS);
    glColor3d(1, 0.15, 0.9);
    glVertex2f(0, 0.6);
    glVertex2f(0.2, 0.6);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.0, 0.2);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}


void update(int value) {



    _move += .02;
    if (_move > 1.89)
    {
        _move = -1.0;
    }

    move2 -= .02;
    if (move2 < -1.89)
    {
        move2 = 1.0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
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