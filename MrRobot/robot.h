#pragma once

#define PI 3.141592653589793

#define X_AXIS 1.0, 0.0, 0.0
#define Y_AXIS 0.0, 1.0, 0.0
#define Z_AXIS 0.0, 0.0, 1.0

#define PLATFORM_SIZE_XYZ 20.0, 2.0, 20.0
#define PLATFORM_COLOR_RGB 0.8, 0.8, 0.8
#define ROBOT_COLOR_RGB 0.8, 0.8, 0.8

#define MAX_X_COORD 9.0
#define MIN_X_COORD -9.0
#define MAX_Z_COORD 9.0
#define MIN_Z_COORD -9.0
#define COORD_CHANGE_SPEED 0.3

#define MAX_VERTICAL_ANGLE 90.0
#define MIN_VERTICAL_ANGLE -90.0
#define MAX_JUNCTION_ANGLE 187.0
#define MIN_JUNCTION_ANGLE -3.0
#define ANGLE_CHANGE_SPEED 3.0

#define MAX_CLAW_OPENING_ANGLE 30.0
#define MIN_CLAW_OPENING_ANGLE -5.0
#define CLAW_OPENING_ANGLE_CHANGE_SPEED 1.0




class Robot {

	public:
		Robot();
		void draw();
		bool isMovementKey(unsigned char key);
		void move(unsigned char key);

	private:
		GLdouble xCoord, zCoord, rotationAngle,
			armHorizontalAngle, armVerticalAngle, armJunctionAngle, clawOpeningAngle;

		void drawPlatform();
			void drawSupportPillar();
			void drawFloor();
		void drawRobot();
			void drawBody();
				void setBodyRotation();
			void drawArm();
				void drawArmBodyJunction();
				void drawArmMainJunction();
				void drawArmFirstBar();
				void drawArmSecondJunction();
				void drawArmSecondBar();
				void drawHand();
				void drawClaws();
					void drawFirstClaw();
					void drawSecondClaw();

		void setXCoord(int key);
		void setZCoord(int key);
		void setRotationAngle(int key);
		void setArmHorizontalAngle(int key);
		void setArmVerticalAngle(int key);
		void setArmJunctionAngle(int key);
		void setClawOpeningAngle(int key);
};
