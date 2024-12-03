#include "pch.h"
#include "Definitions.h"
#include "FileReader.h"
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

ASH_API GLuint ASH::LoadShaders(
    const char* a_sVertexShader, 
    const char* a_sFragmentShader)
{
    // Creating the shaders.
    GLuint uVertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint uFragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    String sVertexCode, sFragmentCode;

    // Getting a pointer to the FileReader singleton.
    FileReader* pFileReader = FileReader::GetInstance();

    // Reading in the shader code from the files.
    sVertexCode = pFileReader->ReadFile(a_sVertexShader);
    sFragmentCode = pFileReader->ReadFile(a_sFragmentShader);

    // Returning an error if either shader is an empty string.
    if (sVertexCode == "" || sFragmentCode == "")
    {
        return ERROR;
    }

    // Compiling the vertex shader:
    std::cout << "\n\tVertex: " << a_sVertexShader << ":\n" << sVertexCode << std::endl;
    char const* sVertexSource = sVertexCode.c_str();
    GLCall(glShaderSource(uVertexShaderID, 1, &sVertexSource, NULL));
    GLCall(glCompileShader(uVertexShaderID));

    // Compiling the fragment shader:
    std::cout << "\n\tFragment: " << a_sFragmentShader << ":\n" << sFragmentCode << std::endl;
    char const* sFragmentSource = sFragmentCode.c_str();
    GLCall(glShaderSource(uFragmentShaderID, 1, &sFragmentSource, NULL));
    GLCall(glCompileShader(uFragmentShaderID));

    // Linking the shaders to the program.
    GLuint uProgramID = glCreateProgram();
    GLCall(glAttachShader(uProgramID, uVertexShaderID));
    GLCall(glAttachShader(uProgramID, uFragmentShaderID));
    GLCall(glLinkProgram(uProgramID));

    GLCall(glDeleteShader(uFragmentShaderID));
    GLCall(glDeleteShader(uVertexShaderID));

    return uProgramID;
}