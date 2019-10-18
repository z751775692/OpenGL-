#include <GLTools.h>	
#include <math.h>
#include <GL/glu.h>
#ifdef _WIN32
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

static float year=0,day=0,plant=0;
static float angle1=0,angle2=0;

void init(void);
void change_size(int w,int h);
void display(void);
void keyboard(unsigned char key,int x,int y);

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("巩固复习");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(change_size);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(display);
	glutMainLoop();

	return 0;
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void change_size(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLdouble)w/(GLdouble)h,1.0,20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,4.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
}
void display(void)
{
	year+=0.05;
	year=year>360 ? 0 : year;
	day+=0.1;
	day=day>360 ? 0 : day;
	plant+=0.01;
	plant=plant>360 ? 0 : plant;

	GLfloat position[]={8.0,8.0,1.5,1.0};
	GLfloat am[]={1.0,0.8,0.4,1.0};
	GLfloat mat[]={0.3,0.6,0.1,1.0};
	//启动光照
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glLightfv(GL_LIGHT0,GL_AMBIENT,am);
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);
	//绘制图形
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.5,0.5);
	glPushMatrix();	
	glRotatef((GLfloat)angle1,1,0,0);	//用于控制所绘制整体模型的旋转
	glRotatef((GLfloat)angle2,0,0,1);
	glPushMatrix();
	glRotatef((GLfloat)plant,0.0,1.0,0.0);	//恒星的自转
	glutSolidSphere(1.0,70,70);		//恒星绘制
	glPushMatrix();	
	glRotatef(90,1.0,0.0,0.0);		//使星环旋转90度
	glutSolidTorus(0.05,2.0,30,50);	//绘制星环
	glPopMatrix();
	glRotatef((GLfloat)year,0.0,1.0,0.0);	//控制行星公转(加速)
	glTranslatef(2.0,0.0,0.0);	
	glRotatef((GLfloat)day,0.0,1.0,0.0);	//控制行星自转
	glutSolidSphere(0.2,50,50);		//绘制行星
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y)	//键盘事件
{
	switch(key)
	{
	case 'w':
		angle1+=2;
		angle1=angle1>360 ? 0 : angle1;
		glutPostRedisplay();
		break;
	case 's':
		angle1-=2;
		angle1=angle1>360 ? 0 : angle1;
		glutPostRedisplay();
		break;
	case 'a':
		angle2+=2;
		angle2=angle2>360 ? 0 : angle2;
		glutPostRedisplay();
		break;
	case 'd':
		angle2-=2;
		angle2=angle2>360 ? 0 : angle2;
		glutPostRedisplay();
		break;
	default:
		break;
	}
		
}
