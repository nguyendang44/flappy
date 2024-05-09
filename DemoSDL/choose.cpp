#include "menu.h"
#include "mainwindow.h"
#include "defs.h"
#include "choose.h"

Choose::Choose(const MainWindow& _win,const int _vol,const int _volt)
    :win(_win),
    vol(_vol),
    volt(_volt),
    background{_win.getRenderer(), BACKGROUND_INTRO},
    vang{_win.getRenderer(), BIRD_CHOOSE1},
    hong{_win.getRenderer(), BIRD_CHOOSE2},
    t{_win.getRenderer()},
    vt{_win.getRenderer()}
{
    if(vol==1){t.loadFromFile(VOL_ON);}
    else{t.loadFromFile(VOL_OFF);};
    if(volt==1){vt.loadFromFile(VOLT_ON);}
    else{vt.loadFromFile(VOLT_OFF);};
}
void Choose::logic()
{
    background.scroll(0);
}

void Choose::render()
{
    win.clear();
    background.render();
    t.render(300,300);
    vt.render(350,300);
    vang.render1(150,150);
    hong.render1(400,150);
    win.update();
}
