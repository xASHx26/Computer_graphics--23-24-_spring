
#include <iostream>

#include <GL/gl.h>

#include <GL/glut.h>

#include <windows.h>

#include <math.h>

using namespace std;

float sunPositionY = 50.6f; // Initial position of the sun

float sunSpeed = 0.1f;       // Speed of the sun

float _angle1 = 0.0f;

float carPosition = -100.0f;  // Initial position of the car

float carSpeed = 1.0f;        // Speed of the car

bool isDay = true;  // Start with day mode

bool sunRising = true;  // Indicates whether the sun is rising or setting

int nightCounter = 0; // Counter to track the duration of the night

const int nightDuration = 200; // Duration for the night (adjust as needed)

void initGL() {

    // Set "clearing" or background color

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Black and opaque

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(-100, 100, -56.18, 56.18);

    glMatrixMode(GL_MODELVIEW);

}

void setDayColors() {

    glClearColor(0.5f, 0.8f, 0.9f, 1.0f); // Sky blue for day

}

void setNightColors() {

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f); // Dark blue for night

}

void drawWheel(float x, float y) {

    glPushMatrix();

    glTranslatef(x, y, 0.0f);

    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);

    glTranslatef(-x, -y, 0.0f);

    glLineWidth(1.5);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 300; i++) {

        glColor3f(.0, .0, 1.0);

        float pi = 3.1416;

        float A = (i * 2 * pi) / 300;

        float r = 2.009;  // Radius of the wheel

        float newX = x + r * cos(A);

        float newY = y + r * sin(A);

        glVertex2f(newX, newY);

    }

    glEnd();

    // Drawing lines inside the circle

    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f); // Red

    glVertex2f(x - 2.009f, y);     // Left

    glVertex2f(x + 2.009f, y);     // Right

    glVertex2f(x, y - 2.009f);     // Bottom

    glVertex2f(x, y + 2.009f);     // Top

    glEnd();

    glPopMatrix();

}

void drawcircle(float x, float y) {

    glLineWidth(1.5);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 300; i++) {

        glColor3f(.0, .0, 1.0);

        float pi = 3.1416;

        float A = (i * 2 * pi) / 300;

        float r = .5;  // Radius of the wheel

        float newX = x + r * cos(A);

        float newY = y + r * sin(A);

        glVertex2f(newX, newY);

    }

    glEnd();

}


