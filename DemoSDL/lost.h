#ifndef LOST_H
#define LOST_H

#include "defs.h"
#include "texture.h"
#include "background.h"
#include "font.h"
#include "mainwindow.h"
#include <string>
class Lost {
    const MainWindow& win;
    const int score;
    const int vol;
    const int volt;
    const int point;
    Background background;
    Background bang;
    Background play;
    Texture t;
    Texture p;
    Texture cup;
    Texture v;
    Texture vt;
    Texture tomenu;
public:
    Lost(const MainWindow&,const int score,const int vol,const int volt,const int point);
    Lost(const Lost&) = delete;
    Lost& operator=(const Lost&) = delete;
    void logic();
    void render();
};

#endif
