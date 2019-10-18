#include <GL/glew.h>
#include <GL/freeglut.h>

//static GLuint sphereList,cubeList;

static float angle=0.0f;

static void init(void)
{
	GLfloat mat_specular[]={1.0,1.0,1.0,0.15};
	GLfloat mat_shininess[]={100.0};
	GLfloat position[]={0.5,0.5,1.0,0.0};

	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	//�����ĳ�ַ�����û��ʹ��
	//sphereList=glGenLists(1);
	//glNewList(sphereList,GL_COMPILE);
	//	glutSolidSphere(0.4,16,16);
	//glEndList();

}

void display(void)
{
	GLfloat mat_solid[]={0.75,0.75,0.0,1.0};	//���ϲ���
	GLfloat mat_zero[]={0.0,0.0,0.0,1.0};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(angle,0.0,1.0,0.0);	//��ת

	//�Ȼ��Ʋ�͸������
	glPushMatrix();
	glTranslatef(0.0,0.0,-0.5);
	glMaterialfv(GL_FRONT,GL_EMISSION,mat_zero);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);
	glutSolidSphere(0.5,50,100);
	glPopMatrix();

	//�ٻ��ư�͸����������
	glPushMatrix();
	glTranslatef(0.0,0.0,0.5);
	glEnable(GL_BLEND);				//�������
	glDisable(GL_LIGHTING);			//�رչ���
	glDepthMask(GL_FALSE);			//��Ȼ���������Ϊֻ��ģʽ
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);	//���û��ģʽ
	glBegin(GL_POLYGON);
		glColor4f(0.2,0.6,0.8,0.75);
		glVertex3f(-0.7,0.7,0.0);
		glVertex3f(0.7,0.7,0.0);
		glVertex3f(0.7,-0.7,0.0);
		glVertex3f(-0.7,-0.7,0.0);
	glEnd();
	glDepthMask(GL_TRUE);	//�ָ���Ȼ�����
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w,int h)
{
	angle += 0.04f;
	angle=angle>360?0:angle;

	glViewport(0,0,(GLfloat)w,(GLfloat)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,2.5,0.0,0.0,0.0,0.0,1.0,0.0);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("���3D");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}
