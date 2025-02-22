#include "Entity.h"

using namespace ASH;

Entity::Entity(ASH::Mesh a_mMesh)
{
    m_pMesh = std::make_shared<Mesh>(a_mMesh);
    m_tTransform = Transform();
}

std::shared_ptr<ASH::Mesh> Entity::GetMesh()
{
    return m_pMesh;
}

Transform& Entity::GetTransform()
{
    return m_tTransform;
}

void Entity::Render(std::shared_ptr<Camera> a_pCamera)
{
    m_pMesh->Render(
        a_pCamera->GetView(),           // View Matrix.
        a_pCamera->GetProjection(),     // Projection Matrix.
        m_tTransform.GetWorld());       // World Matrix.
}
