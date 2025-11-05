#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
using namespace std;



float _move = 0.0f;
float move2 = 1.0f;
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);



    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.98, 0.4);
    glVertex2f(-0.7, 0.4);
    glVertex2f(-0.7, 0.3);
    glVertex2f(-0.98, 0.3);
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(move2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3d(1, 1.0, 0);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.98, -0.1);
    glVertex2f(0.9849819163916, -0.1984922916182);
    glVertex2f(0.6, -0.2);
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