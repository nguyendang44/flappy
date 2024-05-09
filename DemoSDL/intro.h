#ifndef INTRO_H
#define INTRO_H

#include "defs.h"
#include "texture.h"
#include "background.h"
#include "font.h"
#include "mainwindow.h"
class Intro {
    const MainWindow& win;
    const int fl;
    Background background;
    Background tap;
    Background ready;
    Texture p1;
    Background up;
public:
    Intro(const MainWindow&,const int fl);
    Intro(const Intro&) = delete;
    Intro& operator=(const Intro&) = delete;

    void logic();
    void render();
};

#endif // INTRO_H
