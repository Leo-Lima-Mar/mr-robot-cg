#include <math.h>
#include <gl/glut.h>

#include "camera.h"

Camera::Camera() {
	horizontalAngle = 0.0;
	verticalAngle = PI/8.0;
	radius = 17.0;
}

void Camera::prepareProjection() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(FRUSTUM_SPACE);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( // Câmera utilizando coordenadas polares
		cos(verticalAngle) * cos(horizontalAngle) * radius,
		sin(verticalAngle) * radius + 2.0, // 2.0 é a altura do centro do corpo robô (altura mínima do eye)
		cos(verticalAngle) * sin(horizontalAngle) * radius,
		LOOK_AT_CENTER_XYZ,
		LOOK_AT_UP_XYZ);
}

bool Camera::isMovementKey(int key) {
	return key == GLUT_KEY_UP || key == GLUT_KEY_DOWN // Movimento vertical
		|| key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT // Movimento horizontal
		|| key == GLUT_KEY_PAGE_UP || key == GLUT_KEY_PAGE_DOWN // Zoom através do teclado
		|| key == SCROLL_UP || key == SCROLL_DOWN; // Zoom através do mouse
}

void Camera::move(int key) {
	if (key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT) {
		setHorizontalAngle(key);
	} else if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN) {
		setVerticalAngle(key);
	} else if (key == GLUT_KEY_PAGE_UP || key == GLUT_KEY_PAGE_DOWN || key == SCROLL_UP || key == SCROLL_DOWN) {
		setRadius(key);
	}
}


void Camera::setHorizontalAngle(int key) {
	if (key == GLUT_KEY_LEFT) {
		horizontalAngle += HORIZONTAL_ANGLE_CHANGE_SPEED;
	} else if (key == GLUT_KEY_RIGHT) {
		horizontalAngle -= HORIZONTAL_ANGLE_CHANGE_SPEED;
	}
}

void Camera::setVerticalAngle(int key) {
	if (key == GLUT_KEY_UP && verticalAngle < MAX_BETA) {
		verticalAngle += VERTICAL_ANGLE_CHANGE_SPEED;
	} else if (key == GLUT_KEY_DOWN && verticalAngle >= MIN_BETA) {
		verticalAngle -= VERTICAL_ANGLE_CHANGE_SPEED;
	}
}

void Camera::setRadius(int key) {
	if ((key == GLUT_KEY_PAGE_DOWN || key == SCROLL_DOWN) && radius < MAX_RADIUS) {
		radius += RADIUS_CHANGE_SPEED;
	} else if ((key == GLUT_KEY_PAGE_UP || key == SCROLL_UP) && radius >= MIN_RADIUS) {
		radius -= RADIUS_CHANGE_SPEED;
	}
}
