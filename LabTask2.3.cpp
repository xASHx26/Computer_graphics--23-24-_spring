#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
using namespace std;

float _move = 0.0f;
//float _move2 = 0.0f;
float _scaleFactor = 1.0f;
bool _zoomIn = true;
float _angle1 = 0.0f;

void initGL() {



    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}


void drawBatmanLogo() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); // Reset the drawing perspective

    glMatrixMode(GL_MODELVIEW);
    glScalef(_scaleFactor, _scaleFactor, 1.0f);
    glTranslatef(0.4f, 0.0f, 0.0f); // Translate the logo to the middle
    //222


    glLineWidth(7.5);

    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.8, -0.2);

    glVertex2f(-0.8, -0.2);
    glVertex2f(0.0f, -0.2f);

    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.0f, 0.2f);

    glVertex2f(0.0f, 0.2f);
    glVertex2f(-0.8, 0.2);



    glEnd();

    glBegin(GL_POLYGON);

    float xOffset = -1.0f;
    float yOffset = 0.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3f(1.0f, 1.0f, 1.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.291996969092;
        float x = r * cos(a) + xOffset;
        float y = r * sin(a) + yOffset;
        glVertex2f(x, y);
    }

    glEnd();


    glBegin(GL_POLYGON);

    float xOffse = -0.6f;
    float yOffse = -0.4f;

    for (int i = 0; i < 300; i++)
    {
        glColor3f(1.0f, 1.0f, 1.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.285057846547;
        float x = r * cos(a) + xOffse;
        float y = r * sin(a) + yOffse;
        glVertex2f(x, y);
    }

    glEnd();
    glBegin(GL_POLYGON);

    float xOffs = -0.2f;
    float yOffs = -0.4f;

    for (int i = 0; i < 300; i++)
    {
        glColor3f(1.0f, 1.0f, 1.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.284071254425;
        float x = r * cos(a) + xOffs;
        float y = r * sin(a) + yOffs;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON);

    float xOff = 0.2f;
    float yOff = 0.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3f(1.0f, 1.0f, 1.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.289255779865;
        float x = r * cos(a) + xOff;
        float y = r * sin(a) + yOff;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON);

    float xOf = -0.4f;
    float yOf = 0.4f;

    for (int i = 0; i < 300; i++)
    {
        glColor3f(1.0f, 1.0f, 1.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.277083694778;
        float x = r * cos(a) + xOf;
        float y = r * sin(a) + yOf;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON);

    float xO = -0.4f;
    float yO = 0.14f;

    for (int i = 0; i < 300; i++)
    {
        glColor3f(0.0f, 0.0f, 0.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.0499888160722;
        float x = r * cos(a) + xO;
        float y = r * sin(a) + yO;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.45, 0.12);
    glVertex2f(-0.4, 0.12);

    glVertex2f(-0.4, 0.12);
    glVertex2f(-0.44, 0.22);

    glVertex2f(-0.44, 0.22);
    glVertex2f(-0.45, 0.12);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.36, 0.22);
    glVertex2f(-0.36, 0.12);

    glVertex2f(-0.36, 0.12);
    glVertex2f(-0.4, 0.12);

    glVertex2f(-0.4, 0.12);
    glVertex2f(-0.36, 0.22);

    glEnd();
    glEnd();
    glFlush();







    glEnd();

    glFlush();
}

void update(int value) {
    // Update scaling factor for zoom in/out animation
    if (_zoomIn) {
        _scaleFactor += 0.01f;
        if (_scaleFactor >= 2.0f)
            _zoomIn = false;
    }
    else {
        _scaleFactor -= 0.01f;
        if (_scaleFactor <= 0.5f)
            _zoomIn = true;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Batman Logo Zoom Animation");
    initGL();
    gluOrtho2D(-2, 2, -2, 2); // Set the orthographic projection
    glutDisplayFunc(drawBatmanLogo);
    glutTimerFunc(20, update, 0);
    glutMainLoop();
    return 0;
}