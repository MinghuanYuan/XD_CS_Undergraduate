#include <iostream>
#include "windows.h" 
#include<glut.h>

using namespace std;

float n;

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
}


void RenderScene()
{    
	float n2=n+n;
    float n3=n2+n;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.3);
    glRectf(-5.0,4.0, (-5.0+n), 4.0+n);
    glColor3f(0.0,0.0,0.3);
    glRectf((-4.0+n), 4.0, (-4.0+n2), 4.0+n);
    glColor3f(0.5,0.0,0.0);
    glRectf((-3.0+n2), 4.0, (-3.0+n3), 4.0+n);
    glColor3f(1.0,0.0,0.0);
    glRectf(-5.0, 3.0-n, (-5.0+n), 3.0);
    glColor3f(1.0,0.0,1.0);
    glRectf((-4.0+n), 3.0-n,(-4.0+n2), 3.0);
    glColor3f(0.0,0.5,0.0);
    glRectf((-3.0+n2), 3.0-n, (-3.0+n3), 3.0);
    glColor3f(0.5,1.0,0.0);
    glRectf(-5.0, 2.0-n2, (-5.0+n), 2.0-n);
    glColor3f(1.0,0.0,0.0);
    glRectf((-4.0+n), 2.0-n2, (-4.0+n2), 2.0-n);
    glColor3f(0.0,0.3,0.0);
    glRectf((-3.0+n2), 2.0-n2, (-3.0+n3), 2.0-n);
    glFlush();
}

void ChangeSize(GLsizei w,GLsizei h)
{
    GLfloat aspectRatio;
    if(h==0)
        h = 1;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    aspectRatio = (GLfloat)w/(GLfloat)h;
    if(w<=h)
        glOrtho(-10.0,10.0,-10.0/aspectRatio,10.0/aspectRatio,10.0,-1.0);
    else
        glOrtho(-10.0*aspectRatio,10.0*aspectRatio,-10.0,10.0,10.0,-1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main() {
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    //glutInitWindowPosition(50,50);
    glutInitWindowSize(300, 300);
	glutCreateWindow("九宫格");
    init();
    cout<<"请输入方块边长（像素表示）：";
    cin>>n;
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
	glutMainLoop();
    
    return 0;
}

