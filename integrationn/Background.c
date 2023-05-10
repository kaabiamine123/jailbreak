#include "Header/Constantes.h"
#include "Header/Background.h"

void initBackMain(Background *Back)
{
    Back->back[0] = IMG_Load("MainMenu/background.jpg");
    Back->back[1] = IMG_Load("MainMenu/Background2.jpg");
    Back->positionBack.x = 0;
    Back->positionBack.y = 0;
    Back->positionBack.w = SCREEN_W;
    Back->positionBack.h = SCREEN_H;
}
void initBackNGame(Background *Back)
{
    Back->back[2] = IMG_Load("NewGame/NewGame.jpg");
    Back->positionBack.x = 0;
    Back->positionBack.y = 0;
    Back->positionBack.w = SCREEN_W;
    Back->positionBack.h = SCREEN_H;
}
void initBackSet(Background *Back)
{
    Back->back[3] = IMG_Load("Settings/Settings.jpg");
    Back->positionBack.x = 0;
    Back->positionBack.y = 0;
    Back->positionBack.w = SCREEN_W;
    Back->positionBack.h = SCREEN_H;
}

void AfficherMain(Background Main, SDL_Surface *screen, int i)
{
    SDL_BlitSurface(Main.back[i], NULL, screen, &Main.positionBack);
}

void AfficherNGame(Background NGame, SDL_Surface *screen)
{
    SDL_BlitSurface(NGame.back[2], NULL, screen, &NGame.positionBack);
}

void AfficherSet(Background Set, SDL_Surface *screen)
{
    SDL_BlitSurface(Set.back[3], NULL, screen, &Set.positionBack);
}

void freeBackMain(Background Back)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        SDL_FreeSurface(Back.back[i]);
    }
}
void freeBackNGame(Background Back)
{

    SDL_FreeSurface(Back.back[2]);
}
void freeBackSet(Background Back)
{

    SDL_FreeSurface(Back.back[3]);
}


