#pragma once

#include "Core/VBO.h"
#include "Core/EBO.h"
#include "Core/Program.h"
#include "Shapes.h"
#include "Core/SceneCamera.h"
#include "Window.h"
#include "Chunk.h"
#include "Core/Texture.h"

using namespace Engine3D;

class World
{
public:

	World();

	void Render();
private:
	Program* m_Program;
	Texture* texture;
	VBO* m_Vbo;
	EBO* m_Ebo;
	Chunk* m_Chunk;
	glm::mat4 mvp;
};

