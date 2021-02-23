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




void drawCircle(double r, int vertex){
    double ngon = (double) vertex;
    glBegin(GL_POLYGON);
    for(int i=0; i<vertex; i++){
        double x = r * cos(2* M_PI*i/vertex);
        double y = r * sin(2* M_PI*i/vertex);
        glVertex2d(x,y);
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    drawCircle(1.0, 25);
    glutSwapBuffers();
}

void myinit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);

}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Draw Circle");
    glutDisplayFunc(display);

    myinit();
    glutMainLoop();

    return 0;
}

