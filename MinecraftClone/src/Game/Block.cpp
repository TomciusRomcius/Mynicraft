#include "pch.h"
#include "Block.h"

Block::Block(glm::vec3 position, glm::vec2 atlasPosition, unsigned int texCount)
{
	switch (texCount)
	{
	case 1:
		m_TexCoords = CUBE1T_TEXCOORDS;
		break;
	case 2:
		m_TexCoords = CUBE2T_TEXCOORDS;
		break;
	case 3:
		m_TexCoords = CUBE3T_TEXCOORDS;
		break;
	default:
		break;
	}


	for (auto& uv : m_TexCoords)
	{
		uv.x = (uv.x + atlasPosition.x) / 16;  // Atlas width: 256, block width: 16
		uv.y = (uv.y + atlasPosition.y) / 16;  // Atlas height: 256, block height: 16
	}
	for (auto& v : m_Vertices)
	{
		v.x += position.x;
		v.y += position.y;
		v.z += position.z;
	}
}


