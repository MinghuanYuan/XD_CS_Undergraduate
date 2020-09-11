#include"windows.h" 
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
int currentMode = 0;
const int ModeNums = 10;

void init(){
	glClearColor(0.0,0.0,0.0,0.0);
}

void myKey( unsigned char key, int x, int y) {//��ӦASCII��Ӧ�������ĵ�ǰx��yλ��Ҳ�����ء�
	switch(key){
		case ' ': currentMode = (currentMode+1)%ModeNums;
			      glutPostRedisplay();
				  break;
		case 27:  exit(-1);
	}
}

void RenderScene(){
	glClear(GL_COLOR_BUFFER_BIT);//�õ�ǰ�����ɫ�������
	glColor3f(1.0,0.0,1.0);//�ѵ�ǰ�Ļ�ͼ��ɫ����Ϊ��ɫ
	glLineWidth(2);//�����߶ο��
	glPointSize(5);//���õ��С 
	
	switch(currentMode){
		case 0: glBegin(GL_POINTS);//���� 
				break;
		case 1: glBegin(GL_LINE_STRIP);//���� 
				break;
		case 2: glBegin(GL_LINE_LOOP);//�պ������� 
				break;
		case 3: glBegin(GL_TRIANGLES);//��ɫ 
			    break;
		case 4: glTranslatef(10.0,-10.0,0.0);//ƽ�� 
			    glBegin(GL_TRIANGLES);
				break;
		case 5: 
				glTranslatef(10.0,-10.0,0.0);//���� 
				glScalef(2.0,2.0,1.0);
				glBegin(GL_TRIANGLES);
				break;
		case 6: glLoadIdentity();//��ת 
				glScalef(2.0,2.0,1.0);
			    glRotatef(45.0,0.0,0.0,1.0);
			    glTranslatef(10.0,-10.0,0.0);
			    glBegin(GL_TRIANGLES);
				break;
	}
	glVertex2f( 0.0, 20.0 );
	glVertex2f( 6.0, 5.0 );
	glVertex2f( -6.0, 5.0);
	glEnd();
	glFlush();//ˢ�»�ͼ����
}

void ChangeSize(GLsizei w,GLsizei h){
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

int main(){
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(360,360);
	glutCreateWindow("2.3");
	init();
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(myKey);  //Ϊ��ǰ�������ü��̻ص�������
	printf("Press space to continue,press escape to exit!\n");
	glutMainLoop();
	return 0;
}


