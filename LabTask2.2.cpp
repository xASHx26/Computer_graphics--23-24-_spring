#include <windows.h> 
#include <GL/glut.h> 


void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5);


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    //block
    glVertex2f(-0.8, 0.8);
    glVertex2f(-0.8, -0.8);

    glVertex2f(-0.8, -0.8);
    glVertex2f(0.8, -0.8);

    glVertex2f(0.8, -0.8);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.8, 0.8);
    glVertex2f(-0.8, 0.8);
    //up line
    glVertex2f(-.4f, .8f);
    glVertex2f(-.4f, -.8f);

    glVertex2f(0.0f, .8f);
    glVertex2f(0.0f, -.8f);

    glVertex2f(.4f, .8f);
    glVertex2f(.4f, -.8f);
    //low line

    glVertex2f(-.8f, .4f);
    glVertex2f(0.8f, .4f);

    glVertex2f(-.8f, 0.0f);
    glVertex2f(.8f, 0.0f);

    glVertex2f(-.8f, -.4f);
    glVertex2f(.8f, -.4f);




    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8, 0.8);
    glVertex2f(-0.8, 0.4);

    glVertex2f(-0.8, 0.4);
    glVertex2f(-0.4, 0.4);

    glVertex2f(-0.4, 0.4);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.4, 0.8);
    glVertex2f(-0.8, 0.8);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8, 0);
    glVertex2f(-0.8, -0.4);

    glVertex2f(-0.8, -0.4);
    glVertex2f(-0.4, -0.4);

    glVertex2f(-0.4, -0.4);
    glVertex2f(-0.4, 0);

    glVertex2f(-0.4, 0);
    glVertex2f(-0.8, 0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 0.8);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.4, 0.8);
    glVertex2f(0.4, 0.4);

    glVertex2f(0.4, 0.4);
    glVertex2f(0, 0.4);

    glVertex2f(0, 0.4);
    glVertex2f(0, 0.8);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4, 0.4);
    glVertex2f(0, 0.4);

    glVertex2f(0, 0.4);
    glVertex2f(0, 0);

    glVertex2f(0, 0);
    glVertex2f(-0.4, 0);

    glVertex2f(-0.4, 0);
    glVertex2f(-0.4, 0.4);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 0);
    glVertex2f(0.4, 0);

    glVertex2f(0.4, 0);
    glVertex2f(0.4, -0.4);

    glVertex2f(0.4, -0.4);
    glVertex2f(0, -0.4);

    glVertex2f(0, -0.4);
    glVertex2f(0, 0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4, 0.4);
    glVertex2f(0.4, 0);

    glVertex2f(0.4, 0);
    glVertex2f(0.8, 0);

    glVertex2f(0.8, 0);
    glVertex2f(0.8, 0.4);

    glVertex2f(0.8, 0.4);
    glVertex2f(0.4, 0.4);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4, -0.4);
    glVertex2f(-0.4, -0.8);

    glVertex2f(-0.4, -0.8);
    glVertex2f(0, -0.8);

    glVertex2f(0, -0.8);
    glVertex2f(0, -0.4);

    glVertex2f(0, -0.4);
    glVertex2f(-0.4, -0.4);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4, -0.8);
    glVertex2f(0.8, -0.8);

    glVertex2f(0.8, -0.8);
    glVertex2f(0.8, -0.4);

    glVertex2f(0.8, -0.4);
    glVertex2f(0.4, -0.4);

    glVertex2f(0.4, -0.4);
    glVertex2f(0.4, -0.8);

    glEnd();

    glEnd();


    glFlush();

}


int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutCreateWindow("OpenGL Setup");

    glutInitWindowSize(5000, 4000);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}