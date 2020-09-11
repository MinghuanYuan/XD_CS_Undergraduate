#include "windows.h" 
#include<glut.h>

typedef struct{
	float x,y,z;
}Point;

//Point mypoints[4]= {{0.0,1.0,0.0},{3.0,0.0,0.0},{0.0,0.0,0.0},{0.0,5.0,0.0}};  //更改切向量 
Point mypoints[4]= {{0.0,1.0,0.0},{3.0,0.0,0.0},{0.0,1.0,0.0},{3.0,0.0,0.0}}; 
void DrawCurve(int n)
{
	Point p;
	double t,d,t2,t3,dis,dis2,dis3;
	int i;
	d = 1.0/(n-1);
	glBegin(GL_LINE_STRIP);
		for(i=0;i<n;i++)
		{
			dis = 1-t;
			dis2 = dis*dis;
			dis3 = dis*dis2;
			t = i*d;
			t2 = t*t;
			t3 = t*t2;
			p.x = (2*t3-3*t2+1)*mypoints[0].x+(-2*t3+3*t2)*mypoints[1].x+(t3-2*t2+t)*mypoints[2].x+(t3-t2)*mypoints[3].x;
			p.y = (2*t3-3*t2+1)*mypoints[0].y+(-2*t3+3*t2)*mypoints[1].y+(t3-2*t2+t)*mypoints[2].y+(t3-t2)*mypoints[3].y;
			p.z = (2*t3-3*t2+1)*mypoints[0].z+(-2*t3+3*t2)*mypoints[1].z+(t3-2*t2+t)*mypoints[2].z+(t3-t2)*mypoints[3].z;
			glVertex3f(p.x,p.y,p.z);
		}
	glEnd();
	
	glPointSize(6.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (i = 0; i < 2; i++)
		glVertex3f(mypoints[i].x,mypoints[i].y,mypoints[i].z);
	glEnd();
	
}
void RenderScence()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	DrawCurve(100);
	
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
		glOrtho(-5.0,5.0,-5.0/aspectRatio,5.0/aspectRatio,1.0,-1.0);
	else
		glOrtho(-5.0*aspectRatio,5.0*aspectRatio,-5.0,5.0,1.0,-1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("3-2");
	glClearColor(0.0,0.0,0.0,0.0);
	glutDisplayFunc(RenderScence);
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
	return 0;
}