void drawscene() {

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glLoadIdentity();

    if (isDay) {

        setDayColors();

    }
    else {

        setNightColors();

        glBegin(GL_POLYGON);

        drawcircle(-99.0f, 50.0f);

        glEnd();

    }


    // Draw the sun with scaling

    glPushMatrix();

    glColor3f(1.0f, 1.0f, 0.0f); // Yellow for sun

    // Translate the sun to its position

    glTranslatef(-90.98f, sunPositionY, 0.0f);

    // Apply scaling

    // Draw the sun as a circle

    glBegin(GL_POLYGON);

    for (int i = 0; i < 300; i++) {

        float pi = 3.1416;

        float A = (i * 2 * pi) / 300;

        float r = 5.0; // Radius of the sun

        float newX = r * cos(A);

        float newY = r * sin(A);

        glVertex2f(newX, newY);

    }

    glEnd();

    glPopMatrix();

    // Draw mountains with different colors for day and night

    if (isDay) {

        glColor3f(0.6f, 0.4f, 0.2f); // Brown for day

    }
    else {

        glColor3f(0.2f, 0.2f, 0.2f); // Dark gray for night

    }

    glBegin(GL_POLYGON);         // 1st mountain(abde)

    glVertex2f(-100.f, 48.72f);

    glVertex2f(-96.01f, 47.41f);

    glVertex2f(-80.0f, 20.0f);

    glVertex2f(-100.0f, 20.0f);

    glEnd();

    glBegin(GL_POLYGON);         // 2nd mountain(bedc)

    glVertex2f(-96.01f, 47.41f);

    glVertex2f(-100.0f, 20.0f);

    glVertex2f(-80.0f, 20.0f);

    glVertex2f(-90.98f, 42.6f);

    glEnd();

    glBegin(GL_POLYGON);         // 3rd mountain(cfgjd)

    glVertex2f(-90.98f, 42.6f);

    glVertex2f(-85.29f, 42.38f);

    glVertex2f(-80.0f, 40.0f);

    glVertex2f(-64.08f, 20.29f);

    glVertex2f(-80.0f, 20.0f);

    glEnd();

    glBegin(GL_POLYGON);         // 4th mountain(gkll4j)

    glVertex2f(-80.0f, 40.0f);

    glVertex2f(-74.58f, 42.81f);

    glVertex2f(-64.3f, 40.41f);

    glVertex2f(-50.0f, 20.27f);

    glVertex2f(-64.09f, 20.29f);

    glEnd();

    glBegin(GL_POLYGON);         // 5th mountain(lmol4)

    glVertex2f(-64.3f, 40.41f);

    glVertex2f(-55.56f, 38.66f);

    glVertex2f(-43.53f, 43.91f);

    glVertex2f(-50.0f, 20.27f);

    glEnd();

    glBegin(GL_POLYGON);         // 6th mountain(opqh1l4)

    glVertex2f(-43.53f, 43.91f);

    glVertex2f(-31.95f, 41.5f);

    glVertex2f(-17.08f, 36.47f);

    glVertex2f(17.03f, 20.15f);

    glVertex2f(-50.0f, 20.27f);

    glEnd();

    glBegin(GL_POLYGON);         // 7th mountain(qsum4h1)

    glVertex2f(-17.08f, 36.47f);

    glVertex2f(-1.56f, 45.44f);

    glVertex2f(25.99f, 35.82f);

    glVertex2f(35.95f, 20.11f);

    glVertex2f(17.03f, 20.15f);

    glEnd();

    glBegin(GL_POLYGON);    // 8th mountain(huvwt1)

    glVertex2f(17.03f, 20.15f);

    glVertex2f(25.99f, 35.82f);

    glVertex2f(37.58f, 42.6f);

    glVertex2f(45.01f, 37.79f);

    glVertex2f(51.65f, 20.09f);

    glEnd();

    glBegin(GL_POLYGON);    // 9th mountain(wzA1t1)

    glVertex2f(35.95f, 20.11f);

    glVertex2f(60.1f, 47.84f);

    glVertex2f(72.78f, 34.94f);

    glVertex2f(51.65f, 20.09f);

    glEnd();

    glBegin(GL_POLYGON);    // 10th mountain(t1a1b1c1f1)

    glVertex2f(51.65f, 20.09f);

    glVertex2f(72.78f, 34.94f);

    glVertex2f(79.34f, 42.81f);

    glVertex2f(86.34f, 35.6f);

    glVertex2f(100.0f, 20.0f);

    glEnd();

    glBegin(GL_POLYGON);    //11th mountain(f1c1d1e1)

    glVertex2f(100.0f, 20.0f);

    glVertex2f(86.34f, 35.6f);

    glVertex2f(89.83f, 43.69f);

    glVertex2f(100.00f, 48.72f);

    glEnd();

    glBegin(GL_POLYGON);    //1st small mountain1(A2z1w1g2f2)

    glVertex2f(-25.82f, 31.23f);

    glVertex2f(-26.7f, 16.8f);

    glVertex2f(-32.82f, 12.2f);

    glVertex2f(-6.15f, 12.64f);

    glVertex2f(-14.02f, 17.67f);

    glEnd();

    glBegin(GL_POLYGON);    //1st small mountain2(A2b2c2d2f2)

    glVertex2f(-25.82f, 31.23f);

    glVertex2f(-23.64f, 43.91f);

    glVertex2f(-18.39f, 46.09f);

    glVertex2f(-12.71f, 44.34f);

    glVertex2f(-14.02f, 17.67f);

    glEnd();

    glBegin(GL_POLYGON);//2nd small mountain1(j1h1g1p1o1)

    glVertex2f(23.15f, 30.35f);

    glVertex2f(17.03f, 20.15f);

    glVertex2f(22.28f, 11.99f);

    glVertex2f(36.05f, 11.55f);

    glVertex2f(35.83f, 30.35f);

    glEnd();

    glBegin(GL_POLYGON);//2nd small mountain2(j1k1n1o1)

    glVertex2f(23.15f, 30.35f);

    glVertex2f(23.37f, 39.32f);

    glVertex2f(36.49f, 38.66f);

    glVertex2f(35.83f, 30.35f);

    glEnd();

    glBegin(GL_POLYGON);//2nd small mountain3(k1l1m1n1)

    glVertex2f(23.37f, 39.32f);

    glVertex2f(25.56f, 45.22f);

    glVertex2f(33.43f, 45.87f);

    glVertex2f(36.49f, 38.66f);

    glEnd();

    glBegin(GL_POLYGON);//3rd small mountain(q1p1s1r1)

    glVertex2f(35.99f, 17.01f);

    glVertex2f(36.05f, 11.55f);

    glVertex2f(59.88f, 12.2f);

    glVertex2f(44.58f, 26.85f);

    glEnd();


    glBegin(GL_POLYGON);//4th small mountain(q1p1s1r1)

    glVertex2f(51.65f, 20.09f);

    glVertex2f(59.88f, 12.2f);

    glVertex2f(69.28f, 12.2f);

    glVertex2f(68.85f, 27.73f);

    glEnd();

    // glutSwapBuffers();

    glPushMatrix();

    glTranslatef(carPosition, 0.0f, 0.0f);

    if (isDay) {

        glColor3f(1.0f, 0.0f, 0.0f); // Red car for day

    }
    else {

        glColor3f(0.0f, 1.0f, 0.0f); // Dark red car for night

    }

    glBegin(GL_LINES);

    glVertex2f(-24.09f, -35.05f);

    glVertex2f(11.91f, -34.98f);

    glVertex2f(11.91f, -34.98f);

    glVertex2f(14.96f, -36.93f);

    glVertex2f(-24.09f, -35.05f);

    glVertex2f(-24.09f, -37.84f);

    glVertex2f(-20.8f, -35.05f);

    glVertex2f(-20.8f, -36.98f);

    glVertex2f(-2.15f, -34.96f);

    glVertex2f(-2.15f, -39.85f);

    glVertex2f(1.31f, -39.27f);

    glVertex2f(1.31f, -34.95f);

    glEnd();


    if (isDay) {

        glColor3f(1.0f, 0.0f, 0.0f); // Red car for day

    }
    else {

        glColor3f(0.0f, 1.0f, 0.0f); // Dark red car for night

    }

    //car1(p2q2r2b3)

    glBegin(GL_POLYGON);

    glVertex2f(-25.0f, -20.0f);

    glVertex2f(11.96f, -19.98);

    glVertex2f(11.96f, -23.01f);

    glVertex2f(-25.05f, -22.96f);

    glEnd();

    // car2(a3s2t2w2z2)

    glBegin(GL_POLYGON);

    glVertex2f(-18.98f, -22.9f);

    glVertex2f(7.95f, -23.01f);

    glVertex2f(7.95f, -27.43f);

    glVertex2f(-14.97f, -25.99f);

    glVertex2f(-18.98f, -25.94f);

    glEnd();

    // car3(w2t2u2v2)

    glBegin(GL_POLYGON);

    glVertex2f(-14.97f, -25.99f);

    glVertex2f(7.95f, -27.43f);

    glVertex2f(7.89f, -34.93f);

    glVertex2f(-15.0f, -35.00f);

    glEnd();

    // car4(v2n3q3r3)

    glBegin(GL_POLYGON);

    glVertex2f(-15.0f, -35.0f);

    glVertex2f(-2.0f, -30.0f);

    glVertex2f(-2.01f, -31.04f);

    glVertex2f(-12.55f, -34.99f);

    glEnd();

    // car5(p3o3n3q3)

    glBegin(GL_POLYGON);

    glVertex2f(4.32f, -34.94f);

    glVertex2f(6.18f, -34.94f);

    glVertex2f(-2.0f, -30.0f);

    glVertex2f(-2.01f, -31.04f);

    glEnd();

    // car6(l2m2n2o2j2)

    glBegin(GL_POLYGON);

    glVertex2f(-.98f, -2.61f);

    glVertex2f(-.99f, -20.04f);

    glVertex2f(2.1f, -19.98f);

    glVertex2f(2.24f, -2.69f);

    glVertex2f(.97f, -4.03f);

    glEnd();

    // car7(h2k2j2i2)

    glBegin(GL_POLYGON);

    glVertex2f(0.0f, 0.0f);

    glVertex2f(-1.9f, -1.94f);

    glVertex2f(0.97f, -4.03f);

    glVertex2f(2.85f, -2.05f);

    glEnd();

    // car8(g3h3c3d3)

    glBegin(GL_POLYGON);

    glVertex2f(-6.26f, -9.98f);

    glVertex2f(-6.26f, -19.99f);

    glVertex2f(-5.0f, -19.99f);

    glVertex2f(-5.0f, -10.0f);

    glEnd();

    // car9(f3e3d3g3)

    glBegin(GL_POLYGON);

    glVertex2f(-6.87f, -7.14f);

    glVertex2f(-5.64f, -6.22f);

    glVertex2f(-5.0f, -10.0f);

    glVertex2f(-6.26f, -9.98f);

    glEnd();

    // car10(k3l3m3i3j3)

    glBegin(GL_POLYGON);

    glVertex2f(-8.01f, -17.53f);

    glVertex2f(-8.89f, -17.95f);

    glVertex2f(-8.89f, -19.94f);

    glVertex2f(-6.77f, -19.99f);

    glVertex2f(-6.77f, -17.95f);

    glEnd();

    // Draw the wheels

    drawWheel(-24.17f, -39.92f);

    drawWheel(-21.09f, -38.99f);

    drawWheel(-2.12f, -39.85f);

    drawWheel(1.31f, -39.27f);

    drawWheel(15.03f, -39.00f);

    glPopMatrix();

    glutSwapBuffers();


}

void update(int value) {

    _angle1 -= 2.0f;

    if (_angle1 < 360.0) {

        _angle1 += 360;

    }

    carPosition += carSpeed;

    if (carPosition > 100.0f) {

        carPosition = -100.0f;

    }

    if (isDay) {

        sunPositionY -= sunSpeed;

        if (sunPositionY < 37.6f) {

            isDay = false; // Switch to night mode

            nightCounter = 0; // Reset night counter

        }

    }
    else {

        if (nightCounter < nightDuration) {

            nightCounter++; // Increment night duration counter

        }
        else {

            sunPositionY += sunSpeed;

            if (sunPositionY > 50.6f) {

                isDay = true; // Switch to day mode


            }

        }

    }

    glutPostRedisplay(); // Notify GLUT that the display has changed

    glutTimerFunc(20, update, 0); // Notify GLUT to call update again in 25 milliseconds

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1920, 1080);

    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title

    initGL(); // Initialize OpenGL state

    glutDisplayFunc(drawscene);

    glutTimerFunc(20, update, 0); // Add a timer

    glutMainLoop(); // Enter the event-processing loop

    return 0;

}
