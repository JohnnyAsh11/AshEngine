#include "pch.h"
#include "Shader.h"
using namespace ASH;

Shader::Shader(void)
{
	m_sFragmentShaderFile = NULL_STR;
	m_sVertexShaderFile = NULL_STR;
	m_sProgramName = NULL_STR;
	m_uProgramID = -1;
}

Shader::Shader(const Shader& other)
{
	// Setting all of the variables.
	m_sFragmentShaderFile = other.m_sFragmentShaderFile;
	m_sVertexShaderFile = other.m_sVertexShaderFile;
	m_sProgramName = other.m_sProgramName;
	m_uProgramID = other.m_uProgramID;
}

Shader::~Shader(void)
{
	if (m_uProgramID >= 0)
	{
		GLCall(glDeleteProgram(m_uProgramID));
		m_uProgramID = -1;
	}
}

Shader& Shader::operator=(const Shader& other)
{
	// Setting all of the variables.
	m_sFragmentShaderFile = other.m_sFragmentShaderFile;
	m_sVertexShaderFile = other.m_sVertexShaderFile;
	m_sProgramName = other.m_sProgramName;
	m_uProgramID = other.m_uProgramID;

	return *this;
}

GLuint Shader::CompileShader(
	String a_sVertexShaderFile,
	String a_sFragmentShaderFile,
	String a_sProgramName)
{
	// Setting the Program name.
	if (a_sProgramName != NULL_STR)
	{
		m_sProgramName = a_sProgramName;
	}
	else
	{
		m_sProgramName = "MyShaderProgram: " + a_sVertexShaderFile + "\\\\" + a_sFragmentShaderFile;
	}

	// Setting the shader file addresses.
	m_sVertexShaderFile = a_sVertexShaderFile;
	m_sFragmentShaderFile = a_sFragmentShaderFile;

	// Loading the shaders and getting their program ID
	m_uProgramID = LoadShaders(
		m_sVertexShaderFile.c_str(),
		m_sFragmentShaderFile.c_str()
	);

	// Returning the program ID.
	return m_uProgramID;
}

// - - Accessors - -
String Shader::GetProgramName() { return m_sProgramName; }
String Shader::GetVertexShader() { return m_sVertexShaderFile; }
String Shader::GetFragmentShader() { return m_sFragmentShaderFile; }
int Shader::GetProgramID() { return m_uProgramID; }
