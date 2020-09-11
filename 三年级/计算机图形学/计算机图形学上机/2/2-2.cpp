#include"windows.h" 
#include <glut.h>

void RenderScene()
{
	glLoadIdentity();
	glColor3f(1.0,0.0,0.0);
	glRectf(-20,10,10,-30);
	glTranslatef(0.0,5.0,0.0);  
	glPushMatrix();
	glScalef(1.0,-1.0,1.0);
	glPushMatrix();
	glRotated(-45,0,0,1);
	glPushMatrix();
	glTranslated(0.0,-5.0,0.0);
	glPushMatrix();
    glColor3f(1.0,1.0,0.0);
	glRectf(-20,10,10,-30);
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
		glOrtho(-50.0,50.0,-50.0/aspectRatio,50.0/aspectRatio,-50.0,50.0);
	else
		glOrtho(-50.0*aspectRatio,50.0*aspectRatio,-50.0,50.0,-50.0,50.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main()
{
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("2-2");
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glClearColor(1.0,1.0,1.0,1.0);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
	return 0;
}
