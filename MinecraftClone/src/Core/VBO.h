#pragma once
#include "Log.h"

namespace Engine3D
{
	class  VBO
	{
	public:
		explicit VBO(const std::vector<glm::vec3>& vertices);
		explicit VBO(const std::vector<glm::vec3>& vertices, const std::vector<glm::vec2> texCoords);

		void Bind() const;
		~VBO();
	private:
		unsigned int id;
		unsigned int vao;
	};

}
