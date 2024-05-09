#include "mainwindow.h"
#include "defs.h"
#include "intro.h"
#include "level.h"
#include "music.h"
#include "menu.h"
#include "lost.h"
#include <SDL.h>
#include <memory>
#include"font.h"
#include "texture.h"
#include"choose.h"
#include <fstream>
using namespace std;
GameStates doMenu(MainWindow& win,int &vol,int &volt) {
    SDL_Event e;
    Music mus {MUSIC_THEME_PATH};
    int x, y;
    while (true) {
        Menu menu(win,vol,volt);
        menu.render();
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return GameStates::Quit;
            }
            SDL_GetMouseState(&x, &y);
            if (e.type == SDL_MOUSEBUTTONDOWN&&270<=x&&370>=x&&360<=y&&400>=y) {
                return GameStates::Choose;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN&&400<=x&&445>=x&&360<=y&&405>=y) {
                if(vol==1){
                    vol=0;
                    mus.stop();
                }else{
                    vol=1;
                    mus.play();
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN&&450<=x&&495>=x&&360<=y&&405>=y) {
                if(volt==1){
                    volt=0;
                }else{
                    volt=1;
                }
            }
        }
    }
}

GameStates doChoose(MainWindow& win,int &vol,int &fl,int &volt) {
    SDL_Event e;
    Music mus {MUSIC_THEME_PATH};
    int x, y;
    while (true) {
        Choose choose(win,vol,volt);
        choose.render();
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return GameStates::Quit;
            }
            SDL_GetMouseState(&x, &y);
            if (e.type == SDL_MOUSEBUTTONDOWN&&150<=x&&300>=x&&150<=y&&300>=y) {
                fl=1;
                return GameStates::Intro;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN&&400<=x&&550>=x&&150<=y&&300>=y) {
                fl=2;
                return GameStates::Intro;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN&&300<=x&&345>=x&&300<=y&&345>=y) {
                if(vol==1){
                    vol=0;
                    mus.stop();
                }else{vol=1;
                    mus.play();
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN&&350<=x&&395>=x&&300<=y&&345>=y) {
                if(volt==1){
                    volt=0;
                }else{
                    volt=1;
                }
            }
        }
    }
}

GameStates doIntro(MainWindow& win,int fl) {
    Intro intro(win,fl);
    SDL_Event e;

    while (true) {
        intro.render();
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return GameStates::Quit;
            }
            const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
            if (currentKeyStates[SDL_SCANCODE_UP]||e.type == SDL_MOUSEBUTTONDOWN) {
                return GameStates::Level;
            }
        }
    }
}

GameStates doLost(MainWindow& win,int score,int &vol,int &volt,int &point) {
    SDL_Event e;
    if(point<score){point=score;}
    ofstream outfile;
    outfile.open("score.txt");
    outfile << point << endl;
   // dong file da mo.
    outfile.close();
    Music mus {MUSIC_THEME_PATH};
    int x, y;
    while (true) {
        Lost lost(win,score,vol,volt,point);
        lost.render();
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return GameStates::Quit;
            }
            SDL_GetMouseState(&x, &y);
            if (e.type == SDL_MOUSEBUTTONDOWN&&300<=x&&400>=x&&300<=y&&400>=y) {
                return GameStates::Intro;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN&&300<=x&&345>=x&&250<=y&&295>=y) {
                if(vol==1){
                    vol=0;
                    mus.stop();
                }else{vol=1;
                    mus.play();
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN&&360<=x&&405>=x&&250<=y&&295>=y) {
                if(volt==1){
                    volt=0;
                }else{
                    volt=1;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN&&0<=x&&53>=x&&430<=y&&483>=y){
                return GameStates::Menu;
            }
        }
    }
}

GameStates doLevel(MainWindow& win,int &vol,int fl,int &volt,int&point) {
    Level level(win,fl,volt);

    while (level.next_state == GameStates::Null) {
        level.handle_events(volt);
        level.logic(volt);
        level.render();
    }
    if (level.next_state == GameStates::Lost) {
        return doLost(win,level.score,vol,volt,point);
    }
    return GameStates::Intro;
}

int main(int argc, char *argv[])
{
    MainWindow win (SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    win.setIcon(WINDOW_ICON_PATH);

    Music mus {MUSIC_THEME_PATH};
    mus.play();
    int vol=1;
    int fl=1;
    int volt=1;
    int point;
    ifstream infile;
    infile.open("score.txt");
    infile>>point;
    infile.close();
    GameStates current_state = GameStates::Menu;

    while (current_state != GameStates::Quit) {
        switch (current_state)
        {
            case GameStates::Menu: current_state = doMenu(win,vol,volt); break;
            case GameStates::Choose: current_state = doChoose(win,vol,fl,volt); break;
            case GameStates::Intro: current_state = doIntro(win,fl); break;
            case GameStates::Level: current_state = doLevel(win,vol,fl,volt,point); break;
            default: return -1; // unexpected
        }
    }
    return 0;
}
