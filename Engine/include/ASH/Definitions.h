#ifndef __DEFINITIONS_H_
#define __DEFINITIONS_H_

#include <iostream>

// Including OpenGL extension wranglers.
#include <GL/glew.h>
#include <GL/wglew.h>

// Including GLM.
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\ext.hpp>
#include <glm\gtc\quaternion.hpp>
#include <glm\gtx\matrix_decompose.hpp>

#ifdef ASH_EXPORTS
#define ASH_API __declspec(dllexport)
#else
#define ASH_API __declspec(dllimport)
#endif

/* Helper macro for the GLCall macro. If the passed in value evaluates to
    false, it will halt execution at that line of code. */
#define ASSERT(x) if (!(x)) __debugbreak();

/* Error handling macro for GL function calls. */
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

/* Safely reallocates memory.  Deletes data and initializes the pointer to nullptr. */
#define Realloc(p) { if (p) { delete p; p = nullptr; } }

namespace ASH
{
    #pragma region Typedefs
    typedef glm::vec2 Vector2;
    typedef glm::vec3 Vector3;
    typedef glm::vec4 Vector4;
    typedef glm::mat3 Matrix3;
    typedef glm::mat4 Matrix4;
    typedef glm::quat Quaternion;
    typedef std::string String;
    #pragma endregion

    /// <summary>
    /// Converts a Quaternion into a Matrix4.
    /// </summary>
    /// <param name="a_qInput">The Quaternion being converted.</param>
    /// <returns>The converted Matrix4.</returns>
    ASH_API Matrix4 ToMatrix4(Quaternion a_qInput);

    /// <summary>
    /// Checks that there are no errors coming from OpenGL.
    /// </summary>
    ASH_API void GLClearError(void);

    /// <summary>
    /// Logs the OpenGL function calls if they fail as outlined in the macro using GLLogCall.
    /// </summary>
    /// <param name="a_sFunction">The calling function name.</param>
    /// <param name="a_sFile">The file location of the calling function.</param>
    /// <param name="a_uLine">The line that the calling function is on.</param>
    /// <returns>False if there is an error and true if not.  Slightly unintuitive.</returns>
    ASH_API bool GLLogCall(const char* a_sFunction, const char* a_sFile, int a_uLine);

    /// <summary>
    /// Loads and compiles the shaders for the program. 
    /// </summary>
    /// <param name="a_sVertexShader">Filepath to the vertex shader being used.</param>
    /// <param name="a_sFragmentShader">Filepath to the the fragment shader being used.</param>
    /// <returns>The OpenGL identifier of the shaders.</returns>
    ASH_API GLuint LoadShaders(const char* a_sVertexShader, const char* a_sFragmentShader);
}

// Macro variables:
#define PI 3.1415926535
#define IDENTITY_M4 Matrix4(1.0f);
#define VECTOR3_ZERO Vector3(0.0f);

// Axes:
#define AXIS_X Vector3(1.0f, 0.0f, 0.0f)
#define AXIS_Y Vector3(0.0f, 1.0f, 0.0f)
#define AXIS_Z Vector3(0.0f, 0.0f, 1.0f)

// Colors:
#define CORNFLOWER_BLUE Vector4(0.39f, 0.58f, 0.92f, 1.0f)
#define PAPAYA_ORANGE Vector4(0.99f, 0.5f, 0.0f, 1.0f)
#define EMERALD_GREEN Vector4(0.12f, 0.3f, 0.18f, 1.0f)

#define RED Vector4(1.0f, 0.0f, 0.0f, 1.0f)
#define ORANGE Vector4(1.0f, 0.5f, 0.0f, 1.0f)
#define YELLOW Vector4(1.0f, 1.0f, 0.0f, 1.0f)
#define GREEN Vector4(0.0f, 1.0f, 0.0f, 1.0f)
#define BLUE Vector4(0.0f, 0.0f, 1.0f, 1.0f)
#define PURPLE Vector4(0.6f, 0.0f, 1.0f, 1.0f)
#define PINK Vector4(1.0f, 0.0f, 1.0f, 1.0f)

// Default values:
#define ERROR 0
#define SUCCESS 1

#define NULL_STR ""

#endif //__DEFINTIONS_H_
