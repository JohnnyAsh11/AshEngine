#include "Vectangle.h"
#include "ICollidable.h"

#include <typeinfo>
#include <string>
#include <exception>
#include <iostream>

/// <summary>
/// Using the Axis Aligned Bounding Box algorithm, determines whether 2 Vectangles have collided.
/// </summary>
/// <param name="otherObj">Another ICollidable being checked against this instance of a Vectangle.</param>
/// <returns>Whether or not a collision has occured.</returns>
bool Vectangle::CheckCollision(ICollidable& otherObj)
{
	// Creating string instances of each object's type ID
	std::string otherObjID = typeid(otherObj).name();
	std::string thisID = typeid(this).name();

	// Assuring that both objects are Vectangles.
	if (!thisID._Equal(otherObjID))
	{
		// If they are not both Vectangles, throw and exception and print the message.
		std::cout << "ERROR: Passed in ICollidable Object is not a Vectangle" << std::endl;
		throw std::exception("ERROR: Passed in ICollidable Object is not a Vectangle");
	}

	// Casting the BoxCollidable to be a Vectangle.
	Vectangle otherVect = (Vectangle)otherObj;

	// Performing the AABB check.
	return (otherVect.x < (this->x + this->width) &&
			(otherVect.x + width) > this->x &&
			otherVect.y < (this->y + this->height) &&
			(otherVect.y + otherVect.height) > this->y)
}
