#include <windows.h> 
#include<math.h>
#include <GL/glut.h> 

int currentscene = 0;

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
void House()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.2, 0.8);
    glVertex2f(-0.2, -0.8);
    glVertex2f(0.4, -0.8);
    glVertex2f(0.4, 0.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0, -0.8);
    glVertex2f(0.1, -0.8);
    glVertex2f(0.1, -0.6);
    glVertex2f(0, -0.6);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2, -0.5);
    glVertex2f(0.2, -0.6);
    glVertex2f(0.3, -0.6);
    glVertex2f(0.3, -0.5);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.4, 0.9);
    glVertex2f(0.4, 0.8);
    glVertex2f(0.2, 0.8);

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36, 1);
    glVertex2f(0.36, 0.9);
    glVertex2f(0.4, 0.9);
    glVertex2f(0.4, 1);

    glEnd();

    glFlush();

}

void window(float x, float y)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2 + x, 0.7 + y);
    glVertex2f(0.3 + x, 0.7 + y);
    glVertex2f(0.3 + x, 0.6 + y);
    glVertex2f(0.2 + x, 0.6 + y);



    glEnd();


    glFlush();

}

void table()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, -0.6);
    glVertex2f(0.9, -0.6);
    glVertex2f(0.9, -0.5);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.52, -0.52);
    glVertex2f(0.52, -0.58);
    glVertex2f(0.88, -0.58);
    glVertex2f(0.88, -0.52);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.54, -0.59);
    glVertex2f(0.55, -0.59);
    glVertex2f(0.54, -0.66);
    glVertex2f(0.55, -0.66);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.84, -0.59);
    glVertex2f(0.85, -0.59);
    glVertex2f(0.85, -0.66);
    glVertex2f(0.84, -0.66);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4470868438943, -0.6512046352296);
    glVertex2f(0.4470868438943, -0.7512046352296);
    glVertex2f(0.9470868438943, -0.7512046352296);
    glVertex2f(0.9470868438943, -0.6512046352296);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.4570868438943, -0.6712046352296);
    glVertex2f(0.4570868438943, -0.7312046352296);
    glVertex2f(0.9370868438943, -0.7312046352296);
    glVertex2f(0.9370868438943, -0.6712046352296);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.5, -0.74);
    glVertex2f(0.5, -0.8);
    glVertex2f(0.55, -0.8);
    glVertex2f(0.5498864567762, -0.7411413975327);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.84, -0.74);
    glVertex2f(0.84, -0.8);
    glVertex2f(0.9025843531667, -0.8004109426671);
    glVertex2f(0.9, -0.74);


    glEnd();
    glEnd();

    glFlush();

}
void tree()
{

    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex2f(-0.6128255393419, 0.5563316792327);
    glVertex2f(-0.5678255393419, 0.5563316792327);

    glVertex2f(-0.5678255393419, 0.5563316792327);
    glVertex2f(-0.5628255393419, -0.3436683207673);

    glVertex2f(-0.5628255393419, -0.3436683207673);
    glVertex2f(-0.6078255393419, -0.3436683207673);

    glVertex2f(-0.6078255393419, -0.3436683207673);
    glVertex2f(-0.6128255393419, 0.5563316792327);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.5928255393419, 0.6063316792327);
    glVertex2f(-0.6928255393419, 0.5063316792327);

    glVertex2f(-0.6928255393419, 0.5063316792327);
    glVertex2f(-0.4928255393419, 0.5063316792327);

    glVertex2f(-0.4928255393419, 0.5063316792327);
    glVertex2f(-0.5928255393419, 0.6063316792327);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.6928255393419, 0.5063316792327);
    glVertex2f(-0.4928255393419, 0.5063316792327);

    glVertex2f(-0.4928255393419, 0.5063316792327);
    glVertex2f(-0.4428255393419, 0.4063316792327);

    glVertex2f(-0.4428255393419, 0.4063316792327);
    glVertex2f(-0.7428255393419, 0.4063316792327);

    glVertex2f(-0.7428255393419, 0.4063316792327);
    glVertex2f(-0.6928255393419, 0.5063316792327);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.7428255393419, 0.4063316792327);
    glVertex2f(-0.4428255393419, 0.4063316792327);

    glVertex2f(-0.4428255393419, 0.4063316792327);
    glVertex2f(-0.3928255393419, 0.2563316792327);

    glVertex2f(-0.3928255393419, 0.2563316792327);
    glVertex2f(-0.7928255393419, 0.2563316792327);

    glVertex2f(-0.7928255393419, 0.2563316792327);
    glVertex2f(-0.7428255393419, 0.4063316792327);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.7928255393419, 0.2563316792327);
    glVertex2f(-0.3928255393419, 0.2563316792327);

    glVertex2f(-0.3928255393419, 0.2563316792327);
    glVertex2f(-0.3428255393419, 0.1563316792327);

    glVertex2f(-0.8428255393419, 0.1563316792327);
    glVertex2f(-0.8428255393419, 0.1563316792327);

    glVertex2f(-0.8428255393419, 0.1563316792327);
    glVertex2f(-0.7928255393419, 0.2563316792327);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.8428255393419, 0.1563316792327);
    glVertex2f(-0.3428255393419, 0.1563316792327);

    glVertex2f(-0.3928255393419, 0.2563316792327);
    glVertex2f(-0.2802093512555, -0.0041117831013);

    glVertex2f(-0.2802093512555, -0.0041117831013);
    glVertex2f(-0.9, 0);

    glVertex2f(-0.9, 0);
    glVertex2f(-0.8428255393419, 0.1563316792327);
    glEnd();
    glEnd();
    glFlush();
}
void lamp()
{
    glBegin(GL_POLYGON);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.8, -0.4);
    glVertex2f(0.8, 0.3);
    glVertex2f(0.7, 0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.9, 0.2);
    glVertex2f(0.9, 0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.1f);
    glVertex2f(0.75, 0.45);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.9, 0.3);

    glEnd();


    glFlush();

}
void lamp_line()
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f(0.62, 0.22);
    glVertex2f(0.6, 0.16);
    glVertex2f(0.66, 0.22);
    glVertex2f(0.64, 0.16);
    glVertex2f(0.72, 0.22);
    glVertex2f(0.7, 0.16);

    glVertex2f(0.76, 0.22);
    glVertex2f(0.74, 0.16);

    glVertex2f(0.82, 0.22);
    glVertex2f(0.8, 0.16);

    glVertex2f(0.86, 0.22);
    glVertex2f(0.84, 0.16);
    glVertex2f(0.88, 0.22);
    glVertex2f(0.86, 0.16);

    glEnd();
    glFlush();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(7.5);
    House();
    window(0.0, 0.0);
    window(0.0, -0.3);
    window(0.0, -0.6);
    window(0.0, -0.9);
    table();
    tree();
    lamp();
    lamp_line();


    if (currentscene == 0) {
        drawText(-0.6043671270253, -0.5448404795991, "This is a tree", 0.1, 1.0, 0.0, 0.0);
    }
    else if (currentscene == 1) {
        drawText(-0.0061557753375, -0.900403853293, "This is a House", 0.1, 1.0, 0.0, 0.0);
    }
    else if (currentscene == 2) {
        drawText(0.7458127109207, -0.4343275391266, "This is a Tree", 0.1, 1.0, 0.0, 0.0);
    }
    else if (currentscene == 3) {
        drawText(0.7602274422866, -0.9124161294313, "This is a bench", 0.1, 1.0, 0.0, 0.0);
    }

    glutSwapBuffers();
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


