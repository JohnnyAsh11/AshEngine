#ifndef __SHADER_H_
#define __SHADER_H_

#include "Definitions.h"

namespace ASH
{

/// <summary>
/// Shader class holding all data for Shaders in the program.
/// </summary>
class ASH_API Shader
{
private:
	String m_sProgramName = NULL_STR;
	String m_sVertexShaderFile = NULL_STR;
	String m_sFragmentShaderFile = NULL_STR;
	GLuint m_uProgramID = -1;

public:
	/// <summary>
	/// Constructs instances of the Shader class.
	/// </summary>
	Shader(void);

	/// <summary>
	/// Copy constructor for Shader objects.
	/// </summary>
	/// <param name="other">Reference to the Shader that is being copied.</param>
	Shader(const Shader& other);

	/// <summary>
	/// Standard destructor for Shader objects.
	/// </summary>
	~Shader(void);

	/// <summary>
	/// Copy operator for the Shader class.
	/// </summary>
	/// <param name="other">Reference to the Shader that is being copied.</param>
	/// <returns>The reference to the new Shader copy.</returns>
	Shader& operator= (const Shader& other);

	/// <summary>
	/// Compiles the Shader into the program.
	/// </summary>
	/// <param name="a_sVertexShaderFile">The file path to the vertex shader.</param>
	/// <param name="a_sFragmentShaderFile">The file path to the fragmemt shader.</param>
	/// <param name="a_sProgramName">The name of the program.</param>
	/// <returns>The Program ID.</returns>
	GLuint CompileShader(String a_sVertexShaderFile, String a_sFragmentShaderFile, String a_sProgramName = "");

	/// <summary>
	/// Program Name field accessor.
	/// </summary>
	/// <returns>The program name.</returns>
	String GetProgramName();

	/// <summary>
	/// Vertex shader field accessor.
	/// </summary>
	/// <returns>The Shader's vertex shader.</returns>
	String GetVertexShader();

	/// <summary>
	/// Fragment shader field accessor.
	/// </summary>
	/// <returns>The Shader's fragment shader.</returns>
	String GetFragmentShader();

	/// <summary>
	/// Program ID field accessor.
	/// </summary>
	/// <returns>The Shader's program ID.</returns>
	int GetProgramID();
};

}

#endif //__SHADER_H_