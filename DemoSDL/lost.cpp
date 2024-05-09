#include "lost.h"
#include "mainwindow.h"
#include "defs.h"
Lost::Lost(const MainWindow& _win,const int _score,const int _vol,const int _volt)
    :win(_win),
    score(_score),
    vol(_vol),
    volt(_volt),
    background{_win.getRenderer(), BACKGROUND_LEVEL},
    bang{_win.getRenderer(), BACKGROUND_GAMEOVER},
    play{_win.getRenderer(), PLAY_IMAGE},
    t{_win.getRenderer()},
    cup{_win.getRenderer()},
    v{_win.getRenderer()},
    vt{_win.getRenderer()},
    tomenu{_win.getRenderer()}
{
    std::string str = std::to_string(score);
    Font bigfont;
    bigfont.loadFromFile(FONT_PATH, TEXT_SIZE_BIG);
    t.loadFromRenderedText(str, bigfont, SDL_Color{0,0,0,0xFF});
    if(score<10){cup.loadFromFile(LOST_DONG);}
    else if(score<20){cup.loadFromFile(LOST_BAC);}
    else{cup.loadFromFile(LOST_VANG);};
    if(vol==1){v.loadFromFile(VOL_ON);}
    else{v.loadFromFile(VOL_OFF);};
    if(volt==1){vt.loadFromFile(VOLT_ON);}
    else{vt.loadFromFile(VOLT_OFF);};
    tomenu.loadFromFile(TO_MENU);
}

void Lost::logic()
{
    background.scroll(3);
}

void Lost::render()
{
    win.clear();
    background.render();
    bang.render1(220,0);
    t.render(410,105);
    cup.render(240,120);
    play.render1(300,300);
    v.render(300,250);
    vt.render(360,250);
    tomenu.render(0,430);
    win.update();
}
