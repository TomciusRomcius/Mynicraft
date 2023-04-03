#pragma once
#include "Core/Texture.h"
#include "Shapes.h"


class Block
{
public:
	Block(glm::vec3 position, glm::vec2 atlasPosition, unsigned int texCount);
	std::vector<glm::vec3> m_Vertices = CUBE_VERTICES;
	std::vector<glm::vec2> m_TexCoords;
	std::vector<unsigned int> m_Indices = CUBE_INDICES;
	//std::vector<glm::vec3> m_Normals = CUBE_NORMALS;
};

