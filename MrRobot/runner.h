#pragma once

#define ESC_KEY 27

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define WINDOW_TITLE "Mr. Robot"

class Runner {
	public:
		static void start();

	private:
		static Robot robot;
		static Camera camera;

		// Funções de inicialização
		static void createWindow();
		static void registerCallbacks();

		// Funções callback
		static void display();
		static void resizeWindow(GLsizei w, GLsizei h);
		static void readKeyboard(unsigned char key, int x, int y);
		static void readSpecialKeyboard(int key, int x, int y);
		static void readMouse(int button, int state, int x, int y);

};

