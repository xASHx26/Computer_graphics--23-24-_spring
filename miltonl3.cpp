#include <GL/glut.h>
#include <stdlib.h>

// Number of raindrops
#define MAX_RAIN_DROPS 100

// Structure to hold raindrop properties
typedef struct {
    float x;  // x-coordinate of raindrop
    float y;  // y-coordinate of raindrop
    float speed; // speed of raindrop
} RainDrop;

RainDrop raindrops[MAX_RAIN_DROPS];

// Initialize raindrops
void initRain() {
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        raindrops[i].x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f; // Random x position between -1 and 1
        raindrops[i].y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f; // Random y position above the ground
        raindrops[i].speed = 0.01f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 0.05f; // Random speed between 0.01 and 0.06
    }
}

// Function to draw a single raindrop
void drawRaindrop(float x, float y) {
    glLineWidth(2.0); // Set line width for raindrops
    glColor3f(1.0f, 1.0f, 1.0f); // White color for raindrops
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y - 0.05f); // Adjust the length of the raindrops as needed
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color to blue
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    // Draw raindrops
    for (int i = 0; i < MAX_RAIN_DROPS; ++i) {
        drawRaindrop(raindrops[i].x, raindrops[i].y);
    }

    glFlush();
}

// Timer function to update raindrop positions
void update(int value) {
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        raindrops[i].y -= raindrops[i].speed; // Move raindrop downwards
        // If raindrop goes below screen, reset its position to the top
        if (raindrops[i].y < -1.0f) {
            raindrops[i].y = 1.0f; // Reset y-coordinate
            raindrops[i].x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f; // Random x-coordinate
            raindrops[i].speed = 0.01f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 0.05f; // Random speed
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, update, 0); // Call update function after 50 milliseconds
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rain Effect");

    // Initialize raindrops
    initRain();

    glutDisplayFunc(display);
    glutTimerFunc(50, update, 0); // Call update function after 50 milliseconds

    glutMainLoop();
    return 0;
}
