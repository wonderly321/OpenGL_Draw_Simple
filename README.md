## 运行环境
win + vs15/17

## lab 1 
1 实现了直线的DDA算法、正负法、Bresenham算法

<img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_1.png" width = 30% align=center/>

黄、蓝、红依次代表DDA,正负法和Bradenham方法

2 实现了圆弧的正负法和Bradenham算法

<img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_2_1.png" width = 25% /><img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_2_2.png" width = 25% /><img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_2_3.png" width = 25% />

短 bresenham八分弧，长 正负法 四分弧

<img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_2_4.png" width = 30% />

变形 四分弧

<img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_2_5.png" width = 20% /><img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_2_6.png" width = 20% /><img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_2_7.png" width = 20% /><img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_2_8.png" width = 20% />

变形 四分弧

3 利用上述完成的算法绘制中国象棋的棋盘和棋子

<img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_3_1.png" width = 30% />

<img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab1_3_2.png" width = 30% />

## lab 2
1.在lab1_3基础上，自行设计并实现棋盘标志的绘制（如山东大学校徽标志）

<img src="https://github.com/wonderly321/OpenGL_Draw_Simple/blob/master/img/lab2_1.png" width = 30% />

2.实现对棋盘标志的平移、旋转和放缩功能
针对平移，放缩和旋转功能只需关心顶点的转换公式：

```
x = arr[i][0]*k*h+x0;
y = -arr[i][1]*k*h+y0;
```
K为放缩因子，x0,y0为相对坐标原点。

想要放缩只需要适当改变k的大小，平移需改变和原点的相对距离，旋转则改变x,y的正负。

3 to do
* 棋子的移动
* 美化

