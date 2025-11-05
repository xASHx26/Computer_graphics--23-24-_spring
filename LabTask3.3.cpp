#include <windows.h> 
#include<math.h>
#include <GL/glut.h> 


void initGL() {



    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

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


void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(7.5);

    tree();















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