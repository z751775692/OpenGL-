#include <iostream>
#include <GLTools.h>
#include <GLShaderManager.h>
#ifdef _WIN32
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

float angle;
float color1,color2,color3;

void sphere_entry(int du, int dv){

	float gu = 3.1415926535 / du , gv = 2.0*3.1415926535 / (dv-1);

	float x, y, z ,r ;

	glPushMatrix();
#define MAKE_R(z2) sqrt(1.0 - (z2))
#define MAKE_Z(z_step) cos((z_step) *gu)
#define MAKE_Y(x_step,r) (r)*sin((x_step)* gv)
#define MAKE_X(x_step,r) (r)*cos((x_step)* gv)
	// ����
	glBegin(GL_QUADS);
	for (int z_step = 0 ; z_step < du; ++z_step) {
		for (int x_step = 0; x_step < dv; ++x_step) {

			z = MAKE_Z(z_step);
			r = MAKE_R(z*z);
			x = MAKE_X(x_step, r);
			y = MAKE_Y(x_step, r);
			glVertex3f(x, y, z);

			z = MAKE_Z(z_step+1);
			r = MAKE_R(z*z);
			x = MAKE_X(x_step, r);
			y = MAKE_Y(x_step, r);
			glVertex3f(x, y, z);

			z = MAKE_Z(z_step + 1);
			r = MAKE_R(z*z);
			x = MAKE_X(x_step + 1,r);
			y = MAKE_Y(x_step+1, r);
			glVertex3f(x, y, z);

			z = MAKE_Z(z_step);
			r = MAKE_R(z*z);
			x = MAKE_X(x_step + 1,r);
			y = MAKE_Y(x_step + 1, r);
			glVertex3f(x, y, z);
		}
	}
	glEnd();
#undef MAKE_Y
#undef MAKE_Z
#undef MAKE_X
#undef MAKE_R
	glPopMatrix();
}

void changed_size(int w, int h) {
	// �޸��Ӵ�size
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);	//ͶӰ�任
	glLoadIdentity();				
	gluPerspective(45.0f, double(w) / double(h), 1.0f, 10.0f);	//ͬglFrustum()����

	glMatrixMode(GL_MODELVIEW);		//ģ���ӽ�
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 5.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);		//��ͼ�任
}

// ��ʼ����Ⱦ����
void setup_rc() {
	// ��ɫ����
	glClearColor(0,0,0,1.f);
	angle = 0.0f;
	color1=color2=color3=0.0f;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

// ��Ⱦ
void render(void) {
	// �����ɫ���塢��Ȼ��塢ģ�建��
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3f(color1,color2,color3);

	color1 = sin(3.1415926*(angle+2)/360);
	color2 = cos(3.1415926*(angle+8)/360);
	color3 = sin(2*3.1415926*(angle+16)/360);

	glLoadIdentity();	//�ѵ�ǰ��������Ϊ��λ����
	glTranslatef(0.0f, 0.0f, -5.0f);	//�ƶ�--ģ�ͱ任
	glRotatef(angle, 0.0f, 2.0f, 1.0f);	//��ת--ģ�ͱ任

	sphere_entry(32,32);

	angle += .02f;
	angle = angle > 360.0f ? 0.0f : angle;

	// ����������
	glutSwapBuffers();
}

int main(int argc, char**argv) {

	gltSetWorkingDirectory(*argv);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL--��һ����");

	glutReshapeFunc(changed_size);

	glutDisplayFunc(render);
	glutIdleFunc(render);
	setup_rc();

	glutMainLoop();
	return 0;
}
