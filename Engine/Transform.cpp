#include "Transform.h"

using namespace ASH;

Transform::Transform(void)
{
	m_bIsDirty = false;
	m_v3Rotation = VECTOR3_ZERO;
	m_v3Position = VECTOR3_ZERO;
	m_v3Scale = VECTOR3_ZERO;
	m_m4WorldMatrix = IDENTITY_M4;
}

ASH::Vector3& Transform::GetRotation(void)
{
	m_bIsDirty = true;
	return m_v3Rotation;
}
ASH::Vector3& Transform::GetPosition(void)
{
	m_bIsDirty = true;
	return m_v3Position;
}
ASH::Vector3& Transform::GetScale(void)
{
	m_bIsDirty = true;
	return m_v3Scale;
}

void Transform::SetRotation(ASH::Vector3 a_v3Rotation)
{
	m_v3Rotation = a_v3Rotation;
	m_bIsDirty = true;
}
void Transform::SetPosition(ASH::Vector3 a_v3Position)
{
	m_v3Position = a_v3Position;
	m_bIsDirty = true;
}
void Transform::SetScale(ASH::Vector3 a_v3Scale)
{
	m_v3Scale = a_v3Scale;
	m_bIsDirty = true;
}

void Transform::Rotate(ASH::Vector3 a_v3Offset)
{
	m_v3Rotation += a_v3Offset;
	m_bIsDirty = true;
}
void Transform::MoveRelative(ASH::Vector3 a_v3Offset)
{
	// Constructing the rotation matrix.
	Matrix4 ro;
	if (m_v3Rotation.x > 0) ro *= glm::rotate(IDENTITY_M4, m_v3Rotation.x, AXIS_X);
	if (m_v3Rotation.y > 0) ro *= glm::rotate(IDENTITY_M4, m_v3Rotation.y, AXIS_Y);
	if (m_v3Rotation.z > 0) ro *= glm::rotate(IDENTITY_M4, m_v3Rotation.z, AXIS_Z);

	m_bIsDirty = true;

	// Creating a quaternion from the rotation matrix.
	Quaternion roQuat = glm::toQuat(ro);

	// Rotating the absolute offset by the quaternion to make the movement relative.
	Vector3 v3Result = a_v3Offset * roQuat;

	// Adding the result to the Position.
	m_v3Position += v3Result;
}
void Transform::MoveAbsolute(ASH::Vector3 a_v3Offset)
{
	m_v3Position += a_v3Offset;
	m_bIsDirty = true;
}
void Transform::Scale(ASH::Vector3 a_v3ScaleFactor)
{
	m_v3Scale *= a_v3ScaleFactor;
	m_bIsDirty = true;
}

ASH::Matrix4 Transform::GetWorld(void)
{
	// Do not redo calculations that have already been done.
	if (!m_bIsDirty) return m_m4WorldMatrix;

	// Constructing the scale and translation matrices.
	Matrix4 sc = glm::scale(IDENTITY_M4, m_v3Scale);
	Matrix4 tr = glm::translate(IDENTITY_M4, m_v3Position);
	Matrix4 ro;

	// Constructing the rotation matrix.
	if (m_v3Rotation.x > 0) ro *= glm::rotate(IDENTITY_M4, m_v3Rotation.x, AXIS_X);
	if (m_v3Rotation.y > 0) ro *= glm::rotate(IDENTITY_M4, m_v3Rotation.y, AXIS_Y);
	if (m_v3Rotation.z > 0) ro *= glm::rotate(IDENTITY_M4, m_v3Rotation.z, AXIS_Z);

	// Calculating the world matrix.
	m_m4WorldMatrix = sc * tr * ro;

	m_bIsDirty = false;
	return m_m4WorldMatrix;
}
