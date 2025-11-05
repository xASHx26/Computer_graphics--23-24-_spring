#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
using namespace std;

float _move = 0.0f;
float _move2 = 0.0f;

float _angle1 = 0.0f;
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);

    //car
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3d(1, 1.0, 1.0);
    glVertex2f(-0.6, 0.4);
    glVertex2f(0.1, 0.4);
    glVertex2f(0, 0.6);
    glVertex2f(-0.5, 0.6);
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3d(1, 0, 0);
    glVertex2f(-0.8, 0.2);
    glVertex2f(0.3, 0.2);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.1, 0.4);
    glVertex2f(-0.6, 0.4);
    glVertex2f(-0.8, 0.4);

    glVertex2f(-0.8, 0.2);

    glEnd();
    glPopMatrix();

    //circle

    // Circle at the left wheel
    glPushMatrix();
    glTranslatef(-0.65f, 0.15f, 0.0f); // Translate to the bottom-left point of the circle
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f); // Rotate around the bottom-left point
    glTranslatef(0.65f, -0.15f, 0.0f); // Translate back to the original position
    // Draw the circle
    glBegin(GL_POLYGON);
    float xOffa = -0.65;
    float yOffa = 0.15;
    for (int i = 0; i < 300; i++)
    {
        glColor3f(1.0f, 1.0f, 1.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.07234394566543254;
        float x = r * cos(a) + xOffa;
        float y = r * sin(a) + yOffa;
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-0.6, 0.2);    // x, y
    glVertex2f(-0.65, 0.15);
    glVertex2f(-0.6, 0.1);    // x, y
    glVertex2f(-0.65, 0.15);// x, y
    glVertex2f(-0.7, 0.2);    // x, y
    glVertex2f(-0.65, 0.15);
    glVertex2f(-0.7, 0.1);    // x, y
    glVertex2f(-0.65, 0.15);
    // x, y
    glEnd();
    glPopMatrix();

    // Circle at the right wheel
    glPushMatrix();
    glTranslatef(0.15f, 0.15f, 0.0f); // Translate to the bottom-right point of the circle
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f); // Rotate around the bottom-right point
    glTranslatef(-0.15f, -0.15f, 0.0f); // Translate back to the original position
    // Draw the circle
    glBegin(GL_POLYGON);
    float xOffa2 = 0.15;
    float yOffa2 = 0.15;
    for (int i = 0; i < 300; i++)
    {
        glColor3f(1.0f, 1.0f, 1.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.07234394566543254;
        float x = r * cos(a) + xOffa2;
        float y = r * sin(a) + yOffa2;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(0.2, 0.2);    // x, y
    glVertex2f(0.15, 0.15);
    glVertex2f(0.1, 0.2);    // x, y
    glVertex2f(0.15, 0.15);// x, y
    glVertex2f(0.19, 0.095);    // x, y
    glVertex2f(0.15, 0.15);
    glVertex2f(0.12, 0.09);    // x, y
    glVertex2f(0.15, 0.15);
    // x, y
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {


    _angle1 += 2.0f;
    if (_angle1 > 360.0)
    {
        _angle1 -= 360;
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
