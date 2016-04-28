// gltest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl\glut.h> 
void draw_triangle(void) { 
	glBegin(GL_LINE_LOOP);    
	glVertex2f(0.0, 25.0);    
	glVertex2f(25.0, ‐25.0);    
	glVertex2f(‐25.0, ‐25.0);    
	glEnd(); }
void myDisplay(void) {     
glClear(GL_COLOR_BUFFER_BIT); //清除颜色    
glRectf(-0.8f, -0.8f, 0.8f, 0.8f);//逆时针，左下右上的左边顺序
glClear(GL_COLOR_BUFFER_BIT); //清除颜色
glColor3f(1.0, 0.0, 0.0);
glFlush();//保证前面的指令执行而不是在缓冲区中等待
}  
int main(int argc, char *argv[]) { 
glutInit(&argc, argv); //必须在其他glut指令前执行一遍，初始化glut    
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//设置显示方式，     
glutInitWindowPosition(300, 50);//窗口位置     
glutInitWindowSize(650, 650);//窗口大小     
glutCreateWindow("第一个OpenGL程序"); //创建窗口，参数为标题    
glutDisplayFunc(&myDisplay); //需要画图时调用&mydisplay函数   
glutMainLoop();//消息循环注释则看不见图     
return 0; 
}
