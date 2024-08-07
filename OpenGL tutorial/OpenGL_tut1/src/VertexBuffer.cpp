#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    // Actually declaring what the buffer is.
    GLCall(glGenBuffers(1, &_rendererID));

    // OpenGL will ONLY draw the currently bound buffer.
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, _rendererID));

    // 6 * sizeof(float) gets the amount of data in the positions array multiplied by 
    //  the bit size of a float.
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &_rendererID))
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, _rendererID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
