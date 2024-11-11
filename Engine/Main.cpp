#include "Application.h"

int main()
{
	// Creating the application.
	Application* app = new Application();
	app->Init("AshEngine");
	app->Run();

	// Clean up.
	Realloc(app);

	std::cout << "Ended execution" << std::endl;
	return 0;
}