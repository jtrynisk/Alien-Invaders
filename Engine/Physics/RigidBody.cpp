#include "RigidBody.h"
#include "../Engine.h"

RigidBody::RigidBody()
{
	friction = 1;
	mass = 1;
}

void RigidBody::initialize(Vector3* p, Vector3* sc, Vector3 v, Vector3* si,
	float* r, float m, float f)
{
	position = p;
	scale = sc;
	velocity = v;
	size = si;

	rotation = r;
	mass = m;
	friction = f;
}

void RigidBody::update()
{
	velocity.x *= friction;
	velocity.y *= mass * GRAVITY;

	*position = *position + (velocity * Engine::getDeltaTime());
}

void RigidBody::render()
{
	glLoadIdentity();

	glTranslatef(position->x, position->y, position->z);
	glRotatef(*rotation, 0, 0, 1);
	glScalef(scale->x, scale->y, scale->z);

	glBegin(GL_LINES);
	{
		glVertex2i(0, 0);
		glVertex2i(size->x, 0);
		glVertex2i(size->x, size->y);
		glVertex2i(0, size->y);
	}
	glEnd();
}

void RigidBody::addForce(Vector3 force)
{
	velocity = velocity + force;
}