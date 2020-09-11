#include"windows.h" 
#include <glut.h>
float trans=0.05; 
float d=-200.0;

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(1000.0,0.0);
	glVertex2f(-1000.0,0.0);
	glEnd();
	glPushMatrix();
    glLoadIdentity();
	glTranslatef(d,0.0,0.0);
	d+=trans;
	if(d>=150)
	d-=300;
	glColor3f(1.0,0.0,1.0);
	glRectf(-5.0,10.0,5.0,-10.0);
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
	glutInitWindowSize(300,300);
	glutCreateWindow("Æ½ÒÆ");
	glClearColor(0.0,0.0,0.0,0.0);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
	return 0;
}

