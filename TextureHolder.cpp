//
// Created by Saqib Bhatti on 27/5/24.
//

#include "TextureHolder.h"
#include <assert.h>


TextureHolder* TextureHolder::m_s_Instance = nullptr;


TextureHolder::TextureHolder() {
    assert(m_s_Instance == nullptr);  // ensures that m_s_Instance equals nullptr.
    m_s_Instance = this;  // we now have a pointer to a TextureHolder that points to the one and only instance
    // of itself.
}


Texture& TextureHolder:: GetTexture(string const& filename) {
    // Get a reference to m_Textures using m_s_Instance
    auto& m = m_s_Instance->m_Textures; // auto is the equivalent of map<string, Texture>

    // Create an iterator to search for the required key value pair using the passed in file name
    auto keyValuePair = m.find(filename);

    // // Did we find a match?
    if (keyValuePair != m.end()) {
        return keyValuePair->second;
    }
    else {
        // File name not found. // Create a new key value pair using the filename
        auto& texture = m[filename];

        // Load the texture from file in the usual way
        texture.loadFromFile(filename);

        // Return the texture to the calling code
        return texture;
    }
}