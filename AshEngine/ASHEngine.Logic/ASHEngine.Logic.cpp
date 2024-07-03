#include <iostream>
#include "Vectangle.h"

/// <summary>
/// Contains main call and load logic for the engine.  Powerhouse behind the GUI form application.
/// </summary>
int main()
{
	Vectangle vect = Vectangle(0, 0, 100, 100);

	// Main engine logic update loop
	while (true)
	{
		std::cout << vect.GetPosition().GetX() << ", " << vect.GetPosition().GetY() << ", ";
		std::cout << vect.GetWidth() << ", " << vect.GetHeight() << std::endl;

		vect + Vector2(1, 0);
	}
}
