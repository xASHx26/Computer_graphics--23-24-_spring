
#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>


GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;


void update1(int value) {

    position1 -= 0.1f;
    if (position1 < -1.0)
        position1 = 1.0f;
    if (position1 > 1.0)
        position1 = -1.0f;


    glutPostRedisplay();


    glutTimerFunc(100, update1, 0);
}
void update2(int value) {

    position2 += 0.1f;

    if (position2 < -1.0)
        position2 = 1.0f;
    if (position2 > 1.0)
        position2 = -1.0f;


    glutPostRedisplay();


    glutTimerFunc(100, update2, 0);
}



void display() {
    glClearColor(0.53f, 0.8f, 0.92f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(position2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.3, 0.3);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.3, 0.4);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(position1, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.3, 0.1);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.3, 0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(position2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.3, -0.1);
    glVertex2f(-0.3, -0.2);
    glVertex2f(0.3, -0.2);
    glVertex2f(0.3, -0.1);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(position1, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.3, -0.3);
    glVertex2f(0.3, -0.3);
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glEnd();
    glPopMatrix();



    glFlush();
}

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
    {
        glutTimerFunc(100, update1, 0);
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        glutTimerFunc(100, update2, 0);
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Translation Animation");
    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);

    glutMainLoop();
    return 0;
}


