#include "pch.h"
#include "Definitions.h"

using namespace ASH;

ASH_API Matrix4 ASH::ToMatrix4(Quaternion a_qInput)
{
	return glm::mat4_cast(a_qInput);
}

ASH_API void ASH::GLClearError(void)
{
	while (glGetError() != GL_NO_ERROR);
}

ASH_API bool ASH::GLLogCall(const char* a_sFunction, const char* a_sFile, int a_uLine)
{
    while (GLenum error = glGetError())
    {
        // Breaking in to this line and viewing the value of error as
        // a hexidecimal will allow you to get the correct value to search for
        // in GLEW Header files.
        std::cout << "OPENGL ERROR (" << error << "): " << a_sFunction <<
            " " << a_sFile << ":" << a_uLine << std::endl;
        return false;
    }

    return true;
}