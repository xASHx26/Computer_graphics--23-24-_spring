#include <windows.h>
#include <GL/glut.h>
#include <cstdlib> // For rand()
#include <cmath> // For cos() and sin()

float scaleX = 100.0f;
float scaleY = 56.18f;
float _move = 0.0f;
const int numSnowflakes = 100;

struct Snowflake {
    float x;
    float y;
    float speed;
};

Snowflake snowflakes[numSnowflakes];

void initSnow() {
    // Initialize snowflakes with random positions and speeds
    for (int i = 0; i < numSnowflakes; ++i) {
        snowflakes[i].x = (rand() % 200 - 100) / 100.0f; // Random x position between -1 and 1
        snowflakes[i].y = (rand() % 200 - 100) / 100.0f; // Random y position between -1 and 1
        snowflakes[i].speed = (rand() % 100 + 50) / 10000.0f; // Random speed between 0.005 and 0.015
    }
}

void drawSnowflakes() {
    glPointSize(3.0f); // Increase the size of the snowflakes
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // White color for snowflakes
    for (int i = 0; i < numSnowflakes; ++i) {
        glVertex2f(snowflakes[i].x, snowflakes[i].y);
    }
    glEnd();
}

void updateSnow() {
    for (int i = 0; i < numSnowflakes; ++i) {
        snowflakes[i].y -= snowflakes[i].speed; // Move snowflake downwards

        // Wrap around if snowflake goes below the screen
        if (snowflakes[i].y < -1.0f) {
            snowflakes[i].y = 1.0f; // Reset snowflake to the top of the screen
            snowflakes[i].x = (rand() % 200 - 100) / 100.0f; // Random x position between -1 and 1
        }
    }
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

void ground() {
    // Polygons for the ground
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f); // Dark blue
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.8 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(1.0 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glEnd();

    // Add other polygons as per your original code
}

void Sky() {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.1f); // Deep dark blue
    glVertex2f(-1.2 * scaleX, 1 * scaleY);
    glColor3f(0.1f, 0.0f, 0.3f); // Dark purple
    glVertex2f(1 * scaleX, 1 * scaleY);
    glColor3f(0.2f, 0.0f, 0.5f); // Lighter purple
    glVertex2f(1.05 * scaleX, -0.05 * scaleY);
    glColor3f(0.1f, 0.0f, 0.2f); // Darker blue
    glVertex2f(-1.2 * scaleX, 0.2 * scaleY);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);
    glFlush();
}

void mountain() {
    // Mountain polygons with gradient
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 0.6f);
    glVertex2f(-1 * scaleX, 0.2 * scaleY);
    glColor3f(0.3f, 0.6f, 0.9f);
    glVertex2f(-0.8052359506136 * scaleX, 0.6499629374436 * scaleY);
    glVertex2f(-0.5999484996762 * scaleX, 0.1801226514847 * scaleY);
    glEnd();

    // Add other mountain polygons as per your original code
}

void mud() {
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.15f, 0.05f); // Darker brown
    glVertex2f(-1.2 * scaleX, 0.2 * scaleY);
    glColor3f(0.4f, 0.2f, 0.1f); // Slightly lighter brown
    glVertex2f(1.2 * scaleX, 0.2 * scaleY);
    glColor3f(0.5f, 0.25f, 0.15f); // Another shade of brown
    glVertex2f(1.05 * scaleX, -0.05 * scaleY);
    glEnd();
    glFlush();
}

void spaceship() {
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
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

    // Add other parts of spaceship as per your original code

    glPopMatrix();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Sky();
    ground();
    mountain();
    mud();
    drawSnowflakes();
    spaceship();

    glutSwapBuffers();
}

void timer(int) {
    _move += 0.01f;
    if (_move > 1.0f) _move = -1.0f;

    updateSnow();

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // Approximately 60 FPS
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    initSnow();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
