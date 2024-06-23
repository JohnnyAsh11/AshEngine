#include "Vector2.h"
#include "math.h"

// ===== CONSTRUCTORS ===== //
/// <summary>
/// Parameterized Constructor for the Vector2 sturct.
/// </summary>
/// <param name="x">The X coordinate of the Vector2</param>
/// <param name="y">The Y coordinate of the Vector2</param>
Vector2::Vector2(float x, float y)
{
	_x = x;
	_y = y;
}

// ===== PROPERTIES ===== //
/// <summary> Retrieves the X value </summary>
float Vector2::GetX()
{
	return _x;
}
/// <summary> Sets a new X value </summary>
void Vector2::SetX(float newX)
{
	_x = newX;
}

/// <summary> Retrieves the Y value </summary>
float Vector2::GetY()
{
	return _y;
}
/// <summary> Sets a new Y value </summary>
void Vector2::SetY(float newY)
{
	_y = newY;
}

/// <summary> Constructs a Vector with x and y at 0 </summary>
Vector2 Vector2::Zero()
{
	return Vector2(0, 0);
}

// ===== METHODS ===== //
/// <summary>
/// with the distance formula, calculates the distance between 2 Vectors.
/// </summary>
/// <returns>The distance as a float</returns>
float Vector2::Distance(Vector2 otherVec)
{
	float xValue = (float)pow((double)(otherVec._x - _x), 2);
	float yValue = (float)pow((double)(otherVec._y - _y), 2);

	return sqrt(xValue + yValue);
}

// ===== OPERATOR OVERLOADS ===== //
/// <summary> Performs Vector addition. </summary>
Vector2 Vector2::operator+(Vector2 otherVec)
{
	float xResult = this->_x + otherVec._x;
	float yResult = this->_y + otherVec._y;

	return Vector2(xResult, yResult);
}

/// <summary> Performs Vector subtraction. </summary>
Vector2 Vector2::operator-(Vector2 otherVec)
{
	float xResult = _x - otherVec._x;
	float yResult = _y - otherVec._y;

	return Vector2(xResult, yResult);
}
