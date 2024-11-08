#include "Main.h"

typedef unsigned int uint;

/// <summary>
/// Application class that handles everything relating to the window/rendering context.
/// </summary>
class Application
{
private:
	sf::Window* m_pWindow = nullptr;
	Vector3 m_v3Mouse = Vector3();
	bool m_bIsRunning = false;

public:
	/// <summary>
	/// Constructs the Application object.
	/// </summary>
	Application();

	/// <summary>
	/// Initializes the window and rendering context.
	/// </summary>
	/// <param name="a_sAppName">Name of the window.  Defaults to "Window".</param>
	/// <param name="a_uWidth">Width of the window. Defaults to 800.</param>
	/// <param name="a_uHeight">Height of the window. Defaults to 600.</param>
	void Init(String a_sAppName = "Window", uint a_uWidth = 800, uint a_uHeight = 600);

	/// <summary>
	/// Runs the main loop of the Simulation.
	/// </summary>
	void Run(void);

	/// <summary>
	/// Safely Destructs the Application object.
	/// </summary>
	~Application();

private:

};