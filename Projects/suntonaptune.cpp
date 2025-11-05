#include <windows.h>
#include <math.h>
#include <GL/glut.h>

void initGL() {
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
}

int currentScene = 0;
float move = 0.0f;
float moonAngle1 = 0.0f, moonAngle2 = 0.0f, moonAngle3 = 0.0f;
float radiusStartX = 51.1204101147212f;
float radiusStartY = 56.18f;
float radiusEndX = 51.2901657984f;
float radiusEndY = -56.18f;
float radiusMidX = 70.0f;
float radiusMidY = 0.0f;


void drawText(float x, float y, const char* text, float scale, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);
    glColor3f(r, g, b);
    glRasterPos2f(0.0f, 0.0f);
    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
    glPopMatrix();
}

void circle(float xOffset, float yOffset, float r, float red, float green, float blue) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + xOffset;
        float y = r * sin(a) + yOffset;
        glColor3f(red, green, blue);
        glVertex2f(x, y);
    }
    glEnd();
}

void sun() {
    circle(-60.0f, 0.0f, 33.3132820428746, 1.0f, 0.8f, 0.0f);
}

void neptune() {
    circle(60.0f, 0.0f, 22.3526632316143, 0.0f, 0.5f, 1.0f);
}

void moon(float xOffset, float yOffset, float radius, float angle, float moonRadius, float red, float green, float blue) {
    float x = xOffset + radius * cos(angle);
    float y = yOffset + radius * sin(angle);
    circle(x, y, moonRadius, red, green, blue);
}

void radius(float xStart, float yStart, float xEnd, float yEnd, float xMid, float yMid) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 150 * move; i++) {
        float t = i / 150.0f;
        float one_minus_t = 1.0f - t;
        float x = one_minus_t * one_minus_t * xStart + 2 * one_minus_t * t * xMid + t * t * xEnd;
        float y = one_minus_t * one_minus_t * yStart + 2 * one_minus_t * t * yMid + t * t * yEnd;
        glColor3f(1, 1, 1);
        glVertex2f(x, y);
    }
    glEnd();
}
void drawStars() {
    glPointSize(1.0f);

    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);


    for (int i = 0; i < 5; ++i) {
        float x = -100.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (200.0f)));
        float y = -56.18f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (112.36f)));
        glVertex2f(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    drawStars();


    if (currentScene == 0) {
        drawText(0, 35, "Some facts about naptune", 20, 1, 1, 1);

    }
    if (currentScene == 1) {
        move += 0.01f;
        sun();
        currentScene == 1;

    }
    if (currentScene == 2) {

        drawText(-19, 4, "Sun to naptune is aprox 4.4721 billion km", 2, 1, 1, 1);
        sun();
        neptune();




        radius(radiusStartX, radiusStartY, radiusEndX, radiusEndY, radiusMidX, radiusMidY);
        currentScene == 3;


    }
    if (currentScene == 3)
    {
        sun();
        radius(radiusStartX, radiusStartY, radiusEndX, radiusEndY, radiusMidX, radiusMidY);

        drawText(-19, 4, "Naptune Has 14 moon ", 2, 1, 1, 1);
        neptune();

        moon(60.0f, 0.0f, 30.0f, moonAngle1, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 40.0f, moonAngle2, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 50.0f, moonAngle3, 3.0f, 0.5f, 0.5f, 0.5f);
        currentScene == 3;
    }
    glFlush();
    glutSwapBuffers();
}

void update(int value) {
    if (move >= 1.0f) {
        move = 1.0f;
    }


    moonAngle1 += 0.05f;
    moonAngle2 += 0.03f;
    moonAngle3 += 0.02f;

    if (moonAngle1 > 2 * M_PI) moonAngle1 -= 2 * M_PI;
    if (moonAngle2 > 2 * M_PI) moonAngle2 -= 2 * M_PI;
    if (moonAngle3 > 2 * M_PI) moonAngle3 -= 2 * M_PI;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void timer(int value) {

    if (currentScene < 3) {
        currentScene++;
        if (currentScene == 2) {
            move = 0.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(2000, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Sun and Neptune");
    glutInitWindowSize(640, 480);
    glutDisplayFunc(display);
    initGL();
    glutTimerFunc(2000, timer, 0);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
