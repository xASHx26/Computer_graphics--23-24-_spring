#include<cstdio>
#include <windows.h>
#include <GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>>
# define PI           3.14159265358979323846
#include <cctype>
#include<bits/stdc++.h>
#include<GL/glu.h>
//#include<GL/glut.h>
//#include <windows.h>
//#include <iostream>
//#include <math.h>
//#include <stdlib.h>
#include<GL/gl.h>
//#include<cstdio>
#include<time.h>
#include <cstdlib>
#include <ctime>

# define PI 3.14159265358979323846
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define NUM_RAINDROPS 1000

void DayView();
void NightView();

void WinterView();
void WinterSky();

void DayRiver();
void NightRiver();
void DaySky();
void NightSky();
void star();
void WinterRiver();
void Bridge();
void SpringView();
void SpringSky();
void Circle(GLfloat a, GLfloat b, GLfloat r, int R, int G, int B);
void House1();
void House2();
void House3();
GLfloat cherryPos = 0.0f;
GLfloat cherrySpd = 0.05f;
void Circlecherry(GLfloat a, GLfloat b, GLdouble r, int R, int G, int B);
void cherryFall();
void cherryAnimation(int value);
//void Idle();
void Tree();
void Tree1();
void Bench();
void Road();
void Lamppost1();
void Lamppost2();

void Mountain();


void Road();
void Field();
void Lamppost();
int i;
float radius9 = 0.10f;
int triangleAmount = 100; //# of lines used to draw circle
GLfloat twicePi = 2.0f * PI;

///For cloud 1
GLfloat position = 0.0f;
GLfloat speed = 0.01f;

///For cloud 2
GLfloat position2 = 0.0f;
GLfloat speed2 = 0.015f;

///for Boat 1
GLfloat position9 = 0.0f;
GLfloat speed9 = 0.01f;


void cloud1();
void cloud2();
void boat1();

void handleKeypress(unsigned char key, int x, int y);
GLfloat snowPos = 0.0f;
GLfloat snowSpd = 0.05f;

void CircleSnow(GLfloat a, GLfloat b, GLdouble r, int R, int G, int B);
void snowFall();
void snowAnimation(int value);

bool isNight = false;
void Idle();

void CircleForCloud(GLfloat a, GLfloat b, GLfloat r);
void Cloud1();
void Cloud2();
void CloudAnimation1(int value);
void CloudAnimation2(int value);
GLfloat CloudPosition1 = 0.0f;
GLfloat CloudSpeed1 = 0.01f;
GLfloat CloudPosition2 = 0.0f;
GLfloat CloudSpeed2 = 0.01f;

void Sun();
void Moon();
void car1();
void plane();
void PlaneAnimation(int value);
GLfloat position_plane = 1.0f;
GLfloat plane_speed = 0.01f;


void Circle(GLfloat a, GLfloat b, GLfloat r, int R, int G, int B);

GLfloat position_car1 = 0.0f, speed_car1 = 0.1f, rotation_car1 = 0.0f;
void animation_car1(int value);
void display_car1();

GLfloat position_car2 = 0.0f, speed_car2 = 0.1f, rotation_car2 = 0.0f;
void animation_car2(int value);
void display_car2();

int main(int argc, char** argv)
{


    glutInit(&argc, argv);

    glutCreateWindow("Japan");
    glutInitWindowSize(320, 320);
    glutDisplayFunc(DayView);

    //glutIdleFunc(Idle);

    glutTimerFunc(40, CloudAnimation1, 0);
    glutTimerFunc(40, CloudAnimation2, 0);
    glutTimerFunc(100, snowAnimation, 0);
    glutTimerFunc(100, cherryAnimation, 0);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(10, animation_car1, 0);
    glutTimerFunc(10, animation_car2, 0);

    glutTimerFunc(100, PlaneAnimation, 0);

    glutMainLoop();

    return 0;
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (tolower(key))
    {
    case 'd':
        glutDisplayFunc(DayView);
        isNight = false;

        glutPostRedisplay();
        break;

    case 'n':
        glutDisplayFunc(NightView);
        isNight = true;

        glutPostRedisplay();
        break;

    case 'w':
        glutDisplayFunc(WinterView);
        isNight = false;
        //CarSound();
        glutPostRedisplay();
        break;
    case 's':
        glutDisplayFunc(SpringView);
        isNight = false;
        glutPostRedisplay();
        break;






    }
}

void DayView()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    DaySky();
    Sun();

    glPushMatrix();
    glTranslatef(CloudPosition1, 0, 0);
    Cloud1();
    Cloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition2, 0, 0);
    //Copy of cloud1
    glTranslatef(1.0, 0, 0);
    Cloud1();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition2, 0, 0);
    //Copy of Cloud2
    glTranslatef(-1.1, 0, 0);
    Cloud2();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(position_plane, 0, 0);
    glScalef(0.3, 1.1, 0);
    plane();
    glPopMatrix();

    DayRiver();
    Bridge();
    glTranslatef(0.0, -0.122, 0);
    display_car1();

    glLoadIdentity();

    glTranslatef(0.0, -0.134, 0);
    display_car2();
    //display_car3();

    glLoadIdentity();

    glLoadIdentity();
    glFlush();
}
void NightView()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    NightSky();
    star();
    Moon();

    glPushMatrix();
    glTranslatef(position_plane, 0, 0);
    glScalef(0.3, 1.1, 0);
    plane();
    glPopMatrix();

    NightRiver();
    Bridge();
    glTranslatef(0.0, -0.122, 0);
    display_car1();
    display_car2();
    glLoadIdentity();
    glFlush();
}

void WinterView()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    WinterSky();

    WinterRiver();

    glPushMatrix();
    glTranslatef(0, snowPos, 0);
    snowFall();
    glPopMatrix();
    Bridge();
    glTranslatef(0.0, -0.122, 0);
    display_car1();

    glLoadIdentity();
    glTranslatef(0.0, -0.134, 0);
    display_car2();


    glLoadIdentity();
    glFlush();
}

void DayRiver()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 128, 255);
    glVertex2f(-1.0f, -0.27f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.27f);
    glEnd();
}


void NightRiver()
{
    glBegin(GL_QUADS);
    glColor3ub(6, 55, 108);
    glVertex2f(-1.0f, -0.27f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.27f);
    glEnd();
}


void WinterRiver()
{
    glBegin(GL_QUADS);
    glColor3ub(162, 181, 236);
    glVertex2f(-1.0f, -0.27f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glColor3ub(231, 245, 254);
    glVertex2f(1.0f, -0.27f);
    glEnd();

    glLineWidth(4);

    glBegin(GL_LINES);
    glColor3ub(205, 237, 241);
    glVertex2f(-0.9f, -0.9f);
    glVertex2f(0.6f, -0.3f);

    glVertex2f(-0.7f, -0.65f);
    glVertex2f(0.0f, -0.4f);

    glEnd();
    glTranslatef(0.5, 0.2, 0);
    glBegin(GL_LINES);
    glColor3ub(205, 237, 241);

    glVertex2f(-0.05f, -0.75f);
    glVertex2f(-0.4f, -0.9f);

    glEnd();

    glLoadIdentity();

}

void DaySky()
{
    glBegin(GL_QUADS);
    glColor3ub(253, 94, 83);
    glVertex2f(-1.0f, 1.0f);
    glColor3ub(177, 231, 247);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
}
void NightSky()
{
    glBegin(GL_QUADS);
    glColor3ub(3, 55, 95);
    glVertex2f(-1.0f, 1.0f);
    glColor3ub(10, 15, 25);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
}


void WinterSky()
{
    glBegin(GL_QUADS);
    glColor3ub(209, 207, 204);
    glVertex2f(-1.0f, 1.0f);
    glColor3ub(109, 123, 147);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
}


void Sun()
{
    int i;

    GLfloat x = 0.0f;
    GLfloat y = 0.5f;
    GLfloat radius = 0.2f;
    int triangleAmount = 100;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 117, 26);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}



void Moon()
{
    int i;

    GLfloat x = 0.7f;
    GLfloat y = 0.7f;
    GLfloat radius = 0.1f;
    int triangleAmount = 100;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 204);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


