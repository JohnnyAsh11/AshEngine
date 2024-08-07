#include "IndexBuffer.h"

#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
{
    _count = count;

    // Double checking that the unsigned int is the same size as the GLuint.
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    // Actually declaring what the buffer is.
    GLCall(glGenBuffers(1, &_rendererID));

    // OpenGL will ONLY draw the currently bound buffer.
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID));

    // 6 * sizeof(float) gets the amount of data in the positions array multiplied by 
    //  the bit size of a float.
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &_rendererID))
}

void IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID));
}

void IndexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
