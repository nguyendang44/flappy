#ifndef PLAYER_H
#define PLAYER_H

#include "texture.h"

class Player {
    Texture texture;
    const int fl;
public:
    bool isDead;
    double posX, posY;
    double radius;
    double vertSpeed, vertAccel;

    Player(SDL_Renderer* renderer, double x, double y,const int fl);

    void make_jump();
    void render();
    void apply_forces();
};

#endif // PLAYER_H
