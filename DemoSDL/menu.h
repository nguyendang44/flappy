#ifndef MENU_H
#define MENU_H

#include "defs.h"
#include "texture.h"
#include "font.h"
#include "mainwindow.h"
#include "background.h"


class Menu {
    const MainWindow& win;
    const int vol;
    const int volt;
    Background background;
    Texture t;
    Texture vt;
public:
    Menu(const MainWindow&,const int vol,const int volt);
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    void logic();
    void render();
};


#endif // INTRO_H
