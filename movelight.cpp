#include <iostream>
#include <GLTools.h>	// OpenGL toolkit
#include <GLMatrixStack.h>
#include <GLFrame.h>
#include <GLFrustum.h>
#include <GLBatch.h>
#include <GLGeometryTransform.h>
#include <GL/glu.h>
#include <GLShaderManager.h>
#ifdef _WIN32
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

float spin = 0.0f;
float color1,color2,color3;

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	spin+=0.05f;
	spin = spin > 360.0f ? 0.0f : spin;

	color1 = cos(3.1415926*(spin+2)/360);
	color2 = cos(3.1415926*(spin+4)/360);
	color3 = cos(2*3.1415926*(spin+6)/360);

	GLfloat position[]={0.0,0.0,1.5,1.0};
	GLfloat am[]={color1,color2,color3,1.0};
	GLfloat mat[]={0.3,0.6,0.1,1.0};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glTranslatef(0.0,0.0,-6.0);		//模型沿z轴负方向位移

	glPushMatrix();
	//glTranslatef(spin,0.6,0);		//平移光源
	glRotated((GLdouble)spin,1.0,1.0,1.0);	//小立方体所在视图（包括光源（下一句））移动方向
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glLightfv(GL_LIGHT0,GL_AMBIENT,am);
	//glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat);
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);

	glTranslated(0.0,0.0,1.5);
	glDisable(GL_LIGHTING);
	glColor3f(0.0,1.0,1.0);	//指定立方体颜色
	glutWireCube(0.1);		//绘制立方体
	glEnable(GL_LIGHTING);	//启动灯光
	glPopMatrix();

	glutSolidSphere(1,50,50);
	//glutSolidTeapot(0.7);
	//glutSolidTorus(0.275,0.85,20,15);
	glPopMatrix();
	glutSwapBuffers();		//交换缓冲区
}

void reshape(int w, int h) {
	
	//GLfloat position[]={0.0,0.0,1.5,1.0};
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();		
	gluPerspective(40.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);		
	glLoadIdentity();
	//glLightfv(GL_LIGHT0,GL_POSITION,position);
}

void mouse(int button,int state,int x,int y)
{
	switch(button){
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
		{
			spin+=0.01f;
			spin = spin > 360.0f ? 0.0f : spin;
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
}

int main(int argc, char**argv) {

	gltSetWorkingDirectory(*argv);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL--移动光源");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}