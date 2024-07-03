#pragma once

/// <summary>
/// Contains all relevant math and operations for Vector math and objects
/// </summary>
struct Vector2
{
private:
	// ===== FIELDS ===== //
	float _x;
	float _y;

public:
	// ===== CONSTRUCTORS =====//
	Vector2();
	Vector2(float x, float y);

	// ===== PROPERTIES ===== //
	float GetX();
	void SetX(float newX);

	float GetY();
	void SetY(float newY);

	static Vector2 Zero();

	// ===== METHODS ===== //
	float Distance(Vector2 otherVec);

	// ===== OPERATOR OVERLOADS ===== //
	Vector2 operator +(Vector2 otherVec);
	Vector2 operator -(Vector2 otherVec);
	Vector2 operator *(Vector2 otherVec);
	Vector2 operator /(Vector2 otherVec);
};