void CircleForCloud(GLfloat a, GLfloat b, GLfloat r)
{
    int i;

    GLfloat x = a;
    GLfloat y = b;
    GLfloat radius = r;
    int triangleAmount = 20;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
void Cloud1()
{
    CircleForCloud(-0.93f, 0.8f, 0.05f);
    CircleForCloud(-0.88f, 0.82f, 0.05f);
    CircleForCloud(-0.83f, 0.85f, 0.06f);
    CircleForCloud(-0.78f, 0.82f, 0.06f);
    CircleForCloud(-0.73f, 0.78f, 0.04f);
    CircleForCloud(-0.75f, 0.75f, 0.05f);
    CircleForCloud(-0.78f, 0.74f, 0.04f);
    CircleForCloud(-0.81f, 0.71f, 0.05f);
    CircleForCloud(-0.84f, 0.78f, 0.04f);
    CircleForCloud(-0.87f, 0.7f, 0.05f);
    CircleForCloud(-0.9f, 0.75f, 0.04f);
}



void Cloud2()
{
    CircleForCloud(0.93f, 0.8f, 0.05f);
    CircleForCloud(0.85f, 0.82f, 0.05f);
    CircleForCloud(0.8f, 0.85f, 0.06f);
    CircleForCloud(0.75f, 0.82f, 0.06f);
    CircleForCloud(0.7f, 0.78f, 0.04f);
    CircleForCloud(0.73f, 0.75f, 0.05f);
    CircleForCloud(0.78f, 0.76f, 0.04f);
    CircleForCloud(0.81f, 0.71f, 0.05f);
    CircleForCloud(0.84f, 0.78f, 0.04f);
    CircleForCloud(0.87f, 0.7f, 0.05f);
    CircleForCloud(0.9f, 0.75f, 0.04f);
}

void CloudAnimation1(int value)
{
    if (CloudPosition1 > 1.8)
        CloudPosition1 = -1.6f;

    CloudPosition1 += CloudSpeed1;

    glutPostRedisplay();

    glutTimerFunc(40, CloudAnimation1, 0);
}



void CloudAnimation2(int value)
{
    if (CloudPosition2 > 1.0)
        CloudPosition2 = -1.0f;

    CloudPosition2 += CloudSpeed2;

    glutPostRedisplay();

    glutTimerFunc(40, CloudAnimation2, 0);
}


void star()
{


    glTranslatef(0.0, 0.8, 0.0);                              // star 1

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();


    glTranslatef(0.37, 0.8, 0.0);                              // star 2

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(0.65, 0.7, 0.0);                      // star 3

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(0.73, 0.9, 0.0);                          // star 4

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(0.3, 0.76, 0.0);                          // star 6

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(0.81, 0.78, 0.0);                          // star 7

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(0.57, 0.84, 0.0);                              // star 8

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(0.4, 0.9, 0.0);                              // star 8

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(0.7, 0.83, 0.0);                              // star 9

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(0.1, 0.72, 0.0);                              // star 10

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.4, 0.7, 0.0);                              // star 11

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.75, 0.75, 0.0);                              // star 12

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.1, 0.89, 0.0);                              // star 13

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.6, 0.84, 0.0);                              // star 14

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.2, 0.78, 0.0);                              // star 15

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.2, 0.73, 0.0);                              // star 16

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.1, 0.81, 0.0);                              // star 17

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.63, 0.77, 0.0);                              // star 18

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.8, 0.7, 0.0);                              // star 19

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.4, 0.7, 0.0);                              // star 20

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(-0.8, 0.84, 0.0);                              // star 21

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(0.2, 0.88, 0.0);                              // star 22

    glScalef(0.1, 0.1, 0.0);
    glBegin(GL_POLYGON); // start middle part
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 1
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.07f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 2
    glColor3ub(255, 255, 255);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 3
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04f, -0.05f);
    glVertex2f(-0.07f, -0.14f);
    glVertex2f(0.0f, -0.09f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 4
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.07f, -0.14f);
    glVertex2f(0.04f, -0.05f);

    glEnd();

    glBegin(GL_TRIANGLES); // star triangle 5
    glColor3ub(255, 255, 255);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glLoadIdentity();


    glLoadIdentity();
}


