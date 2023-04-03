#include "pch.h"
#include "Block.h"

Block::Block(glm::vec3 position, std::vector<glm::vec2> uv)
{
	for (int i = 0; i < uv.size(); i++)
	{
		uv[i].x /= 8; // Atlas width: 256, block width: 16
		uv[i].y /= 8; // Atlas height: 256, block height: 16
	}
	m_TexCoords = uv;
	for (auto& v : m_Vertices)
	{
		v.x += position.x;
		v.y += position.y;
		v.z += position.z;
	}
}


