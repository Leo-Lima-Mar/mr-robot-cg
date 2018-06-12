#include <gl/glut.h>

#include "lighting.h"

void Lighting::initLighting() {

	GLfloat ambientLight[4] = { AMBIENT_LIGHT };
	GLfloat diffuseLight[4] = { DIFFUSE_LIGHT }; // "cor"
	GLfloat specularLight[4] = { SPECULAR_LIGHT }; // "brilho"
	GLfloat lightPosition[4] = { LIGHT_POSITION };

	// Capacidade de brilho do material
	GLfloat specularity[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLint materialSpec = 60;

	glShadeModel(GL_SMOOTH); // Habilita o modelo de colorização de Gouraud
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularity); // Define a refletância do material
	glMateriali(GL_FRONT, GL_SHININESS, materialSpec); // Define a concentração do brilho
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight); // Ativa o uso da luz ambiente

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	
	glEnable(GL_COLOR_MATERIAL); // Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_LIGHTING); // Habilita o uso de iluminação
	glEnable(GL_LIGHT0); // Habilita a luz de número 0
	glEnable(GL_DEPTH_TEST); // Habilita o depth-buffering
}

void Lighting::toggleLighting(unsigned char key) {
	glIsEnabled(GL_LIGHTING) ? glDisable(GL_LIGHTING) : glEnable(GL_LIGHTING);
}