#include <windows.h>
#include <math.h>
#include <GL/glut.h>


bool exploding = false;
float explosionSize = 0.0f;
int explosionFrames = 0;


float shakeOffsetX = 0.0f;
float shakeOffsetY = 0.0f;

void initGL() {
    glClearColor(0.7, 0.8, 1.0, 1.0); // Light blue background
}

void lavaVolcano() {
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.4f, 0.0f); // Brownish lava color
    glVertex2f(-0.1 + shakeOffsetX, 0.8 + shakeOffsetY);
    glVertex2f(0.1 + shakeOffsetX, 0.8 + shakeOffsetY);
    glVertex2f(0.2 + shakeOffsetX, 0.2 + shakeOffsetY);
    glVertex2f(-0.2 + shakeOffsetX, 0.2 + shakeOffsetY);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.2f, 0.0f); // Darker brown for volcano's top
    glVertex2f(-0.1 + shakeOffsetX, 0.8 + shakeOffsetY);
    glVertex2f(-0.05 + shakeOffsetX, 0.7 + shakeOffsetY);
    glVertex2f(0 + shakeOffsetX, 0.75 + shakeOffsetY);
    glVertex2f(0.05 + shakeOffsetX, 0.7 + shakeOffsetY);
    glVertex2f(0.1 + shakeOffsetX, 0.8 + shakeOffsetY);
    glEnd();
}

void volcanoExplosion() {

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color for explosion

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.2f, 0.0f); // Darker brown for volcano's top
    glVertex2f(-0.1245189626275, 0.8584632674536);
    glVertex2f(-0.1, 0.8);
    glVertex2f(0.1, 0.8);


    glVertex2f(0.1325137749523, 0.8532443286195);
    glVertex2f(0.0816291213197, 0.8258448997404);
    glVertex2f(0.0659723048174, 0.8506348592024);
    glVertex2f(0.0085639776422, 0.8441111856598);
    glVertex2f(-0.0201401859454, 0.8832532269156);
    glVertex2f(-0.0645011660353, 0.8258448997404);
    glVertex2f(-0.1245189626275, 0.8584632674536);
    glEnd();


    glColor3f(1.0f, 0.0f, 0.0f); // Red lava particles
    glBegin(GL_POINTS);
    for (int i = 0; i < 50; ++i) {
        float x = ((float)rand() / RAND_MAX) * 0.2 - 0.1;
        float y = ((float)rand() / RAND_MAX) * 0.1 + 0.8 + explosionSize * 2;
        glVertex2f(x, y);
    }
    glEnd();
}

void lavaParticles() {

    glPointSize(3.0f);


    glColor3f(1.0f, 0.0f, 0.0f); // Red lava particles
    glBegin(GL_POINTS);
    for (int i = 0; i < 50; ++i) {

        float x = ((float)rand() / RAND_MAX) * 0.2 - 0.1;

        float y = ((float)rand() / RAND_MAX) * 0.1 + 0.8 + explosionSize * 2;

        if (x >= -0.2 && x <= 0.2) {

            glVertex2f(x, y);
        }
    }
    glEnd();


    for (int i = 0; i < 50; ++i) {

        float x = ((float)rand() / RAND_MAX) * 0.2 - 0.1;

        float y = ((float)rand() / RAND_MAX) * 0.1 + 0.8 - 0.01f * explosionFrames;

        if (x >= -0.2 && x <= 0.2) {

            glVertex2f(x, y);
        }
    }
}

void river() {
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.2f, 0.8f); // Blue river color
    glVertex2f(-1, -0.4);
    glVertex2f(1, -0.4);
    glVertex2f(1, 0.1);
    glVertex2f(-1, 0.1);
    glEnd();
}

void land() {
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.6f, 0.1f); // Green land color
    glVertex2f(-1, 0.2);
    glVertex2f(1, 0.2);
    glVertex2f(1, 0.1);
    glVertex2f(-1, 0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 0.1f); // Darker green for ground
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.4);
    glVertex2f(-1, -0.4);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    lavaVolcano();

    if (exploding) {
        volcanoExplosion();
        lavaParticles();
    }

    river();
    land();

    glutSwapBuffers();
}

void update(int value) {
    static int frameCounter = 0;
    frameCounter++;


    if (frameCounter >= 180) {
        exploding = true;
        frameCounter = 0;

        explosionFrames = 0;
        explosionSize = 0.0f;

        shakeOffsetX = ((float)rand() / RAND_MAX) * 0.01f - 0.005f;
        shakeOffsetY = ((float)rand() / RAND_MAX) * 0.01f - 0.005f;
    }


    if (exploding) {
        explosionFrames++;

        explosionSize += 0.02f;

        if (explosionFrames >= 30) {
            exploding = false;
            explosionSize = 0.0f;
            explosionFrames = 0;

            shakeOffsetX = 0.0f;
            shakeOffsetY = 0.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Exploding Volcano");
    glutDisplayFunc(display);
    initGL();
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
