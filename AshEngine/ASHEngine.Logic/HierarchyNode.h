#pragma once

/// <summary>
/// A single Node contained within the Hierarchy Linked Data Structure
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class HierarchyNode
{

private:
	// ====== FIELDS ===== //
	HierarchyNode* _next;
	HierarchyNode* _previous;
	T _data;

public:

	// ====== CONSTRUCOTRS ===== //
	HierarchyNode(T data)
	{
		_data = data;
	}

	HierarchyNode(const& HierarchyNode original)
	{
		// Only constructing the _next and _previous fields with the original ptr values 
		// if they contain values.
		if (original._next != nullptr)
		{
			_next = original._next;
		}

		if (original._previous != nullptr)
		{
			_previous = original._previous;
		}

		// Setting the data.
		_data = original._data;
	}

	// ===== DESTRUCTOR ====== //
	~HierarchyNode()
	{
		delete _next;
		delete _previous;
	}

	// ====== METHODS ====== //
	HierarchyNode<T> GetNextNode()
	{
		return *_next;
	}
	HierarchyNode<T> GetPreviousNode()
	{
		return *_previous;
	}
	T GetData()
	{
		return _data;
	}

	void SetNextNode()

	// ====== OPERATOR OVERLOADS ====== //
	HierarchyNode& operator =(const HierarchyNode& original)
	{
		if (_next != nullptr)
		{
			delete _next;
		}

		if (_previous != nullptr)
		{
			delete _previous;
		}

		_next = original._next;
		_previous = original._previous;
		_data = original._data;
	}

};

