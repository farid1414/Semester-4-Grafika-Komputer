/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else```````````````````````````````````````````````````````````````````
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include<math.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>



int i=0; int j=0;
void lingkaran(int xp, int yp, int r, int n){
    xp=2;
    yp=5;
    r=6;
    float a,x,y;
    glColor4ub(i,j,0,200);
    glBegin(GL_POLYGON);
        a=6.28/n;
        for (int i=0; i<n; i++){
            x = xp+r * cos(i*a);
            y = yp+r * sin(i*a);
            glVertex2d(x,y);
        }
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);//untuk membuat opacity
    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex2d(-500,0);
        glVertex2d(500,0);
        glVertex2d(0,400);
        glVertex2d(0,-400);
    glEnd();

    lingkaran(0,0,100,25);
    i+=20;
    j+=1;
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Lingkaran titik pusat (2,5)");

    gluOrtho2D(-500,500,-400,400);


    glutDisplayFunc(display);
    glutIdleFunc(display);

    glClearColor(1,1,1,0);
    glutMainLoop();
}
