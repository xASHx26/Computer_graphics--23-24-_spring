#include <windows.h> 
#include<math.h>
#include <GL/glut.h> 

int currentscene = 0;


void sky()
{
    glBegin(GL_POLYGON);
    glColor3f(0.53f, 0.81f, 0.98f);
    glVertex2f(-1.0012384840816, 0.2804620422142);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(0.9987142628961, 0.2710572983101);
    glEnd();
    glFlush();
}
void r()
{
    glBegin(GL_POLYGON);
    glColor3f(0.49f, 0.78f, 0.96f);
    glVertex2f(1.0, 0.2);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4203772636486, 0.1814318506227);
    glVertex2f(0.38f, 0.18);
    glVertex2f(0.7, 0.1);
    glVertex2f(0.6001827899022, 0.0602637884191);
    glVertex2f(1, -0.1);
    glEnd();
    glFlush();
}
void nr()
{
    glBegin(GL_POLYGON);
    glColor3f(0.16f, 0.16f, 0.16f);
    glVertex2f(1.0, 0.2);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4203772636486, 0.1814318506227);
    glVertex2f(0.38f, 0.18);
    glVertex2f(0.7, 0.1);
    glVertex2f(0.6001827899022, 0.0602637884191);
    glVertex2f(1, -0.1);
    glEnd();
    glFlush();
}
void nsky()
{
    glBegin(GL_POLYGON);
    glColor3f(0.14f, 0.14f, 0.15f);
    glVertex2f(-1.0012384840816, 0.2804620422142);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(0.9987142628961, 0.2710572983101);
    glEnd();
    glFlush();
}
void di()
{
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.4f, 0.2f);
    glVertex2f(-1.0012384840816, 0.2804620422142);
    glVertex2f(-1, 0.2);
    glVertex2f(1, 0.2);
    glVertex2f(0.9987142628961, 0.2710572983101);
    glEnd();
    glFlush();
}
void area()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-1, 0.2);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 0.2);
    glEnd();
    glFlush();
}
void House1()
{
    //house up
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(-0.2, 0.4);
    glVertex2f(0.2003855801538, 0.3811806139102);
    glVertex2f(0.4203772636486, 0.1814318506227);
    glVertex2f(0.0f, 0.2f);
    glEnd();//n
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.4f, 0.0f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.18f, 0.38f);
    glVertex2f(-0.36f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.0f, 1.0f);
    glVertex2f(-0.35f, 0.0f);
    glVertex2f(-0.36f, 0.2f);
    glVertex2f(-0.18f, 0.38f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.38, 0.036);
    glVertex2f(0.38f, 0.185f);

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.55f, 0.0f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.3f, 0.18f);
    glVertex2f(-0.1f, 0.18f);
    glVertex2f(-0.1f, 0.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.3f, 0.1f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.3f, 0.18f);
    glVertex2f(-0.2006543136017, 0.1384995039264);
    glVertex2f(-0.2, 0);

    glEnd();
    glFlush();
}
void House2()
{
    //house up
    glBegin(GL_POLYGON);

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(-0.2, 0.4);
    glVertex2f(0.2003855801538, 0.3811806139102);
    glVertex2f(0.4203772636486, 0.1814318506227);
    glVertex2f(0.0f, 0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.4f, 0.2f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.18f, 0.38f);
    glVertex2f(-0.36f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.2f, 1.0f);
    glVertex2f(-0.35f, 0.0f);
    glVertex2f(-0.36f, 0.2f);
    glVertex2f(-0.18f, 0.38f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.38, 0.036);
    glVertex2f(0.38f, 0.185f);

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.3f, 0.2f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.3f, 0.18f);
    glVertex2f(-0.1f, 0.18f);
    glVertex2f(-0.1f, 0.0f);

    glEnd();

    glFlush();
}
void sun()
{
    glBegin(GL_POLYGON);
    float xOixu = 0.4f;
    float yOixu = 0.7f;

    for (int i = 0;i < 300;i++)
    {
        glColor3f(1.0f, 0.8f, 0.2f);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 300;
        float r = 0.1f;
        float x = r * cos(A) + xOixu;
        float y = r * sin(A) + yOixu;
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();

}
void moon()
{
    glBegin(GL_POLYGON);
    float xOixy = 0.3f;
    float yOixy = 0.6f;

    for (int i = 0;i < 300;i++)
    {
        glColor3f(0.85f, 0.9f, 0.9f);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 300;
        float r = 0.1f;
        float x = r * cos(A) + xOixy;
        float y = r * sin(A) + yOixy;
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();

}

void Tree()
{
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.3f, .0f);
    glVertex2f(-0.64f, 0.4f);
    glVertex2f(-0.56f, 0.4f);
    glVertex2f(-0.55f, 0.05f);
    glVertex2f(-0.65f, 0.05f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.3f, .10f);
    glVertex2f(-0.65f, 0.05f);
    glVertex2f(-0.55f, 0.05f);
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(-0.7f, 0.0);

    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin

    float xO = -0.7f;
    float yO = 0.5f;

    for (int i = 0;i < 300;i++)
    {
        glColor3f(0.0, 0.9, 0.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 300;
        float r = 0.166f;
        float x = r * cos(A) + xO;
        float y = r * sin(A) + yO;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_POLYGON);
    float xOi = -0.50f;
    float yOi = 0.54f;

    for (int i = 0;i < 300;i++)
    {
        glColor3f(0.0, 0.9, 0.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 300;
        float r = 0.165f;
        float x = r * cos(A) + xOi;
        float y = r * sin(A) + yOi;
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POLYGON);
    float xOix = -0.6f;
    float yOix = 0.7f;

    for (int i = 0;i < 300;i++)
    {
        glColor3f(0.0, 0.9, 0.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 300;
        float r = 0.143f;
        float x = r * cos(A) + xOix;
        float y = r * sin(A) + yOix;
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}
void drawText(float x, float y, const char* text, float scale, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);
    glColor3f(r, g, b); // Set text color
    glRasterPos2f(0.0f, 0.0f);
    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
    glPopMatrix();
}
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(8);
    sky();
    di();
    area();
    House1();
    Tree();
    sun();
    r();

    if (currentscene == 0) {
        drawText(-0.6f, -0.5f, "This is a tree", 0.15, 1.0, 0.0, 0.0);
    }
    else if (currentscene == 1) {
        drawText(-0.1f, -0.9f, "This is a House", 0.15, 1.0, 0.0, 0.0);
    }
    else if (currentscene == 2) {
        drawText(0.7f, -0.4f, "This is a Tree", 0.15, 1.0, 0.0, 0.0);
    }
    else if (currentscene == 3) {
        drawText(0.7f, -0.9f, "This is a bench", 0.15, 1.0, 0.0, 0.0);
    }

    glutSwapBuffers(); // Swap the front and back buffers to display the rendered image
}
void update(int value) {
    currentscene = (currentscene + 1) % 4;
    glutPostRedisplay();
    glutTimerFunc(2000, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Vertex, Primitive & Color");
    glutInitWindowSize(800, 600);
    glutDisplayFunc(display);
    glutTimerFunc(2000, update, 0); // Start the timer
    glutMainLoop();
    return 0;
}
