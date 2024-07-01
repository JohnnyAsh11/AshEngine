#pragma once

#include "ICollidable.h"
#include "Vector2.h"

struct Vectangle : ICollidable
{
private:
	float x;
	float y;
	float width;
	float height;

public:
	Vectangle(Vector2 position);
	Vectangle(Vector2 position, Vector2 dimensions);
	Vectangle(float x, float y, float width, float height);

	bool CheckCollision(ICollidable& otherObj) override;
};

