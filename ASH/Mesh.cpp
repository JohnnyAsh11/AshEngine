#include "Mesh.h"

using namespace ASH;

// Construction // Rule of Three
Mesh::Mesh()
{
	m_vbo = 0;
	m_vao = 0;
	m_lVertices = new VectorList();
	m_VertexType = VertexType::Undefined;
	m_dVertexCount = 0;
}
Mesh::~Mesh(void)
{
	delete[] m_lVertices;
}
Mesh::Mesh(const Mesh& other)
{
	// If the list is allocated,
	if (m_lVertices != nullptr)
	{
		// Then delete the list.
		delete[] m_lVertices;
	}

	// Instantiating a new list.
	m_lVertices = new VectorList();

	// Populate the list with the other Mesh's vertices.
	for (int i = 0; i < other.m_lVertices->size(); i++)
	{
		m_lVertices->push_back((*other.m_lVertices)[i]);
	}

	// Setting all other values.
	m_vbo = other.m_vbo;
	m_vao = other.m_vao;
	m_VertexType = other.m_VertexType;
	m_dVertexCount = other.m_dVertexCount;
}
Mesh& Mesh::operator=(const Mesh& other)
{
	// If the list is allocated,
	if (m_lVertices != nullptr)
	{
		// Then delete the list.
		delete[] m_lVertices;
	}

	// Instantiating a new list.
	m_lVertices = new VectorList();

	// Populate the list with the other Mesh's vertices.
	for (int i = 0; i < other.m_lVertices->size(); i++)
	{
		m_lVertices->push_back((*other.m_lVertices)[i]);
	}

	// Setting all other values.
	m_vbo = other.m_vbo;
	m_vao = other.m_vao;
	m_VertexType = other.m_VertexType;
	m_dVertexCount = other.m_dVertexCount;

	// Returning the altered Mesh.
	return *this;
}

void ASH::Mesh::AddVertex(Vector3 a_v3VertexPosition)
{
}

void ASH::Mesh::AddVertexColor(Vector3 a_v3VertexPosition, Vector3 a_v3VertexColor)
{
}

void ASH::Mesh::Clear(void)
{
}

void ASH::Mesh::Reset(void)
{
}

