#include "windows.h" 
#include <glut.h>
#include <math.h>
#include <stdio.h>
double xx0,yy0,xx1,yy1;
typedef struct {
	float x,y;
}point;

//设置渲染状态 
void init() 
{
	glClearColor(0.0f,1.0f,1.0f,0.0f);
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
		glOrtho(-100.0,100.0,-100.0/aspectRatio,100.0/aspectRatio,1.0,-1.0);
	else
		glOrtho(-100.0*aspectRatio,100.0*aspectRatio,-100.0,100.0,1.0,-1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


//绘制场景
int MidPointLine(int x0, int y0, int x1,int y1, point pixels[])
{
	int a,b,d1,d2,d,x,y,num=0;
	a=y0-y1;
	b=x1-x0;
	d=2*a+b;
	d1=2*a;
	d2=2*(a+b);
	x=x0; y=y0;
	pixels[0].x = x;
	pixels[0].y = y;
	while(x<x1)
	{
		num++;
		if(d<0) 
		{
			x++; y++; d+=d2;
			pixels[num].x = x;
			pixels[num].y = y;
		}
		else 
		{
			x++; d+=d1;
			pixels[num].x = x;
			pixels[num].y = y;
		}
	}
	return num; 
}

void drawLine(int x1,int y1,int x2,int y2)
{
	point pixels[100];
	int num;
	int i;
	double k;
	k=1.0*(y2-y1)/(x2-x1);
	printf("K=%f", k);
	if(k>0&&k<=1)
	num = MidPointLine(x1,y1,x2,y2,pixels);
	else if(k>1) 
	{
		point pixels_t[100];
		num = MidPointLine(y1,x1,y2,x2,pixels_t);
		for(i=0;i<num;i++)
		{
			pixels[i].x = pixels_t[i].y;
			pixels[i].y = pixels_t[i].x;
		}
	}
	
	else if(k<0&&k>=-1)
	{
		point pixels_t[100];
		num = MidPointLine(-x1,y1,-x2,y2,pixels_t);
		for(i=0;i<num;i++)
		{
			pixels[i].x = -pixels_t[i].x;
			pixels[i].y = pixels_t[i].y;
		}
			
	}
	else
	{
		point pixels_t[100];
		num = MidPointLine(y1,-x1,y2,-x2,pixels_t);
		for(i=0;i<num;i++)
		{
			pixels[i].x = -pixels_t[i].x;
			pixels[i].y = pixels_t[i].y;
		}
			
	}
	glBegin(GL_POINTS);
		for(i=0;i<num;i++)
			glVertex2f(pixels[i].x,pixels[i].y);
	glEnd();
}
	
	
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.f);
	drawLine(0,0,-50,50);
	glFlush();
}

int main()
{
//	scanf("%d %d %d %d",&xx0, &yy0, &xx1, &yy1);
	
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("中点线算法");
	
	init();
//	scanf("%d %d %d %d",&xx0, &yy0, &xx1, &yy1);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	glutMainLoop(); 
	return 0;
}
	


