#ifndef DEFS_H
#define DEFS_H
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 485;
#define WINDOW_TITLE ""
#define WINDOW_ICON_PATH "./flappy_assets/flappy.png"

#define BACKGROUND_INTRO "./flappy_assets/clouds.jpg"
#define BACKGROUND_LEVEL "./flappy_assets/clouds.jpg"
#define BACKGROUND_GAMEOVER "flappy_assets/background.png"
#define BACKGROUND_MENU "./flappy_assets/menu.jpg"
#define BACKGROUND_TAP "./flappy_assets/tap.png"
#define BACKGROUND_READY "./flappy_assets/ready.png"
#define BACKGROUND_BIRD "./flappy_assets/chimhong.png"
#define BACKGROUND_UP "./flappy_assets/up.png"

#define LOST_VANG "./flappy_assets/vang.png"
#define LOST_BAC "./flappy_assets/bac.png"
#define LOST_DONG "./flappy_assets/dong.png"
#define TO_MENU "./flappy_assets/tomenu.png"

#define VOL_ON "./flappy_assets/volon.png"
#define VOL_OFF "./flappy_assets/voloff.png"
#define VOLT_ON "./flappy_assets/volton.png"
#define VOLT_OFF "./flappy_assets/voltoff.png"

#define FONT_PATH "./flappy_assets/Purisa-BoldOblique.ttf"

#define MUSIC_THEME_PATH "./flappy_assets/flappy.mp3"
#define SOUND_JUMP "./flappy_assets/jump.wav"
#define SOUND_LOST "./flappy_assets/lost.wav"

#define BIRD_CHOOSE2 "./flappy_assets/chong.png"
#define BIRD_CHOOSE1 "./flappy_assets/cvang.png"

#define PIPE_IMAGE "./flappy_assets/pipe.png"
#define BIRD_IMAGE "./flappy_assets/chimhong.png"
#define BIRD_IMAGE2 "./flappy_assets/chimvang.png"

#define PLAY_IMAGE "./flappy_assets/play.png"

#define TEXT_SIZE_BIG 30
#define TEXT_SIZE_SMALL 16

enum class GameStates {
    Intro,
    Level,
    Lost,
    Quit,
    Null,
    Menu,
    Choose
};

#endif // DEFS_H
