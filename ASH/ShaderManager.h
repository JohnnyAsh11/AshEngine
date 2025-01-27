#ifndef __SHADERMMANAGER_H_
#define __SHADERMANAGER_H_

#include "Shader.h"
#include <vector>
#include <map>

namespace ASH 
{
	class ASH_API ShaderManager
	{
	private:
		static ShaderManager* m_pInstance;

		std::vector<Shader> m_lShaders;
		std::map<String, int> m_mShaderIDs;
	public:
		static ShaderManager* GetInstance();

		static void ReleaseInstance();

	private:

	};
}

#endif //__SHADERMANAGER_H_

