#pragma once

#include "Renderer.h"
#include <vector>
#include <exception>

struct VertexBufferElement
{
public:
	VertexBufferElement(unsigned int type, unsigned int count, unsigned int normalized)
	{
		this->type = type;
		this->count = count;
		this->normalized = normalized;
	}

	unsigned int count;
	unsigned int type;
	unsigned int normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
			case GL_FLOAT:			 return 4;
			case GL_UNSIGNED_INT:	 return 4;
			case GL_UNSIGNED_BYTE:	 return 1;
		}

		ASSERT(false);
		return 0;
	}
};


class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> _elements;
	unsigned int _stride;

public:
	VertexBufferLayout()
	{
		_stride = 0;
	}

	template<typename T>
	void Push(unsigned int count)
	{
		throw std::exception("TYPAL ERROR IN VBL");
	}

	template<>
	void Push<float>(unsigned int count)
	{
		_elements.push_back(VertexBufferElement(GL_FLOAT, count, GL_FALSE));
		_stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		_elements.push_back(VertexBufferElement(GL_UNSIGNED_INT, count, GL_FALSE));
		_stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		_elements.push_back(VertexBufferElement(GL_UNSIGNED_BYTE, count, GL_TRUE));
		_stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement>& GetElements() const { return _elements; };
	inline unsigned int GetStride() const { return _stride; }
};

