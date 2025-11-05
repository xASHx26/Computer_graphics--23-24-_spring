#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <chrono>


float mR = 0.18;
float vR = 0.24;
float eR = 0.3;
float maR = 0.38;
float jR = 0.54;
float sR = 0.73;
float uR = 0.85;
float nR = 0.97;


float mAV = 0.39;
float vAV = 0.72f;
float eAV = 1.0f;
float maAV = 1.52f;
float jAV = 2.20f;
float sAV = 2.58f;
float uAV = 3.2f;
float nAV = 3.3f;

void circle(float xOffa, float yOffa, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + xOffa;
        float y = r * sin(a) + yOffa;
        glVertex2f(x, y);
    }
    glEnd();
}

void ring(float xOffa, float yOffa, float r, float thickness) {
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float innerR = r - thickness / 2;
        float outerR = r + thickness / 2;
        float xInner = innerR * cos(a) + xOffa;
        float yInner = innerR * sin(a) + yOffa;
        float xOuter = outerR * cos(a) + xOffa;
        float yOuter = outerR * sin(a) + yOffa;
        glVertex2f(xInner, yInner);
        glVertex2f(xOuter, yOuter);
    }
    glEnd();
}


double getTime() {
    using namespace std::chrono;
    return duration_cast<duration<double>>(steady_clock::now().time_since_epoch()).count();
}



void display() {
    glClearColor(0.0f, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);


    double t = getTime();

    // Orbits
    glColor3f(1, 1, 1);
    ring(0, 0, mR, 0.01);  // Mercury's orbit
    ring(0, 0, vR, 0.01);    // Venus's orbit
    ring(0, 0, eR, 0.01);    // Earth's orbit
    ring(0, 0, maR, 0.01);     // Mars's orbit
    ring(0, 0, jR, 0.01);  // Jupiter's orbit
    ring(0, 0, sR, 0.01);   // Saturn's orbit
    ring(0, 0, uR, 0.01);   // Uranus's orbit
    ring(0, 0, nR, 0.01);  // Neptune's orbit
    ring(0, 0, sR - 0.1, 0.005); // Ring around Saturn (smaller)


    // Sun
    glColor3f(1, 1, 0);
    circle(0, 0, 0.14);

    // Planets
    double mA = mAV * t;
    double vA = vAV * t;
    double eA = eAV * t;
    double maA = maAV * t;
    double jA = jAV * t;
    double sA = sAV * t;
    double uA = uAV * t;
    double nA = nAV * t;

    glColor3f(0.6, 0.6, 0.6);
    circle(mR * cos(mA), mR * sin(mA), 0.02);  // Mercury
    glColor3f(0.8, 0.4, 0);
    circle(vR * cos(vA), vR * sin(vA), 0.05);  // Venus
    glColor3f(0, 0, 1);
    circle(eR * cos(eA), eR * sin(eA), 0.04);  // Earth
    glColor3f(1, 0, 0);
    circle(maR * cos(maA), maR * sin(maA), 0.04);  // Mars
    glColor3f(0.8, 0.8, 0.4);
    circle(jR * cos(jA), jR * sin(jA), 0.09);  // Jupiter
    glColor3f(0.8, 0.8, 0.4);
    circle(sR * cos(sA), sR * sin(sA), 0.08);  // Saturn
    glColor3f(0.4, 0.4, 1);
    circle(uR * cos(uA), uR * sin(uA), 0.06);  // Uranus
    glColor3f(0.2, 0.2, 1);
    circle(nR * cos(nA), nR * sin(nA), 0.06);  // Neptune

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Solar System");
    glutInitWindowSize(800, 600);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
