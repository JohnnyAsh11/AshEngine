#include "Application.h"

Application::Application() { }

Application::Application(Application const& a_aInput)
{
	// Copying stack allocated data.
	m_v3Mouse = a_aInput.m_v3Mouse;
	m_bIsRunning = a_aInput.m_bIsRunning;

	// Deep copying the objects stored on the heap.
	m_pWindow = new sf::Window(
		sf::VideoMode(
			a_aInput.m_pWindow->getSize().x, 
			a_aInput.m_pWindow->getSize().y),
		"COPY WINDOW",
		sf::Style::Default,
		sf::ContextSettings(24));


	m_sProgramShader = new Shader(*a_aInput.m_sProgramShader);
}

Application& Application::operator=(Application const& a_aInput)
{
	// Copying stack allocated data.
	m_v3Mouse = a_aInput.m_v3Mouse;
	m_bIsRunning = a_aInput.m_bIsRunning;

	// Deep copying the objects stored on the heap.
	m_pWindow = new sf::Window(
		sf::VideoMode(
			a_aInput.m_pWindow->getSize().x,
			a_aInput.m_pWindow->getSize().y),
		"COPY WINDOW",
		sf::Style::Default,
		sf::ContextSettings(24));
	m_sProgramShader = new Shader(*a_aInput.m_sProgramShader);

	// Returning this instance of the application.
	return *this;
}

void Application::ChangeScreenBounds(void)
{
	std::cout << "Altering screen bounds" << std::endl;
}

void Application::ClearScreen(Vector4 a_v4ClearColor)
{
	// Actually clearing the color in the render window.
	GLCall(glClearColor(
		a_v4ClearColor.x,
		a_v4ClearColor.y,
		a_v4ClearColor.z,
		a_v4ClearColor.w));
}