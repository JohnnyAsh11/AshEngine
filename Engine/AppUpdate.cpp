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
	int dSubdivisions = 48;
	float fDeltaAngle = (2.0f * PI) / dSubdivisions;
	float fRadius = 0.75f;
	Vector3 v3Origin = Vector3(0.0f, 0.0f, 0.0f);
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
		m_Mesh->AddVertexColor(v3Origin, PINK);
		m_Mesh->AddVertexColor(lVertices[i], EMERALD_GREEN);
		m_Mesh->AddVertexColor(lVertices[(i + 1) % dSubdivisions], EMERALD_GREEN);
	}

	m_Mesh2 = new Mesh();
	m_Mesh2->AddVertexColor(Vector3(+0.0f, +0.25f, +0.0f), RED);
	m_Mesh2->AddVertexColor(Vector3(-0.25f, -0.25f, +0.0f), GREEN);
	m_Mesh2->AddVertexColor(Vector3(+0.25f, -0.25f, +0.0f), BLUE);

	// Compiling the meshes for OpenGL to actually use.
	m_Mesh->CompileMesh();
	m_Mesh2->CompileMesh();
}

void Application::Update(void)
{
	// Empty at the moment - -
}

void Application::Render(void)
{
	m_Mesh->Render();
	m_Mesh2->Render();

	// Clearing the screen to be a base color.
	this->ClearScreen(EMERALD_GREEN);
}

Application::~Application()
{
	// Freeing heap allocated variables.
	Realloc(m_Mesh);
	Realloc(m_Mesh2);

	// Releasing singletons.
	FileReader::GetInstance()->ReleaseInstance();

	// Freeing memory.
	Realloc(m_sProgramShader);
	Realloc(m_pWindow);
}