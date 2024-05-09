#ifndef CHOOSE_H
#define CHOOSE_H

#include "defs.h"
#include "texture.h"
#include "font.h"
#include "mainwindow.h"
#include "background.h"


class Choose {
    const MainWindow& win;
    const int vol;
    const int volt;
    Background background;
    Background vang;
    Background hong;
    Texture t;
    Texture vt;
public:
    Choose(const MainWindow&,const int vol,const int volt);
    Choose(const Choose&) = delete;
    Choose& operator=(const Choose&) = delete;
    void logic();
    void render();
};


#endif // CHOOSE_H
