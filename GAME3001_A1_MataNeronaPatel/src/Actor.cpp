#include "Actor.h"
#include "TextureManager.h"


Actor::Actor()
{
	TextureManager::Instance().load("../Assets/textures/Shellby_Pilot.png", "Actor");

	const auto size = TextureManager::Instance().getTextureSize("Actor");
	setWidth(size.x);
	setHeight(size.y);
	getTransform()->position = glm::vec2(600.0f, 400.0f);
	getRigidBody()->velocity = glm::vec2(0, 0);
	getRigidBody()->isColliding = false;

	setType(TARGET);
}

Actor::~Actor()
= default;

void Actor::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the actor
	TextureManager::Instance().draw("Actor", x, y, 0, 255, true);
}

void Actor::update()
{
	
}

void Actor::clean()
{
}