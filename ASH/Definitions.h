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
    typedef glm::vec2 Vector2;
    typedef glm::vec3 Vector3;
    typedef glm::vec4 Vector4;
    typedef glm::mat3 Matrix3;
    typedef glm::mat4 Matrix4;
    typedef glm::quat Quaternion;
    typedef std::string String;

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
}

// Macro variables:
#define PI 3.1415926535
#define IDENTITY_M4 Matrix4(1.0f);
#define VECTOR3_ZERO Vector3(0.0f);

// Axes:
#define AXIS_X Vector3(1.0f, 0.0f, 0.0f)
#define AXIS_Y Vector3(0.0f, 1.0f, 0.0f)
#define AXIS_Z Vector3(0.0f, 0.0f, 1.0f)


#endif //__DEFINTIONS_H_
