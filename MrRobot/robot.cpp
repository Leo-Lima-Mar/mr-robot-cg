#include <math.h>
#include <gl/glut.h>

#include "robot.h"
#include "texture.h"

Robot::Robot() {
	xCoord = 0.0;
	zCoord = 0.0;
	rotationAngle = 0.0;

	armHorizontalAngle = 0.0;
	armVerticalAngle = 0.0;
	armJunctionAngle = 0.0;
	clawOpeningAngle = 5.0;
}


void Robot::draw() {
	drawPlatform();
	drawRobot();
}


void Robot::drawPlatform() {
	glPushMatrix();
		drawSupportPillar();
		drawFloor();
	glPopMatrix();
}

void Robot::drawSupportPillar() {
	glPushMatrix(); // Pilar com largura 20x20 e altura 100
		glColor3f(PLATFORM_COLOR_RGB);
		glTranslatef(0.0, -50.01, 0.0); // 0.01 a menos para não sobrepor com a textura
		glScalef(1.0, 5.0, 1.0);
		glutSolidCube(20.0); 
	glPopMatrix();
}

void Robot::drawFloor() {
	Texture::setTexture(Texture::woodTexture);
	glBegin(GL_QUADS); // Quadrado 20x20 com piso de madeira no plano XZ
		glTexCoord2f(10.0, 10.0); glVertex3f(-10.0, 0.0, -10.0);
		glTexCoord2f(0.0, 10.0); glVertex3f(10.0, 0.0, -10.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(10.0, 0.0, 10.0);
		glTexCoord2f(10.0, 0.0); glVertex3f(-10.0, 0.0, 10.0);
	glEnd();
}


void Robot::drawRobot() {
	glPushMatrix();
		drawBody();
		drawArm();
	glPopMatrix();
}


void Robot::drawBody() {
	glPushMatrix();
		glTranslatef(xCoord, 1.0, zCoord); // Ajusta a posição do corpo no plano XZ
		setBodyRotation(); // Gira o robô em relação ao eixo Y e ajusta posição da textura

		glColor3f(ROBOT_COLOR_RGB);
		Texture::setTexture(Texture::voltorbTexture);
		gluSphere(Texture::quad, 1.0, 100.0, 100.0);

		glLoadIdentity();
	glPopMatrix();
}

void Robot::setBodyRotation() {
	glRotatef(rotationAngle, Y_AXIS);

	// Ajustando posicionamento da textura do voltorb
	glRotatef(70.0, Y_AXIS);
	glRotatef(235.0, X_AXIS);
	glRotatef(-10.0, Z_AXIS);
}


void Robot::drawArm() {
	glTranslatef(xCoord, 2.0, zCoord); // Andar junto com o corpo
	glRotatef(rotationAngle, Y_AXIS); // Girar junto com o corpo

	drawArmBodyJunction();
	drawArmMainJunction();
	drawArmFirstBar();
	drawArmSecondJunction();
	drawArmSecondBar();
	drawHand();
}

void Robot::drawArmBodyJunction() {
	glTranslatef(0.0, 0.5, 0.0);
	glRotatef(90.0, X_AXIS);

	Texture::setTexture(Texture::metal1Texture);
	gluCylinder(Texture::quad, 0.2, 0.2, 0.5, 20.0, 20.0);
	glRotatef(-90.0, X_AXIS);
}

void Robot::drawArmMainJunction() {
	Texture::setTexture(Texture::metal2Texture);
	gluSphere(Texture::quad, 0.3, 20.0, 20.0);

	glRotatef(armHorizontalAngle, Y_AXIS);
	glRotatef(armVerticalAngle, Z_AXIS);
}

void Robot::drawArmFirstBar() {
	glTranslatef(0.0, 1.5, 0.0);
	glRotatef(90.0, X_AXIS);

	Texture::setTexture(Texture::metal1Texture);
	gluCylinder(Texture::quad, 0.2, 0.2, 1.5, 20.0, 20.0);
}

void Robot::drawArmSecondJunction() {
	Texture::setTexture(Texture::metal2Texture);

	glRotatef(armJunctionAngle, Y_AXIS);

	gluSphere(Texture::quad, 0.3, 30.0, 30.0);
}

void Robot::drawArmSecondBar() {
	glRotatef(-90.0, X_AXIS);
	glRotatef(90.0, Y_AXIS);

	Texture::setTexture(Texture::metal1Texture);
	gluCylinder(Texture::quad, 0.2, 0.2, 1.5, 20.0, 20.0);
}


void Robot::drawHand() {
	glTranslatef(0.0, 0.0, 1.5);
	glRotatef(90.0, Z_AXIS);

	Texture::setTexture(Texture::metal2Texture);
	gluSphere(Texture::quad, 0.3, 30.0, 30.0);

	drawClaws();
}

void Robot::drawClaws() {
	Texture::setTexture(Texture::infiniteMirrorSpaceTexture);

	drawFirstClaw();
	drawSecondClaw();
}

void Robot::drawFirstClaw() {
	glRotatef(-clawOpeningAngle, X_AXIS);
	glTranslatef(0.0, 0.1, 0.0);

	gluCylinder(Texture::quad, 0.1, 0.0, 1.0, 20.0, 20.0);
}

void Robot::drawSecondClaw() {
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(2.0 * clawOpeningAngle, X_AXIS);
	glTranslatef(0.0, -0.1, 0.0);

	gluCylinder(Texture::quad, 0.1, 0.0, 1.0, 20.0, 20.0);
}



bool Robot::isMovementKey(unsigned char key) {
	return key == 'w' || key == 'a' || key == 's' || key == 'd' // Movimento do robô
		|| key == 'q' || key == 'e'	// Giro do robô
		|| key == '8' || key == '2' || key == '4' || key == '6' // Movimento da primeira haste
		|| key == '7' || key == '1' // Movimento da segunda haste
		|| key == '+' || key == '-'; // Movimento da pinça
}

void Robot::move(unsigned char key) {
	if (key == 'w' || key == 's') {
		setXCoord(key);
	} else if (key == 'a' || key == 'd') {
		setZCoord(key);
	} else if (key == 'q' || key == 'e') {
		setRotationAngle(key);
	} else if (key == '4' || key == '6') {
		setArmHorizontalAngle(key);
	} else if (key == '8' || key == '2') {
		setArmVerticalAngle(key);
	} else if (key == '1' || key == '7') {
		setArmJunctionAngle(key);
	} else if (key == '+' || key == '-') {
		setClawOpeningAngle(key);
	}
}

void Robot::setXCoord(int key) {
	if (key == 's' && xCoord < MAX_X_COORD) {
		xCoord += COORD_CHANGE_SPEED;
	} else if (key == 'w' && xCoord >= MIN_X_COORD) {
		xCoord -= COORD_CHANGE_SPEED;
	}
}

void Robot::setZCoord(int key) {
	if (key == 'a' && zCoord < MAX_Z_COORD) {
		zCoord += COORD_CHANGE_SPEED;
	} else if (key == 'd' && zCoord >= MIN_Z_COORD) {
		zCoord -= COORD_CHANGE_SPEED;
	}
}

void Robot::setRotationAngle(int key) {
	if (key == 'e') {
		rotationAngle += ANGLE_CHANGE_SPEED;
	} else if (key == 'q') {
		rotationAngle -= ANGLE_CHANGE_SPEED;
	}
}

void Robot::setArmHorizontalAngle(int key) {
	if (key == '6') {
		armHorizontalAngle += ANGLE_CHANGE_SPEED;
	} else if (key == '4') {
		armHorizontalAngle -= ANGLE_CHANGE_SPEED;
	}
}

void Robot::setArmVerticalAngle(int key) {
	if (key == '8' && armVerticalAngle < MAX_VERTICAL_ANGLE) {
		armVerticalAngle += ANGLE_CHANGE_SPEED;
	} else if (key == '2' && armVerticalAngle >= MIN_VERTICAL_ANGLE) {
		armVerticalAngle -= ANGLE_CHANGE_SPEED;
	}
}

void Robot::setArmJunctionAngle(int key) {
	if (key == '7' && armJunctionAngle < MAX_JUNCTION_ANGLE) {
		armJunctionAngle += ANGLE_CHANGE_SPEED;
	} else if (key == '1' && armJunctionAngle >= MIN_JUNCTION_ANGLE) {
		armJunctionAngle -= ANGLE_CHANGE_SPEED;
	}
}

void Robot::setClawOpeningAngle(int key) {
	if (key == '+' && clawOpeningAngle < MAX_CLAW_OPENING_ANGLE) {
		clawOpeningAngle += CLAW_OPENING_ANGLE_CHANGE_SPEED;
	} else if (key == '-' && clawOpeningAngle >= MIN_CLAW_OPENING_ANGLE) {
		clawOpeningAngle -= CLAW_OPENING_ANGLE_CHANGE_SPEED;
	}
}

