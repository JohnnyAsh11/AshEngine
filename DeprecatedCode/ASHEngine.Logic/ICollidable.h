#pragma once

#include "Vector2.h"
#include "Vectangle.h"

/// <summary>
/// Dictates how a Collidable object will behave.
/// </summary>
class ICollidable
{
protected:
	Vector2 position;
	Vector2 dimensions;

public:
	virtual bool CheckCollision(ICollidable& otherObj) = 0;

public:

	/// <summary>
	/// ICollidable to Vectangle typecast overload.
	/// </summary>
	operator Vectangle() const
	{
		return Vectangle(position, dimensions);
	}
};

