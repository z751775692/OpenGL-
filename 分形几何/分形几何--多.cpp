#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<conio.h>
#include<graphics.h>

#define PI 3.1415926
#define stacksize 1024

typedef struct _point {
    double x;
    double y;
    double delta;
}point;

typedef struct _L_Sys {
    char *name;
    char *startStr; /* 初始字符串 */
    char *replaceF;
    char *replaceX;  /* 替换X字符串 */
    char *replaceY;  /* 替换Y字符串 */
    char *replaceS;  /* 替换S字符串 */
    char *replaceG;  /* 替换G字符串 */
    char *replaceK;  /* 替换K字符串 */
    char *replaceL;  /* 替换L字符串 */
    char *replaceH;  /* 替换H字符串 */
    int StartX;  /* 起始点坐标 */
    int StartY;
    int depth;   /* 递归深度 */
    int ruleNumber;  /* 规则数 */
    double angle;
    double direct_init;
    double length;

}L_Sys;

L_Sys ls[100];

void init_L_Sys(L_Sys *LS, char *_name, char *_startStr, char *_replaceF,
        char *_replaceX, char *_replaceY, char *_replaceS, char *_replaceG,
        char *_replaceK, char *_replaceL, char *_replaceH,  int _StartX,
        int _StartY, int _depth, int _ruleNumber, double _angle,
        double _direct_init, double _length)    /* 初始化 */
{
    (*LS).name = (char *)malloc(strlen(_name) + 1);
    if((*LS).name == NULL) return;
    strcpy((*LS).name, _name);
    (*LS).startStr = (char *)malloc(strlen(_startStr) + 1);
    if((*LS).startStr == NULL) return;
    strcpy((*LS).startStr, _startStr);
    (*LS).replaceF = (char *)malloc(strlen(_replaceF) + 1);
    if((*LS).replaceF == NULL) return;
    strcpy((*LS).replaceF, _replaceF);
    (*LS).replaceX = (char *)malloc(strlen(_replaceX) + 1);
    if((*LS).replaceX == NULL) return;
    strcpy((*LS).replaceX, _replaceX);
    (*LS).replaceY = (char *)malloc(strlen(_replaceY) + 1);
    if((*LS).replaceY == NULL) return;
    strcpy((*LS).replaceY, _replaceY);
    (*LS).replaceS = (char *)malloc(strlen(_replaceS) + 1);
    if((*LS).replaceS == NULL) return;
    strcpy((*LS).replaceS, _replaceS);
    (*LS).replaceG = (char *)malloc(strlen(_replaceG) + 1);
    if((*LS).replaceG == NULL) return;
    strcpy((*LS).replaceG, _replaceG);
    (*LS).replaceK = (char *)malloc(strlen(_replaceK) + 1);
    if((*LS).replaceK == NULL) return;
    strcpy((*LS).replaceK, _replaceK);
    (*LS).replaceL = (char *)malloc(strlen(_replaceL) + 1);
    if((*LS).replaceL == NULL) return;
    strcpy((*LS).replaceL, _replaceL);
    (*LS).replaceH = (char *)malloc(strlen(_replaceH) + 1);
    if((*LS).replaceH == NULL) return;
    strcpy((*LS).replaceH, _replaceH);
    (*LS).StartX = _StartX;
    (*LS).StartY = _StartY;
    (*LS).depth = _depth;
    (*LS).ruleNumber = _ruleNumber;
    (*LS).angle = _angle;
    (*LS).direct_init = _direct_init;
    (*LS).length = _length;
}

