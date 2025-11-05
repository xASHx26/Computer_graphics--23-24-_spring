#include <windows.h>
#include <GL/glut.h>
#include <cstdlib> 
#include <cmath> 
float scaleX = 100.0f;
float scaleY = 56.18f;
float siamMove = 0.0f;
float siamMove2 = 0.0f;
float siamMove3 = 0.0f;
float siamMove4 = 0.0;
float siamMove5 = 0.0f;
int currentScene = 0;
float move = 0.0f;
float moonAngle1 = 0.0f, moonAngle2 = 0.0f, moonAngle3 = 0.0f;
float radiusStartX = 51.1204101147212f;
float radiusStartY = 56.18f;
float radiusEndX = 51.2901657984f;
float radiusEndY = -56.18f;
float radiusMidX = 70.0f;
float radiusMidY = 0.0f;
const float INITIAL_VELOCITY = 20.0f;
float siamMove6 = 0.0f;
bool moveRover = false;
float _velocity = INITIAL_VELOCITY;
float _direction2 = 1.0f;
int _direction = 1;
float carPosition = -100.0f;
float carSpeed = 1.0f;
const int numSnowflakes = 100;
bool displayStarted = false;
bool shouldRunDisplay = false;
struct Snowflake {
    float x;
    float y;
    float speed;
};
void SiamDrawText(float x, float y, const char* text, float scale, float r, float g, float b) {
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
Snowflake snowflakes[numSnowflakes];
void initSnow() {
    for (int i = 0; i < numSnowflakes; ++i) {
        snowflakes[i].x = (rand() % 20000 - 10000) / 100.0f;
        snowflakes[i].y = (rand() % 11236 - 5618) / 100.0f;
        snowflakes[i].speed = (rand() % 100 + 50) / 10000.0f;
    }
}
void drawSnowflakes() {
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < numSnowflakes; ++i) {
        glVertex2f(snowflakes[i].x, snowflakes[i].y);
    }
    glEnd();
}
void siamUpdateSnow() {
    for (int i = 0; i < numSnowflakes; ++i) {
        snowflakes[i].y -= snowflakes[i].speed;
        if (snowflakes[i].y < -56.18f) {
            snowflakes[i].y = 56.18f;
            snowflakes[i].x = (rand() % 20000 - 10000) / 100.0f;
        }
    }
}
void SiamCircle(float xOffset, float yOffset, float r, float red, float green, float blue) {
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
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.8 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(1.0 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.6f);
    glVertex2f(-1 * scaleX, -0.6 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.8f);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glVertex2f(0 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.7f);
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(0.6 * scaleX, -0.5 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.0f, 0.6f);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(0.6 * scaleX, -0.5 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.8f);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glVertex2f(-0.1 * scaleX, -1 * scaleY);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.9f);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glVertex2f(1 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 1.0f);
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glVertex2f(1 * scaleX, -0.4 * scaleY);
    glVertex2f(0.7 * scaleX, -0.3 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glVertex2f(-1 * scaleX, -1 * scaleY);
    glVertex2f(-0.1 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.4f);
    glVertex2f(-0.1 * scaleX, -1 * scaleY);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.6f);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glVertex2f(1 * scaleX, -0.4 * scaleY);
    glVertex2f(1 * scaleX, -0.8 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(-1 * scaleX, -1 * scaleY);
    glVertex2f(-1 * scaleX, -1.2 * scaleY);
    glVertex2f(1 * scaleX, -1.2 * scaleY);
    glVertex2f(1 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.1f);
    glVertex2f(-1 * scaleX, -1.2 * scaleY);
    glVertex2f(-1 * scaleX, -1.4 * scaleY);
    glVertex2f(1 * scaleX, -1.4 * scaleY);
    glVertex2f(1 * scaleX, -1.2 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.6f);
    glVertex2f(1 * scaleX, -0.8 * scaleY);
    glVertex2f(1 * scaleX, -1 * scaleY);
    glVertex2f(0.8 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.6f);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(-1 * scaleX, -0.6 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.6f);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(-100, -0.5 * 56.18);
    glVertex2f(-50, -28);
    glVertex2f(-100, -0.6 * 56.18);
    glEnd();
}
void siamSky() {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.1f);
    glVertex2f(-1.2 * scaleX, 1 * scaleY);
    glColor3f(0.1f, 0.0f, 0.3f);
    glVertex2f(1 * scaleX, 1 * scaleY);
    glColor3f(0.2f, 0.0f, 0.5f);
    glVertex2f(1.05 * scaleX, -0.05 * scaleY);
    glColor3f(0.1f, 0.0f, 0.2f);
    glVertex2f(-1.2 * scaleX, 0.2 * scaleY);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);
    glPointSize(1.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 5; ++i) {
        float x = -100.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (200.0f)));
        float y = -56.18f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (112.36f)));
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
void mountain() {
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 0.6f);
    glVertex2f(-1 * scaleX, 0.2 * scaleY);
    glColor3f(0.3f, 0.6f, 0.9f);
    glVertex2f(-0.8052359506136 * scaleX, 0.6499629374436 * scaleY);
    glVertex2f(-0.5999484996762 * scaleX, 0.1801226514847 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 0.6f);
    glVertex2f(-0.5999484996762 * scaleX, 0.1801226514847 * scaleY);
    glColor3f(0.3f, 0.6f, 0.9f);
    glVertex2f(-0.2473459943025 * scaleX, 0.7530800383732 * scaleY);
    glVertex2f(0.4009809471278 * scaleX, 0.1316905541238 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 0.6f);
    glVertex2f(0.024983344593 * scaleX, 0.1497009106251 * scaleY);
    glColor3f(0.3f, 0.6f, 0.9f);
    glVertex2f(0.4850498251202 * scaleX, 0.7821643488918 * scaleY);
    glVertex2f(1.0002558146587 * scaleX, 0.1110764591988 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.35f, 0.55f);
    glVertex2f(-1 * scaleX, 0.2 * scaleY);
    glVertex2f(-0.8528284587349 * scaleX, 0.266578844244 * scaleY);
    glVertex2f(-0.8977769386273 * scaleX, 0.340611634655 * scaleY);
    glColor3f(0.1f, 0.3f, 0.5f);
    glVertex2f(-0.8 * scaleX, 0.4 * scaleY);
    glVertex2f(-0.8343202611322 * scaleX, 0.4886772154769 * scaleY);
    glVertex2f(-0.8052359506136 * scaleX, 0.6499629374436 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.35f, 0.55f);
    glVertex2f(-0.5999484996762 * scaleX, 0.1801226514847 * scaleY);
    glVertex2f(-0.2605661354473 * scaleX, 0.3882041427763 * scaleY);
    glVertex2f(-0.3345989258582 * scaleX, 0.5098294413086 * scaleY);
    glColor3f(0.1f, 0.3f, 0.5f);
    glVertex2f(-0.2499900225314 * scaleX, 0.6393868245278 * scaleY);
    glVertex2f(-0.2473459943025 * scaleX, 0.7530800383732 * scaleY);
    glVertex2f(-0.5999484996762 * scaleX, 0.1801226514847 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.35f, 0.55f);
    glVertex2f(0.024983344593 * scaleX, 0.1497009106251 * scaleY);
    glVertex2f(0.426881204083 * scaleX, 0.3247474652812 * scaleY);
    glVertex2f(0.3660685548169 * scaleX, 0.5124734695376 * scaleY);
    glColor3f(0.1f, 0.3f, 0.5f);
    glVertex2f(0.5247102485546 * scaleX, 0.6367427962988 * scaleY);
    glVertex2f(0.4850498251202 * scaleX, 0.7821643488918 * scaleY);
    glEnd();
    glFlush();
}
void spaces()
{
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.35f, 0.55f);
    glVertex2f(-1 * scaleX, 0.2 * scaleY);
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glVertex2f(1 * scaleX, -0.4 * scaleY);
    glVertex2f(1.0002558146587 * scaleX, 0.1110764591988 * scaleY);
    glEnd();
    glFlush();
}
void arc(float xOffset, float yOffset, float r, float red, float green, float blue) {
    glBegin(GL_LINE);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + xOffset;
        float y = r * sin(a) + yOffset;
        glColor3f(red, green, blue);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
void spaceship() {
    glTranslatef(50, 100.0f, 0.0f);
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(siamMove, 0.0f, 0.0f);
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
    glFlush();
}
void spacerover() {
    glPushMatrix();
    glTranslatef(0.0, siamMove3, 0);
    glTranslatef(siamMove4, 0.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.75f, 0.75f);
    glVertex2f(-0.8 * scaleX, 0.0f);
    glVertex2f(-0.5f * scaleX, 0);
    glVertex2f(-0.4 * scaleX, -0.1 * scaleY);
    glVertex2f(-0.9 * scaleX, -0.1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-0.85 * scaleX, -0.15f * scaleY);
    glVertex2f(-0.75 * scaleX, -0.15 * scaleY);
    glVertex2f(-0.8 * scaleX, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-0.55 * scaleX, -0.15 * scaleY);
    glVertex2f(-0.45 * scaleX, -0.15 * scaleY);
    glVertex2f(-0.5 * scaleX, 0.0);
    glEnd();
    glColor3f(0.0f, 0.8f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(-0.6 * scaleX, -0.05 * scaleY);
    glVertex2f(-0.7 * scaleX, -0.05 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 1.0f);
    glVertex2f(-0.65 * scaleX, 0.1 * scaleY);
    glVertex2f(-0.75 * scaleX, 0);
    glVertex2f(-0.55 * scaleX, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 1.0f);
    glVertex2f(-0.55 * scaleX, 0.1 * scaleY);
    glVertex2f(-0.54 * scaleX, 0.1 * scaleY);
    glVertex2f(-0.54 * scaleX, 0 * scaleY);
    glVertex2f(-0.55 * scaleX, 0 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-0.54 * scaleX, 0.1 * scaleY);
    glVertex2f(-0.5 * scaleX, 0.08 * scaleY);
    glVertex2f(-0.54 * scaleX, 0.06 * scaleY);
    glEnd();
    glPopMatrix();
    glFlush();
}
void arc(float xOffset, float yOffset, float r) {
    glLineWidth(7);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + xOffset;
        float y = r * sin(a) + yOffset;
        float red = 1.0 - (float)i / 300;
        float green = 0.5;
        float blue = (float)i / 300;
        glColor3f(red, green, blue);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
void ball_naptune_gravity()
{
    glPushMatrix();
    glTranslatef(0.0, siamMove5, 0);
    SiamCircle(-0.2 * scaleX, -0.1 * scaleY, 3, 0, 0, 1);
    SiamDrawText(-0.25 * scaleX, -0.2 * scaleY, "Naptune", 2, 0, 0, 1);
    glPopMatrix();
}
void ball_naptune_earth()
{
    glPushMatrix();
    glTranslatef(0.0, siamMove6, 0);
    SiamCircle(0.0577543454977 * scaleX, -0.10277862500768 * scaleY, 3, 0, 1, 0);
    SiamDrawText(0.02 * scaleX, -0.2 * scaleY, "Earth", 2, 0, 1, 0);
    glPopMatrix();
}
void siamSun() {
    SiamCircle(-60.0f, 0.0f, 33.3132820428746, 1.0f, 0.8f, 0.0f);
}
void neptune() {
    SiamCircle(60.0f, 0.0f, 22.3526632316143, 0.0f, 0.5f, 1.0f);
}
void moon(float xOffset, float yOffset, float radius, float angle, float moonRadius, float red, float green, float blue) {
    float x = xOffset + radius * cos(angle);
    float y = yOffset + radius * sin(angle);
    SiamCircle(x, y, moonRadius, red, green, blue);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    if (currentScene == 0) {
        SiamDrawText(-19, 00, "Some facts about Neptune", 200, 0, 0, 1);
    }
    else if (currentScene == 1) {
        move += 0.01f;
        siamSun();
    }
    else if (currentScene == 2) {
        if (move < 1.0f) {
            move += 0.01f;
        }
        SiamDrawText(-27, 4, "Sun to Neptune is approximately 4.4721 billion km", 1, 1, 1, 1);
        siamSun();
        radius(radiusStartX, radiusStartY, radiusEndX, radiusEndY, radiusMidX, radiusMidY);
        neptune();
    }
    else if (currentScene == 3) {
        siamSun();
        radius(radiusStartX, radiusStartY, radiusEndX, radiusEndY, radiusMidX, radiusMidY);
        SiamDrawText(-19, 4, "Neptune Has 14 moons", 2, 1, 1, 1);
        neptune();
    }
    else if (currentScene == 4) {
        siamSun();
        radius(radiusStartX, radiusStartY, radiusEndX, radiusEndY, radiusMidX, radiusMidY);
        SiamDrawText(-19, 4, "Neptune Has 14 moons", 2, 1, 1, 1);
        neptune();
        moon(60.0f, 0.0f, 30.0f, moonAngle1, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 40.0f, moonAngle2, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 50.0f, moonAngle3, 3.0f, 0.5f, 0.5f, 0.5f);
    }
    else if (currentScene == 5) {
        siamSky();
        ball_naptune_gravity();
        ball_naptune_earth();
        siamSun();
        neptune();
        moon(60.0f, 0.0f, 30.0f, moonAngle1, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 40.0f, moonAngle2, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 50.0f, moonAngle3, 3.0f, 0.5f, 0.5f, 0.5f);
    }
    else if (currentScene == 6)
    {
        ground();
        drawStars();
        arc(0, -110, 160.08225989589045);
        mountain();
        spaces();
        drawSnowflakes();
        spacerover();
    }
    glFlush();
    glutSwapBuffers();

}
void display_scene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    spacerover();
    glFlush();
    glutSwapBuffers();
}
void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    spacerover();
    spaceship();
    glFlush();
    glutSwapBuffers();
}
void display3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    SiamDrawText(-0.3 * scaleX, 0.8 * scaleY, "The gravity of comparison between earth and naptune", 2, 0, 1, 1);
    siamMove3 = 0.0f;
    siamMove4 = 0.0f;
    spacerover();
    spaceship();
    glFlush();
    glutSwapBuffers();
}
void display4()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    SiamDrawText(-0.3 * scaleX, 0.8 * scaleY, "The gravity of comparison between earth and neptune", 2, 0, 1, 1);
    spacerover();
    spaceship();
    glFlush();
    glutSwapBuffers();
}
void display5()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    SiamDrawText(-0.3 * scaleX, 0.8 * scaleY, "The gravity of comparison between earth and neptune", 2, 0, 1, 1);
    ball_naptune_gravity();
    ball_naptune_earth();
    spacerover();
    spaceship();
    glFlush();
    glutSwapBuffers();
}
void siamUpdate(int value) {
    siamMove -= 5.0;
    if (siamMove <= -90.0) {
        siamMove = -90.1;
    }
    glutPostRedisplay();
    glutTimerFunc(100, siamUpdate, 0);
}
void siamUpdate2(int value)
{
    if (moveRover) {
        siamMove3 += 1.0f;
        if (siamMove3 >= 30) {
            siamMove3 = 30.1;
            siamMove4 += 1.0;
            if (siamMove4 >= 190)
            {
                siamMove4 = -60;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, siamUpdate2, 0);
}
void siamUpdate3(int value)
{
    siamMove5 += 1.0f * _direction;
    if (siamMove5 >= 30.0f)
    {
        siamMove5 = 30.0f;
        _direction = -1;
    }
    else if (siamMove5 <= -20.0f)
    {
        siamMove5 = -20.0f;
        _direction = 1;
    }
    glutPostRedisplay();
    glutTimerFunc(100, siamUpdate3, 0);
}
void siamUpdate4(int value)
{
    _velocity += -9.8f * 0.1f;
    siamMove6 += _velocity * 0.1f;
    if (siamMove6 <= -20.0f)
    {
        siamMove6 = -20.0f;
        _velocity = -_velocity;
    }
    if (siamMove6 >= 30.0f)
    {
        siamMove6 = 30.0f;
        _velocity = -_velocity;
    }
    glutPostRedisplay();
    glutTimerFunc(100, siamUpdate4, 0);
}
void siamUpdate5(int value) {
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
    glutTimerFunc(16, siamUpdate5, 0);
}
void timer(int) {
    siamMove2 += 1.01f;
    if (siamMove2 > -60.0f) siamMove2 = -60.1f;
    for (int i = 0; i < numSnowflakes; ++i) {
        snowflakes[i].speed = 1.0f + 0.01f * (56.18f - snowflakes[i].y);
    }
    siamUpdateSnow();
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}
void timer2(int value) {
    if (currentScene < 4) {
        currentScene++;
        if (currentScene == 2) {
            move = 0.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(3000, timer2, 0);
}
void siaminitGL() {
    glClearColor(.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    initSnow();
}
void handlekey(unsigned char key, int x, int y)
{

    switch (key)
    {
    case 'N':
        currentScene = 0;
        glutDisplayFunc(display);
        break;
    case 'Z':
        siamMove = 0.0f;
        glutDisplayFunc(display_scene);
        break;
    case 'X':
        siamMove = 0.0f;
        glutDisplayFunc(display2);
        break;
    case 'C':
        moveRover = true;
        break;
    case 'V':
        glutDisplayFunc(display4);
        glutPostRedisplay();
        break;
    case 'B':
        glutDisplayFunc(display5);
        glutPostRedisplay();
        break;
    }


}
void idle() {
    if (shouldRunDisplay) {
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Naptune");
    glutInitWindowSize(1980, 1080);

    glutKeyboardFunc(handlekey);
    glutDisplayFunc(display);
    glutTimerFunc(3000, timer2, 0);
    glutTimerFunc(16, siamUpdate5, 0);
    glutTimerFunc(100, siamUpdate4, 0);
    glutTimerFunc(100, siamUpdate3, 0);
    glutTimerFunc(100, siamUpdate2, 0);
    glutTimerFunc(100, siamUpdate, 0);
    glutTimerFunc(16, timer, 0);
    siaminitGL();
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}