#ifndef __ENTITY_H_
#define __ENTITY_H_

#include <ASH/Mesh.h>
#include <memory>
#include "Transform.h"
#include "Camera.h"

/// <summary>
/// Container for a Mesh and a Transform object.
/// </summary>
class Entity
{
private:
	Transform m_tTransform;
	std::shared_ptr<ASH::Mesh> m_pMesh = nullptr;

public:
	/// <summary>
	/// Constructs an instance of an entity in the world.
	/// </summary>
	/// <param name="a_mMesh">Mesh for the Entity.</param>
	Entity(ASH::Mesh a_mMesh);

	/// <summary>
	/// Gets the Mesh that the Entity is using.
	/// </summary>
	std::shared_ptr<ASH::Mesh> GetMesh();
	
	/// <summary>
	/// Gets the Transform of the Entity from the Entity.
	/// </summary>
	Transform& GetTransform();

	/// <summary>
	/// Renders the Entity to the game world.
	/// </summary>
	/// <param name="a_pCamera">Camera being used for view and projection matrices.</param>
	void Render(std::shared_ptr<Camera> a_pCamera);
};

#endif //__ENTITY_H_
