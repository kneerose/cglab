// Implementation of Mid-Point Circle Algorithm
#include<GL/glut.h>
#include<iostream>
using namespace std;
int x_center,y_center,r;
void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+x_center, y+y_center);
    glEnd();
}
void MCircle()
{
    int x = 0;
    int y = r;
    float decision = 5/4 - r;
    plot(x, y);
    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2*x+1;
        }
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
}
void display()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    MCircle();
    glFlush ();
}
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
}

void reshape(int w,int h)
{
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-200,200,-200,200);
   glMatrixMode(GL_MODELVIEW);

}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
cout<<"Enter the value of x_center : \t";
cin>>x_center;
cout<<"Enter the value of y_center: :\t";
cin>>y_center;
cout<<"Enter the value of radius : \t";
cin>>r;
glutCreateWindow ("midpoint circle algorithm");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
init();
glutMainLoop();
}
