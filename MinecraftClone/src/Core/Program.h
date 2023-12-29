#pragma once
#include "Shader.h"
#include "Log.h"

namespace Engine3D
{
	class Program
	{
	public:
		Program(Shader* vertexShader, Shader* fragmentShader);
		void UseProgram() const;
		unsigned int Id() const;
		bool Error() const;
	private:
		unsigned int id;
	};
}
