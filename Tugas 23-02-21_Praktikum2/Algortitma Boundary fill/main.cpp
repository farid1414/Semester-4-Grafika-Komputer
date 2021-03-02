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

void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(2,1);
    glVertex2f(3,6);
    glVertex2f(5,4);
    glVertex2f(8,8);
    glVertex2f(10,4);
    glVertex2f(12,2);
    glVertex2f(2,1);
    glEnd();
    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Polygon");
    gluOrtho2D(-15., 15., -15., 15.);
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
