//
// Created by Jens Benz on 07.03.2021.
//
#include "ResourceLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

CharImage createCharImage(const char *path, bool flip) {
    stbi_set_flip_vertically_on_load(flip);
    CharImage res{};
    std::string currPath = "res/pics/";
    currPath.append(path);
    const char *realPath = reinterpret_cast<const char *>(currPath.c_str());

    res.image = stbi_load(realPath, &res.w, &res.h, &res.comp, STBI_rgb_alpha);

    if (res.image == nullptr)
        throw std::runtime_error(std::string("Failed to load texture at ").append(realPath));
    return res;
}

void createGLImage(CharImage &img) {  // Kanskje jeg kan ta char * og kutte vekk alt etter x24 y24 etc?
    if (img.image)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.w, img.h, 0, (img.comp == 4 ? GL_RGBA : GL_RGB), GL_UNSIGNED_BYTE, img.image);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(img.image);
}

unsigned int createTexture(CharImage &img) {
    unsigned int texture{};
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load and generate the texture
    createGLImage(img);
    glBindTexture(GL_TEXTURE_2D, 0);
    return texture;
}