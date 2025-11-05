#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

const int numParticles = 100;
struct Particle {
    float x;
    float y;
    float size;
    float opacity;
};

Particle particles[numParticles];

void initSmoke() {
    for (int i = 0; i < numParticles; ++i) {
        particles[i].x = (rand() % 200 - 100) / 100.0f; // Random x position
        particles[i].y = (rand() % 200 - 100) / 100.0f; // Random y position
        particles[i].size = (rand() % 5 + 5) / 10.0f; // Random size between 0.5 and 1.0
        particles[i].opacity = (rand() % 50 + 50) / 100.0f; // Random opacity between 0.5 and 1.0
    }
}

void drawSmoke() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POINTS);
    glColor4f(0.75f, 0.75f, 0.75f, 0.5f); // Silver smoke color with transparency
    for (int i = 0; i < numParticles; ++i) {
        glVertex2f(particles[i].x, particles[i].y);
    }
    glEnd();
    glDisable(GL_BLEND);
}

void updateSmoke() {
    for (int i = 0; i < numParticles; ++i) {
        particles[i].y += 0.01f; // Move particles upwards
        particles[i].opacity -= 0.001f; // Reduce opacity over time
        if (particles[i].opacity <= 0.0f) { // Reset particle if opacity is zero
            particles[i].x = (rand() % 200 - 100) / 100.0f;
            particles[i].y = -1.0f;
            particles[i].opacity = (rand() % 50 + 50) / 100.0f;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the object
    glTranslatef(50, 100.0f, 0.0f);
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-20, -12);
    glVertex2f(8, -12);
    glVertex2f(14, -15);
    glVertex2f(8, -18);
    glVertex2f(-20, -18);
    glVertex2f(-22, -17);
    glVertex2f(-22, -15);
    glVertex2f(-22, -13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-20, -12);
    glVertex2f(-20, -5);
    glVertex2f(-18, -4);
    glVertex2f(-10, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-20, -18);
    glVertex2f(-20, -24);
    glVertex2f(-18, -26);
    glVertex2f(-10, -18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-12, -10);
    glVertex2f(4, -10);
    glVertex2f(4, -12);
    glVertex2f(-10, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(4, -18);
    glVertex2f(4, -20);
    glVertex2f(-12, -20);
    glVertex2f(-10, -18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-14, -14);
    glVertex2f(-14, -16);
    glVertex2f(8, -16);
    glVertex2f(8, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(8, -12);
    glVertex2f(8, -18);
    glVertex2f(14, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-22.5, -17);
    glVertex2f(-24.017, -16.9);
    glVertex2f(-23.5, -16);
    glVertex2f(-24, -15.5);
    glVertex2f(-22.5, -15);
    glVertex2f(-24, -14.5);
    glVertex2f(-23.5, -14);
    glVertex2f(-24, -13);
    glVertex2f(-22.5, -13);
    glVertex2f(-22, -12);
    glVertex2f(-22, -18);
    glVertex2f(-22.5, -18);
    glEnd();

    glPopMatrix();

    // Draw the smoke effect
    drawSmoke();

    glutSwapBuffers();
}


void timer(int) {
    updateSmoke();
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // Update every ~16ms for 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Smoke Effect");
    gluOrtho2D(-100, 100, -56.18, 56.18);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background

    initSmoke();

    glutMainLoop();

    return 0;
}
