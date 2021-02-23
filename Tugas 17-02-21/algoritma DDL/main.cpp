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
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <windows.h>
#include <stdlib.h>




/* GLUT callback Handlers */

#define window_wide 1300
#define window_height 700

float x1,y1,x2,y2,check=0;
void setPixel(int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}

void algorithm()
{
float dx = x2-x1;
float dy = y2-y1;
float m = dy/dx;
if(m>=-1 && m<=1)
{
if(dx<0)
{
int temp = x1;
x1 = x2;
x2 = temp;
temp = y1;
y1 = y2;
y2 = temp;
dx *= -1;
dy *= -1;
}
int x = x1;
int y = y1;
while(x < x2)
{
x++;
y = y+m+0.5;
setPixel(x,y);
}
}
else
{
if(dy<0)
{
int temp = x1;
x1 = x2;
x2 = temp;
temp = y1;
y1 = y2;
y2 = temp;
dx *= -1;
dy *= -1;
}
int x = x1;
int y = y1;
while(y < y2)
{
y++;
x = x+1/m+0.5;
setPixel(x,y);
}
}
}

void myMouse(int button, int state, int x, int y)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
if(check==0)
{
x1 = x;
y1 = window_height-y;
check = 1;
setPixel(x1,y1);
}
else if(check==1)
{
x2 = x;
y2 = window_height-y;
check = 0;
setPixel(x2,y2);
algorithm();
//glFlush();
}
}
}

void myDisplay(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(1.0,0.0,0.0);
gluOrtho2D(0.0,window_wide,0.0,window_height);
glClear(GL_COLOR_BUFFER_BIT);
glutMouseFunc(myMouse);
}

int main(int argc, char** argv)
{
glutInitWindowSize(window_wide,window_height);
glutInitWindowPosition(0, 0);
glutCreateWindow("Aloritma DDA");
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}
