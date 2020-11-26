//Implementation of Mid-Point ellipse Algorithm
#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
int x_center,y_center,rx,ry;
void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+x_center, y+y_center);
    glEnd();
}
void MEllipse()
{
    int x = 0;
    int y = ry;
    float p1k = pow(ry,2)-pow(rx,2)*ry+(1/4)*pow(rx,2);
    while((2*pow(ry,2)*x) < (2*pow(rx,2)*y))
       {
        x++;
        if (p1k<0)
            p1k = p1k + pow(ry,2)*2*x + pow(ry,2);
        else
           {
            y--;
            p1k = p1k + 2*x*pow(ry,2) + pow(ry,2) - 2*y*pow(rx,2);
           }
        plot(x,y);
        plot(-x,y);
        plot(-x,-y);
        plot(x,-y);
       }
    float p2k = pow(ry,2)*pow((x+1/2),2) + pow(rx,2)*pow((y-1),2) - pow(rx,2)*pow(ry,2);
    while(y!=0)
    {
        y--;
        if (p2k>0)
            p2k = p2k - 2*y*pow(rx,2) + pow(rx,2);
        else
            {
                x++;
                p2k = p2k + pow(ry,2)*(2*x) - 2*y*pow(rx,2) + pow(rx,2);
            }
        plot(x,y);
        plot(-x,y);
        plot(-x,-y);
        plot(x,-y);
    }
}
void display()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    MEllipse();
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
cout<<"Enter the value of radius rx: \t";
cin>>rx;
cout<<"Enter the value of radius ry: \t";
cin>>ry;
glutCreateWindow ("midpoint ellipse algorithm");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
init();
glutMainLoop();
}
