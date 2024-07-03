#pragma once

#include "Vector2.h"

struct Vectangle
{
private:
	// ===== FIELDS ===== //
	float _x;
	float _y;
	float _width;
	float _height;

public:
	// ===== CONSTRUCTORS ===== //
	Vectangle();
	Vectangle(Vector2 position);
	Vectangle(Vector2 position, Vector2 dimensions);
	Vectangle(float x, float y, float width, float height);

	// ===== PROPERTIES ===== //
	Vector2 GetPosition();
	float GetWidth();
	float GetHeight();

	// ===== METHODS ===== //
	bool CheckCollision(Vectangle otherVect);
	bool Contains(Vector2 point);

	// ===== OPERATOR OVERLOADS ===== //
	Vectangle operator +(Vector2 otherVec);
	Vectangle operator -(Vector2 otherVec);
	Vectangle operator *(Vector2 otherVec);
	Vectangle operator /(Vector2 otherVec);
};

