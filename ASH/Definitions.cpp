#include "pch.h"
#include "Definitions.h"

using namespace ASH;

ASH_API Matrix4 ASH::ToMatrix4(Quaternion a_qInput)
{
	return glm::mat4_cast(a_qInput);
}