#include "pch.h"
#include "Mesh.h"

using namespace ASH;

// Construction // Rule of Three
Mesh::Mesh()
{
	m_VBO = 0;
	m_VAO = 0;
	m_lVertices = VectorList();
	m_VertexType = VertexType::Undefined;
	m_dVertexCount = 0;
	m_pShader = new Shader();
}
Mesh::~Mesh(void)
{
	// Freeing any heap allocated memory.
	Realloc(m_pShader);
}
Mesh::Mesh(const Mesh& other)
{
	// Safely freeing the memory for the Shader.
	if (m_pShader != nullptr)
	{
		Realloc(m_pShader);
	}

	// Instantiating a new list.
	m_lVertices = VectorList();

	// Populate the list with the other Mesh's vertices.
	for (int i = 0; i < other.m_lVertices.size(); i++)
	{
		m_lVertices.push_back((other.m_lVertices)[i]);
	}

	// Setting all other values.
	m_VBO = other.m_VBO;
	m_VAO = other.m_VAO;
	m_VertexType = other.m_VertexType;
	m_dVertexCount = other.m_dVertexCount;
	m_pShader = other.m_pShader;
}
Mesh& Mesh::operator=(const Mesh& other)
{
	// Safely freeing the memory for the Shader.
	if (m_pShader != nullptr)
	{
		Realloc(m_pShader);
	}

	// Instantiating a new list.
	m_lVertices = VectorList();

	// Populate the list with the other Mesh's vertices.
	for (int i = 0; i < other.m_lVertices.size(); i++)
	{
		m_lVertices.push_back((other.m_lVertices)[i]);
	}

	// Setting all other values.
	m_VBO = other.m_VBO;
	m_VAO = other.m_VAO;
	m_VertexType = other.m_VertexType;
	m_dVertexCount = other.m_dVertexCount;
	m_pShader = other.m_pShader;

	// Returning the altered Mesh.
	return *this;
}

void Mesh::AddVertex(Vector3 a_v3VertexPosition)
{
	// Changing the vertex type from undefined.
	if (m_VertexType == VertexType::Undefined) m_VertexType = VertexType::VertexPosition;

	// Assuring that the data being added matches the buffer format.
	if (m_VertexType != VertexType::VertexPosition) return;

	// Actually adding the vertexc to the list.
	m_lVertices.push_back(a_v3VertexPosition);

	// Incrementing the vertex count.
	m_dVertexCount++;
}

void Mesh::AddVertexColor(Vector3 a_v3VertexPosition, Vector3 a_v3VertexColor)
{
	// Changing the vertex type from undefined. 
	if (m_VertexType == VertexType::Undefined) m_VertexType = VertexType::VertexPositionColor;

	// Assuring that the data being added matches the buffer format.
	if (m_VertexType != VertexType::VertexPositionColor) return;

	// Actually adding the vertices to the list.
	m_lVertices.push_back(a_v3VertexPosition);
	m_lVertices.push_back(a_v3VertexColor);

	// Incrementing the vertex count.
	m_dVertexCount++;
}

void Mesh::Clear(void)
{
	// Actually clearing the list.
	m_lVertices.clear();

	// Resetting variables.
	this->Reset();
}

void Mesh::CompileMesh()
{
	// Checking if the Shaders have been loaded.
	if (m_pShader->GetProgramID() == -1)
	{
		// Compiling with the basic shaders.
		m_pShader->CompileShader(
			"shaders/basicVertex.hlsl",
			"shaders/basicFrag.hlsl",
			"BasicProgramShaders");
	}

	// Creating/Setting the Vertex Array object.
	GLCall(glGenVertexArrays(1, &m_VAO));
	GLCall(glBindVertexArray(m_VAO));

	// Creating/Setting the Vertex Buffer object.
	GLCall(glGenBuffers(1, &m_VBO));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));
	GLCall(glBufferData(
		GL_ARRAY_BUFFER, 
		m_dVertexCount * (int)m_VertexType * sizeof(Vector3),
		&m_lVertices[0],
		GL_STATIC_DRAW));

	// Position attribute
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		(int)m_VertexType * sizeof(Vector3), 
		(GLvoid*)0));

	// Only run the color attribute if the color is included in the vertices.
	if (m_VertexType == VertexType::VertexPositionColor)
	{
		// Color attribute
		GLCall(glEnableVertexAttribArray(1));
		GLCall(glVertexAttribPointer(
			1, 
			3,
			GL_FLOAT, 
			GL_FALSE, 
			(int)m_VertexType * sizeof(Vector3),
			(GLvoid*)(1 * sizeof(Vector3))));
	}

	// Unbinding the VAO at the end of the method.
	glBindVertexArray(0);
}

void Mesh::Render()
{
	// Assigning the program to use this Mesh's Shaders.
	glUseProgram(m_pShader->GetProgramID());

	// Binding this Mesh's VAO and VBO.
	glBindVertexArray(m_VAO);

	Matrix4 m4Model = IDENTITY_M4;
	Matrix4 m4View;
	Matrix4 m4Projection;

	// Reading the uniforms from the shader and send values.
	GLuint MVP = glGetUniformLocation(m_pShader->GetProgramID(), "MVP");

	// Grabbing the uniform Matrix4.
	glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(m4Projection * m4View * m4Model));

	// Drawing the vertex buffers.
	glDrawArrays(GL_TRIANGLES, 0, m_dVertexCount);

	// Unbinding the VAO at the end of the method.
	glBindVertexArray(0);
}

void Mesh::Reset(void)
{
	if (m_VBO > 0)
	{
		glDeleteBuffers(1, &m_VBO);
	}

	if (m_VAO > 0)
	{
		glDeleteVertexArrays(1, &m_VAO);
	}

	m_VertexType = VertexType::Undefined;
	m_dVertexCount = 0;
	m_VAO = 0;
	m_VBO = 0;
}

