#include "windows.h"
#include <stdlib.h>
#include <glut.h>
#include <stdio.h>
#include <math.h>
#define MaxNumPts 64

int WindowHeight;
int WindowWidth;
float PointArray[MaxNumPts][2];
int NumPts = 0;
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);		
	if ( NumPts>1 ) {
		glBegin( GL_LINE_STRIP );
		for ( int i=0; i<NumPts; i++ ) {
		   glVertex2f( PointArray[i][0], PointArray[i][1] );
		}
		glEnd();
	}
	glColor3f( 0.0, 1.0, 0.0);			
	glBegin( GL_POINTS );
	for (int  i=0; i<NumPts; i++ ) {
	   glVertex2f( PointArray[i][0], PointArray[i][1] );
	}
	glEnd();
    glFlush();

}
void removeFirstPoint() {
	int i;
	if ( NumPts>0 ) {
		
		NumPts--;
		for ( i=0; i<NumPts; i++ ) {
			PointArray[i][0] = PointArray[i+1][0];
			PointArray[i][1] = PointArray[i+1][1];
		}
	}
}
void removeLastPoint() {
	if ( NumPts>0 ) {
		NumPts--;
	}
}
void polygonFill() 
{
   glBegin(GL_POLYGON);
   glColor3f(1.0, 0.0, 0.5);
   for (int i = 0; i <NumPts; i++) 
   {
       glVertex2f( PointArray[i][0], PointArray[i][1] );
   }
    glEnd();
    glFlush();
}
void myKeyboardFunc (unsigned char key, int x, int y)
{
	switch (key) {
	case 'f':
		removeFirstPoint();
		glutPostRedisplay();
		break;
	case 'l':
		removeLastPoint();
		glutPostRedisplay();
		break;
	case 'a':
	    polygonFill();
	    break;
	case 'q':		
		exit(0);
		break;
	}
}

void addNewPoint( float x, float y ) {
	if ( NumPts>=MaxNumPts ) {
		removeFirstPoint();
	}
	PointArray[NumPts][0] = x;
	PointArray[NumPts][1] = y;
	NumPts++;
}

void myMouseFunc( int button, int state, int x, int y ) {
	if ( button==GLUT_LEFT_BUTTON && state==GLUT_DOWN ) {
		float xPos = ((float)x)/((float)(WindowWidth-1));
		float yPos = ((float)y)/((float)(WindowHeight-1));

		yPos = 1.0f-yPos;			

		addNewPoint( xPos, yPos );
		glutPostRedisplay();
	}
}

void ChangeSize(int w, int h)
{
	WindowHeight = (h>1) ? h : 2;
	WindowWidth = (w>1) ? w : 2;
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);  
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB ); 
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("4-4");
	glClearColor( 0.0, 0.0, 0.0, 0.0);
	glPointSize(6);
	glLineWidth(5);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(myKeyboardFunc);
	glutMouseFunc(myMouseFunc);
	glutMainLoop();
	return 0;				
}
