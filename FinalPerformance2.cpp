#include <windows.h>
#include<math.h>
#include <GL/glut.h>
#include<iostream>
using namespace std;
float mm = 0.00;
int currentscene = 0;
int boatMove;
void initGL() { glClearColor(0.0f, 0.0f, 0.0f, 0.0f); }
void drawRaindrop(float x, float y) {
    glPointSize(0.01);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, y);
    glVertex2f(x, y - 0.04f);
    glEnd();
}
void Sky() {

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

void moon() {

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
}

void mountain() {
    // Draw mountains
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
}

void ground() {

    glBegin(GL_POLYGON);
    glColor3f(121 / 255.0f, 173 / 255.0f, 98 / 255.0f);
    glVertex2f(-1.2, 0.2);
    glVertex2f(1.2, 0.1);
    glVertex2f(1.2, -0.8);
    glVertex2f(-1.4, -0.6);
    glEnd();
}

bool isDay = true;
void mud() {

    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(-1.2, 0.2);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(1.2, 0.2);
    glColor3f(0.6f, 0.4f, 0.2f);
    glVertex2f(1.05, -0.05);
    glEnd();
}
void boat(float x) {
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(x - 0.1, 0.1);
    glVertex2f(x, 0);
    glVertex2f(x + 0.3, 0);
    glVertex2f(x + 0.4, 0.1);
    glEnd();
}



float boatX = 1.2;

void update(int value) {
    mm += 0.001;
    if (mm > 0.8) {
        mm = 0.8;
        boatMove = 1;
    }

    if (boatMove == 1) {

        boatX -= 0.005;
        if (boatX < -0.5) {
            boatMove = 2;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Sky();
    moon();
    mountain();
    ground();
    mud();


    glColor3f(0.0, 0.5, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.6 + mm);
    glVertex2f(-1, -0.6 + mm);
    glEnd();


    for (int i = 0; i < 100; ++i) {
        float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
        float y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
        drawRaindrop(x, y);
    }

    if (boatMove == 1 || boatMove == 2) {
        boat(boatX);
    }

    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Day and Night Scenario");
    initGL();
    glutDisplayFunc(display);
    glutTimerFunc(20, update, 0); // Start the timer immediately
    glutMainLoop();
    return 0;
}