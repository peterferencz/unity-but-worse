#pragma once
#include "graphics/mesh/Mesh.h"

class BirdMesh : public Mesh {
public:
    BirdMesh() : Mesh({
        // Position               // Normal (Approx)  // UVs
        {{ 0.0f,  0.5f,  0.0f},  {0.0f,  1.0f, 0.0f}, {0.5f, 0.5f}}, // 0: Top Spine Peak
        {{-0.8f,  0.0f,  0.0f},  {-1.0f, 0.0f, 0.0f}, {0.0f, 0.5f}}, // 1: Left Wing Tip
        {{ 0.8f,  0.0f,  0.0f},  {1.0f,  0.0f, 0.0f}, {1.0f, 0.5f}}, // 2: Right Wing Tip
        {{ 0.0f,  0.0f,  0.6f},  {0.0f,  0.0f, 1.0f}, {0.5f, 1.0f}}, // 3: Tail End
        {{ 0.0f,  0.1f, -0.6f},  {0.0f,  0.0f,-1.0f}, {0.5f, 0.0f}}  // 4: Beak Tip
    }, {
        // Main Body Pyramid
        0, 1, 3, // Left Back flank
        0, 3, 2, // Right Back flank
            
        // Beak / Head Pyramid
        0, 4, 1, // Left Front flank
        0, 2, 4  // Right Front flank
    }) {

    }
};