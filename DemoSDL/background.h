#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "texture.h"

#include <string>
#include <SDL.h>

class Background {
    Texture t;
    int scrollingOffset;
    int x=0;
    int y=0;
public:
    Background(SDL_Renderer* renderer, const std::string& path);

    void render();
    void render1(int x,int y);
    void scroll(int distance);
};

#endif // BACKGROUND_H
