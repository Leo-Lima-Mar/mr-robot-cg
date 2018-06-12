#pragma once

#define WOOD_TEXTURE_FILE "./textures/wood.bmp"
#define VOLTORB_TEXTURE_FILE "./textures/voltorb.bmp"
#define METAL1_TEXTURE_FILE "./textures/metal1.bmp"
#define METAL2_TEXTURE_FILE "./textures/metal2.bmp"
#define INFINITE_MIRROR_SPACE_TEXTURE_FILE "./textures/infiniteMirrorSpace.bmp" 

class Texture {

	public:
		static GLuint woodTexture, voltorbTexture,
			metal1Texture, metal2Texture, infiniteMirrorSpaceTexture;

		static GLUquadric *quad;

		static void initTextures();
		static void setTexture(GLuint texture);

	private:
		static GLuint loadTextureFromFile(const char *filename);

};