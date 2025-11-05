#include <windows.h> 
#include <GL/glut.h> 
#include<math.h>
#include <ctime>

#include<iostream>
using namespace std;
int elapsedTime = 0;
const int dayDuration = 2;

void Sky()
{
    glBegin(GL_POLYGON);


    glColor3f(0x6A / 255.0f, 0x6F / 255.0f, 0xAF / 255.0f);
    glVertex2f(-1.2, 1);
    glVertex2f(1, 1);


    glColor3f(0xC8 / 255.0f, 0xC9 / 255.0f, 0xE5 / 255.0f);
    glVertex2f(1.05, -0.05);
    glVertex2f(-1.2, 0.2);

    glEnd();



    glFlush();
}
void rivr()
{
    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0, 0.2);
    glVertex2f(-0.3, -0.1);
    glVertex2f(-0.1, -0.3);
    glVertex2f(-0.4, -0.6);
    glVertex2f(-0.2, -0.8);
    glVertex2f(-0.3, -0.9);
    glVertex2f(-0.4, -1.1);
    glVertex2f(-0.2, -1.1);
    glVertex2f(0.05, -0.95);
    glVertex2f(0.2, -0.9);
    glVertex2f(0, -0.7);
    glVertex2f(0.25, -0.35);
    glVertex2f(0.05, -0.1);
    glVertex2f(0.2680683815806, 0.1990663142448);
    glVertex2f(0, 0.2);



    glEnd();

    //tree circle


    glFlush();
}


void hous()
{
    //body
    glBegin(GL_POLYGON);

    glColor3f(0x99 / 255.0f, 0x69 / 255.0f, 0x43 / 255.0f);


    glVertex2f(0.7, -0.6);
    glVertex2f(0.7, -0.9);
    glVertex2f(1, -0.9);
    glVertex2f(1, -0.6);

    glEnd();
    //head
    glBegin(GL_POLYGON);

    glColor3f(0xDB / 255.0f, 0xC0 / 255.0f, 0x8B / 255.0f);

    glVertex2f(0.64, -0.62);
    glVertex2f(1.06, -0.62);
    glVertex2f(0.85, -0.4);


    glEnd();
    //window
    glBegin(GL_POLYGON);

    glColor3f(0xE5 / 255.0f, 0xF3 / 255.0f, 0xE4 / 255.0f);

    glVertex2f(0.74, -0.68);
    glVertex2f(0.74, -0.84);
    glVertex2f(0.8, -0.84);
    glVertex2f(0.8, -0.68);


    glEnd();
    //door
    glBegin(GL_POLYGON);

    glColor3f(0xE5 / 255.0f, 0xF3 / 255.0f, 0xE4 / 255.0f);

    glVertex2f(0.84, -0.78);
    glVertex2f(0.9, -0.78);
    glVertex2f(0.9, -0.9);
    glVertex2f(0.84, -0.9);



    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0xE5 / 255.0f, 0xF3 / 255.0f, 0xE4 / 255.0f);

    glVertex2f(0.68, -0.89);
    glVertex2f(0.6800379059788, -0.9185509677358);
    glVertex2f(1.02, -0.91);
    glVertex2f(1.02, -0.89);



    glEnd();

    glFlush();

}
void mud()
{
    glBegin(GL_POLYGON);


    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(-1.2, 0.2);


    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(1.2, 0.2);


    glColor3f(0.6f, 0.4f, 0.2f);
    glVertex2f(1.05, -0.05);

    glEnd();
    glFlush();
}
void tree()
{
    //body
    glBegin(GL_POLYGON);

    glColor3f(0x62 / 255.0f, 0x4B / 255.0f, 0x21 / 255.0f);

    glVertex2f(0.9, -1.1);
    glVertex2f(1.15, -1.05);
    glVertex2f(1.12, -0.38);
    glVertex2f(0.95, -0.3);
    glVertex2f(0.98, -0.4);


    glVertex2f(1, -0.9);


    glEnd();

    glBegin(GL_POLYGON);
    float xOffa = 0.95, f;
    float yOffa = -0.3f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(0x4B / 255.0f, 0x5C / 255.0f, 0x26 / 255.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.08;
        float x = r * cos(a) + xOffa;
        float y = r * sin(a) + yOffa;
        glVertex2f(x, y);

    }

    glEnd();

    glBegin(GL_POLYGON);
    float xOff = 0.985;
    float yOff = -0.265f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(0x4B / 255.0f, 0x5C / 255.0f, 0x26 / 255.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.08;
        float x = r * cos(a) + xOff;
        float y = r * sin(a) + yOff;
        glVertex2f(x, y);

    }

    glEnd();
    glFlush();
}
void  mountain()
{
    glBegin(GL_POLYGON);

    glColor3f(0.8f, 0.9f, 0.98f);
    glVertex2f(-1.2, 0.2);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.8, 0.7);
    glVertex2f(-0.6, 0.2);

    glEnd();

    glBegin(GL_POLYGON);


    glColor3f(0.8f, 0.9f, 0.98f);
    glVertex2f(-0.6, 0.2);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2, 0.9);
    glVertex2f(0.38, 0.08);

    glEnd();

    glBegin(GL_POLYGON);


    glColor3f(0.8f, 0.9f, 0.98f);
    glVertex2f(0, 0.2);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.5, 0.9);
    glVertex2f(1.1, 0);

    glEnd();



    glBegin(GL_POLYGON);


    glColor3f(0xD3 / 255.0f, 0xED / 255.0f, 0xEE / 255.0f);
    glVertex2f(-1.2, 0.2);
    glVertex2f(-1, 0.3);
    glVertex2f(-1, 0.4);


    glColor3f(0xC8 / 255.0f, 0xC9 / 255.0f, 0xE5 / 255.0f);
    glVertex2f(-0.85, 0.45);
    glVertex2f(-0.85, 0.6);
    glVertex2f(-0.8, 0.7);

    glEnd();


    glBegin(GL_POLYGON);


    glColor3f(0xD3 / 255.0f, 0xED / 255.0f, 0xEE / 255.0f);
    glVertex2f(-0.6, 0.2);
    glVertex2f(-0.2, 0.9);
    glVertex2f(-0.2, 0.7);


    glColor3f(0xC8 / 255.0f, 0xC9 / 255.0f, 0xE5 / 255.0f);
    glVertex2f(-0.35, 0.55);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.6, 0.2);
    glEnd();

    glBegin(GL_POLYGON);


    glColor3f(0xD3 / 255.0f, 0xED / 255.0f, 0xEE / 255.0f);
    glVertex2f(0, 0.2);
    glVertex2f(0.5, 0.9);
    glVertex2f(0.5, 0.7);


    glColor3f(0xC8 / 255.0f, 0xC9 / 255.0f, 0xE5 / 255.0f);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.4, 0.4);
    glVertex2f(0, 0.2);
    glEnd();
    glFlush();
}