void init(int n)
{
 /*init_L_Sys(&ls[i], "hualei", "Start", "F", "X", "Y", "S", "G", "K", "L", "H",
        pStartX, pStartY, depth, ruleNumber, angle, direct_init, length);          */
    switch(n) {
    case 0:
        init_L_Sys(&ls[0], "xiecao", "G", "F-XF", "", "", "",
            "GFX[+++++GFG][-----GFG]", "", "", "", 340, 20, 6, 2, -3, 60, 3.3);
        break;
    case 1:
        init_L_Sys(&ls[1], "shusan", "X", "FF", "--FXF++FXF++FXF--", "", "",
            "", "", "", "", 200, 50, 6, 2, -60, 0, 6);
        break;
    case 2:
        init_L_Sys(&ls[2], "hualei", "F", "F[+F[+F][-F]F][-F[+F][-F]F]F[+F][-F]F",
         "", "", "", "", "", "", "", 200, 20, 5, 1, 30, 90, 6);
        break;
    case 3:
        init_L_Sys(&ls[3], "shuzhi", "K", "", "", "", "[+++G][---H]FFS",
        "G+G[-FH]F", "FSF", "", "-H[+FG]F",
        200, 210, 13, 4, -18, -90, 9.5);
        break;
    case 4:
        init_L_Sys(&ls[4], "shuzhi", "F", "F[+F]F[-F]F", "", "", "",
        "", "", "", "",
        200, 5, 6, 1, -25.7341, 90, 1.5);
        break;
    case 5:
        init_L_Sys(&ls[5], "korch", "F", "F[+F]F[-F]F", "", "", "",
        "", "", "", "",
        200, 5, 6, 1, -25.7341, 90, 1.5);
        break;    
    case 6:
        init_L_Sys(&ls[6], "pugongying", "Y", "", "X[-FFF][+FFF]FX",
        "YFX[+Y][-Y]", "", "", "", "", "",
        200, 10, 10, 2, 30, 90, 0.37);
        break;    
    case 7:
        init_L_Sys(&ls[7], "guanmucong", "F", "FF-[-F+F+F]+[+F-F-F]", "", "",
         "", "", "", "", "",
        250, 20, 6, 1, -30, 90, 3.5);
        break;    

    case 8:
        init_L_Sys(&ls[8], "kaihuadecao", "G", "", "XFX", "", "",
        "[+FGF][-FGF]XG", "", "", "",
        200, 10, 8, 2, -30, 90, 3);
        break;
    case 9:
        init_L_Sys(&ls[9], "guanmucong2", "F",
        "F[+++++++++++++++++++++++++F]-F[-------------------------F]F", "", "",
        "", "", "", "", "",
        370, 30, 6, 1, -1.2, 90, 2);
        break;
    case 10:
        init_L_Sys(&ls[10], "yangliu", "F", "FF+[+F-F-F]-[-F+F+F]", "", "",
        "", "", "", "", "", 170, 0, 5, 1, -22.5, 90, 7);
        break;
    case 11:
        init_L_Sys(&ls[11], "Juliet", "X", "", "X+YF+", "-FX-Y", "", "", "", "", "",
        95, 250, 17, 2, 90, 0, 1);
    case 12:
        init_L_Sys(&ls[12], "zhuanqiang", "X", "", "XFYFX+F+YFXFY-F-XFYF",
         "YFXFY-F-XFYFX+F+YFXFY", "", "", "", "", "",
        30, 40, 4, 2, 90, 0, 13);
        break;
    case 13:
        init_L_Sys(&ls[13], "zhuanqiang_X", "F+F+F+F", "F+F-F-FF+F+F-F", "",
         "", "", "", "", "", "",
        80, 90, 4, 1, 90, 0, 3.5);
        break;
    case 14:
        init_L_Sys(&ls[14], "sanjiaoraosanjiao", "X", "FFF", "--FXF++FXF++FXF--",
         "", "", "", "", "", "",
        200, 10, 6, 2, -60, 0, 1.7);
        break;
    case 15:
        init_L_Sys(&ls[15], "yibimigong", "X", "", "-YF+XFX+FY-", "+XF-YFY-FX+",
         "", "", "", "", "",
        50, 30, 6, 2, -90, 0, 10);
    case 16:
        init_L_Sys(&ls[16], "shu", "X", "FF", "F[+X]F[-X]+X", "", "", "", "", "", "",
        200, 10, 10, 2, 30, 90, 0.35);
    case 17:
        init_L_Sys(&ls[17], "duichengdeshu", "X", "FF", "F[+X][-X]FX", "", "",
        "", "", "", "",
        200, 10, 10, 2, 30, 90, 0.35);
        break;
    default:
        break;
    }
    return;

}

void freeMemory(L_Sys *LS)  /* 释放内存 */
{
    free((*LS).name);
    (*LS).name = NULL;
    free((*LS).startStr);
    (*LS).startStr = NULL;
    free((*LS).replaceF);
    (*LS).replaceF = NULL;
    free((*LS).replaceX);
    (*LS).replaceX = NULL;
    free((*LS).replaceY);
    (*LS).replaceY = NULL;
    free((*LS).replaceS);
    (*LS).replaceS = NULL;
    free((*LS).replaceG);
    (*LS).replaceG = NULL;
    free((*LS).replaceK);
    (*LS).replaceK = NULL;
    free((*LS).replaceL);
    (*LS).replaceL = NULL;
    free((*LS).replaceH);
    (*LS).replaceH = NULL;
}

