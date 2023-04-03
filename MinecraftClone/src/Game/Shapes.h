#pragma once
#include "pch.h"


    inline std::vector<glm::vec3> CUBE_VERTICES =
    {
    {-0.5f, -0.5f, 0.5f}, // 0: Bottom left front
    {0.5f, -0.5f, 0.5f},  // 1: Bottom right front
    {0.5f, 0.5f, 0.5f},   // 2: Top right front
    {-0.5f, 0.5f, 0.5f},  // 3: Top left front

    {-0.5f, -0.5f, -0.5f}, // 4: Bottom left back
    {-0.5f, 0.5f, -0.5f},  // 5: Top left back
    {0.5f, 0.5f, -0.5f},   // 6: Top right back
    {0.5f, -0.5f, -0.5f},  // 7: Bottom right back

    {-0.5f, 0.5f, -0.5f}, // 8: Top left back
    {-0.5f, 0.5f, 0.5f},  // 9: Top left front
    {0.5f, 0.5f, 0.5f},   // 10: Top right front
    {0.5f, 0.5f, -0.5f},  // 11: Top right back

    {-0.5f, -0.5f, 0.5f}, // 12: Bottom left front
    {-0.5f, -0.5f, -0.5f}, // 13: Bottom left back
    {0.5f, -0.5f, -0.5f},  // 14: Bottom right back
    {0.5f, -0.5f, 0.5f},   // 15: Bottom right front

    {-0.5f, -0.5f, -0.5f}, // 16: Bottom left back
    {-0.5f, 0.5f, -0.5f},  // 17: Top left back
    {-0.5f, 0.5f, 0.5f},   // 18: Top left front
    {-0.5f, -0.5f, 0.5f},  // 19: Bottom left front

    {0.5f, -0.5f, 0.5f},  // 20: Bottom right front
    {0.5f, 0.5f, 0.5f},   // 21: Top right front
    {0.5f, 0.5f, -0.5f},  // 22: Top right back
    {0.5f, -0.5f, -0.5f}
    };

    inline std::vector<unsigned int> CUBE_INDICES = {
        // Front face
        0, 1, 2,
        2, 3, 0,

        // Back face
        4, 5, 6,
        6, 7, 4,

        // Top face
        8, 9, 10,
        10, 11, 8,

        // Bottom face
        12, 13, 14,
        14, 15, 12,

        // Left face
        16, 17, 18,
        18, 19, 16,

        // Right face
        20, 21, 22,
        22, 23, 20,

        // Left face
        0, 3, 16,
        16, 19, 3,

        // Right face
        1, 2, 21,
        21, 20, 2

    };

    inline std::vector<glm::vec2> CUBE3T_TEXCOORDS =
    {
        // Front face
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),

        // Back face
        glm::vec2(1.0f, 0.0f),
        glm::vec2(0.0f, 0.0f),
        glm::vec2(0.0f, 1.0f),
        glm::vec2(1.0f, 1.0f),

        // Top face
        glm::vec2(1.0f, 0.0f),
        glm::vec2(2.0f, 0.0f),
        glm::vec2(2.0f, 1.0f),
        glm::vec2(1.0f, 1.0f),

        // Bottom face
        glm::vec2(2.0f, 0.0f),
        glm::vec2(3.0f, 0.0f),
        glm::vec2(3.0f, 1.0f),
        glm::vec2(2.0f, 1.0f),

        // Left face
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),

        // Right face
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),
    };

    inline std::vector<glm::vec2> CUBE2T_TEXCOORDS =
    {
        // Front face
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),

        // Back face
        glm::vec2(1.0f, 0.0f),
        glm::vec2(0.0f, 0.0f),
        glm::vec2(0.0f, 1.0f),
        glm::vec2(1.0f, 1.0f),

        // Top face
        glm::vec2(1.0f, 0.0f),
        glm::vec2(2.0f, 0.0f),
        glm::vec2(2.0f, 1.0f),
        glm::vec2(1.0f, 1.0f),

        // Bottom face
        glm::vec2(1.0f, 0.0f),
        glm::vec2(2.0f, 0.0f),
        glm::vec2(2.0f, 1.0f),
        glm::vec2(1.0f, 1.0f),

        // Left face
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),

        // Right face
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),
    };
inline std::vector<glm::vec2> CUBE1T_TEXCOORDS =
{
    // Front face
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),

    // Back face
    glm::vec2(1.0f, 0.0f),
    glm::vec2(0.0f, 0.0f),
    glm::vec2(0.0f, 1.0f),
    glm::vec2(1.0f, 1.0f),

    // Top face
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),

    // Bottom face
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),

    // Left face
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),

    // Right face
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),
};