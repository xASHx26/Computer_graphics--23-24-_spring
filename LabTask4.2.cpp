#include <windows.h> 
#include <GL/glut.h> 
#include<math.h>
void traficlight()
{
    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.2, 0.2);
    glVertex2f(-1.2, -0.2);
    glVertex2f(-0.2, -0.2);
    glVertex2f(-0.2, 0.2);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2, 1.2);
    glVertex2f(-0.2, 0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.2, 1.2);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(1.2, 0.2);
    glVertex2f(1.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, 0.2);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2, -1.2);
    glVertex2f(0.2, -1.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(-0.2, -0.2);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, 0.2);


    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineStipple(5, 0x0C0F);
    glBegin(GL_LINES);
    glVertex2f(-1.15, 0.0);
    glVertex2f(-0.1, 0.0);
    glVertex2f(0, -1.1);
    glVertex2f(0, -0.1);
    glVertex2f(1.1, 0);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.0, 1.1);
    glVertex2f(0.0, 0.1);

    glEnd();


    glDisable(GL_LINE_STIPPLE);





    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, 0.1);


    glEnd();
    glBegin(GL_POLYGON);
    float xOffa = -0.1f;
    float yOffa = 0.1f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 1.0f, 1.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.1;
        float x = r * cos(a) + xOffa;
        float y = r * sin(a) + yOffa;
        glVertex2f(x, y);

    }

    glEnd();

    glBegin(GL_POLYGON);
    float xOffa2 = 0.1f;
    float yOffa2 = 0.1f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 1.0f, 1.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.1;
        float x = r * cos(a) + xOffa2;
        float y = r * sin(a) + yOffa2;
        glVertex2f(x, y);

    }

    glEnd();
    glBegin(GL_POLYGON);
    float xOffa3 = 0.1f;
    float yOffa3 = -0.1f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 1.0f, 1.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.1;
        float x = r * cos(a) + xOffa3;
        float y = r * sin(a) + yOffa3;
        glVertex2f(x, y);

    }

    glEnd();
    glBegin(GL_POLYGON);
    float xOffa4 = -0.1f;
    float yOffa4 = -0.1f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 1.0f, 1.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.1;
        float x = r * cos(a) + xOffa4;
        float y = r * sin(a) + yOffa4;
        glVertex2f(x, y);

    }

    glEnd();

    glBegin(GL_POLYGON);
    float xOffa5 = 0.0f;
    float yOffa5 = 0.f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 1.0f, 1.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.04;
        float x = r * cos(a) + xOffa5;
        float y = r * sin(a) + yOffa5;
        glVertex2f(x, y);

    }

    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.38, -0.3);
    glVertex2f(-0.26, -0.3);
    glVertex2f(-0.26, -0.6);
    glVertex2f(-0.38, -0.6);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.35, -0.2005);
    glVertex2f(-0.28, -0.2005);
    glVertex2f(-0.28, -0.3);
    glVertex2f(-0.35, -0.3);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5, 0.35);
    glVertex2f(-0.5, 0.25);
    glVertex2f(-0.25, 0.25);
    glVertex2f(-0.25, 0.35);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2, 0.28);
    glVertex2f(-0.2481812657682, 0.2792777718654);
    glVertex2f(-0.25, 0.32);
    glVertex2f(-0.2, 0.32);


    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.22, 0.5);
    glVertex2f(0.22, 0.25);
    glVertex2f(0.33, 0.25);
    glVertex2f(0.33, 0.5);


    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.26, 0.2);
    glVertex2f(0.29, 0.2);
    glVertex2f(0.28994796877, 0.2501393887935);
    glVertex2f(0.26, 0.25);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.24, -0.22);
    glVertex2f(0.24, -0.32);
    glVertex2f(0.6, -0.32);
    glVertex2f(0.6, -0.22);


    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2, -0.24);
    glVertex2f(0.2, -0.28);
    glVertex2f(0.24, -0.28);
    glVertex2f(0.24, -0.24);


    glEnd();
    glBegin(GL_POLYGON);
    float xOffa1 = 0.32f;
    float yOffa1 = -0.26f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 0.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa1;
        float y = r * sin(a) + yOffa1;
        glVertex2f(x, y);

    }
    glEnd();
    glBegin(GL_POLYGON);
    float xOffa11 = 0.44f;
    float yOffa11 = -0.26f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(0.0f, 1.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa11;
        float y = r * sin(a) + yOffa11;
        glVertex2f(x, y);

    }
    glEnd();
    glBegin(GL_POLYGON);
    float xOffa1q1 = 0.54f;
    float yOffa1q1 = -0.26f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 1.0f, 0.0f); // Set color to yellow

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa1q1;
        float y = r * sin(a) + yOffa1q1;
        glVertex2f(x, y);

    }
    glEnd();

    //2
    glBegin(GL_POLYGON);
    float xOffa12 = 0.27f;
    float yOffa12 = 0.3f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 0.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa12;
        float y = r * sin(a) + yOffa12;
        glVertex2f(x, y);

    }
    glEnd();
    glBegin(GL_POLYGON);
    float xOffa113 = 0.27f;
    float yOffa113 = 0.38f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(0.0f, 1.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa113;
        float y = r * sin(a) + yOffa113;
        glVertex2f(x, y);

    }
    glEnd();
    glBegin(GL_POLYGON);
    float xOffa1q12 = 0.27f;
    float yOffa1q12 = 0.46f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 1.0f, 0.0f); // Set color to yellow

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa1q12;
        float y = r * sin(a) + yOffa1q12;
        glVertex2f(x, y);

    }
    glEnd();
    //3
    glBegin(GL_POLYGON);
    float xOffa221 = -0.45f;
    float yOffa221 = 0.3f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 0.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa221;
        float y = r * sin(a) + yOffa221;
        glVertex2f(x, y);

    }
    glEnd();
    glBegin(GL_POLYGON);
    float xOffa1331 = -0.37f;
    float yOffa1331 = 0.3f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(0.0f, 1.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa1331;
        float y = r * sin(a) + yOffa1331;
        glVertex2f(x, y);

    }
    glEnd();
    glBegin(GL_POLYGON);
    float xOffa1wq1 = -0.29f;
    float yOffa1wq1 = 0.3f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 1.0f, 0.0f); // Set color to yellow

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa1wq1;
        float y = r * sin(a) + yOffa1wq1;
        glVertex2f(x, y);

    }
    glEnd();

    //4
    glBegin(GL_POLYGON);
    float xOffa312 = -0.32f;
    float yOffa312 = -0.34f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 0.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa312;
        float y = r * sin(a) + yOffa312;
        glVertex2f(x, y);

    }
    glEnd();
    glBegin(GL_POLYGON);
    float xOffa1132 = -0.32f;
    float yOffa1132 = -0.44f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(0.0f, 1.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa1132;
        float y = r * sin(a) + yOffa1132;
        glVertex2f(x, y);

    }
    glEnd();
    glBegin(GL_POLYGON);
    float xOffa1q122 = -0.32f;
    float yOffa1q122 = -0.54f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 1.0f, 0.0f); // Set color to yellow

        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.025;
        float x = r * cos(a) + xOffa1q122;
        float y = r * sin(a) + yOffa1q122;
        glVertex2f(x, y);

    }
    glEnd();
    glFlush();
}


