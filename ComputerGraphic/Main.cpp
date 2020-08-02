#include<iostream>
#include<Windows.h>
#include<GL/glew.h>
#include<GL/glut.h>

using namespace std;

float x_float = -0.5f, interval = 0.1f;

void display() {
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
		glVertex2f(x_float, -0.5f); glVertex2f(x_float +1.0f, -0.5f);
		glVertex2f(x_float + 1.0f, 0.5f); glVertex2f(x_float, 0.5f);
	glEnd();

	glFlush();

	//cout << "flushed" << endl;
}

void keyPressed(unsigned char key, int x, int y) {
	cout << key << endl;
}

void specialPressed(int key, int x, int y) {
	cout << "special:" << key << endl;
	if (key == 101) {
		if (x_float > 0.0f || x_float < -0.5f) interval *= -1;
		x_float += interval;
		cout << x_float << endl;
	}
}

void timerTicked(int value) {
	glutPostRedisplay();
	glutTimerFunc(100, timerTicked, 0);
}

int main(int argcp, char** argv) {
	glutInit(&argcp, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(400, 250);
	glutCreateWindow("title here");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(specialPressed);

	glutTimerFunc(0, timerTicked, 0);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glutMainLoop();
}