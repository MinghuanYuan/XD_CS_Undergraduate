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

void myKey( unsigned char key, int x, int y) {//响应ASCII对应键，鼠标的当前x和y位置也被返回。
	switch(key){
		case ' ': currentMode = (currentMode+1)%ModeNums;
			      glutPostRedisplay();
				  break;
		case 27:  exit(-1);
	}
}

void RenderScene(){
	glClear(GL_COLOR_BUFFER_BIT);//用当前的清除色清除窗口
	glColor3f(1.0,0.0,1.0);//把当前的绘图颜色设置为黑色
	glLineWidth(2);//设置线段宽度
	glPointSize(5);//设置点大小 
	
	switch(currentMode){
		case 0: glBegin(GL_POINTS);//画点 
				break;
		case 1: glBegin(GL_LINE_STRIP);//画线 
				break;
		case 2: glBegin(GL_LINE_LOOP);//闭合三角形 
				break;
		case 3: glBegin(GL_TRIANGLES);//填色 
			    break;
		case 4: glTranslatef(10.0,-10.0,0.0);//平移 
			    glBegin(GL_TRIANGLES);
				break;
		case 5: 
				glTranslatef(10.0,-10.0,0.0);//放缩 
				glScalef(2.0,2.0,1.0);
				glBegin(GL_TRIANGLES);
				break;
		case 6: glLoadIdentity();//旋转 
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
	glFlush();//刷新绘图命令
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
	glutKeyboardFunc(myKey);  //为当前窗口设置键盘回调函数。
	printf("Press space to continue,press escape to exit!\n");
	glutMainLoop();
	return 0;
}


