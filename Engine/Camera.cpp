#include "Camera.h"

using namespace ASH;

Matrix4 Camera::GetView()
{
    return IDENTITY_M4;
}

Matrix4 Camera::GetProjection()
{
    return IDENTITY_M4;
}
