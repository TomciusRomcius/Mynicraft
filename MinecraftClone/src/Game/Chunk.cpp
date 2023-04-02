#include "pch.h"
#include "Chunk.h"
#include "PerlinNoise.hpp"

Chunk::Chunk()
{
	int n = 0; // Used for indice calculations

	siv::PerlinNoise perlin{ 50 };

	// Generate terrain
	for (int x = 0; x < MAX_LENGTH; x++)
	{
		for (int y = 0; y < MAX_HEIGHT; y++)
		{

			for (int z = 0; z < MAX_LENGTH; z++)
			{
				// Calculate cube height and don't render the cube if height > noise

				float height = (CUBE_VERTICES[0].y + CUBE_VERTICES[2].y) / 2.f + y;
				if (height > (perlin.octave2D_01(x * .1f, z * .1f, 1, 0.1f) * MAX_HEIGHT) )
				{
					continue;
				}

				// Translate the cube

				for (auto v : CUBE_VERTICES)
				{
					v += glm::vec3(x, y, z);
					vertices.push_back(v);
				}
				// Translate all the indices
				for (auto in : CUBE_INDICES)
				{

					indices.push_back(in + n * 8);
				}
				for (auto t : CUBE_TEXCOORDS)
				{
					texCoords.push_back(t);
				}

				n++;
			}
		}
	}

}
