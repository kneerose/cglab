#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>
#include <cmath>
int ch;
double a,rad;
float x,y,xs,ys;
using namespace std;
void display()
{
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.9);
    glVertex2f(0.0,-15.0);
    glVertex2f(0.0,15.0);
    glVertex2f(0.0,0.0);
    glVertex2f(-15.0,0.0);
    glVertex2f(15.0,0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(-7.0,1.0);
    glVertex2f(-4.0,4.0);
    glEnd();
}
void translate()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    display();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(-1.0+x,1.0+y);
    glVertex2f(-7.0+x,1.0+y);
    glVertex2f(-4.0+x,4.0+y);
    glEnd();
    glFlush();

}
void rotation()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    display();
    rad=(M_PI/180)*a;
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,1.0);
    glVertex2d(-1.0*cos(rad)-1.0*sin(rad),-1.0*sin(rad)+1.0*cos(rad));
    glVertex2d(-7.0*cos(rad)-1.0*sin(rad),-7.0*sin(rad)+1.0*cos(rad));
    glVertex2d(-4.0*cos(rad)-4.0*sin(rad),-4.0*sin(rad)+4.0*cos(rad));
    glEnd();
    glFlush();

}
void scaling()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    display();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(-1.0*xs,1.0*ys);
    glVertex2f(-7.0*xs,1.0*ys);
    glVertex2f(-4.0*xs,4.0*ys);
    glEnd();
    glFlush();
}
void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
}

void reshape(int w,int h)
{
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-15,15,-15,15);
   glMatrixMode(GL_MODELVIEW);

}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);
    cout<<"********************2D triangle********************"<<endl;
    cout<<"1. Translation"<<endl;
    cout<<"2. Scaling"<<endl;
    cout<<"3. Rotation"<<endl;
    cout<<" Choose the option :"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:  cout<<"enter the translation value (x,y): \t";
                 cin>>x>>y;
                 glutCreateWindow("Translation");
                 glutDisplayFunc(translate);
                 glutReshapeFunc(reshape);
                 init();
                 glutMainLoop();
                 break;
        case 2:  cout<<"enter the scaling value (x,y): \t";
                 cin>>xs>>ys;
                 glutCreateWindow("Scaling");
                 glutDisplayFunc(scaling);
                 glutReshapeFunc(reshape);
                 init();
                 glutMainLoop();
                 break;
        case 3:  cout<<"enter angle for rotation:\t";
                 cin>>a;
                 glutCreateWindow("Rotation about origin");
                 glutDisplayFunc(rotation);
                 glutReshapeFunc(reshape);
                 init();
                 glutMainLoop();
                 break;
        default: cout<<"invalid input"<<endl;
                 break;
    }


}
