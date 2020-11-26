// Implementation Of DDA Algorithm
#include<GL/glut.h>
#include<iostream>
using namespace std;
float x1,x2,y1,y2;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);
    float dy,dx,step,x,y,k,Xin,Yin;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)> abs(dy))
    {
        step = abs(dx);
    }
    else
       {
           step = abs(dy);
       }

    Xin = dx/step;
    Yin = dy/step;

    x=x1;
    y=y1;
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glBegin(GL_POINTS);
    for (k=1 ;k<=step;k++)
    {
        x= x + Xin;
        y= y + Yin;
        glVertex2f(x,y);
    }
     glEnd();
    glFlush();
}

void init()
{
glClearColor(0.0,0.0,0.0,0.1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,50,0,50);
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1000, 1000);
glutInitWindowPosition (100,100);
cout<<"Enter the value of x1 : \t";
cin>>x1;
cout<<"Enter the value of y1: :\t";
cin>>y1;
cout<<"Enter the value of x2 : \t";
cin>>x2;
cout<<"Enter the value of y2: :\t";
cin>>y2;
glutCreateWindow ("DDA Line Algorithm");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
