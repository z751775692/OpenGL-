#include <GL/glew.h>
#include <GL/freeglut.h> 
#pragma comment(lib,"glew32.lib")

void Init()
{
    glClearColor(1.0, 1.0, 0.0, 0.0) ;
    glBlendFunc(GL_ONE, GL_ONE) ;
    glEnable(GL_BLEND) ;
} 

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT) ;
    glColor3f(0.0, 0.0, 1.0) ;
    glRectf(-0.5, -0.5, 0.5, 0.5) ;
    glFlush() ;
} 

void Reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h) ;
    glMatrixMode(GL_PROJECTION) ;
    glLoadIdentity() ;
    if(w <= h)
        glOrtho(-1.0, 1.0, -1.0*(GLfloat)h/(GLfloat)w,
        1.0*(GLfloat)h/(GLfloat)w, -10.0, 10.0) ;
    else
		glOrtho(-1.0*(GLfloat)w/(GLfloat)h,
		1.0*(GLfloat)w/(GLfloat)h, -1.0, 1.0, -10.0, 10.0) ;
    glMatrixMode(GL_MODELVIEW) ;
    glLoadIdentity() ;
}

void Keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
		case 'a':
		glBlendEquation(GL_FUNC_ADD) ;
		break ;
		case 's':
		glBlendEquation(GL_FUNC_SUBTRACT) ;
		break ;
		case 'd':
		glBlendEquation(GL_FUNC_REVERSE_SUBTRACT) ;
		break;
		case 'f':
		glBlendEquation(GL_MIN) ;
		break ;
		case 'g':
		glBlendEquation(GL_MAX) ;
		break ;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)

{       
    glutInit(&argc, argv) ;
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB) ;
    glutInitWindowSize(800, 600) ;
    glutCreateWindow("Blend") ;
    glewInit();
    Init() ;
    glutReshapeFunc(Reshape) ;
    glutKeyboardFunc(Keyboard) ;
    glutDisplayFunc(Display) ;
    glutMainLoop() ;
    return 0 ;
}