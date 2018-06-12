#include <gl/glut.h>
#include "RgbImage.h"

#include "texture.h"

void Texture::initTextures() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);

	quad = gluNewQuadric();

	woodTexture = loadTextureFromFile(WOOD_TEXTURE_FILE);
	infiniteMirrorSpaceTexture = loadTextureFromFile(INFINITE_MIRROR_SPACE_TEXTURE_FILE);

	metal1Texture = loadTextureFromFile(METAL1_TEXTURE_FILE);
	metal2Texture = loadTextureFromFile(METAL2_TEXTURE_FILE);
	
	voltorbTexture = loadTextureFromFile(VOLTORB_TEXTURE_FILE);
}

GLuint Texture::loadTextureFromFile(const char *filename) {
	GLuint textureId;
	RgbImage theTexMap(filename); //Image with texture
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Texture to be edited
											 //Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D, //Always GL_TEXTURE_2D
		0, //0 for now
		GL_RGB, //Format OpenGL uses for image
		theTexMap.GetNumCols(), //Width
		theTexMap.GetNumRows(), //Height
		0, //The border of the image
		GL_RGB, //GL_RGB: pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE:pixels are stored as
						  //unsigned numbers
		theTexMap.ImageData()); //The actual pixel data
	return textureId; //Returns the id of the texture
}

void Texture::setTexture(GLuint texture) {
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	gluQuadricTexture(Texture::quad, 1);
}