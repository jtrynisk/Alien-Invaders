#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "../Math/Vector3.h"

class RigidBody
{
public:

	const float GRAVITY = 9.8f;

	RigidBody();
	
	void initialize(Vector3* p, Vector3* sc, Vector3 v, Vector3* si,
		float* r, float m, float f);

	void update();

	void render();

	void addForce(Vector3 force);

private:
	Vector3* position;

	Vector3* scale;

	Vector3* size;
	
	Vector3 velocity;

	float* rotation;

	float mass;

	float friction;
};

#endif RIGID_BODY_H