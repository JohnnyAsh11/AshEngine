#ifndef __TRANSFORM_H_
#define __TRANSFORM_H_

#include <ASH/Definitions.h>

/// <summary>
/// Tracks all transformation performed on an instance of an object in the world.
/// </summary>
struct Transform
{
private:
	bool m_bIsDirty;
	ASH::Vector3 m_v3Rotation;
	ASH::Vector3 m_v3Position;
	ASH::Vector3 m_v3Scale;
	ASH::Matrix4 m_m4WorldMatrix;
public:
	/// <summary>
	/// Default constructor for the Transform struct.
	/// </summary>
	Transform(void);

	/// <summary>
	/// Gets the rotation of the Transform.
	/// </summary>
	/// <returns>The address to the rotation Vector.</returns>
	ASH::Vector3& GetRotation(void);

	/// <summary>
	/// Gets the position of the Transform
	/// </summary>
	/// <returns>The address to the position Vector.</returns>
	ASH::Vector3& GetPosition(void);

	/// <summary>
	/// Gets the scale of the Transform.
	/// </summary>
	/// <returns>The address to the scale Vector.</returns>
	ASH::Vector3& GetScale(void);

	/// <summary>
	/// Sets the rotation vector for the Transform.
	/// </summary>
	/// <param name="a_v3Rotation">The new rotation vector for the Transform.</param>
	void SetRotation(ASH::Vector3 a_v3Rotation);

	/// <summary>
	/// Sets the position vector for the Transform.
	/// </summary>
	/// <param name="a_v3Position">The new position vector for the Transform.</param>
	void SetPosition(ASH::Vector3 a_v3Position);

	/// <summary>
	/// Sets the scale vector for the Transform.
	/// </summary>
	/// <param name="a_v3Scale">The new scale vector for the Transform.</param>
	void SetScale(ASH::Vector3 a_v3Scale);

	/// <summary>
	/// Adds a rotation Vector into the preexisting rotation.
	/// </summary>
	/// <param name="a_v3Offset">The rotational offset being added into the rotation.</param>
	void Rotate(ASH::Vector3 a_v3Offset);

	/// <summary>
	/// Moves the position of the Transform relative to the Transform's local coordinates.
	/// </summary>
	/// <param name="a_v3Offset">The offset that the Transform is being moved by.</param>
	void MoveRelative(ASH::Vector3 a_v3Offset);

	/// <summary>
	/// Moves the position of the Transform relative to the world's coordinates.
	/// </summary>
	/// <param name="a_v3Offset">The offset that the Transform is being moved by.</param>
	void MoveAbsolute(ASH::Vector3 a_v3Offset);

	/// <summary>
	/// Scales the Transform by a passed in factor.
	/// </summary>
	/// <param name="a_v3ScaleFactor">The scale factor that everything goes by.</param>
	void Scale(ASH::Vector3 a_v3ScaleFactor);

	/// <summary>
	/// Gets and potentially recalculates the world matrix of the Transform.
	/// </summary>
	/// <returns>Returns a copy of the Matrix4 world matrix.</returns>
	ASH::Matrix4 GetWorld(void);
};

#endif //__TRANSFORM_H_
