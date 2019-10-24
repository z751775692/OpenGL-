#include<stdio.h>
#include<math.h>
#include<conio.h>
#include"graphics.h"
void  koch(double x0, double y0, double x1, double y1, int k)
{
    double x2, y2, x3, y3, x4, y4;
    x2 = 2.0/3 * x0 + 1.0/3 * x1;  /*�������������Եõ��������� ����ļ���ʽ*/
    y2 = 2.0/3 * y0 + 1.0/3 * y1;
    x3 = 1.0/3 * x0 + 2.0/3 * x1;
    y3 = 1.0/3 * y0 + 2.0/3 * y1;
    x4 = 1.0/2 * (x0 + x1) - sqrt(3.0)/6 * (y1 - y0);
    y4 = 1.0/2 * (y0 + y1) + sqrt(3.0)/6 * (x1 - x0);
    if( k > 1)    /*���������������1���ͼ���������ȥ����ִ�����³���*/
    {
        koch(x0, y0, x2, y2, k - 1);  /*����(x0, y0)��(x2, y2)Ϊ�˵���߶���Ϊ
        ��ʼ�߶ν��е������㣬������ͬ*/
        koch(x2, y2, x4, y4, k - 1);
        koch(x4, y4, x3, y3, k - 1);
        koch(x3, y3, x1, y1, k - 1);
    } else {      /*���������������1��ֹͣ�����������������ɵ�ͼ��*/
        line(x0, y0, x2, y2);       /*��ֱ����������(x0, y0)��(x2, y2)*/
        line(x2, y2, x4, y4);       /*��ֱ����������(x2, y2)��(x4, y4)*/
        line(x4, y4, x3, y3);       /*��ֱ����������(x4, y4)��(x3, y3)*/
        line(x3, y3, x1, y1);       /*��ֱ����������(x3, y3)��(x1, y1)*/
    }
}

int main()
{
    int n, gdriver = DETECT, gmode;      /*�����������n*/
    initgraph(&gdriver, &gmode,"C:\\Win-TC\\BGI");     /*ͼ��ϵͳ��ʼ��*/
    printf("Please input the value of the positive integer n (n<9):");
    scanf("%d", &n);               /*�����������n*/
    setcolor(GREEN);
    koch(50, 120, 450, 120, n);
    getch();
    closegraph(); /*�ر�ͼ��ϵͳ*/
    return 0;
}
