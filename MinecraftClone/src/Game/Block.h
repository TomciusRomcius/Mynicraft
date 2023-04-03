#pragma once
#include "Core/Texture.h"
#include "Shapes.h"


class Block
{
public:
	Block(glm::vec3 position, std::vector<glm::vec2> uv);


	inline const std::vector<glm::vec3>& GetVertices() const
	{
		return m_Vertices;
	}

	inline const std::vector<glm::vec2>& GetUV() const
	{
		return m_TexCoords;
	}

	inline const std::vector<unsigned int>& GetIndices() const
	{
		return m_Indices;
	}
private:
	std::vector<glm::vec3> m_Vertices = CUBE_VERTICES;
	std::vector<glm::vec2> m_TexCoords;
	std::vector<unsigned int> m_Indices = CUBE_INDICES;
	//std::vector<glm::vec3> m_Normals = CUBE_NORMALS;
};

