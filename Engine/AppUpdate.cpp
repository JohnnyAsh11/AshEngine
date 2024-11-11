#include "Application.h"

void Application::Update(void)
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
}

void Application::Render(void)
{
	std::cout << "Rendering" << std::endl;
}

void Application::ChangeScreenBounds(void)
{
	std::cout << "Altering screen bounds" << std::endl;
}

void Application::ClearScreen(Vector4 a_v4ClearColor)
{
	// Setting the clear color.
	if (m_v4ClearColor != a_v4ClearColor)
	{
		m_v4ClearColor = a_v4ClearColor;
	}

	GLCall(glClearColor(
			m_v4ClearColor.x, 
			m_v4ClearColor.y,
			m_v4ClearColor.z,
			m_v4ClearColor.w));
}