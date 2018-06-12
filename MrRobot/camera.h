#pragma once

#define PI 3.141592653589793

#define SCROLL_UP 3
#define SCROLL_DOWN 4

#define FRUSTUM_SPACE -1.0, 1.0, -1.0, 1.0, 3.0, 70.0 // -3.0, 3.0, -3.0, 3.0, 3.0, 60.0 
#define LOOK_AT_UP_XYZ 0.0, 1.0, 0.0
#define LOOK_AT_CENTER_XYZ 0, 1, 0

#define MAX_RADIUS 50.0
#define MIN_RADIUS 9.0

#define MAX_BETA (PI/2) - 0.03
#define MIN_BETA 0.0

#define HORIZONTAL_ANGLE_CHANGE_SPEED 0.03
#define VERTICAL_ANGLE_CHANGE_SPEED 0.03
#define RADIUS_CHANGE_SPEED 1.0

class Camera {

	public:
		Camera();
		void prepareProjection();
		bool isMovementKey(int key);
		void move(int key);

	private:
		GLdouble horizontalAngle, verticalAngle, radius;

		void setHorizontalAngle(int key);
		void setVerticalAngle(int key);
		void setRadius(int key);
};