void sun()
{

    glBegin(GL_POLYGON);
    float xOff2 = 0.2;
    float yOff2 = 0.65;

    for (int i = 0; i < 300; i++) {
        // Calculate the fade color from yellow to light white
        float fadeFactor = static_cast<float>(i) / 300.0f;
        glColor3f((255 - fadeFactor * (255 - 230)) / 255.0f,
            (206 - fadeFactor * (206 - 230)) / 255.0f,
            (7 - fadeFactor * (7 - 230)) / 255.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.29;
        float x = r * cos(a) + xOff2;
        float y = r * sin(a) + yOff2;
        glVertex2f(x, y);
    }

    glEnd();
    glFlush();
}
void moonBorder() {
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);

    float xOff2 = 0.2;
    float yOff2 = 0.65;
    float radius = 0.29;

    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float x = radius * cos(a) + xOff2;
        float y = radius * sin(a) + yOff2;
        glVertex2f(x, y);
    }

    glEnd();
}
void moon()
{
    glBegin(GL_POLYGON);
    float xOff2 = 0.2;
    float yOff2 = 0.65;

    for (int i = 0; i < 300; i++) {

        float fadeFactor = static_cast<float>(i) / 300.0f;
        glColor3f((0 + fadeFactor * (255 - 0)) / 255.0f,
            (0 + fadeFactor * (255 - 0)) / 255.0f,
            (0 + fadeFactor * (255 - 0)) / 255.0f);

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.29;
        float x = r * cos(a) + xOff2;
        float y = r * sin(a) + yOff2;
        glVertex2f(x, y);
    }

    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);

    for (int i = 0; i < 20; i++) {
        float xStar = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.2 - 1.2;
        float yStar = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 1.2 - 0.05;

        glVertex2f(xStar, yStar);
    }

    glEnd();
    glFlush();
}


void ground()
{
    glBegin(GL_POLYGON);

    glColor3f(121 / 255.0f, 173 / 255.0f, 98 / 255.0f);

    glVertex2f(-1.4, 0);
    glVertex2f(-1.4, -0.1);
    glVertex2f(1.4, -0.1);
    glVertex2f(1.4, 0);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(121 / 255.0f, 173 / 255.0f, 98 / 255.0f);

    glVertex2f(-1.4, -0.3);
    glVertex2f(-1.4, -0.4);
    glVertex2f(1.4, -0.5);
    glVertex2f(1.4, -0.4);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(121 / 255.0f, 173 / 255.0f, 98 / 255.0f);

    glVertex2f(-1.4, -0.6);
    glVertex2f(-1.4, -0.7);
    glVertex2f(1.4, -0.9);
    glVertex2f(1.4, -0.8);

    glEnd();
    glFlush();
}

void nightsky()
{
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.2, 1);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(1, 1);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(1.05, -0.05);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-1.2, 0.2);

    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);

    for (int i = 0; i < 100; i++) {
        float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.2 - 1.2;
        float y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 1.2 - 0.05;

        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}











int currentScene = 1;


void display() {
    glClearColor(0.0f, 0.8f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    if (elapsedTime < dayDuration) {

        Sky();
        sun();
        mountain();
        ground();
        mud();
        rivr();
        tree();
        hous();
    }
    else {

        nightsky();
        moon();
        moonBorder();
        mountain();
        ground();
        mud();
        rivr();
        tree();
        hous();
    }

    glutSwapBuffers();
}

void key_callback(unsigned char key, int x, int y) {
    if (key == '1' || key == '2') {
        currentScene = key - '0';
        glutPostRedisplay();
    }
}

void timer(int value) {
    elapsedTime++;
    if (elapsedTime >= dayDuration * 2) {
        elapsedTime = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(1000, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("AUTO");
    glutInitWindowSize(800, 600);
    glutDisplayFunc(display);
    glutKeyboardFunc(key_callback);

    // Start the timer
    glutTimerFunc(1000, timer, 0);

    glutMainLoop();

    return 0;
}

