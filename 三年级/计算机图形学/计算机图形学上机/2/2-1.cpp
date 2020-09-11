#include"windows.h" 
#include <glut.h>
void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
}
void RenderScene()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-35,1,1,1);
	glPushMatrix();	
	glColor3f(0.0,1.0,0.0);
	glutWireCube(20.0);
	glTranslatef(10.0,20.0,10.0);
	glPushMatrix();
	glScalef(2.0,1.0,0.5);
	glPushMatrix();
	glTranslatef(-10,-20,-10);
    glPushMatrix();
    glColor3f(0.0,0.0,1.0);
	glutWireCube(20.0);
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
	glutCreateWindow("Ëõ·Å");

	init();
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	glutMainLoop();
	return 0;
}
