#include <gl/glut.h>

#include "camera.h"
#include "lighting.h"
#include "robot.h"
#include "runner.h"
#include "texture.h"


void Runner::start() {
	createWindow();
	Lighting::initLighting();
	Texture::initTextures();
	registerCallbacks();
}

void Runner::createWindow() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);

	glClearColor(BACKGROUND_COLOR_RGBA);
}


void Runner::registerCallbacks() {
	glutDisplayFunc(display);
	glutReshapeFunc(resizeWindow);
	glutKeyboardFunc(readKeyboard);
	glutSpecialFunc(readSpecialKeyboard);
	glutMouseFunc(readMouse);
}

void Runner::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera.prepareProjection();
	robot.draw();

	glutSwapBuffers();
}


void Runner::resizeWindow(GLsizei w, GLsizei h) {
	glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT); // Volta sempre ao tamanho original
}

void Runner::readKeyboard(unsigned char key, int x, int y) {
	if (key == ESC_KEY) {
		exit(0);
	} else if (key == 'l') {
		Lighting::toggleLighting(key);
	} else if (robot.isMovementKey(key)) {
		robot.move(key);
	}
}

void Runner::readSpecialKeyboard(int key, int x, int y) {
	if (camera.isMovementKey(key)) {
		camera.move(key);
	} 
}

void Runner::readMouse(int button, int state, int x, int y) {
	if (camera.isMovementKey(button) && state == GLUT_DOWN) {
		camera.move(button);
	} 
}

