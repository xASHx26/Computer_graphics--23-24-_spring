#include <windows.h>
#include <GL/glut.h>
#include <cstdlib> 
#include <cmath> 

float scaleX = 100.0f;
float scaleY = 56.18f;
float _move = 0.0f;
float _move2 = 0.0f;
float _move3 = 0.0f;
float _move4 = 0.0;
float carPosition = -100.0f;  // Initial position of the car
float _angle1 = 0.0f;

float carSpeed = 1.0f;        // Speed of the car
const int numSnowflakes = 100;

struct Snowflake {
    float x;
    float y;
    float speed;
};

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

void updateSnow() {
    for (int i = 0; i < numSnowflakes; ++i) {

        snowflakes[i].y -= snowflakes[i].speed;


        if (snowflakes[i].y < -56.18f) {
            snowflakes[i].y = 56.18f;
            snowflakes[i].x = (rand() % 20000 - 10000) / 100.0f;
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
void Sky() {
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
void mud() {
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.15f, 0.05f);
    glVertex2f(-1.2 * scaleX, 0.2 * scaleY);
    glColor3f(0.4f, 0.2f, 0.1f);
    glVertex2f(1.2 * scaleX, 0.2 * scaleY);
    glColor3f(0.5f, 0.25f, 0.15f);
    glVertex2f(1.05 * scaleX, -0.05 * scaleY);
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

    glTranslatef(0, 100.0f, 0.0f);
    glPushMatrix();


    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

    glTranslatef(_move, 0.0f, 0.0f);


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
void spacerover()
{
    glTranslatef(0.0, _move3, 0);
    glTranslatef(_move4, 0.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);

    glVertex2f(-0.8 * scaleX, 0.0f);

    glVertex2f(-0.5f * scaleX, 0);

    glVertex2f(-0.4 * scaleX, -0.1 * scaleY);

    glVertex2f(-0.9 * scaleX, -0.1 * scaleY);

    glEnd();
    //circlecuve
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex2f(-0.85 * scaleX, -0.15f * scaleY);
    glVertex2f(-0.75 * scaleX, -0.15 * scaleY);
    glVertex2f(-0.8 * scaleX, 0.0);
    glEnd();

    //circlecurve
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex2f(-0.55 * scaleX, -0.15 * scaleY);
    glVertex2f(-0.45 * scaleX, -0.15 * scaleY);
    glVertex2f(-0.5 * scaleX, 0.0);
    glEnd();





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

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':

        glutDisplayFunc(spacerover);
        break;
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);


    ground();
    Sky();

    arc(0, -110, 160.08225989589045);



    mountain();

    spaces();
    drawSnowflakes();
    spacerover();
    spaceship();







    glFlush();
    glutSwapBuffers();
}
void timer(int) {
    _move2 += 0.01f;
    if (_move2 > 1.0f) _move2 = -1.0f;


    for (int i = 0; i < numSnowflakes; ++i) {


        snowflakes[i].speed = 1.0f + 0.01f * (56.18f - snowflakes[i].y);
    }

    updateSnow();

    glutPostRedisplay();
    glutTimerFunc(500, timer, 0);
}


void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
}

void initGL() {
    glClearColor(.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    initSnow();
}
void update(int value) {
    _move -= 3.0;
    if (_move <= -118.0) {

        _move = -118.1;
    }







    glutPostRedisplay();


    glutTimerFunc(100, update, 0);
}

void update2(int value)
{
    _move3 += 1.0f;
    if (_move3 >= 30) {

        _move3 = 30.1;
        _move4 += 1.0;
        if (_move4 >= 110)
        {
            _move4 = 0.0;
        }
    }


    glutPostRedisplay();


    glutTimerFunc(100, update2, 0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Cosmic Landscape");
    glutInitWindowSize(1980, 1080);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);

    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update, 0);

    glutTimerFunc(500, timer, 0);
    initGL();

    glutMainLoop();
    return 0;
}