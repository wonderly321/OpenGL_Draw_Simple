#include "stdafx.h"
#include <gl/glut.h>
#include "math.h"
#include "stdlib.h"

//初始化窗口界面
void myinit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

//DDA画法
void dda_line(int xa, int ya, int xb, int yb) {
	GLfloat delta_x, delta_y, x, y;
	int dx, dy, steps;
	dx = xb - xa;
	dy = yb - ya;
	if (abs(dx)>abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	delta_x = (GLfloat)dx / (GLfloat)steps;
	delta_y = (GLfloat)dy / (GLfloat)steps;
	x = xa;
	y = ya;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex3f(x, y, 0);

	for (int i = 0; i <= steps; i++)
	{
		x += delta_x;
		y += delta_y;
		glBegin(GL_POINTS);
		glVertex3f(x, y, 0);
		glEnd();
	}
}

//正负法生成直线
void sign_line(int xa, int ya, int xb, int yb)
{
	int x = xa, y = ya;
	int a = ya - yb, b = xb - xa;
	int cx, cy;
	if (b >= 0)
	{
		//xb >= xa的情况
		cx = 1;
		//从左向右画
	}
	else {
		// x2 < x1 的情况 
		b = -b; //使 b>=0 
		cx = -1; // 从右往左画 
	} if (a <= 0) {
		//y2 >= y1 的情况 
		cy = 1; // 从下往上画
	}
	else {
		//y2 < y1 的情况 
		a = -a; //使 a<=0 
		cy = -1; // 从上往下画 
	}
	int d, d1, d2;
	glBegin(GL_POINTS);
	if (-a <= b) // 斜率绝对值 <= 1 
	{
		d = 2 * a + b;
		d1 = 2 * a;
		d2 = 2 * (a + b);
		while (x != xb)
		{
			if (d < 0)
			{//去右上方像素点 
				y += cy;
				d += d2;
			}
			else {
				//取右下方像素点 
				d += d1;
			}
			x += cx;
			glVertex2f(x, y);
		}
	}
	else
		// 斜率绝对值 > 1 
	{
		//因两种情况以直线y=x为轴对称
		//可轻松将斜率绝对值大于1的情况转换为斜率的绝对值小于1的情况 
		d = 2 * b + a;
		d1 = 2 * a;
		d2 = 2 * (a + b);
		while (y != yb)
		{
			if (d < 0)
			{
				d += d1;
			}
			else
			{
				x += cx;
				d += d2;
			}
			y += cy;
			glVertex2f(x, y);
		}
	}
	glEnd();
}
// 基于 Bresenham 算法画直线
void bresenham_line(int x1, int y1, int x2, int y2)
{
	int x = x1;
	int y = y1;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int s1 = x2 > x1 ? 1 : -1;
	int s2 = y2 > y1 ? 1 : -1;
	bool change = false;
	// 默认不互换 dx、dy 
	if (dy > dx)
		// 当斜率大于 1 时，dx、dy 互换 
	{
		int temp = dx;
		dx = dy;
		dy = temp;
		change = true;
	}
	int p = 2 * dy - dx;
	glBegin(GL_POINTS);
	for (int i = 0; i < dx; i++)
	{
		glVertex2f(x, y);
		if (p >= 0)
		{
			if (!change)
				// 当斜率 < 1 时，选取上下象素点 
				y += s2;
			else// 当斜率 > 1 时，选取左右象素点 
				x += s1;
			p -= 2 * dx;
		} if (!change)
			x += s1;
		// 当斜率 < 1 时，取 x 
		else y += s2;
		// 当斜率 > 1 时，取 y 
		p += 2 * dy;
	}
	glEnd();
}

//display对象
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//调用DDA直线生成算法
	glColor3f(1.0, 1.0, 0.0);
	dda_line(50, 50, 200, 450);
	//调用正负法直线生成算法
	glColor3f(0.0, 1.0, 1.0);
	sign_line(50, 50, 400, 400);
	//调用bresenham法直线生成算法
	glColor3f(1.0, 0.0, 1.0);
	bresenham_line(50, 50, 450, 200);
	glFlush();


}

//主程序入口
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(600, 50);
	glutCreateWindow("DrawLine");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}