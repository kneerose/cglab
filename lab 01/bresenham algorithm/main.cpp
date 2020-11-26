//Implementation Of Bresenham Line Drawing Algorithm
#include<GL/glut.h>
#include <iostream>
using namespace std;
float x1,x2,y1,y2;
void display ()
{
    float dx=x2-x1;
    float dy=y2-y1;
    float p0 = 2*dy - dx;
    float x=x1,y=y1;

    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    float p =p0;
    int k;
    for(k=0;k<dx;k++)
    {
        if(p<0)
        {
            x = x+1;
            glVertex2f(x,y);
        }

        else
        {
            x = x+1; y = y+1;
            glVertex2f(x,y);
        }
    }
    glEnd();
    glFlush();
}

void init()
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,1000,0,1000);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (100, 100);
    cout<<"Enter the value of x1 : \t";
    cin>>x1;
    cout<<"Enter the value of y1: :\t";
    cin>>y1;
    cout<<"Enter the value of x2 : \t";
    cin>>x2;
    cout<<"Enter the value of y2: :\t";
    cin>>y2;
    glutCreateWindow ("Bresenham Line Algorithm ");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
