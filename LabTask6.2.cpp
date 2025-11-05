#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;


int objectIndex = 0;
bool separate = true;

void circle(float xOffa, float yOffa, float r)
{
    glBegin(GL_POLYGON);

    for (int i = 0; i < 300; i++)
    {

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;

        float x = r * cos(a) + xOffa;
        float y = r * sin(a) + yOffa;
        glVertex2f(x, y);
    }
    glEnd();
}

void drawScene()
{
    glClearColor(0.53f, 0.8f, 0.92f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.8, -0.4);
    glVertex2f(0.95, -0.4);
    glVertex2f(0.95, 0.2);
    glEnd();

    if (separate)
    {
        switch (objectIndex)
        {
        case 0:
            glColor3f(1, 0, 0); // Red
            circle(-0.58, -0.1, 0.2);
            break;
        case 1:
            glColor3f(0, 1, 0); // Green
            circle(-0.14, -0.1, 0.2);
            break;
        case 2:
            glColor3f(0, 0, 1); // Blue
            circle(0.28, -0.1, 0.2);
            break;
        case 3:
            glColor3f(1, 1, 1); // White
            circle(0.7, -0.1, 0.2);
            break;
        default:
            break;
        }
    }
    else
    {
        // Drawing all circles together, each with its own color
        glColor3f(1, 0, 0); // Red
        circle(-0.58, -0.1, 0.2);

        glColor3f(0, 1, 0); // Green
        circle(-0.14, -0.1, 0.2);

        glColor3f(0, 0, 1); // Blue
        circle(0.28, -0.1, 0.2);

        glColor3f(1, 1, 1); // White
        circle(0.7, -0.1, 0.2);
    }

    glutSwapBuffers();
}

void update(int value)
{
    if (separate)
    {
        if (objectIndex < 3)
        {
            objectIndex++;
            glutPostRedisplay();
            glutTimerFunc(2000, update, 0);
        }
        else
        {
            separate = false;
            objectIndex = 0;
            glutPostRedisplay();
            glutTimerFunc(2000, update, 0);
        }
    }
    else
    {
        objectIndex = 0;
        separate = true;
        glutPostRedisplay();
        glutTimerFunc(2000, update, 0);
    }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Transformation");
    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update, 0);
    glutMainLoop();
    return 0;
}
