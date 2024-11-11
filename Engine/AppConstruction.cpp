#include "Application.h"

Application::Application()
{
	std::cout << "Constructing" << std::endl;
}

Application::Application(Application const& a_aInput)
{
	std::cout << "Copy Constructing" << std::endl;
}

Application::~Application()
{
	Realloc(m_pWindow);
}

Application& Application::operator=(Application const& a_aInput)
{
	return *new Application();
}