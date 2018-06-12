#include <gl/glut.h>
#include "RgbImage.h"

#include "camera.h"
#include "robot.h"
#include "runner.h"
#include "texture.h"

Robot Runner::robot;
Camera Runner::camera;

GLuint Texture::woodTexture, Texture::voltorbTexture, 
	Texture::metal1Texture, Texture::metal2Texture, Texture::infiniteMirrorSpaceTexture;
GLUquadric* Texture::quad;

int main(int argc, char ** argv) {
	glutInit(&argc, argv);

	Runner::start();

	glutMainLoop();
	return 0;
}
