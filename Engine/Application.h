#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include "Main.h"

typedef unsigned int uint;

/// <summary>
/// Application class that handles everything relating to the window/rendering context.
/// </summary>
class Application
{
private:
	Mesh* m_Mesh = nullptr;
	Mesh* m_Mesh2 = nullptr;

	// Fields for the window itself
	sf::Window* m_pWindow = nullptr;
	ASH::Shader* m_pProgramShader = nullptr;

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

	/// <summary>
	/// Copy constructor that creates a deep copy of the passed in Application object.
	/// </summary>
	/// <param name="a_aInput"></param>
	Application(Application const& a_aInput);

	/// <summary>
	/// Deep copies a passed in instance of the Application object.
	/// </summary>
	/// <param name="a_aInput">The original Application.</param>
	/// <returns>A copy of the passed Application</returns>
	Application& operator=(Application const& a_aInput);

private:
	/// <summary>
	/// Initializes the window itself. Helper method for Init.
	/// </summary>
	void InitWindow();

	/// <summary>
	/// Initializes the base shaders for the window.
	/// </summary>
	void ShaderInit(void);

	/// <summary>
	/// Frame to frame update method for the Application.
	/// </summary>
	void Update(void);

	/// <summary>
	/// Dictates what to render within the Application.
	/// </summary>
	void Render(void);

	/// <summary>
	/// Clears everything off of the screen for the next frame.
	/// </summary>
	/// <param name="a_v4Color">The color to clear the screen with.  Defaults to Cornflower Blue</param>
	void ClearScreen(Vector4 a_v4ClearColor = CORNFLOWER_BLUE);

	/// <summary>
	/// Detects if the screen bounds have changed and updates the window.
	/// </summary>
	void OnChangeScreenBounds(void);
};

#endif //__APPLICATION_H_