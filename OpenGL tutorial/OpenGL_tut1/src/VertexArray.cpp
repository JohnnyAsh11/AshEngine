#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &_rendererID));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &_rendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, VertexBufferLayout& layout)
{
    Bind();
	vb.Bind();

    unsigned int offset = 0;
    const std::vector<VertexBufferElement>& elements = layout.GetElements();

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const VertexBufferElement& element = elements[i];

        // Must be used while a buffer is bound for the next 2 functions
        // the last 0 is to the next attribute within the vertex, so 0 because we only have 1 
        // attribute but if we had more it would be the bits to the next attribute.
        // -> you need to cast it to a (const void*) in order for it to compile.
        GLCall(glEnableVertexAttribArray(i));

        GLCall(
            glVertexAttribPointer(
                i, 
                element.count, 
                element.type, 
                element.normalized, 
                layout.GetStride(),
                (const void*)offset)
        );

        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }

}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(_rendererID));
}

void VertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0));
}
