#include"windows.h" 
#include <glut.h>
float ro=0.05; 
float x=5.0,y=-50.0,angle=0.0;

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
	glBegin(GL_POINTS);
		glColor3f( 0.0,1.0,0.0);
		glVertex2f(0.0,0.0);
	glEnd();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(x,y,0.0);
	glRotatef(angle,0,0,1.0);
	glTranslatef(-x,-y,0.0);
	angle+=ro;
	if(angle>=360.0)
	angle-=360.0;
	glColor3f(0.0,1.0,1.0);
	glRectf(-5.0,50.0,5.0,-50.0);
    glutPostRedisplay();
	glFlush();
	
	
}
void ChangeSize(GLsizei w,GLsizei h)
{
	float ratio;
	if(h==0)
		h = 1;
	ratio = (GLfloat)w/(GLfloat)h;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		gluOrtho2D(-200.0,200.0,-200.0/ratio,200.0/ratio);
	else
		gluOrtho2D(-200.0*ratio,200.0*ratio,-200.0,200);
 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main()
{
	
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(300,300);
	glutCreateWindow("Ðý×ª");
	glClearColor(0.0,0.0,0.0,0.0);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
	return 0;
}
