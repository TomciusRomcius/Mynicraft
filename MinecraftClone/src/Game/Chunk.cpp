#include "pch.h"
#include "Chunk.h"
#include "PerlinNoise.hpp"

Chunk::Chunk(int chunkX, int chunkZ)
{
	airBlockPositions = {};
	std::random_device rd;
	unsigned int seed = rd();
	siv::PerlinNoise perlin{ seed };

	std::vector<Block> blocks;
	std::vector<glm::vec3> cubePositions;
	std::vector<glm::vec3> airBlockPositions;

	this->octave2D_01 = [&](float x, float y) { return perlin.octave2D_01(x, y, 2, 0.5f); };
	

	vertices = {};
	indices = {};
	texCoords = {};

	// Generate airblocks
	/*
	for (int x = 0; x < MAX_LENGTH; x++)
	{
		for (int z = 0; z < MAX_LENGTH; z++)
		{
			int height = round(perlin.octave2D_01(x * 1.3f, z * 1.5f, 2, 0.5f) * MAX_HEIGHT);
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
	*/


	for (int x = 0; x < MAX_LENGTH; x++) {
		for (int z = 0; z < MAX_LENGTH; z++) {
			int height = round(perlin.octave2D_01(x * 0.1, z * 0.1, 2, 0.5f) * MAX_HEIGHT);
			heightMap[x][z] = height;
		}
	}

	int n = 0;
	/*
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
	*/
	GenerateMesh();

}

void Chunk::GenerateMesh()
{	
	// Generate air blocks
	for (int x = 0; x < MAX_LENGTH; x++)
	{
		for (int z = 0; z < MAX_LENGTH; z++)
		{
			airBlockPositions.insert({ x, heightMap[x][z], z });
		}
	}

	// Generate missing air blocks due to big height differences


	// Check all four directions
	for (int x = 0; x < MAX_LENGTH; x++) {
		for (int z = 0; z < MAX_LENGTH; z++) {
			for (int dx = -1; dx <= 1; dx++)
			{
				for (int dz = -1; dz <= 1; dz++)
				{
					if (dx == 0 && dz == 0) continue;
					if (x + dx < 0 || x + dx >= MAX_LENGTH || z + dz < 0 || z + dz >= MAX_LENGTH) continue;
					int diff = heightMap[x][z] - heightMap[x + dx][z + dz];
					if (diff > 1)
					{
						for (int i = 1; i <= diff; i++)
						{
							airBlockPositions.insert({ x + dx, heightMap[x][z] - i, z + dz});
						}
					}
				}
			}
		}
	}

	// Generate blocks

	std::vector<Block> blocks;

	for (auto& airBlock : airBlockPositions)
	{
		blocks.push_back(Block({ airBlock, { 0, 0 }, 3 }));
	}

	// Generate mesh

	for (int i = 0; i < blocks.size(); i++)
	{
		for (auto& v : blocks[i].m_Vertices)
		{
			vertices.push_back(v);
		}
		for (auto& in : blocks[i].m_Indices)
		{
			indices.push_back(in + i * 24); // 24 vertices in a cube
		}
		for (auto& uv : blocks[i].m_TexCoords)
		{
			texCoords.push_back(uv);
		}
	}
	
}

bool Chunk::IsNeighborAir(glm::vec3 cube)
{

	return false;
}
