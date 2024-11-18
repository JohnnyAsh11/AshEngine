#include "Application.h"

int main()
{
	// Creating the application.
	Application* app = new Application();
	app->Init("AshEngine");

	FileReader* fileReader = FileReader::GetInstance();
	String basicShader = fileReader->ReadFile("shaders/basic.vs");
	fileReader->ReleaseInstance();

	app->Run();

	// Clean up.
	Realloc(app);

	std::cout << "Ended execution" << std::endl;
	return 0;
}