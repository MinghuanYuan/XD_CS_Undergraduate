#include "windows.h" 
#include<glut.h>
#include<stdio.h>
typedef struct{
	float x,y,z;
}Point;
Point ctrlpoints[4]= {{0.0,0.0,0.0},{1.0,1.0,1.0},{2.0,-1.0,-1.0},{3.0,0.0,0.0}};
void DrawCurve(int n)
{
	Point p;
	double t,d,t2,t3,dis,dis2,dis3;
	int i;
	d = 1.0/(n-1);
	glBegin(GL_LINE_STRIP);
		for(i=0;i<n;i++)
		{
			t = i*d;
			t2 = t*t;
			t3 = t*t2;
			dis = 1-t;
			dis2 = dis*dis;
			dis3 = dis*dis2;
			p.x = dis*dis*dis/6*ctrlpoints[0].x+(3*t3-6*t2+4)/6*ctrlpoints[1].x+(-3*t3+3*t2+3*t+1)/6*ctrlpoints[2].x+t3/6*ctrlpoints[3].x;
			p.y = dis*dis*dis/6*ctrlpoints[0].y+(3*t3-6*t2+4)/6*ctrlpoints[1].y+(-3*t3+3*t2+3*t+1)/6*ctrlpoints[2].y+t3/6*ctrlpoints[3].y;
			p.z = dis*dis*dis/6*ctrlpoints[0].z+(3*t3-6*t2+4)/6*ctrlpoints[1].z+(-3*t3+3*t2+3*t+1)/6*ctrlpoints[2].z+t3/6*ctrlpoints[3].z;
			glVertex3f(p.x,p.y,p.z);
		}
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(6.0);
	glBegin(GL_POINTS);
	for (i = 0; i < 4; i++)
		glVertex3f(ctrlpoints[i].x,ctrlpoints[i].y,ctrlpoints[i].z);
	glEnd();

	glBegin(GL_LINE_STRIP);
		for(i=0;i<n;i++)
		{
			t = i*d;
			dis = 1-t;
			t2 = t*t;
			dis2 = dis*dis;
			t3 = t*t2;
			dis3 = dis*dis2;
			p.x = dis3*ctrlpoints[0].x+3*t*dis2*ctrlpoints[1].x+3*t2*dis*ctrlpoints[2].x+t3*ctrlpoints[3].x;
			p.y = dis3*ctrlpoints[0].y+3*t*dis2*ctrlpoints[1].y+3*t2*dis*ctrlpoints[2].y+t3*ctrlpoints[3].y;
			p.z = dis3*ctrlpoints[0].z+3*t*dis2*ctrlpoints[1].z+3*t2*dis*ctrlpoints[2].z+t3*ctrlpoints[3].z;
			glVertex3f(p.x,p.y,p.z);
		}
	glEnd();
	
	glPointSize(5.0);
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	for (i = 0; i < 4; i++)
		glVertex3f(ctrlpoints[i].x,ctrlpoints[i].y,ctrlpoints[i].z);
	glEnd();
}
void RenderScence()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	DrawCurve(200);
	
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
		glOrtho(-2.0,2.0,-2.0/aspectRatio,2.0/aspectRatio,1.0,-1.0);
	else
		glOrtho(-2.0*aspectRatio,2.0*aspectRatio,-2.0,2.0,1.0,-1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("4-1");
	glClearColor(0.0,0.0,0.0,0.0);
	glutDisplayFunc(RenderScence);
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
	return 0;
}
