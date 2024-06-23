#pragma once

/// <summary>
/// Dictates how a Collidable object will behave.
/// </summary>
class ICollidable
{
protected:
	virtual bool CheckCollision(ICollidable otherObj) = 0;
};

