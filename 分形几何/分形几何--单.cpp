#include<stdio.h>
#include<math.h>
#include<conio.h>
#include"graphics.h"
void  koch(double x0, double y0, double x1, double y1, int k)
{
    double x2, y2, x3, y3, x4, y4;
    x2 = 2.0/3 * x0 + 1.0/3 * x1;  /*由上面的运算可以得到其余三点 坐标的计算式*/
    y2 = 2.0/3 * y0 + 1.0/3 * y1;
    x3 = 1.0/3 * x0 + 2.0/3 * x1;
    y3 = 1.0/3 * y0 + 2.0/3 * y1;
    x4 = 1.0/2 * (x0 + x1) - sqrt(3.0)/6 * (y1 - y0);
    y4 = 1.0/2 * (y0 + y1) + sqrt(3.0)/6 * (x1 - x0);
    if( k > 1)    /*如果迭代次数大于1，就继续迭代下去，即执行以下程序*/
    {
        koch(x0, y0, x2, y2, k - 1);  /*对以(x0, y0)和(x2, y2)为端点的线段作为
        初始线段进行迭代运算，以下类同*/
        koch(x2, y2, x4, y4, k - 1);
        koch(x4, y4, x3, y3, k - 1);
        koch(x3, y3, x1, y1, k - 1);
    } else {      /*如果迭代次数等于1，停止迭代，画出迭代生成的图形*/
        line(x0, y0, x2, y2);       /*用直线联结两点(x0, y0)和(x2, y2)*/
        line(x2, y2, x4, y4);       /*用直线联结两点(x2, y2)和(x4, y4)*/
        line(x4, y4, x3, y3);       /*用直线联结两点(x4, y4)和(x3, y3)*/
        line(x3, y3, x1, y1);       /*用直线联结两点(x3, y3)和(x1, y1)*/
    }
}

int main()
{
    int n, gdriver = DETECT, gmode;      /*定义迭代次数n*/
    initgraph(&gdriver, &gmode,"C:\\Win-TC\\BGI");     /*图形系统初始化*/
    printf("Please input the value of the positive integer n (n<9):");
    scanf("%d", &n);               /*输入迭代次数n*/
    setcolor(GREEN);
    koch(50, 120, 450, 120, n);
    getch();
    closegraph(); /*关闭图形系统*/
    return 0;
}
