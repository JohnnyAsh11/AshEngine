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
	Mesh mesh = Mesh();
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
			0.0f));
	}

	// Adding the vertices into the buffers of the mesh.
	for (uint i = 0; i < dSubdivisions; i++)
	{
		mesh.AddVertexColor(v3Origin, PINK);
		mesh.AddVertexColor(lVertices[i], EMERALD_GREEN);
		mesh.AddVertexColor(lVertices[(i + 1) % dSubdivisions], EMERALD_GREEN);
	}

	Mesh mesh2 = Mesh();
	mesh2.AddVertexColor(Vector3(+0.0f, +0.25f, +0.0f), RED);
	mesh2.AddVertexColor(Vector3(-0.25f, -0.25f, +0.0f), GREEN);
	mesh2.AddVertexColor(Vector3(+0.25f, -0.25f, +0.0f), BLUE);

	// Compiling the meshes for OpenGL to actually use.
	mesh.CompileMesh();
	mesh2.CompileMesh();

	m_lEntities.push_back(Entity(mesh));
	m_lEntities.push_back(Entity(mesh2));

	m_pCamera = std::make_shared<Camera>(Camera());
}

void Application::Update(void)
{
	// Empty at the moment - -
}

void Application::Render(void)
{
	for (uint i = 0; i < m_lEntities.size(); i++)
	{
		m_lEntities[i].Render(m_pCamera);
	}

	// Clearing the screen to be a base color.
	this->ClearScreen(EMERALD_GREEN);
}

Application::~Application()
{
	// Freeing heap allocated variables. ----> CURRENTLY NONE <----

	// Releasing singletons.
	FileReader::GetInstance()->ReleaseInstance();

	// Freeing memory.
	//Realloc(m_pProgramShader);
	Realloc(m_pWindow);
}