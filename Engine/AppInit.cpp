#include "Application.h"

void Application::Run(void)
{
	// Starting up the loop with the control variable.
	m_bIsRunning = true;

	while (m_bIsRunning)
	{
		// Handling window events.
		sf::Event event;
		while (m_pWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// Closing the application.
				m_bIsRunning = false;
			}
			else if (event.type == sf::Event::Resized)
			{
				// Adjusting the viewport when the window is resized.
				GLCall(glViewport(0, 0, event.size.width, event.size.height));
			}
		}

		// Calling the logic update method.
		this->Update();

		// Clearing the buffers.
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		// Coloring and drawing.
		this->Render();

		// Ending the current frame (internally swaps the front and back buffers)
		m_pWindow->display();
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
	// Initializing the shader object.
	m_sProgramShader = new Shader();
	
	// Compiling the loaded in fragment and vertex shaders.
	//  Will automatically use the basic vertex and fragment shaders.
	m_sProgramShader->CompileShader(
		"shaders/basicVertex.hlsl",
		"shaders/basicFrag.hlsl", 
		"BasicProgramShaders");

	// Outputing that there was an error.
	if (m_sProgramShader->GetProgramID() == ERROR)
	{
		std::cout << "There was an error in shader compilation" << std::endl;
	}
}  