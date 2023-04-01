#include "pch.h"
#include "Shader.h"

#define DSHADER_PATH(shader) (std::string("src/Shaders/") + std::string(shader)).c_str()

namespace Engine3D
{
	Shader::Shader(unsigned int shaderType, const char* src)
	{
		id = glCreateShader(shaderType);
		std::string source = ReadSource(DSHADER_PATH(src));
		const char* csource = source.c_str();
		glShaderSource(id, 1, &csource, 0);
		glCompileShader(id);

		GLint success = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			auto message = malloc(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, (GLchar*)message);
			std::cout << message << std::endl;
			glDeleteShader(id);
			delete(message);
		}
	}

	std::string Shader::ReadSource(const char* filePath) const
	{
		std::fstream file(filePath, std::ios::in);
		if (!file.is_open())
		{
			std::cout << "Failed to load shader: " << filePath << std::endl;
			return "err";
		}

		std::string content;
		std::string line = "";
		while (!file.eof())
		{
			std::getline(file, line);
			content.append(line + "\n");
		}
		file.close();
		return content;

		return nullptr;
	}
}