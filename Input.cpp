#include <windows.h>
#include <GL/glut.h>
#include <cstdlib> // For rand()
#include<math.h>
float scaleX = 100.0f;
float scaleY = 56.18f;
float _move = 0.0f;
void initGL() {
    glClearColor(.0f, 0.0f, 0.0f, 0.0f);
}
void drawCircumcircularArc(float cx, float cy, float radius, float startAngle, float endAngle, float middleX, float middleY, int numSegments) {
    // Convert angles from degrees to radians
    startAngle = startAngle * M_PI / 180.0;
    endAngle = endAngle * M_PI / 180.0;

    // Calculate distance and angle of the middle point from the center
    float dx = middleX - cx;
    float dy = middleY - cy;
    float distance = sqrt(dx * dx + dy * dy);
    float middleAngle = atan2(dy, dx);

    // Calculate start and end angles of the circumcircle arc
    float startDelta = middleAngle - startAngle;
    float endDelta = middleAngle - endAngle;

    // Start drawing the arc
    glBegin(GL_LINE_STRIP);
    // Draw from start angle to middle angle
    for (int i = 0; i <= numSegments / 2; ++i) {
        float angle = startAngle + (startDelta / (numSegments / 2)) * i;
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
    // Draw from middle angle to end angle
    for (int i = 0; i <= numSegments / 2; ++i) {
        float angle = middleAngle + (endDelta / (numSegments / 2)) * i;
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void cr1() {
    // Set color to white for the arc
    glColor3f(1.0, 1.0, 1.0);
    // Draw the circumcircular arc passing through the middle point
    drawCircumcircularArc(0.0, 0.0, 50.0, -180.0, -60.0, 20.0, 20.0, 100);
}
void ground() {
    // First polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f); // Dark blue
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.8 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(1.0 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glEnd();

    // Second polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.6f); // Medium blue
    glVertex2f(-1 * scaleX, -0.6 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glEnd();

    // Third polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.8f); // Slightly lighter blue with a hint of green
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glVertex2f(0 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glEnd();

    // Fourth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.7f); // Medium blue with a hint of green
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(0.6 * scaleX, -0.5 * scaleY);
    glEnd();

    // Fifth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.0f, 0.6f); // Dark blue with a hint of purple
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(0.6 * scaleX, -0.5 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glEnd();

    // Sixth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.8f); // Lighter blue
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glVertex2f(-0.1 * scaleX, -1 * scaleY);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glEnd();

    // Seventh polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.9f); // Even lighter blue
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glVertex2f(1 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -1 * scaleY);
    glEnd();

    // Eighth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 1.0f); // Bright blue with a touch of green
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glVertex2f(1 * scaleX, -0.4 * scaleY);
    glVertex2f(0.7 * scaleX, -0.3 * scaleY);
    glEnd();

    // Ninth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f); // Dark blue
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glVertex2f(-1 * scaleX, -1 * scaleY);
    glVertex2f(-0.1 * scaleX, -1 * scaleY);
    glEnd();

    // Tenth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.4f); // Dark blue with a touch of black
    glVertex2f(-0.1 * scaleX, -1 * scaleY);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -1 * scaleY);
    glEnd();

    // Eleventh polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.6f); // Medium blue with a touch of green
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glVertex2f(1 * scaleX, -0.4 * scaleY);
    glVertex2f(1 * scaleX, -0.8 * scaleY);
    glEnd();

    // Twelfth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.2f); // Dark blue with more black
    glVertex2f(-1 * scaleX, -1 * scaleY);
    glVertex2f(-1 * scaleX, -1.2 * scaleY);
    glVertex2f(1 * scaleX, -1.2 * scaleY);
    glVertex2f(1 * scaleX, -1 * scaleY);
    glEnd();

    // Thirteenth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.1f); // Very dark blue, almost black
    glVertex2f(-1 * scaleX, -1.2 * scaleY);
    glVertex2f(-1 * scaleX, -1.4 * scaleY);
    glVertex2f(1 * scaleX, -1.4 * scaleY);
    glVertex2f(1 * scaleX, -1.2 * scaleY);
    glEnd();

    // Fourteenth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.6f); // Medium blue with a hint of black
    glVertex2f(1 * scaleX, -0.8 * scaleY);
    glVertex2f(1 * scaleX, -1 * scaleY);
    glVertex2f(0.8 * scaleX, -1 * scaleY);
    glEnd();

    // Fifteenth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.6f); // Medium blue
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(-1 * scaleX, -0.6 * scaleY);
    glEnd();

    // Sixteenth polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.6f); // Medium blue with a hint of green
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glEnd();
    //seventheen polygon 
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f); // Dark blue
    glVertex2f(-100, -0.5 * 56.18);
    glVertex2f(-50, -28);
    glVertex2f(-100, -0.6 * 56.18);

    glEnd();
}
void Sky() {
    glBegin(GL_POLYGON);
    // Adjust color gradient to reflect a cosmic theme
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




void moon(float x, float y, float radius) {
    // Define the colors for the cosmic gradient
    float colors[][3] = {
        {0.8f, 0.8f, 0.8f},  // Light gray
        {0.4f, 0.4f, 0.4f},  // Medium gray
        {0.1f, 0.1f, 0.1f},  // Dark gray
        {0.0f, 0.0f, 0.0f}   // Black
    };

    // Set the number of colors
    int numColors = sizeof(colors) / sizeof(colors[0]);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; ++i) {
        // Calculate the color index based on the position along the circumference
        int colorIndex = (i * numColors) / 100;
        float* currentColor = colors[colorIndex];

        glColor3f(currentColor[0], currentColor[1], currentColor[2]);

        float angle = i * 2.0f * M_PI / 100;
        float moonX = x + radius * cos(angle);
        float moonY = y + radius * sin(angle);
        glVertex2f(moonX, moonY);
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
    //shaders
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
    glColor3f(0.3f, 0.15f, 0.05f); // Darker brown
    glVertex2f(-1.2 * scaleX, 0.2 * scaleY);
    glColor3f(0.4f, 0.2f, 0.1f); // Slightly lighter brown
    glVertex2f(1.2 * scaleX, 0.2 * scaleY);
    glColor3f(0.5f, 0.25f, 0.15f); // Another shade of brown
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
void spaceship()
{
    glPushMatrix(); // Save the current transformation matrix

    // Apply rotation to make the spaceship vertical
    glTranslatef(_move, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f); // Rotate 90 degrees around the z-axis

    //space ship body
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f); // Gray color for body
    glVertex2f(-20, -12);
    glVertex2f(8, -12);
    glVertex2f(14, -15);
    glVertex2f(8, -18);
    glVertex2f(-20, -18);
    glVertex2f(-22, -17);
    glVertex2f(-22, -15);
    glVertex2f(-22, -13);
    glEnd();

    //wings1
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray color for wings
    glVertex2f(-20, -12);
    glVertex2f(-20, -5);
    glVertex2f(-18, -4);
    glVertex2f(-10, -12);
    glEnd();

    //wings2
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray color for wings
    glVertex2f(-20, -18);
    glVertex2f(-20, -24);
    glVertex2f(-18, -26);
    glVertex2f(-10, -18);
    glEnd();

    //shuttle1
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f); // Light gray color for shuttle
    glVertex2f(-12, -10);
    glVertex2f(4, -10);
    glVertex2f(4, -12);
    glVertex2f(-10, -12);
    glEnd();

    //shuttle2
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f); // Light gray color for shuttle
    glVertex2f(4, -18);
    glVertex2f(4, -20);
    glVertex2f(-12, -20);
    glVertex2f(-10, -18);
    glEnd();

    //upper shuttle
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f); // Light gray color for shuttle
    glVertex2f(-14, -14);
    glVertex2f(-14, -16);
    glVertex2f(8, -16);
    glVertex2f(8, -14);
    glEnd();

    //head
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f); // Silver color for head
    glVertex2f(8, -12);
    glVertex2f(8, -18);
    glVertex2f(14, -15);
    glEnd();

    //flames
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for flames
    glVertex2f(-22.5, -17);
    glVertex2f(-24.0172260954958, -16.9005409597052);
    glVertex2f(-23.5, -16);
    glVertex2f(-24, -15.5);
    glVertex2f(-22.5, -15);

    glVertex2f(-24, -14.5);
    glVertex2f(-23.5, -14);
    glVertex2f(-24, -13);
    glVertex2f(-22.5, -13);
    glVertex2f(-22.5, -17);
    glEnd();

    glPopMatrix(); // Restore the previous transformation matrix
}

void arc(float xOffset, float yOffset, float r) {
    glLineWidth(7); // Set the line width before drawing
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + xOffset;
        float y = r * sin(a) + yOffset;

        // Define gradient colors
        float red = 1.0 - (float)i / 300; // Red component decreases as i increases
        float green = 0.5; // Constant green component
        float blue = (float)i / 300; // Blue component increases as i increases

        glColor3f(red, green, blue);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);

    cr1(); // Draw the circumcircular arc first

    ground();
    Sky();
    arc(0, -110, 160.08225989589045);
    moon(-70, 40, 0.5);  // Add a moon at (-70, 40) with radius 0.5
    moon(-50, 35, 0.5);  // Add another moon at (-50, 35) with radius 0.5
    moon(-30, 45, 0.5);  // Add another moon at (-30, 45) with radius 0.5
    moon(-10, 40, 0.5);  // Add another moon at (-10, 40) with radius 0.5
    moon(10, 30, 0.5);   // Add another moon at (10, 30) with radius 0.5
    moon(30, 25, 0.5);   // Add another moon at (30, 25) with radius 0.5
    // Add 10 more moons
    moon(-60, 50, 0.5);  // Example position and radius, adjust as needed
    moon(-40, 55, 0.5);
    moon(-20, 50, 0.5);
    moon(0, 45, 0.5);
    moon(20, 40, 0.5);
    moon(40, 35, 0.5);
    moon(60, 30, 0.5);
    moon(-80, 30, 0.5);
    moon(-90, 20, 0.5);
    moon(-100, 10, 0.5);
    // Add 10 more moons on the left side of the 3rd mountain
    moon(-60, 50, 0.5);   // Example position and radius, adjust as needed
    moon(-65, 45, 0.5);
    moon(-70, 40, 0.5);
    moon(-75, 35, 0.5);
    moon(-80, 30, 0.5);
    moon(-85, 25, 0.5);
    moon(-90, 20, 0.5);
    moon(-95, 15, 0.5);
    moon(-100, 10, 0.5);
    moon(-105, 5, 0.5);
    // Add 20 more moons on the right side of the 3rd mountain
    moon(40, 50, 0.5);   // Example position and radius, adjust as needed
    moon(45, 45, 0.5);
    moon(50, 40, 0.5);
    moon(55, 35, 0.5);
    moon(60, 30, 0.5);
    moon(65, 25, 0.5);
    moon(70, 20, 0.5);
    moon(75, 15, 0.5);
    moon(80, 10, 0.5);
    moon(85, 5, 0.5);
    moon(90, 0, 0.5);
    moon(95, 5, 0.5);
    moon(100, 10, 0.5);
    moon(105, 15, 0.5);
    moon(110, 20, 0.5);
    moon(115, 25, 0.5);
    moon(120, 30, 0.5);
    moon(125, 35, 0.5);
    moon(130, 40, 0.5);
    moon(135, 45, 0.5);




    mountain();

    spaces();
    spaceship();

    glFlush(); // Ensure all OpenGL commands are executed
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Vertex, Primitive & Color");
    glutInitWindowSize(320, 320);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}