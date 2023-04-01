#include "pch.h"
#include "Program.h"

namespace Engine3D
{
	Program::Program(Shader* vertexShader, Shader* fragmentShader)
	{
		id = glCreateProgram();
		glAttachShader(id, vertexShader->Id());
		glAttachShader(id, fragmentShader->Id());
		glLinkProgram(id);

		int status;
		glGetProgramiv(id, GL_LINK_STATUS, &status);
		if (status == GL_FALSE)
			EN_ERROR("Faield to create the program")
	}

	void Program::UseProgram() const
	{
		glUseProgram(id);
	}

	unsigned int Program::Id() const
	{
		return id;
	}
	bool Program::Error() const
	{
		return error;
	}
}
