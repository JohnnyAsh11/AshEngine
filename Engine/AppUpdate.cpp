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

	// Creating some variables for generating the circle.
	m_Mesh = new Mesh();
	int dSubdivisions = 24;
	float fDeltaAngle = (2.0f * PI) / dSubdivisions;
	float fRadius = 0.5f;
	Vector3 v3Origin = Vector3(0.5f, 0.0f, 0.0f);
	std::vector<Vector3> lVertices;

	// Creating the vertices for the circle.
	for (uint i = 0; i < dSubdivisions; i++)
	{
		lVertices.push_back(Vector3(
			cos(i * fDeltaAngle) * fRadius + v3Origin.x,
			sin(i * fDeltaAngle) * fRadius + v3Origin.y,
			0.0f
		));
	}

	// Adding the vertices into the buffers of the mesh.
	for (uint i = 0; i < dSubdivisions; i++)
	{
		m_Mesh->AddVertexColor(v3Origin, BLUE);
		m_Mesh->AddVertexColor(lVertices[i], RED);
		m_Mesh->AddVertexColor(lVertices[(i + 1) % dSubdivisions], GREEN);
	}

	// Compiling the mesh for OpenGL to actually use.
	m_Mesh->CompileMesh();
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

	m_Mesh->Update();
}

void Application::Render(void)
{
	m_Mesh->Render();

	// Clearing the screen to be a base color.
	this->ClearScreen(CORNFLOWER_BLUE);
}

Application::~Application()
{
	// Freeing heap allocated variables.
	Realloc(m_Mesh);

	// Releasing singletons.
	FileReader::GetInstance()->ReleaseInstance();

	// Freeing memory.
	Realloc(m_pWindow);
	Realloc(m_sProgramShader);
}