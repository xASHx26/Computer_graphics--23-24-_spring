#include <GL/glut.h>
#include <stdlib.h>


#define MAX_RAIN_DROPS 100


typedef struct {
    float x;
    float y;
    float speed;
} RainDrop;

RainDrop raindrops[MAX_RAIN_DROPS];


void initRain() {
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        raindrops[i].x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
        raindrops[i].y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
        raindrops[i].speed = 0.01f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 0.05f;
    }
}


void drawRaindrop(float x, float y) {
    glLineWidth(2.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y - 0.05f);
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);


    for (int i = 0; i < MAX_RAIN_DROPS; ++i) {
        drawRaindrop(raindrops[i].x, raindrops[i].y);
    }

    glFlush();
}


void update(int value) {
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        raindrops[i].y -= raindrops[i].speed;

        if (raindrops[i].y < -1.0f) {
            raindrops[i].y = 1.0f;
            raindrops[i].x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
            raindrops[i].speed = 0.01f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 0.05f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rain Effect");

    initRain();

    glutDisplayFunc(display);
    glutTimerFunc(50, update, 0);

    glutMainLoop();
    return 0;
}
