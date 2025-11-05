#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

float fogOpacity = 0.0f; // Initial opacity of the fog

void drawScene() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Set background color to dark gray
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void drawFog() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    // Draw fog
    glColor4f(0.5f, 0.5f, 0.5f, fogOpacity); // Set fog color with opacity
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    // Draw haunted house
    glColor3f(0.5f, 0.5f, 0.5f); // Set house color
    glBegin(GL_QUADS);
    glVertex2f(-0.4, -0.4);
    glVertex2f(0.4, -0.4);
    glVertex2f(0.4, 0.4);
    glVertex2f(-0.4, 0.4);
    glEnd();

    glColor3f(0.3f, 0.3f, 0.3f); // Set roof color
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, 0.4);
    glVertex2f(0.5, 0.4);
    glVertex2f(0.0, 0.7);
    glEnd();

    glutSwapBuffers();
}

void updateFog(int value) {
    fogOpacity += 0.01f; // Increase opacity to simulate fog
    if (fogOpacity > 0.6f) { // Reset opacity if it reaches maximum
        fogOpacity = 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(50, updateFog, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Haunted Place");
    glutDisplayFunc(drawScene);
    gluOrtho2D(-1, 1, -1, 1);
    glutTimerFunc(50, updateFog, 0); // Start updating fog opacity
    glutMainLoop();
    return 0;
}
