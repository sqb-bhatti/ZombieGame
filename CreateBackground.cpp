//
// Created by Saqib Bhatti on 22/5/24.
//

#include "CreateBackground.h"



int createBackground(VertexArray& rVA, IntRect arena) {
    const int TILE_SIZE = 50;  // size in pixels of each tile within the sprite sheet.
    const int TILE_TYPES = 3;
    const int VERTS_IN_QUAD = 4;  // fact that there are four vertices in every quad.

    // width and height of the world in the number of tiles, not pixels. The worldWidth and worldHeight variables are
    // initialized by dividing the height and width of the passed-in arena by the TILE_SIZE constant.
    int worldWidth = arena.width / TILE_SIZE;
    int worldHeight = arena.height / TILE_SIZE;

    // Primitive are we using?
    rVA.setPrimitiveType(Quads);

    // Set the size of the vertex array
    rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

    // Start at the beginning of the vertex array. Will use currentVertex as we loop through the vertex array,
    // initializing all the vertices.
    int currentVertex = 0;

    for (int w = 0; w < worldWidth; w++) {
        for (int h = 0; h < worldHeight; h++) {
            // Position each vertex in the current quad. Set the position of each vertex
            rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
            rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
            rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
            rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

            /*
             vertex arrays can also be textured. To do so, you'll need to manipulate the texCoords attribute of the
             vertices. This attribute defines which pixel of the texture is mapped to the vertex.
             */
            // Define the position in the Texture for current quad. The condition checks whether the current quad is
            // either one of the very first or the very last quads in the arena. If it is (one of the first or last),
            // then this means it is part of the boundary.
            if (h == 0 || h == worldHeight-1 || w == 0 || w == worldWidth-1) {
                // Use the wall texture
                rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);

                rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);

                rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);

                rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
            }
            else {
                // Use a random floor texture
                srand((int)time(0) + h * w - h);
                int mOrG = (rand() % TILE_TYPES);  // initialized with a number between 0 and TILE_TYPES.
                int verticalOffset = mOrG * TILE_SIZE;

                rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
                rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
                rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
                rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
            }

            // Position ready for the next four vertices by advancing it four places. Either grass, stone, bush or wall
            currentVertex = currentVertex + VERTS_IN_QUAD;
        }
    }

    return TILE_SIZE;
}