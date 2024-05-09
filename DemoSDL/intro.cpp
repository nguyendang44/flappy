#include "intro.h"
#include "mainwindow.h"
#include "defs.h"

Intro::Intro(const MainWindow& _win,const int _fl)
    :win(_win),
    fl(_fl),
    background{_win.getRenderer(), BACKGROUND_INTRO},
    tap{_win.getRenderer(),BACKGROUND_TAP},
    ready{_win.getRenderer(),BACKGROUND_READY},
    p1(_win.getRenderer()),
    up(_win.getRenderer(),BACKGROUND_UP)
{
    if(fl==1){p1.loadFromFile(BIRD_IMAGE2);}
    else{p1.loadFromFile(BIRD_IMAGE);};
}

void Intro::logic()
{
    background.scroll(3);
}

void Intro::render()
{
    win.clear();
    background.render();
    tap.render1(10,130);
    ready.render1(80,0);
    up.render1(120,380);
    p1.render(120,230);
    win.update();
}
