#include "pch.h"
#include "Chunk.h"
#include "PerlinNoise.hpp"

Chunk::Chunk(int chunkX, int chunkZ)
{
	std::random_device rd;
	unsigned int seed = rd();
	siv::PerlinNoise perlin{ seed };

	std::vector<Block> blocks;
	std::vector<glm::vec3> cubePositions;
	std::vector<glm::vec3> airBlockPositions;

	// Generate airblocks
	for (int x = 0; x < MAX_LENGTH; x++)
	{
			for (int z = 0; z < MAX_LENGTH; z++)
			{
				int height = round(perlin.octave2D_01(x * 0.01f, z * 0.01f, 2, 0.5f) * MAX_HEIGHT);
				airBlockPositions.push_back({ x + chunkX * MAX_LENGTH, height, z + chunkZ * MAX_LENGTH });

			}
	}

	for (int x = 0; x < MAX_LENGTH; x++)
	{
		for (int y = 0; y < MAX_HEIGHT; y++)
		{
			for (int z = 0; z < MAX_LENGTH; z++)
			{
				glm::vec3 position{ x + chunkX * MAX_LENGTH , y, z + chunkZ * MAX_LENGTH };
				for (const auto& airBlock : airBlockPositions)
				{
					if (glm::distance(position, airBlock) == 1)
					{
						blocks.push_back(Block({ position, { 0, 0 }, 3 }));
					}
				}
			}
		}
	}

	int n = 0;

	for (auto& block : blocks)
	{
		for (auto& v : block.m_Vertices)
		{
			vertices.push_back(v);
		}
		for (auto& in : block.m_Indices)
		{
			indices.push_back(in + n * 24); // 24 vertices in a cube
		}
		for (auto& uv : block.m_TexCoords)
		{
			texCoords.push_back(uv);
		}
		n++;
	}
}

bool Chunk::IsNeighborAir(glm::vec3 cube)
{

	return false;
}
