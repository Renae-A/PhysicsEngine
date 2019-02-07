#include "Rigidbody.h"

using glm::vec2;

const float MIN_LINEAR_THRESHOLD = 0.001;


Rigidbody::Rigidbody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float rotation, float mass) :
	PhysicsObject(shapeID), m_position(position), m_velocity(velocity), m_rotation(rotation), m_mass(mass)
{
	/*m_linearDrag = 0;
	m_angularDrag = 0;*/
}


Rigidbody::~Rigidbody()
{

}

void Rigidbody::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	applyForce(gravity * m_mass * timeStep);
	m_position += m_velocity * timeStep;
}

void Rigidbody::debug()
{

}

void Rigidbody::applyForce(glm::vec2 force)
{
	glm::vec2 acceleration = force / m_mass;
	m_velocity += acceleration;
}

void Rigidbody::applyForceToActor(Rigidbody * actor2, glm::vec2 force)
{
	actor2->applyForce(force);
	applyForce(-force);
}
