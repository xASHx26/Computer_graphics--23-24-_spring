#include <windows.h> 
#include<math.h>
#include <GL/glut.h> 




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

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(7.5);

    table();











}



int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutCreateWindow("Vertex, Primitive & Color");

    glutInitWindowSize(320, 320);

    glutDisplayFunc(display);


    glutMainLoop();

    return 0;

}