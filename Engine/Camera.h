#ifndef __CAMERA_H_
#define __CAMERA_H_

#include <ASH/Definitions.h>

/// <summary>
/// Defines View and Projection matrix logic for rendering.
/// </summary>
class Camera
{
private:

public:
	
	ASH::Matrix4 GetView();
	ASH::Matrix4 GetProjection();

};

#endif //__CAMERA_H_
