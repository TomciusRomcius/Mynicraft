#pragma once
#include "pch.h"


    inline std::vector<glm::vec3> CUBE_VERTICES =
    {
    { -0.5f, -0.5f,  0.5f }, // 0: Front bottom left
    {  0.5f, -0.5f,  0.5f }, // 1: Front bottom right
    {  0.5f,  0.5f,  0.5f }, // 2: Front top right
    { -0.5f,  0.5f,  0.5f }, // 3: Front top left
    { -0.5f, -0.5f, -0.5f }, // 4: Back bottom left
    {  0.5f, -0.5f, -0.5f }, // 5: Back bottom right
    {  0.5f,  0.5f, -0.5f }, // 6: Back top right
    { -0.5f,  0.5f, -0.5f }  // 7: Back top left
    };

    inline std::vector<unsigned int> CUBE_INDICES =
    {
        // Front face
        0, 1, 2,
        2, 3, 0,
        // Back face
        5, 4, 7,
        7, 6, 5,
        // Top face
        3, 2, 6,
        6, 7, 3,
        // Bottom face
        0, 4, 5,
        5, 1, 0,
        // Right face
        1, 5, 6,
        6, 2, 1,
        // Left face
        4, 0, 3,
        3, 7, 4
    };
    inline std::vector<glm::vec2> CUBE_TEXCOORDS =
    {
        // Front face
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {1.0f, 1.0f},
        {0.0f, 1.0f},

        // Back face
        {1.0f, 0.0f},
        {1.0f, 1.0f},
        {0.0f, 1.0f},
        {0.0f, 0.0f},

        // Top face
        {0.0f, 1.0f},
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {1.0f, 1.0f},

        // Bottom face
        {1.0f, 1.0f},
        {0.0f, 1.0f},
        {0.0f, 0.0f},
        {1.0f, 0.0f},

        // Right face
        {1.0f, 0.0f},
        {1.0f, 1.0f},
        {0.0f, 1.0f},
        {0.0f, 0.0f},

        // Left face
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {1.0f, 1.0f},
        {0.0f, 1.0f}
    };
