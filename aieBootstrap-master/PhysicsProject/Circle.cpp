#include "Circle.h"

Circle::Circle(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 colour) :
	Rigidbody(CIRCLE, position, velocity, 0, mass)
{
	m_radius = radius;
	m_colour = colour;
}

Circle::~Circle()
{
}

void Circle::makeGizmo()
{
	
}

bool Circle::checkCollision(PhysicsObject * pOther)
{
	return false;
}
