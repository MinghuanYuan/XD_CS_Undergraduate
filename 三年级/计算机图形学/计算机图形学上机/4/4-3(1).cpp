#include "windows.h"
#include <glut.h>
void DrawColorLine()
{
  
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(-5,10);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(5,-10);
    glEnd();

}
void init()
{
    glClearColor(0.0,0.0,0.0, 0.0);
	glLineWidth(10);
}
void RenderScence()
{
    glClear(GL_COLOR_BUFFER_BIT);
    DrawColorLine();
    glFlush();
}
void ChangeSize(GLsizei w,GLsizei h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w<=h)
		glOrtho(-20.0,20.0,-20.0*(GLfloat)h/(GLfloat)w,20.0*(GLfloat)h/(GLfloat)w,-50.0,50.0);
	else
		glOrtho(-20.0*(GLfloat)h/(GLfloat)w,20.0*(GLfloat)h/(GLfloat)w,-20.0,20.0,-50.0,50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("²åÖµ");
    init();
    glutDisplayFunc(RenderScence);
    glutReshapeFunc(ChangeSize);
    glutMainLoop();
    return 0;
}
