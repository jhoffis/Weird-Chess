#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <stdexcept>
#include "src/Shader.h"

struct CharImage {
    int w;
    int h;
    int comp;
    unsigned char *image;
};

CharImage createCharImage(const char *path, bool flip);
void createGLImage(CharImage &img);
unsigned int createTexture(CharImage &img);


#endif