#include "Application.h"

void Application::Init(String a_sAppName, uint a_uWidth, uint a_uHeight)
{
	m_pWindow = new sf::Window(
		sf::VideoMode(a_uWidth, a_uHeight),
		a_sAppName, 
		sf::Style::Default,
		sf::ContextSettings(24));

	FileReader* fileReader = FileReader::GetInstance();
	String basicShader = fileReader->ReadFile("shaders/basic.vs");
	fileReader->ReleaseInstance();

	InitWindow();
	//ShaderInit();
}

void Application::Run(void)
{
	// Starting up the loop with the control variable.
	m_bIsRunning = true;

	while (m_bIsRunning)
	{
		// Calling the logic update method.
		this->Update();

		// Clearing the buffers.
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		// Coloring and drawing.
		GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));

		// Ending the current frame (internally swaps the front and back buffers)
		m_pWindow->display();

		// Clearing the screen to be papaya orange.
		this->ClearScreen(PAPAYA_ORANGE);
	}
}

void Application::InitWindow()
{
	m_pWindow->setVerticalSyncEnabled(true);

	// Initializing GLEW.
	glewExperimental = GL_TRUE;
	GLCall(glewInit());

	// Enabling pixel blending and its mode.
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	// Enabling depth testing and its mode.
	GLCall(glEnable(GL_DEPTH_TEST));
	GLCall(glDepthFunc(GL_LEQUAL));

	// Disallows the faces from being viewed from behind.
	GLCall(glEnable(GL_CULL_FACE));
}

void Application::ShaderInit(void)
{

}