void cars()
{
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.35, 0.05);
    glVertex2f(-0.5, 0.05);
    glVertex2f(-0.5, 0.06);
    glVertex2f(-0.46, 0.08);
    glVertex2f(-0.45, 0.1);
    glVertex2f(-0.35, 0.1);

    glEnd();
    glBegin(GL_POLYGON);
    float xOffa5 = -0.47f;
    float yOffa5 = 0.05f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 0.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.01;
        float x = r * cos(a) + xOffa5;
        float y = r * sin(a) + yOffa5;
        glVertex2f(x, y);

    }

    glEnd();

    //2nd
    glBegin(GL_POLYGON);


    glEnd();
    glBegin(GL_POLYGON);
    float xOffa1 = -0.38f;
    float yOffa1 = 0.05f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 0.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.01;
        float x = r * cos(a) + xOffa1;
        float y = r * sin(a) + yOffa1;
        glVertex2f(x, y);

    }

    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3, -0.1);
    glVertex2f(0.35, -0.05);
    glVertex2f(0.5, -0.05);
    glVertex2f(0.5, -0.1);


    glEnd();
    glBegin(GL_POLYGON);
    float xOffa2221 = 0.36f;
    float yOffa2221 = -0.1f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 0.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.01;
        float x = r * cos(a) + xOffa2221;
        float y = r * sin(a) + yOffa2221;
        glVertex2f(x, y);

    }

    glEnd();
    glBegin(GL_POLYGON);
    float xOffa22212 = 0.46f;
    float yOffa22212 = -0.1f;
    for (int i = 0; i < 300; i++)
    {

        glColor3f(1.0f, 0.0f, 0.0f);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = 0.01;
        float x = r * cos(a) + xOffa22212;
        float y = r * sin(a) + yOffa22212;
        glVertex2f(x, y);

    }

    glEnd();
    glFlush();

}
void display() {

    glClearColor(0.0f, 0.8f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5);
    traficlight();
    cars();
}


int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutCreateWindow("OpenGL Setup");

    glutInitWindowSize(5000, 4000);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}