void fileCopy(FILE *dest, FILE *src) /* 复制文件函数 */
{
    char ch;
    fseek(src, 0, SEEK_SET);
    ch = fgetc(src);
    while(ch != EOF) {
        fputc(ch, dest);
        ch = fgetc(src);
    }
}

void fractal(int curr_string)  /* 核心功能函数 */
{
    int i, j, k, size, depth, len;
    char a[2], ch;
    double Delta;
    FILE *result, *tmp;
    point stack[stacksize];
    point *p;
    point bef, aft;

    tmp = fopen("B.txt","w+");
    if(tmp == NULL) return;
    init(curr_string);
    p = stack;
    fputs(ls[curr_string].startStr, tmp);
    depth = ls[curr_string].depth;
    len =  ls[curr_string].length;
    for(i = 0; i < depth; i++) {
        result = fopen("A.txt","w+");
        if(result == NULL) return;

        fseek(tmp, 0, SEEK_SET);
        ch = fgetc(tmp);
        while(ch != EOF) {      /* F X Y S G K L H*/
            if(ch == 'F') {
                fputs(ls[curr_string].replaceF, result);
            } else if (ch == 'X') {
                fputs(ls[curr_string].replaceX, result);
            } else if (ch == 'Y') {
                fputs(ls[curr_string].replaceY, result);
            } else if (ch == 'S') {
                fputs(ls[curr_string].replaceS, result);
            } else if (ch == 'G') {
                fputs(ls[curr_string].replaceG, result);
            } else if (ch == 'K') {
                fputs(ls[curr_string].replaceK, result);
            } else if (ch == 'L') {
                fputs(ls[curr_string].replaceL, result);
            } else if (ch == 'H') {
                fputs(ls[curr_string].replaceH, result);
            } else {
                fputc(ch, result);
            }
            ch = fgetc(tmp);
        }
       fseek(tmp, 0, SEEK_SET);
       fileCopy(tmp, result);
       fclose(result);
    }
    bef.x = ls[curr_string].StartX;
    bef.y = ls[curr_string].StartY;

    bef.delta = PI * (ls[curr_string].angle)/180;
    Delta = PI * (ls[curr_string].angle)/180;   /* 转换为弧度制 */

    result = fopen("A.txt","r");
    fseek(result, 0, SEEK_SET);
    ch = fgetc(result);
    while(ch != EOF) {

        switch(ch) {
        case 'F':
        case 'X':
        case 'Y':
        case 'S':
        case 'G':
        case 'K':
        case 'L':
        case 'H':
            aft.x = bef.x + len * cos(bef.delta);
            aft.y = bef.y - len * sin(bef.delta);
            aft.delta = bef.delta;
            line(bef.x, 400 - bef.y, aft.x, 400 - aft.y);

            bef.x = aft.x;
            bef.y = aft.y;
            bef.delta = aft.delta;
            break;
        case '+':
            bef.delta += Delta;
            break;
        case '-':
            bef.delta -= Delta;
            break;
        case '[':
            *(p++) = bef;
            break;
        case ']':
            bef = *(--p);
            break;
        default:
            break;
        }
        ch = fgetc(result);
    }
    fclose(tmp);
    fclose(result);
    freeMemory(&ls[curr_string]);
}

int main(void)
{
    char ch;
    int n, gdriver = DETECT, gmode;
    wu:
    printf("xiecao:0  shusan:1  hualei:2  shuzhi1:3  shuzhi2:4\n");   /* 说明 */
    printf("korch:5  pugongying:6  guanmucong:7  kaihuadecao:8  guanmucong2:9\n");
    printf("yangliu:10  Juliet:11  zhuanqiang:12  zhuanqiang_X:13  sanjiaoraosanjiao:14\n");
    printf("yibimigong:15  shu:16  duichengdeshu:17\n");
    printf("guanmucong2:9\n");
    printf("continue?(Y/N)\n");
    ch = getchar();
    if(ch == 'n' || ch == 'N')
        return 0;
    else {
        printf("please input a non-negative number to choose which image you what to see(0 <= n <= 17 ): ");
        scanf("%d", &n);

        initgraph(1000,800);  /*图形系统初始化*/
        setcolor(GREEN);  /* 设置画笔的颜色 */
        fractal(n);
        getch();
        closegraph();  /*关闭图形系统*/
        getchar();
        goto wu;
    }
    return 0;
}