void CircleSnow(GLfloat a, GLfloat b, GLdouble r, int R, int G, int B)
{
    int i;

    GLfloat x = a;
    GLfloat y = b;
    GLdouble radius = r;
    int triangleAmount = 60;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(R, G, B);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * sin(i * twicePi / triangleAmount)),
            y + 2 * (radius * cos(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}



void snowAnimation(int value)
{

    if (snowPos < -5)
        snowPos = -4;

    snowPos -= snowSpd;

    glutPostRedisplay();


    glutTimerFunc(100, snowAnimation, 0);
}



void snowFall()
{


    int cnt = 0;
    float posY = 0.99;

    for (int i = 0; i < 100; i++)
    {
        float posX = -1.5;

        for (int j = 0; j < 15; j++)
        {
            if (cnt % 4 == 0)
            {
                posX += 0.33;
            }
            else if (cnt % 3 == 0)
            {
                posX += 0.25;
            }
            else
            {
                posX += 0.15;
            }
            CircleSnow(posX, posY, 0.008, 240, 240, 240);
            CircleSnow(posX, posY, 0.005, 198, 222, 245);


            cnt++;

        }
        posY += 0.2;

    }

}

void PlaneAnimation(int value)
{
    if (position_plane < -1.5)
        position_plane = 1.0f;
    position_plane -= 0.10;
    glutPostRedisplay();
    glutTimerFunc(200, PlaneAnimation, 0);
}
void plane()
{
    //planeBody

    glPushMatrix();
    glTranslatef(position_plane, 0, 0);
    glScalef(0.3, 0.8, 0);
    glBegin(GL_POLYGON);
    glColor3ub(57, 162, 244);
    glVertex2f(-0.3f, 0.8f);
    glVertex2f(0.3f, 0.8f);
    glVertex2f(0.37f, 0.89f);
    glVertex2f(-0.25f, 0.95f);
    glVertex2f(-0.33f, 0.87f);

    glEnd();



    //planeTail

    glBegin(GL_QUADS);
    glColor3ub(57, 162, 244);
    glVertex2f(0.3f, 0.8f);
    glVertex2f(0.36f, 0.8f);
    glVertex2f(0.38f, 0.98f);
    glVertex2f(0.3f, 0.91f);

    glEnd();


    //middleLine

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.33f, 0.87f);
    glVertex2f(0.37f, 0.84f);
    glEnd();
    //Bwindow
    if (!isNight) {

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.31f, 0.88f);
        glVertex2f(-0.2f, 0.88f);
        glVertex2f(-0.19f, 0.93f);
        glVertex2f(-0.25f, 0.93f);

        glEnd();
    }
    if (isNight) {
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 0);
        glVertex2f(-0.31f, 0.88f);
        glVertex2f(-0.2f, 0.88f);
        glVertex2f(-0.19f, 0.93f);
        glVertex2f(-0.25f, 0.93f);

        glEnd();


    }
    //Uwing
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.09f, 0.93f);
    glVertex2f(-0.05f, 0.93f);
    glVertex2f(-0.04f, 0.98f);
    glVertex2f(-0.07f, 0.98f);

    glEnd();
    //1Wing
    if (!isNight) {

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.15f, 0.87f);
        glVertex2f(-0.11f, 0.865f);
        glVertex2f(-0.11f, 0.92f);
        glVertex2f(-0.15f, 0.925f);

        glEnd();
    }
    if (isNight) {
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 0);
        glVertex2f(-0.15f, 0.87f);
        glVertex2f(-0.11f, 0.865f);
        glVertex2f(-0.11f, 0.92f);
        glVertex2f(-0.15f, 0.925f);

        glEnd();
    }
    //2wing
    if (!isNight) {
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.09f, 0.87f);
        glVertex2f(-0.05f, 0.865f);
        glVertex2f(-0.05f, 0.915f);
        glVertex2f(-0.09f, 0.92f);

        glEnd();
    }
    if (isNight) {
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 0);
        glVertex2f(-0.09f, 0.87f);
        glVertex2f(-0.05f, 0.865f);
        glVertex2f(-0.05f, 0.915f);
        glVertex2f(-0.09f, 0.92f);

        glEnd();
    }
    //3wing
    if (!isNight) {

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.03f, 0.87f);
        glVertex2f(0.01f, 0.865f);
        glVertex2f(0.01f, 0.915f);
        glVertex2f(-0.03f, 0.92f);

        glEnd();
    }
    if (isNight) {
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 0);
        glVertex2f(-0.03f, 0.87f);
        glVertex2f(0.01f, 0.865f);
        glVertex2f(0.01f, 0.915f);
        glVertex2f(-0.03f, 0.92f);

        glEnd();
    }
    //4wing
    if (!isNight) {

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.03f, 0.865f);
        glVertex2f(0.07f, 0.860f);
        glVertex2f(0.07f, 0.910f);
        glVertex2f(0.03f, 0.915f);

        glEnd();
    }
    if (isNight) {
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 0);
        glVertex2f(0.03f, 0.865f);
        glVertex2f(0.07f, 0.860f);
        glVertex2f(0.07f, 0.910f);
        glVertex2f(0.03f, 0.915f);

        glEnd();
    }

    //5wing
    if (!isNight) {

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.09f, 0.865f);
        glVertex2f(0.13f, 0.860f);
        glVertex2f(0.13f, 0.905f);
        glVertex2f(0.09f, 0.910f);

        glEnd();
    }
    if (isNight) {
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 0);
        glVertex2f(0.09f, 0.865f);
        glVertex2f(0.13f, 0.860f);
        glVertex2f(0.13f, 0.905f);
        glVertex2f(0.09f, 0.910f);

        glEnd();
    }
    //6wing
    if (!isNight) {

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.15f, 0.860f);
        glVertex2f(0.19f, 0.855f);
        glVertex2f(0.19f, 0.9f);
        glVertex2f(0.15f, 0.905f);

        glEnd();
    }
    if (isNight) {
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 0);
        glVertex2f(0.15f, 0.860f);
        glVertex2f(0.19f, 0.855f);
        glVertex2f(0.19f, 0.9f);
        glVertex2f(0.15f, 0.905f);

        glEnd();
    }

    //fBwING
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.095f, 0.75f);
    glVertex2f(-0.055f, 0.75f);
    glVertex2f(-0.099f, 0.83f);
    glVertex2f(-0.18f, 0.83f);

    glEnd();
    //bBwING
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.18f, 0.75f);
    glVertex2f(0.22f, 0.75f);
    glVertex2f(0.18f, 0.83f);
    glVertex2f(0.1f, 0.83f);



    glEnd();



    glPopMatrix();
}
void Bridge()
{
    //UP TO DOWN
    //x-axis Rod-1
    glBegin(GL_QUADS);
    glColor3ub(81, 78, 82);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(-1.0f, -0.16f);
    glVertex2f(1.0f, -0.16f);
    glVertex2f(1.0f, -0.15f);
    glEnd();

    //Road
    glBegin(GL_QUADS);
    glColor3ub(81, 78, 82);
    glVertex2f(-1.0f, -0.16f);
    glVertex2f(-1.0f, -0.18f);
    glVertex2f(1.0f, -0.18f);
    glVertex2f(1.0f, -0.16f);
    glEnd();

    //x-axis Rod-2
    glBegin(GL_QUADS);
    glColor3ub(53, 35, 30);
    glVertex2f(-1.0f, -0.18f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, -0.18f);
    glEnd();

    //x-axis Rod-3
    glBegin(GL_QUADS);
    glColor3ub(193, 191, 194);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(-1.0f, -0.21f);
    glVertex2f(1.0f, -0.21f);
    glVertex2f(1.0f, -0.2f);
    glEnd();

    //x-axis Rod-4
    glBegin(GL_QUADS);
    glColor3ub(112, 111, 109);
    glVertex2f(-1.0f, -0.21f);
    glVertex2f(-1.0f, -0.22f);
    glVertex2f(1.0f, -0.22f);
    glVertex2f(1.0f, -0.21f);
    glEnd();

    //x-axis Rod-5
    glBegin(GL_QUADS);
    glColor3ub(21, 19, 24);
    glVertex2f(-1.0f, -0.22f);
    glVertex2f(-1.0f, -0.24f);
    glVertex2f(1.0f, -0.24f);
    glVertex2f(1.0f, -0.22f);
    glEnd();

    //x-axis Rod-6
    glBegin(GL_QUADS);
    glColor3ub(62, 43, 41);
    glVertex2f(-1.0f, -0.24f);
    glVertex2f(-1.0f, -0.26f);
    glVertex2f(1.0f, -0.26f);
    glVertex2f(1.0f, -0.24f);
    glEnd();

    //x-axis Rod-7
    glBegin(GL_QUADS);
    glColor3ub(179, 170, 161);
    glVertex2f(-1.0f, -0.26f);
    glVertex2f(-1.0f, -0.27f);
    glVertex2f(1.0f, -0.27f);
    glVertex2f(1.0f, -0.26f);
    glEnd();



    //LEFT TO RIGHT
    //y-axis rod-1
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();

    //y-axis rod-2
    glTranslatef(0.1, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-3
    glTranslatef(0.2, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-4
    glTranslatef(0.3, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-5
    glTranslatef(0.4, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-6
    glTranslatef(0.5, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-7
    glTranslatef(0.6, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-8
    glTranslatef(0.7, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-9
    glTranslatef(0.8, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-10
    glTranslatef(0.9, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-11
    glTranslatef(1.0, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-12
    glTranslatef(1.1, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-13
    glTranslatef(1.2, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-14
    glTranslatef(1.3, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-15
    glTranslatef(1.4, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-16
    glTranslatef(1.5, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-17
    glTranslatef(1.6, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-18
    glTranslatef(1.7, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-19
    glTranslatef(1.8, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-20
    glTranslatef(1.9, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f, -0.21f);
    glVertex2f(-0.95f, -0.27f);
    glEnd();
    glLoadIdentity();



    //LEFT TO RIGHT
    //Diagonal rod-1
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();

    //Diagonal rod-2
    glTranslatef(0.2, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-3
    glTranslatef(0.4, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-4
    glTranslatef(0.6, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-5
    glTranslatef(0.8, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-6
    glTranslatef(1.0, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-7
    glTranslatef(1.2, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-8
    glTranslatef(1.4, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-9
    glTranslatef(1.6, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-10
    glTranslatef(1.8, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f, -0.265f);
    glVertex2f(-0.85f, -0.215f);
    glEnd();
    glLoadIdentity();



    //RIGHT TO LEFT
    //Diagonal rod-1
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();

    //Diagonal rod-2
    glTranslatef(-0.2, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-3
    glTranslatef(-0.4, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-4
    glTranslatef(-0.6, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-5
    glTranslatef(-0.8, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-6
    glTranslatef(-1.0, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-7
    glTranslatef(-1.2, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-8
    glTranslatef(-1.4, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-9
    glTranslatef(-1.6, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-10
    glTranslatef(-1.8, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-11
    glTranslatef(-2.0, 0, 0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f, -0.265f);
    glVertex2f(0.95f, -0.215f);
    glEnd();
    glLoadIdentity();

    //piller1
    glBegin(GL_QUADS);
    glColor3ub(81, 78, 82);
    glVertex2f(-0.88f, -0.27f);
    glVertex2f(-0.82f, -0.27f);
    glVertex2f(-0.82f, -0.68f);
    glVertex2f(-0.88f, -0.68f);
    glEnd();

    //piller2
    glBegin(GL_QUADS);
    glColor3ub(81, 78, 82);
    glVertex2f(0.88f, -0.27f);
    glVertex2f(0.82f, -0.27f);
    glVertex2f(0.82f, -0.68f);
    glVertex2f(0.88f, -0.68f);
    glEnd();
}

void animation_car1(int value)
{

    if (position_car1 > 1.0)
    {
        position_car1 = -1.0f;
    }

    position_car1 += speed_car1;

    glutPostRedisplay();


    glutTimerFunc(200, animation_car1, 0);
}

void display_car1()
{

    glPushMatrix();
    glTranslatef(position_car1, 0, 0);


    glScalef(0.2, 0.2, 0);
    glBegin(GL_QUADS); // bus body
    glColor3ub(249, 216, 216);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.25f, -0.1f);
    glVertex2f(0.2f, 0.1f);

    glEnd();

    glBegin(GL_QUADS); // design
    glColor3ub(253, 174, 174);
    glVertex2f(-0.06f, 0.1f);
    glVertex2f(0.0f, -0.1f);
    glVertex2f(0.08f, -0.1f);
    glVertex2f(0.02f, 0.1f);

    glEnd();


    glColor3ub(0, 0, 0);
    int i_car;

    GLfloat x_car = .15f;
    GLfloat y_car = -0.1f;
    GLfloat radius_car = .05f;
    int triangleAmount_car = 20;

    GLfloat twicePi_car = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 1
    glVertex2f(x_car, y_car);
    for (i_car = 0; i_car <= triangleAmount_car; i_car++)
    {
        glVertex2f(
            x_car + (radius_car * cos(i_car * twicePi_car / triangleAmount_car)),
            y_car + (radius_car * sin(i_car * twicePi_car / triangleAmount_car))
        );
    }
    glEnd();


    glTranslatef(-0.25, 0.0, 0.0);
    glColor3ub(0, 0, 0);
    int j_car;

    GLfloat x_car1 = .15f;
    GLfloat y_car1 = -0.1f;
    GLfloat radius_car1 = .05f;
    int triangleAmount_car1 = 20;

    GLfloat twicePi_car1 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 2
    glVertex2f(x_car, y_car);
    for (j_car = 0; j_car <= triangleAmount_car1; j_car++)
    {
        glVertex2f(
            x_car1 + (radius_car1 * cos(j_car * twicePi_car1 / triangleAmount_car1)),
            y_car1 + (radius_car1 * sin(j_car * twicePi_car1 / triangleAmount_car1))
        );
    }
    glEnd();

    glLoadIdentity();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(position_car1, 0, 0);


    glScalef(0.2, 0.2, 0);
    glBegin(GL_QUADS); // mirror
    if (!isNight)
    {
        glColor3ub(64, 224, 208);
    }
    if (isNight)
    {
        glColor3ub(241, 201, 8);
    }
    glVertex2f(-0.195f, 0.08f);
    glVertex2f(-0.195f, 0.0f);
    glVertex2f(0.219f, 0.0f);
    glVertex2f(0.2f, 0.08f);

    glEnd();

    glBegin(GL_QUADS); // back light
    glColor3ub(255, 69, 0);
    glVertex2f(-0.2f, -0.03f);
    glVertex2f(-0.2f, -0.06f);
    glVertex2f(-0.18f, -0.06f);
    glVertex2f(-0.18f, -0.03f);

    glEnd();

    glBegin(GL_QUADS); // head light
    glColor3ub(255, 69, 0);
    glVertex2f(0.21f, -0.03f);
    glVertex2f(0.21f, -0.06f);
    glVertex2f(0.24f, -0.06f);
    glVertex2f(0.234f, -0.03f);

    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);// mirror outline 1
    glColor3ub(0, 0, 0);
    glVertex2f(-0.195f, 0.08f);
    glVertex2f(-0.195f, 0.0f);

    glEnd();

    glBegin(GL_LINES);// mirror outline 2
    glColor3ub(0, 0, 0);
    glVertex2f(-0.195f, 0.0f);
    glVertex2f(0.219f, 0.0f);

    glEnd();

    glBegin(GL_LINES);// mirror outline 3
    glColor3ub(0, 0, 0);
    glVertex2f(0.219f, 0.0f);
    glVertex2f(0.2f, 0.08f);

    glEnd();

    glBegin(GL_LINES);// mirror outline 4
    glColor3ub(0, 0, 0);
    glVertex2f(-0.195f, 0.08f);
    glVertex2f(0.2f, 0.08f);

    glEnd();

    glBegin(GL_LINES);// mirror border 1
    glColor3ub(0, 0, 0);
    glVertex2f(-0.04f, 0.08f);
    glVertex2f(-0.04f, 0.00f);

    glEnd();

    glBegin(GL_LINES);// mirror border 2
    glColor3ub(0, 0, 0);
    glVertex2f(0.1f, 0.08f);
    glVertex2f(0.1f, 0.00f);

    glEnd();

    glPushMatrix();
    glTranslatef(-0.1, -0.1, 0.0);
    glRotatef(rotation_car1, 0.0, 0.0, -0.1); // wheel 1 rotation

    glScalef(0.2, 0.2, 0);
    glLineWidth(5);
    glBegin(GL_LINES);//wheel line
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, 0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, 0.03f);

    glEnd();

    glPopMatrix();
    rotation_car1 += 0.1f;


    glPushMatrix();
    glTranslatef(0.15, -0.1, 0.0);
    glRotatef(rotation_car1, 0.0, 0.0, -0.1); // wheel 2 rotation

    glScalef(0.2, 0.2, 0);
    glBegin(GL_LINES);//wheel line
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, 0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249, 216, 216);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, 0.03f);

    glEnd();

    glPopMatrix();
    rotation_car1 += 0.1f;




    glPopMatrix();


}
void animation_car2(int value)
{

    if (position_car2 < -1.0)
    {
        position_car2 = 1.0f;
    }

    position_car2 -= speed_car2;

    glutPostRedisplay();


    glutTimerFunc(200, animation_car2, 0);
}



void display_car2()
{

    glPushMatrix();
    glTranslatef(position_car2, 0, 0);


    glScalef(0.1, 0.1, 0);
    glBegin(GL_QUADS); // car upper body
    glColor3ub(101, 92, 92);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.1f, 0.2f);

    glEnd();

    glBegin(GL_QUADS); // car lower body
    glColor3ub(101, 92, 92);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.45f, -0.1f);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.3f, 0.1f);

    glEnd();


    glBegin(GL_QUADS); // car design
    glColor3ub(54, 51, 51);
    glVertex2f(-0.414f, 0.05f);
    glVertex2f(-0.438f, -0.05f);
    glVertex2f(0.3f, -0.05f);
    glVertex2f(0.3f, 0.05f);

    glEnd();



    glColor3ub(0, 0, 0);
    int i_car3;

    GLfloat x_car3 = .15f;
    GLfloat y_car3 = -0.1f;
    GLfloat radius_car3 = .06f;
    int triangleAmount_car3 = 20;

    GLfloat twicePi_car3 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 1
    glVertex2f(x_car3, y_car3);
    for (i_car3 = 0; i_car3 <= triangleAmount_car3; i_car3++)
    {
        glVertex2f(
            x_car3 + (radius_car3 * cos(i_car3 * twicePi_car3 / triangleAmount_car3)),
            y_car3 + (radius_car3 * sin(i_car3 * twicePi_car3 / triangleAmount_car3))
        );
    }
    glEnd();


    glTranslatef(-0.4, 0.0, 0.0);
    glColor3ub(0, 0, 0);
    int j_car4;

    GLfloat x_car4 = .15f;
    GLfloat y_car4 = -0.1f;
    GLfloat radius_car4 = .06f;
    int triangleAmount_car4 = 20;

    GLfloat twicePi_car4 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 2
    glVertex2f(x_car4, y_car4);
    for (j_car4 = 0; j_car4 <= triangleAmount_car4; j_car4++)
    {
        glVertex2f(
            x_car4 + (radius_car4 * cos(j_car4 * twicePi_car4 / triangleAmount_car4)),
            y_car4 + (radius_car4 * sin(j_car4 * twicePi_car4 / triangleAmount_car4))
        );
    }
    glEnd();

    glLoadIdentity();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(position_car2, 0, 0);


    glScalef(0.1, 0.1, 0);
    glBegin(GL_QUADS); // car mirror
    if (!isNight)
    {
        glColor3ub(64, 224, 208);
        glVertex2f(-0.095f, 0.19f);
        glVertex2f(-0.185f, 0.1f);
        glVertex2f(0.185f, 0.1f);
        glVertex2f(0.095f, 0.19f);
    }
    if (isNight)
    {
        glColor3ub(250, 237, 172);
        glVertex2f(-0.095f, 0.19f);
        glVertex2f(-0.185f, 0.1f);
        glVertex2f(0.185f, 0.1f);
        glVertex2f(0.095f, 0.19f);
    }

    glEnd();

    glBegin(GL_LINES); // mirror line
    glColor3ub(0, 0, 0);
    glVertex2f(0.01f, 0.19f);
    glVertex2f(0.0f, 0.1f);

    glEnd();


    glBegin(GL_QUADS); // car headlight
    glColor3ub(255, 99, 71);
    glVertex2f(-0.423f, 0.015f);
    glVertex2f(-0.431f, -0.015f);
    glVertex2f(-0.39f, -0.015f);
    glVertex2f(-0.39f, 0.015f);

    glEnd();

    glBegin(GL_QUADS); // car back light
    glColor3ub(255, 99, 71);
    glVertex2f(0.285f, 0.015f);
    glVertex2f(0.285f, -0.015f);
    glVertex2f(0.3f, -0.015f);
    glVertex2f(0.3f, 0.015f);

    glEnd();


    glPushMatrix();
    glTranslatef(-0.25, -0.1, 0.0);
    glRotatef(rotation_car1, 0.0, 0.0, 0.1); // wheel 1 rotation

    glScalef(0.1, 0.1, 0);
    glLineWidth(5);
    glBegin(GL_LINES);//wheel line vertical
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line vertical
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line horizontal
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line horizontal
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, 0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, 0.03f);

    glEnd();

    glPopMatrix();
    rotation_car1 += 0.1f;


    glPushMatrix();
    glTranslatef(0.15, -0.1, 0.0);
    glRotatef(rotation_car1, 0.0, 0.0, 0.1); // wheel 2 rotation

    glScalef(0.1, 0.1, 0);
    glBegin(GL_LINES);//wheel line
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, 0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.03f, -0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101, 92, 92);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.03f, 0.03f);

    glEnd();

    glPopMatrix();
    rotation_car1 += 0.1f;


    glPopMatrix();
}

void Circle(GLfloat a, GLfloat b, GLfloat r, int R, int G, int B)
{
    int i;

    GLfloat x = a;
    GLfloat y = b;
    GLfloat radius = r;
    int triangleAmount = 20;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(R, G, B);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount / 2; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + 6 * (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
void Circlecherry(GLfloat a, GLfloat b, GLdouble r, int R, int G, int B)
{
    int i;

    GLfloat x = a;
    GLfloat y = b;
    GLdouble radius = r;
    int triangleAmount = 60;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(R, G, B);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * sin(i * twicePi / triangleAmount)),
            y + 2 * (radius * cos(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}



void cherryAnimation(int value)
{

    if (cherryPos < -5)
        cherryPos = -4;

    cherryPos -= cherrySpd;

    glutPostRedisplay();


    glutTimerFunc(180, cherryAnimation, 0);
}



void cherryFall()
{


    int cnt = 0;
    float posY = 0.99;

    for (int i = 0; i < 100; i++)
    {
        float posX = -1.5;

        for (int j = 0; j < 15; j++)
        {
            if (cnt % 4 == 0)
            {
                posX += 0.33;
            }
            else if (cnt % 3 == 0)
            {
                posX += 0.1;
            }
            else
            {
                posX += 0.3;
            }
            Circlecherry(posX, posY, 0.008, 255, 153, 255);
            Circlecherry(posX, posY, 0.005, 255, 179, 255);

            cnt++;

        }
        posY += 0.2;

    }

}

void  SpringView()
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SpringSky();
    Mountain();
    Road();
    Field();
    House1();
    Lamppost1();
    Lamppost2();
    Bench();
    glPushMatrix();
    glTranslatef(CloudPosition1, 0, 0);
    Cloud1();
    Cloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition2, 0, 0);
    //Copy of cloud1
    glTranslatef(1.0, 0, 0);
    Cloud1();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition2, 0, 0);
    //Copy of Cloud2
    glTranslatef(-1.1, 0, 0);
    Cloud2();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, cherryPos, 0);
    cherryFall();
    glPopMatrix();

    glPushMatrix();

    glFlush();
}

void SpringSky()
{
    glBegin(GL_QUADS);
    glColor3ub(191, 128, 255);
    glVertex2f(-1.0f, 1.0f);
    glColor3ub(230, 204, 255);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
}

void Mountain()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 1.0f);
    glColor3ub(140, 140, 140);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(1.0f, -0.15f);

    glEnd();
}
void Road()
{
    glBegin(GL_QUADS);
    glColor3ub(71, 72, 76);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.0f, -0.65f);
    glVertex2f(-1.0f, -0.65f);

    // Roadline
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.70f, -0.35f);
    glVertex2f(-0.50f, -0.35f);
    glVertex2f(-0.50f, -0.40f);
    glVertex2f(-0.70f, -0.40f);

    // Roadline 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.70f + 0.45f, -0.35f);
    glVertex2f(-0.50f + 0.45f, -0.35f);
    glVertex2f(-0.50f + 0.45f, -0.40f);
    glVertex2f(-0.70f + 0.45f, -0.40f);

    // Roadline 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.70f + 0.85f, -0.35f);
    glVertex2f(-0.50f + 0.85f, -0.35f);
    glVertex2f(-0.50f + 0.85f, -0.40f);
    glVertex2f(-0.70f + 0.85f, -0.40f);


    // Roadline 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.70f + 1.3f, -0.35f);
    glVertex2f(-0.50f + 1.3f, -0.35f);
    glVertex2f(-0.50f + 1.3f, -0.40f);
    glVertex2f(-0.70f + 1.3f, -0.40f);

    //Straightline
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-1.0f, -0.18f);
    glVertex2f(1.0f, -0.18f);
    glVertex2f(1.0f, -0.20f);
    glVertex2f(-1.0f, -0.20f);

    //Straightline 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-1.0f, -0.63f);
    glVertex2f(1.0f, -0.63f);
    glVertex2f(1.0f, -0.61f);
    glVertex2f(-1.0f, -0.61f);

    glEnd();
}

void Field()
{
    glBegin(GL_QUADS);
    glColor3ub(153, 255, 153);
    glVertex2f(1.0f, -0.65f);
    glVertex2f(-1.0f, -0.65f);
    glColor3ub(0, 51, 0);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
}

void House1()
{
    //roofH1
    glBegin(GL_QUADS);
    glColor3ub(51, 0, 0);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(1.0f, 0.35f);
    glVertex2f(1.0f, 0.15f);
    glVertex2f(0.48f, 0.15f);
    glEnd();

    //bor1
    glBegin(GL_QUADS);
    glColor3ub(26, 0, 0);
    glVertex2f(0.62f, 0.39f);
    glVertex2f(1.0f, 0.39f);
    glVertex2f(1.0f, 0.35f);

    glVertex2f(0.6f, 0.35f);

    glEnd();

    //bor2
    glBegin(GL_QUADS);
    glColor3ub(26, 0, 0);
    glVertex2f(0.60f, 0.39f);
    glVertex2f(0.62f, 0.39f);;
    glVertex2f(0.46f, 0.15f);
    glVertex2f(0.51f, 0.15f);

    glEnd();

    //bor3
    glBegin(GL_QUADS);
    glColor3ub(26, 0, 0);
    glVertex2f(0.49f, 0.15f);
    glVertex2f(1.0f, 0.15f);
    glVertex2f(1.0f, 0.13f);
    glVertex2f(0.50f, 0.13f);

    glEnd();

    //bodyH1
    glBegin(GL_QUADS);
    glColor3ub(191, 128, 64);
    glVertex2f(0.50f, 0.13f);
    glVertex2f(1.0f, 0.13f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(0.50f, -0.15f);
    glEnd();

    //bodyBorH1
    glBegin(GL_QUADS);
    glColor3ub(26, 0, 0);
    glVertex2f(0.50f, -0.15f);
    glVertex2f(1.0f, -0.15f);

    glVertex2f(1.0f, -0.19f);
    glVertex2f(0.47f, -0.19f);
    glEnd();

    //middleBorH1
    glBegin(GL_QUADS);
    glColor3ub(26, 0, 0);
    glVertex2f(0.50f, 0.04f);
    glVertex2f(1.0f, 0.04f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.50f, 0.0f);
    glEnd();

    //verBor1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.60f, 0.13f);
    glVertex2f(0.62f, 0.13f);
    glVertex2f(0.62f, 0.04f);
    glVertex2f(0.60f, 0.04f);
    glEnd();

    //verBor2
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.60f, 0.0f);
    glVertex2f(0.62f, 0.0f);
    glVertex2f(0.62f, -0.15f);
    glVertex2f(0.60f, -0.15f);
    glEnd();


    //verBor1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.90f, 0.13f);
    glVertex2f(0.92f, 0.13f);
    glVertex2f(0.92f, 0.04f);
    glVertex2f(0.90f, 0.04f);
    glEnd();

    //verBor2
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.90f, 0.0f);
    glVertex2f(0.92f, 0.0f);
    glVertex2f(0.92f, -0.15f);
    glVertex2f(0.90f, -0.15f);
    glEnd();


}


void Lamppost1() {
    glBegin(GL_QUADS);
    glColor3ub(41, 41, 61);
    glVertex2f(-0.85f, -0.65);
    glVertex2f(-0.83f, -0.65f);
    glVertex2f(-0.83f, 0.25);
    glVertex2f(-0.85f, 0.25f);
    glEnd();

    //void LampHead1()

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.87f, 0.25f);
    glVertex2f(-0.81f, 0.25f);
    glVertex2f(-0.78f, 0.32f);
    glVertex2f(-0.90f, 0.32f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.78f, 0.32f);
    glVertex2f(-0.90f, 0.32f);
    glVertex2f(-0.84f, 0.38f);

    glEnd();

}

void Lamppost2() {
    glBegin(GL_QUADS);
    glColor3ub(41, 41, 61);
    glVertex2f(0.1f, -0.65);
    glVertex2f(0.12f, -0.65f);
    glVertex2f(0.12f, 0.25);
    glVertex2f(0.1f, 0.25f);
    glEnd();

    //void LampHead2()

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(0.08f, 0.25f);
    glVertex2f(0.14f, 0.25f);
    glVertex2f(0.18f, 0.32f);
    glVertex2f(0.04f, 0.32f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 102);
    glVertex2f(0.18f, 0.32f);
    glVertex2f(0.04f, 0.32f);

    glVertex2f(0.11f, 0.38f);

    glEnd();

}
void Bench()
{
    glBegin(GL_QUADS);
    glColor3ub(204, 102, 0);
    glVertex2f(-0.75f, -0.76f);
    glVertex2f(-0.38f, -0.76f);
    glVertex2f(-0.34f, -0.825f);
    glVertex2f(-0.79f, -0.825f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.34f, -0.825f);
    glVertex2f(-0.79f, -0.825f);
    glVertex2f(-0.79f, -0.88f);
    glVertex2f(-0.34f, -0.88f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.79f, -0.88f);
    glVertex2f(-0.77f, -0.88f);
    glVertex2f(-0.77f, -0.94f);
    glVertex2f(-0.79f, -0.94f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.36f, -0.88f);
    glVertex2f(-0.34f, -0.88f);
    glVertex2f(-0.34f, -0.94f);
    glVertex2f(-0.36f, -0.94f);
    glEnd();

}

float raindrops[NUM_RAINDROPS][2]; // Array to store positions of raindrops

void initGL() {
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f); // Light blue background
}

///********************************************Drawing Cloud 1*******************************************///
void cloud1()
{

    glPushMatrix();
    glTranslatef(position, 0.0f, 0.0f);

    //circle1
    GLfloat x1 = -0.5f; GLfloat y1 = 0.90f; GLfloat radius1 = -0.04f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x1 + (radius1 * cos(i * twicePi / triangleAmount)),
            y1 + (radius1 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    //circle2
    GLfloat x2 = -0.5f; GLfloat y2 = 0.85f; GLfloat radius2 = -0.04f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x2 + (radius2 * cos(i * twicePi / triangleAmount)),
            y2 + (radius2 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    //circle3
    GLfloat x3 = -0.45f; GLfloat y3 = 0.90f; GLfloat radius3 = -0.04f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x3 + (radius3 * cos(i * twicePi / triangleAmount)),
            y3 + (radius3 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    //circle4
    GLfloat x4 = -0.45f; GLfloat y4 = 0.85f; GLfloat radius4 = -0.04f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x4 + (radius4 * cos(i * twicePi / triangleAmount)),
            y4 + (radius4 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    //circle5
    GLfloat x5 = -0.55f; GLfloat y5 = 0.87f; GLfloat radius5 = -0.04f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x5 + (radius5 * cos(i * twicePi / triangleAmount)),
            y5 + (radius5 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    //circle6
    GLfloat x6 = -0.42f; GLfloat y6 = 0.87f; GLfloat radius6 = -0.04f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x6 + (radius6 * cos(i * twicePi / triangleAmount)),
            y6 + (radius6 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();

}

///****************************************Drawing Cloud 2***************************************///
void cloud2()
{
    glPushMatrix();
    glTranslatef(position2, 0.0f, 0.0f);

    //circle12
    GLfloat x12 = 0.95f; GLfloat y12 = 0.90f; GLfloat radius12 = 0.04f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x12, y12); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x12 + (radius12 * cos(i * twicePi / triangleAmount)),
            y12 + (radius12 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    //circle13
    GLfloat x13 = 0.90f; GLfloat y13 = 0.90f; GLfloat radius13 = 0.04f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x13, y13); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x13 + (radius13 * cos(i * twicePi / triangleAmount)),
            y13 + (radius13 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    //circle14
    GLfloat x14 = 0.87f; GLfloat y14 = 0.88f; GLfloat radius14 = 0.04f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x14, y14); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x14 + (radius14 * cos(i * twicePi / triangleAmount)),
            y14 + (radius14 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    //circle15
    GLfloat x15 = 0.92f; GLfloat y15 = 0.88f; GLfloat radius15 = 0.05f;
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x15, y15); // center of circle
    for (i = 0; i <= triangleAmount;i++) {
        glVertex2f(x15 + (radius15 * cos(i * twicePi / triangleAmount)),
            y15 + (radius15 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glPopMatrix();
}

///*******************************************Boat-1 Drawing***********************************///
void boat1() {
    glPushMatrix();
    glTranslatef(position9, 0.0f, 0.0f);


    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);//black-base of the boat-2
    glVertex2f(0.50f, -0.60f);
    glVertex2f(0.45f, -0.55f);
    glVertex2f(0.85f, -0.55f);
    glVertex2f(0.80f, -0.60f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.3f, 0.3f);//hood-1 of the boat-2
    glVertex2f(0.65f, -0.55f);
    glVertex2f(0.60f, -0.45f);
    glVertex2f(0.72f, -0.45f);
    glVertex2f(0.77f, -0.55f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.4f, 0.3f);//hood-2 of the boat-2
    glVertex2f(0.65f, -0.55f);
    glVertex2f(0.60f, -0.45f);
    glVertex2f(0.56f, -0.55f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);//stick of boat-2
    glVertex2f(0.555f, -0.55f);
    glVertex2f(0.555f, -0.25f);
    glVertex2f(0.56f, -0.25f);
    glVertex2f(0.56f, -0.55f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.7f);//paal
    glVertex2f(0.555f, -0.25f);
    glVertex2f(0.45f, -0.50f);
    glVertex2f(0.54f, -0.50f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);//rope-1
    glVertex2f(0.54f, -0.50f);
    glVertex2f(0.555f, -0.55f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);//rope-2
    glVertex2f(0.45f, -0.50f);
    glVertex2f(0.555f, -0.55f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);//rope-3
    glVertex2f(0.56f, -0.25f);
    glVertex2f(0.85f, -0.55f);
    glEnd();

    glPopMatrix();

}

/// move cloud1
void update(int value)
{
    if (position < -1.0)
        position = 2.0f;
    position -= speed;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

///move cloud 2
void update2(int value)
{
    if (position2 < -2.0)
        position2 = 2.0f;
    position2 -= speed2;

    glutPostRedisplay();
    glutTimerFunc(100, update2, 0);
}

///move boat1
void update9(int value)
{
    if (position9 >= 2.0)
        position9 = -2.0f;
    position9 += speed9;

    glutPostRedisplay();
    glutTimerFunc(100, update9, 0);
}
void displayDay_view() {
    glClear(GL_COLOR_BUFFER_BIT);


    ///*******************************************Drawing River***********************************///
    glBegin(GL_QUADS);  // These vertices form a closed polygon
    glColor3f(0.2f, 0.3f, 0.4f); // Muddy Gray-Blue
    glVertex2f(-1.0f, -0.20f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 0.48f);
    glVertex2f(-1.0f, 0.45f);
    glEnd();


    ///*******************************************Drawing Sky***********************************///
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.3f, 0.5f, 0.7f); // Rainy Sky Shade
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.00f);
    glVertex2f(-1.0f, 0.00f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // White (Lightning Color)
    // Main Bolt
    glVertex2f(0.0f, 0.0f); // Starting point
    glVertex2f(0.1f, 0.2f); // Endpoint 1
    glVertex2f(0.1f, 0.2f); // Starting point
    glVertex2f(-0.05f, 0.35f); // Endpoint 2
    glVertex2f(-0.05f, 0.35f); // Starting point
    glVertex2f(0.05f, 0.5f); // Endpoint 3
    glVertex2f(0.05f, 0.5f); // Starting point
    glVertex2f(-0.05f, 0.65f); // Endpoint 4
    glVertex2f(-0.05f, 0.65f); // Starting point
    glVertex2f(0.1f, 0.8f); // Endpoint 5
    glVertex2f(0.1f, 0.8f); // Starting point
    glVertex2f(0.0f, 1.0f); // Endpoint 6
    // Branches
    glVertex2f(0.1f, 0.2f); // Starting point
    glVertex2f(0.12f, 0.18f); // Endpoint 7
    glVertex2f(-0.05f, 0.35f); // Starting point
    glVertex2f(-0.07f, 0.33f); // Endpoint 8
    glVertex2f(0.05f, 0.5f); // Starting point
    glVertex2f(0.07f, 0.5f); // Endpoint 9
    glVertex2f(-0.05f, 0.65f); // Starting point
    glVertex2f(-0.08f, 0.63f); // Endpoint 10
    glVertex2f(0.1f, 0.8f); // Starting point
    glVertex2f(0.12f, 0.78f); // Endpoint 11
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // White (Lightning Color)
    // Main Bolt
    glVertex2f(-0.5f, 0.0f); // Starting point
    glVertex2f(-0.6f, 0.2f); // Endpoint 1
    glVertex2f(-0.6f, 0.2f); // Starting point
    glVertex2f(-0.45f, 0.35f); // Endpoint 2
    glVertex2f(-0.45f, 0.35f); // Starting point
    glVertex2f(-0.55f, 0.5f); // Endpoint 3
    glVertex2f(-0.55f, 0.5f); // Starting point
    glVertex2f(-0.45f, 0.65f); // Endpoint 4
    glVertex2f(-0.45f, 0.65f); // Starting point
    glVertex2f(-0.6f, 0.8f); // Endpoint 5
    glVertex2f(-0.6f, 0.8f); // Starting point
    glVertex2f(-0.5f, 1.0f); // Endpoint 6
    // Branches
    glVertex2f(-0.6f, 0.2f); // Starting point
    glVertex2f(-0.62f, 0.18f); // Endpoint 7
    glVertex2f(-0.45f, 0.35f); // Starting point
    glVertex2f(-0.47f, 0.33f); // Endpoint 8
    glVertex2f(-0.55f, 0.5f); // Starting point
    glVertex2f(-0.57f, 0.5f); // Endpoint 9
    glVertex2f(-0.45f, 0.65f); // Starting point
    glVertex2f(-0.48f, 0.63f); // Endpoint 10
    glVertex2f(-0.6f, 0.8f); // Starting point
    glVertex2f(-0.62f, 0.78f); // Endpoint 11
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // White (Lightning Color)
    // Main Bolt
    glVertex2f(0.5f, 0.0f); // Starting point
    glVertex2f(0.6f, 0.2f); // Endpoint 1
    glVertex2f(0.6f, 0.2f); // Starting point
    glVertex2f(0.45f, 0.35f); // Endpoint 2
    glVertex2f(0.45f, 0.35f); // Starting point
    glVertex2f(0.55f, 0.5f); // Endpoint 3
    glVertex2f(0.55f, 0.5f); // Starting point
    glVertex2f(0.45f, 0.65f); // Endpoint 4
    glVertex2f(0.45f, 0.65f); // Starting point
    glVertex2f(0.6f, 0.8f); // Endpoint 5
    glVertex2f(0.6f, 0.8f); // Starting point
    glVertex2f(0.5f, 1.0f); // Endpoint 6
    // Branches
    glVertex2f(0.6f, 0.2f); // Starting point
    glVertex2f(0.62f, 0.18f); // Endpoint 7
    glVertex2f(0.45f, 0.35f); // Starting point
    glVertex2f(0.47f, 0.33f); // Endpoint 8
    glVertex2f(0.55f, 0.5f); // Starting point
    glVertex2f(0.57f, 0.5f); // Endpoint 9
    glVertex2f(0.45f, 0.65f); // Starting point
    glVertex2f(0.48f, 0.63f); // Endpoint 10
    glVertex2f(0.6f, 0.8f); // Starting point
    glVertex2f(0.62f, 0.78f); // Endpoint 11
    // Additional Branches
    glVertex2f(0.6f, 0.2f); // Starting point
    glVertex2f(0.63f, 0.22f); // Endpoint 12
    glVertex2f(0.45f, 0.35f); // Starting point
    glVertex2f(0.43f, 0.37f); // Endpoint 13
    glVertex2f(0.55f, 0.5f); // Starting point
    glVertex2f(0.58f, 0.52f); // Endpoint 14
    glVertex2f(0.45f, 0.65f); // Starting point
    glVertex2f(0.47f, 0.67f); // Endpoint 15
    glVertex2f(0.6f, 0.8f); // Starting point
    glVertex2f(0.63f, 0.82f); // Endpoint 16
    glEnd();



    ///calling cloud1
    cloud1();

    ///cloud2 calling
    cloud2();


    ///**********************************************Drawing Hill****************************************///

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f); // Light Gray
    glVertex2f(-.69f, 0.00f);
    glVertex2f(-0.33f, 0.40f);
    glVertex2f(0.10f, 0.00f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f); // Light Gray
    glVertex2f(0.19f, 0.00f);
    glVertex2f(0.40f, 0.35f);
    glVertex2f(0.72f, 0.00f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.8f, 0.4f); // Bright Green
    glVertex2f(-1.0f, 0.28f);
    glVertex2f(-0.70f, 0.60f);
    glVertex2f(-0.20f, 0.00f);
    glVertex2f(-1.00f, 0.00f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glVertex2f(0.30f, 0.00f);
    glVertex2f(0.70f, 0.55f);
    glVertex2f(1.00f, 0.30f);
    glVertex2f(1.00f, 0.00f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.6f, 0.3f); // Medium Green
    glVertex2f(-.45f, 0.00f);
    glVertex2f(0.00f, 0.70f);
    glVertex2f(0.50f, 0.00f);
    glEnd();



    ///***************************************Drawing Grassy Ground*****************************///
    glBegin(GL_QUADS);  // These vertices form a closed polygon

    glColor3f(0.0f, 0.7f, 0.3f); //Green
    glVertex2f(-1.0f, -0.50f);
    glVertex2f(1.0f, -0.50f);
    glVertex2f(1.0f, 0.00f);
    glVertex2f(-1.0f, 0.00f);
    glEnd();


    ///*****************************************Drawing Tree*********************************///

    //Drawing Log Shape
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.3f, 0.1f); // Light chocolate

    glVertex2f(-0.43f, -0.30f);
    glVertex2f(-0.46f, -0.37f);
    glVertex2f(-0.46f, -0.31f);
    glVertex2f(-0.55f, -0.35f);
    glVertex2f(-0.49f, -0.30f);
    glVertex2f(-0.47f, -0.26f);
    glVertex2f(-0.46f, -0.20f);
    glVertex2f(-0.48f, -0.10f);
    glVertex2f(-0.50f, -0.05f);
    glVertex2f(-0.46f, -0.09f);
    glVertex2f(-0.46f, -0.05f);
    glVertex2f(-0.44f, -0.05f);
    glVertex2f(-0.43f, -0.09f);
    glVertex2f(-0.40f, -0.05f);
    glVertex2f(-0.38f, -0.05f);
    glVertex2f(-0.39f, -0.10f);
    glVertex2f(-0.39f, -0.15f);
    glVertex2f(-0.38f, -0.20f);
    glVertex2f(-0.38f, -0.26f);
    glVertex2f(-0.37f, -0.30f);
    glVertex2f(-0.32f, -0.35f);
    glVertex2f(-0.39f, -0.31f);
    glVertex2f(-0.38f, -0.37f);

    glEnd();


    ///Drawing tree leaf
    //circle 7 middle

    GLfloat x27 = -0.44f; GLfloat y27 = 0.14f;

    glColor3f(0.0f, 0.4f, 0.0f); //Green

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x27, y27); // center of circle

    for (i = 0; i <= triangleAmount;i++) {

        glVertex2f(x27 + (radius9 * cos(i * twicePi / triangleAmount)),

            y27 + (radius9 * sin(i * twicePi / triangleAmount)));

    }

    glEnd();

    //circle 1

    GLfloat x20 = -0.62f; GLfloat y20 = 0.10f;

    glColor3f(0.0f, 1.0f, 0.0f); //Green

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x20, y20); // center of circle

    for (i = 0; i <= triangleAmount;i++) {

        glVertex2f(x20 + (radius9 * cos(i * twicePi / triangleAmount)),

            y20 + (radius9 * sin(i * twicePi / triangleAmount)));

    }

    glEnd();

    //circle 2

    GLfloat x21 = -0.51f; GLfloat y21 = 0.23f;

    glColor3f(0.0f, 1.0f, 0.0f); //Green

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x21, y21); // center of circle

    for (i = 0; i <= triangleAmount;i++) {

        glVertex2f(x21 + (radius9 * cos(i * twicePi / triangleAmount)),

            y21 + (radius9 * sin(i * twicePi / triangleAmount)));

    }

    glEnd();

    //circle 3

    GLfloat x22 = -0.36f; GLfloat y22 = 0.2f;

    glColor3f(0.0f, 1.0f, 0.0f); //Green

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x22, y22); // center of circle

    for (i = 0; i <= triangleAmount;i++) {

        glVertex2f(x22 + (radius9 * cos(i * twicePi / triangleAmount)),

            y22 + (radius9 * sin(i * twicePi / triangleAmount)));

    }

    glEnd();


    //circle 4

    GLfloat x24 = -0.24f; GLfloat y24 = 0.11f;

    glColor3f(0.0f, 1.0f, 0.0f); //Green

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x24, y24); // center of circle

    for (i = 0; i <= triangleAmount;i++) {

        glVertex2f(x24 + (radius9 * cos(i * twicePi / triangleAmount)),

            y24 + (radius9 * sin(i * twicePi / triangleAmount)));

    }

    glEnd();

    //circle 5

    GLfloat x25 = -0.36f; GLfloat y25 = 0.01f;

    glColor3f(0.0f, 1.0f, 0.0f); //Green

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x25, y25); // center of circle

    for (i = 0; i <= triangleAmount;i++) {

        glVertex2f(x25 + (radius9 * cos(i * twicePi / triangleAmount)),

            y25 + (radius9 * sin(i * twicePi / triangleAmount)));

    }

    glEnd();

    //circle 6

    GLfloat x26 = -0.53f; GLfloat y26 = 0.02f;

    glColor3f(0.0f, 1.0f, 0.0f); //Green

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x26, y26); // center of circle

    for (i = 0; i <= triangleAmount;i++) {

        glVertex2f(x26 + (radius9 * cos(i * twicePi / triangleAmount)),

            y26 + (radius9 * sin(i * twicePi / triangleAmount)));

    }

    glEnd();


    ///***************************************river border**************************************///
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.5f, 0.5f, 0.5f);//grey
    glVertex2f(-1.0f, -0.45f);
    glVertex2f(1.0f, -0.45f);
    glVertex2f(1.0f, -0.50f);
    glVertex2f(-1.0f, -0.50f);
    glEnd();



    ///*******************************************Drawing River***********************************///
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.6f, 1.0f, 1.0f); // Light Sky
    glVertex2f(-1.0f, -0.50f);
    glVertex2f(1.0f, -0.50f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();











    ///**************************************Drawing House****************************************///
     //roofH1
    glBegin(GL_QUADS);
    glColor3ub(61, 61, 92);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(1.0f, 0.35f);
    glVertex2f(1.0f, 0.15f);
    glVertex2f(0.48f, 0.15f);
    glEnd();

    //bor1
    glBegin(GL_QUADS);
    glColor3ub(20, 20, 31);
    glVertex2f(0.62f, 0.39f);
    glVertex2f(1.0f, 0.39f);
    glVertex2f(1.0f, 0.35f);

    glVertex2f(0.6f, 0.35f);

    glEnd();

    //bor2
    glBegin(GL_QUADS);
    glColor3ub(20, 20, 31);
    glVertex2f(0.60f, 0.39f);
    glVertex2f(0.62f, 0.39f);;
    glVertex2f(0.46f, 0.15f);
    glVertex2f(0.51f, 0.15f);

    glEnd();

    //bor3
    glBegin(GL_QUADS);
    glColor3ub(20, 20, 31);
    glVertex2f(0.49f, 0.15f);
    glVertex2f(1.0f, 0.15f);
    glVertex2f(1.0f, 0.13f);
    glVertex2f(0.50f, 0.13f);

    glEnd();

    //bodyH1
    glBegin(GL_QUADS);
    glColor3ub(255, 230, 230);
    glVertex2f(0.50f, 0.13f);
    glVertex2f(1.0f, 0.13f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(0.50f, -0.15f);
    glEnd();

    //bodyBorH1
    glBegin(GL_QUADS);
    glColor3ub(128, 64, 0);
    glVertex2f(0.50f, -0.15f);
    glVertex2f(1.0f, -0.15f);

    glVertex2f(1.0f, -0.19f);
    glVertex2f(0.47f, -0.19f);
    glEnd();

    //middleBorH1
    glBegin(GL_QUADS);
    glColor3ub(255, 179, 102);
    glVertex2f(0.50f, 0.04f);
    glVertex2f(1.0f, 0.04f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.50f, 0.0f);
    glEnd();

    //verBor1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.60f, 0.13f);
    glVertex2f(0.62f, 0.13f);
    glVertex2f(0.62f, 0.04f);
    glVertex2f(0.60f, 0.04f);
    glEnd();

    //verBor2
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.60f, 0.0f);
    glVertex2f(0.62f, 0.0f);
    glVertex2f(0.62f, -0.15f);
    glVertex2f(0.60f, -0.15f);
    glEnd();


    //verBor1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.90f, 0.13f);
    glVertex2f(0.92f, 0.13f);
    glVertex2f(0.92f, 0.04f);
    glVertex2f(0.90f, 0.04f);
    glEnd();

    //verBor2
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.90f, 0.0f);
    glVertex2f(0.92f, 0.0f);
    glVertex2f(0.92f, -0.15f);
    glVertex2f(0.90f, -0.15f);
    glEnd();


    ///Drawing House

    //Drawing Overall Shape
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.8f, 0.8f, 0.3f);//Hay Yellow
    glVertex2f(-0.90f, -0.15f);
    glVertex2f(-0.65f, -0.15f);
    glVertex2f(-0.59f, -0.24f);
    glVertex2f(-0.60f, -0.24f);
    glVertex2f(-0.60f, -0.37f);
    glVertex2f(-0.72f, -0.40f);
    glVertex2f(-0.95f, -0.40f);
    glVertex2f(-0.95f, -0.24f);
    glVertex2f(-0.98f, -0.24f);
    glEnd();


    //drawing roof
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.6f, 0.6f, 0.1f);
    glVertex2f(-0.73f, -0.24f);
    glVertex2f(-0.65f, -0.15f);
    glVertex2f(-0.59f, -0.24f);
    glEnd();

    //drawing Door Side
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.6f, 0.6f, 0.5f);//Ash
    glVertex2f(-0.72f, -.38f);
    glVertex2f(-0.72f, -.24f);
    glVertex2f(-0.60f, -.24f);
    glVertex2f(-0.60f, -.36f);
    glEnd();

    //drawing Front Side
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(1.0f, 1.0f, 0.8f);//Off White
    glVertex2f(-0.95f, -0.24f);
    glVertex2f(-0.72f, -0.24f);
    glVertex2f(-0.72f, -0.38f);
    glVertex2f(-0.95f, -0.38f);
    glEnd();

    //Drawing Window 1
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
    glVertex2f(-0.92f, -.28f);
    glVertex2f(-0.92f, -.33f);
    glVertex2f(-0.87f, -.33f);
    glVertex2f(-0.87f, -.28f);
    glEnd();

    //Drawing Window 2
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
    glVertex2f(-0.80f, -.28f);
    glVertex2f(-0.80f, -.33f);
    glVertex2f(-0.75f, -.33f);
    glVertex2f(-0.75f, -.28f);
    glEnd();

    //Drawing Door
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
    glVertex2f(-0.68f, -.28f);
    glVertex2f(-0.68f, -.37f);
    glVertex2f(-0.64f, -.37f);
    glVertex2f(-0.64f, -.28f);
    glEnd();

    //drawing Border
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.5f, 0.5f, 0.5f);//grey
    glVertex2f(-0.72f, -0.40f);
    glVertex2f(-0.97f, -0.40f);
    glVertex2f(-0.97f, -0.38f);
    glVertex2f(-0.72f, -0.38f);
    glEnd();

    //drawing Border
    glBegin(GL_POLYGON);  // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); //Black
    glVertex2f(-0.72f, -0.38f);
    glVertex2f(-0.58f, -0.35f);
    glVertex2f(-0.58f, -0.37f);
    glVertex2f(-0.72f, -0.40f);
    glEnd();

    boat1();


    ///********************************* Update and draw raindrops************************
    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_LINES);
    for (int i = 0; i < NUM_RAINDROPS; ++i) {
        raindrops[i][1] -= 0.01f; // Move raindrop downwards
        glVertex2f(raindrops[i][0], raindrops[i][1]);
        glVertex2f(raindrops[i][0], raindrops[i][1] - 0.02f); // Length of raindrop
        // Reset raindrop if it goes below the screen
        if (raindrops[i][1] < -1.0f) {
            raindrops[i][0] = (float)(rand() % (WINDOW_WIDTH * 2)) / WINDOW_WIDTH - 1.0f; // Random x-coordinate
            raindrops[i][1] = 1.0f; // Start from top of screen
        }
    }
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
    glutPostRedisplay(); // Request display update
    glutTimerFunc(16, timer, 0); // 60 fps
}



