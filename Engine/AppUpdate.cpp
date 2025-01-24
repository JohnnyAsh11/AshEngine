#include "Application.h"

typedef std::vector<Vector3> VectorList;

void Application::Init(String a_sAppName, uint a_uWidth, uint a_uHeight)
{
	std::cout << "Initializing the Window." << std::endl;

	// Initializing the window object.
	m_pWindow = new sf::Window(
		sf::VideoMode(a_uWidth, a_uHeight),
		a_sAppName,
		sf::Style::Default,
		sf::ContextSettings(24));

	// Initializing the window settings.
	InitWindow();

	// Initializing the Shader.
	ShaderInit();
	glUseProgram(m_sProgramShader->GetProgramID());

	VectorList lPositions = VectorList();
	lPositions.push_back(Vector3(-0.5f, -0.5f, 0.0f));
	lPositions.push_back(Vector3(0.5f, -0.5f, 0.0f));
	lPositions.push_back(Vector3(0.0f, 0.5f, 0.0f));
	int vertexCount = lPositions.size();

	VectorList lColors = VectorList();
	lColors.push_back(EMERALD_GREEN);
	lColors.push_back(PAPAYA_ORANGE);
	lColors.push_back(CORNFLOWER_BLUE);

	VectorList lVertices = VectorList();
	for (uint i = 0; i < vertexCount; i++)
	{
		lVertices.push_back(lPositions[i]);
		lVertices.push_back(lColors[i]);
	}

	// Creating/Setting the Vertex Array object.
	GLuint vao;
	GLCall(glGenVertexArrays(1, &vao));
	GLCall(glBindVertexArray(vao));

	// Creating/Setting the Vertex Buffer object.
	GLuint vbo;
	GLCall(glGenBuffers(1, &vbo));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
	GLCall(glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(Vector3), &lVertices[0], GL_STATIC_DRAW));

	//count the attributes
	int attributeCount = 2;

	// Position attribute
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, vertexCount, GL_FLOAT, GL_FALSE, attributeCount * sizeof(Vector3), (GLvoid*)0));

	// Color attribute
	GLCall(glEnableVertexAttribArray(1));
	GLCall(glVertexAttribPointer(1, vertexCount, GL_FLOAT, GL_FALSE, attributeCount * sizeof(Vector3), (GLvoid*)(1 * sizeof(Vector3))));
	// Getting the attribute location of the program shader.
	//GLint positionBufferID = glGetAttribLocation(m_sProgramShader->GetProgramID(), "positionBuffer");
	//glEnableVertexAttribArray(positionBufferID);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
}

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
	// Drawing the triangle.
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));

	// Clearing the screen to be a base color.
	this->ClearScreen(EMERALD_GREEN);
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

	// Actually clearing the color in the render window.
	GLCall(glClearColor(
			m_v4ClearColor.x, 
			m_v4ClearColor.y,
			m_v4ClearColor.z,
			m_v4ClearColor.w));
}