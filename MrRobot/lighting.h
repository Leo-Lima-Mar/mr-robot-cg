#pragma once

#define AMBIENT_LIGHT 0.2, 0.2, 0.2, 1.0
#define DIFFUSE_LIGHT 0.7, 0.7, 0.7, 1.0 
#define SPECULAR_LIGHT 1.0, 1.0, 1.0, 1.0
#define LIGHT_POSITION 3.0, 3.0, 3.0, 0.0

#define BACKGROUND_COLOR_RGBA 0.258823, 0.525490, 0.956862, 0.0

class Lighting {

	public:
		static void initLighting();
		static void toggleLighting(unsigned char key);

	private:

};