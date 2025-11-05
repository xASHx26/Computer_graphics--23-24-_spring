#include <windows.h> 
#include<math.h>
#include <GL/glut.h> 


void initGL() {



    glClearColor(0.0, 0.0, 0.0, 1.0);


}
void lamp()
{
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.0f, 0.0f);
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
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(7.5);


    lamp();

    lamp_line();






    glEnd();
    glEnd();








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