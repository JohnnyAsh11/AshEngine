#include "Vectangle.h"

#include <string>
#include <exception>
#include <iostream>

Vectangle::Vectangle()
{
	_x = 0;
	_y = 0;
	_width = 0;
	_height = 0;
}

Vectangle::Vectangle(Vector2 position)
	: Vectangle(position.GetX(), position.GetY(), 50, 50)
{}

Vectangle::Vectangle(Vector2 position, Vector2 dimensions)
	: Vectangle(position.GetX(), position.GetY(), dimensions.GetX(), dimensions.GetY())
{}

Vectangle::Vectangle(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
}

Vector2 Vectangle::GetPosition()
{
	return Vector2(_x, _y);
}

float Vectangle::GetWidth()
{
	return _width;
}

float Vectangle::GetHeight()
{
	return _height;
}

/// <summary>
/// Using the Axis Aligned Bounding Box algorithm, determines whether 2 Vectangles have collided.
/// </summary>
/// <param name="otherObj">Another ICollidable being checked against this instance of a Vectangle.</param>
/// <returns>Whether or not a collision has occured.</returns>
bool Vectangle::CheckCollision(Vectangle otherVect)
{
	// Performing the AABB check.
	return (otherVect._x < (this->_x + this->_width) &&
		   (otherVect._x + _width) > this->_x &&
		   otherVect._y < (this->_y + this->_height) &&
		   (otherVect._y + otherVect._height) > this->_y);
}

/// <summary>
/// Checks if the passed in Vector2 point is 
/// </summary>
/// <param name="point">A Vector2 point.</param>
/// <returns>Whether or not the point is within the Vectangle.</returns>
bool Vectangle::Contains(Vector2 point)
{
	// Checking if the point is within the current instance of a Vectangle.
	return point.GetX() < (_x + _width) && point.GetX() > _x &&
		   point.GetY() < (_y = _height) && point.GetY() > _y;
}

Vectangle Vectangle::operator+(Vector2 otherVec)
{
	Vector2 resultingPosition = this->GetPosition() + otherVec;
	Vectangle vect = Vectangle(resultingPosition);

	vect._width = _width;
	vect._height = _height;

	return vect;
}

Vectangle Vectangle::operator-(Vector2 otherVec)
{
	Vector2 resultingPosition = this->GetPosition() - otherVec;
	Vectangle vect = Vectangle(resultingPosition);

	vect._width = _width;
	vect._height = _height;

	return vect;
}

Vectangle Vectangle::operator*(Vector2 otherVec)
{
	Vector2 resultingPosition = this->GetPosition() * otherVec;
	Vectangle vect = Vectangle(resultingPosition);

	vect._width = _width;
	vect._height = _height;

	return vect;
}

Vectangle Vectangle::operator/(Vector2 otherVec)
{
	Vector2 resultingPosition = this->GetPosition() / otherVec;
	Vectangle vect = Vectangle(resultingPosition);

	vect._width = _width;
	vect._height = _height;

	return vect;
}
