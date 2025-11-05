#include <windows.h> 
#include <GL/glut.h> 
#include<math.h>    


void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5);

    //N
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8, 0.6);
    glVertex2f(-0.8, -0.2);

    glVertex2f(-0.8, -0.2);
    glVertex2f(-0.75, -0.2);

    glVertex2f(-0.75, -0.2);
    glVertex2f(-0.75, 0.55);

    glVertex2f(-0.75, 0.55);
    glVertex2f(-0.5, -0.2);

    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.4, -0.2);


    glVertex2f(-0.4, -0.2);
    glVertex2f(-0.7, 0.6);

    glVertex2f(-0.7, 0.6);
    glVertex2f(-0.8, 0.6);







    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.4, -0.2);

    glVertex2f(-0.4, -0.2);
    glVertex2f(-0.35, -0.2);

    glVertex2f(-0.35, -0.2);
    glVertex2f(-0.35, 0.6);

    glVertex2f(-0.35, 0.6);
    glVertex2f(-0.4, 0.6);

    glEnd();

    //A
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.3, 0.6);
    glVertex2f(-0.3, -0.2);

    glVertex2f(-0.3, -0.2);
    glVertex2f(-0.1, -0.2);

    glVertex2f(-0.1, -0.2);
    glVertex2f(-0.1, 0.6);

    glVertex2f(-0.1, 0.6);
    glVertex2f(-0.3, 0.6);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.25, 0.5);
    glVertex2f(-0.25, 0.35);

    glVertex2f(-0.25, 0.35);
    glVertex2f(-0.1, 0.35);

    glVertex2f(-0.1, 0.35);
    glVertex2f(-0.1, 0.50);

    glVertex2f(-0.1, 0.50);
    glVertex2f(-0.25, 0.5);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.25, 0.5);
    glVertex2f(-0.25, 0.35);

    glVertex2f(-0.25, 0.35);
    glVertex2f(-0.1, 0.35);

    glVertex2f(-0.1, 0.35);
    glVertex2f(-0.1, 0.50);

    glVertex2f(-0.1, 0.50);
    glVertex2f(-0.25, 0.5);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.25, 0.05);
    glVertex2f(-0.25, -0.1);

    glVertex2f(-0.25, -0.1);
    glVertex2f(-0.1, -0.1);

    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.05);

    glVertex2f(-0.1, 0.05);
    glVertex2f(-0.25, 0.05);


    glEnd();

    //p

    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.08, 0.6);
    glVertex2f(-0.08, -0.2);

    glVertex2f(-0.08, -0.2);
    glVertex2f(-0.05, -0.2);

    glVertex2f(-0.05, -0.2);
    glVertex2f(-0.05, 0.6);

    glVertex2f(-0.05, 0.6);
    glVertex2f(-0.08, 0.6);


    glEnd();

    glBegin(GL_POLYGON);

    float xOffse = 0.0f;
    float yOffse = 0.55f;

    for (int i = 0; i < 300; i++)
    {
        glColor3f(0.0f, 0.0f, 0.0f);;

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.09;
        float x = r * cos(a) + xOffse;
        float y = r * sin(a) + yOffse;
        glVertex2f(x, y);
    }


    glEnd();

    //T

    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.15, 0.6);
    glVertex2f(0.15, -0.2);

    glVertex2f(0.15, -0.2);
    glVertex2f(0.16, -0.2);

    glVertex2f(0.16, -0.2);
    glVertex2f(0.16, 0.6);

    glVertex2f(0.16, 0.6);
    glVertex2f(0.15, 0.6);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.08, 0.38);
    glVertex2f(0.08, 0.36);

    glVertex2f(0.08, 0.36);
    glVertex2f(0.22, 0.36);

    glVertex2f(0.22, 0.36);
    glVertex2f(0.22, 0.38);

    glVertex2f(0.22, 0.38);
    glVertex2f(0.08, 0.38);


    glEnd();

    //u 
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.30, 0);

    glVertex2f(0.30, 0);
    glVertex2f(0.32, -0.06);

    glVertex2f(0.32, -0.06);
    glVertex2f(0.38, -0.06);

    glVertex2f(0.38, -0.06);
    glVertex2f(0.40, 0);

    glVertex2f(0.38, -0.06);
    glVertex2f(0.40, 0);

    glVertex2f(0.40, 0);
    glVertex2f(0.4, 0.6);

    glVertex2f(0.4, 0.6);
    glVertex2f(0.38, 0.6);

    glVertex2f(0.38, 0.6);
    glVertex2f(0.39, 0);


    glVertex2f(0.39, 0);
    glVertex2f(0.37, -0.05);

    glVertex2f(0.37, -0.05);
    glVertex2f(0.33, -0.05);

    glVertex2f(0.33, -0.05);
    glVertex2f(0.32, 0);

    glVertex2f(0.32, 0);
    glVertex2f(0.32, 0.6);

    glVertex2f(0.32, 0.6);
    glVertex2f(0.3, 0.6);



    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.38, 0.6);
    glVertex2f(0.39, 0);

    glVertex2f(0.39, 0);
    glVertex2f(0.37, -0.05);

    glVertex2f(0.37, -0.05);
    glVertex2f(0.33, -0.05);

    glVertex2f(0.33, -0.05);
    glVertex2f(0.32, 0);

    glVertex2f(0.32, 0);
    glVertex2f(0.32, 0.6);

    glVertex2f(0.32, 0.6);
    glVertex2f(0.38, 0.6);



    glEnd();




    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.30, 0);

    glVertex2f(0.30, 0);
    glVertex2f(0.32, -0.06);

    glVertex2f(0.32, -0.06);
    glVertex2f(0.38, -0.06);

    glVertex2f(0.38, -0.06);
    glVertex2f(0.40, 0);

    glVertex2f(0.38, -0.06);
    glVertex2f(0.40, 0);

    glVertex2f(0.40, 0);
    glVertex2f(0.4, 0.6);

    glVertex2f(0.4, 0.6);
    glVertex2f(0.38, 0.6);

    glVertex2f(0.38, 0.6);
    glVertex2f(0.39, 0);


    glVertex2f(0.39, 0);
    glVertex2f(0.37, -0.05);

    glVertex2f(0.37, -0.05);
    glVertex2f(0.33, -0.05);

    glVertex2f(0.33, -0.05);
    glVertex2f(0.32, 0);

    glVertex2f(0.32, 0);
    glVertex2f(0.32, 0.6);

    glVertex2f(0.32, 0.6);
    glVertex2f(0.3, 0.6);



    glEnd();

    //N
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.5, 0.6);
    glVertex2f(0.5, -0.2);

    glVertex2f(0.5, -0.2);
    glVertex2f(0.55, -0.2);

    glVertex2f(0.55, -0.2);
    glVertex2f(0.55, 0.55);

    glVertex2f(0.55, 0.55);
    glVertex2f(0.7, -0.2);

    glVertex2f(0.7, -0.2);
    glVertex2f(0.75, -0.2);

    glVertex2f(0.75, -0.2);
    glVertex2f(0.75, 0.6);

    glVertex2f(0.75, 0.6);
    glVertex2f(0.7, 0.6);

    glVertex2f(0.7, 0.6);
    glVertex2f(0.7, 0);

    glVertex2f(0.7, 0);
    glVertex2f(0.55, 0.55);

    glVertex2f(0.55, 0.55);
    glVertex2f(0.5, 0.6);





    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.56, 0.6);
    glVertex2f(0.7, 0);

    glVertex2f(0.7, 0);
    glVertex2f(0.7, 0.6);

    glVertex2f(0.7, 0.6);
    glVertex2f(0.56, 0.6);







    glEnd();

    //E

    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.8, 0.6);
    glVertex2f(0.8, -0.2);

    glVertex2f(0.8, -0.2);
    glVertex2f(0.95, -0.2);

    glVertex2f(0.95, -0.2);
    glVertex2f(0.95, -0.05);

    glVertex2f(0.95, -0.05);
    glVertex2f(0.85, -0.05);

    glVertex2f(0.85, -0.05);
    glVertex2f(0.85, 0.15);

    glVertex2f(0.85, 0.15);
    glVertex2f(0.95, 0.15);

    glVertex2f(0.95, 0.15);
    glVertex2f(0.95, 0.3);

    glVertex2f(0.95, 0.3);
    glVertex2f(0.85, 0.3);

    glVertex2f(0.85, 0.3);
    glVertex2f(0.85, 0.5);

    glVertex2f(0.85, 0.5);
    glVertex2f(0.95, 0.5);

    glVertex2f(0.95, 0.5);
    glVertex2f(0.95, 0.6);

    glVertex2f(0.95, 0.6);
    glVertex2f(0.8, 0.6);






    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.85, 0.5);
    glVertex2f(0.85, 0.3);

    glVertex2f(0.85, 0.3);
    glVertex2f(0.95, 0.3);

    glVertex2f(0.95, 0.3);
    glVertex2f(0.95, 0.5);

    glVertex2f(0.95, 0.5);
    glVertex2f(0.85, 0.5);







    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.85, 0.15);
    glVertex2f(0.85, -0.05);

    glVertex2f(0.85, -0.05);
    glVertex2f(0.95, -0.05);

    glVertex2f(0.95, -0.05);
    glVertex2f(0.95, 0.15);

    glVertex2f(0.95, 0.15);
    glVertex2f(0.85, 0.15);



    glEnd();

    //u2nd

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.32, 0.6);
    glVertex2f(0.38, 0.6);

    glVertex2f(0.38, 0.6);
    glVertex2f(0.39, 0);

    glVertex2f(0.39, 0);
    glVertex2f(0.36, -0.06);

    glVertex2f(0.36, -0.06);
    glVertex2f(0.32, 0);

    glVertex2f(0.32, 0);
    glVertex2f(0.32, 0.6);






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