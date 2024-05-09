#include "menu.h"
#include "mainwindow.h"
#include "defs.h"
#include "background.h"

Menu::Menu(const MainWindow& _win,const int _vol,const int _volt)
    :win(_win),
    vol(_vol),
    volt(_volt),
    background{_win.getRenderer(), BACKGROUND_MENU},
    t{_win.getRenderer()},
    vt{_win.getRenderer()}
{
    if(vol==1){t.loadFromFile(VOL_ON);}
    else{t.loadFromFile(VOL_OFF);};
    if(volt==1){vt.loadFromFile(VOLT_ON);}
    else{vt.loadFromFile(VOLT_OFF);};
}
void Menu::logic()
{
    background.scroll(0);
}

void Menu::render()
{
    win.clear();
    background.render();
    t.render(400,360);
    vt.render(450,360);
    win.update();
}
