#include "Header/Constantes.h"
#include "Header/Background.h"
#include "Header/Music.h"
#include "Header/Buttons.h"
#include "Header/Text.h"
#include "Header/Menu.h"

void NewGame(SDL_Surface *screen, int *Mode)//bich kif nenzel 3ala bouton newgame n3aytlil fct hedi chtjibli background ekher
{
    Background NGame;
    SDL_Event event;//5tr chn3ml event bich nkiti
    int continuer = 1;
    SDL_WM_SetCaption("NEW GAME", NULL);
    initBackNGame(&NGame);
    while (continuer)
    {
        SDL_PollEvent(&event);//programme yok3ed y5dem o wa9t ana n3ml event howa y3mili execution mta3ha 33aks waitevent tstnaik hata ta3tiha event
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            SaveScreenMode(screen, Mode);//5atr ana ki bich nkiti lezem nrja3 lil interface menu 
            break;
        case SDL_KEYDOWN://si chnenzel 3al clavier 
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                SaveScreenMode(screen, Mode);
                break;
            }
            break;
        }
        AfficherNGame(NGame, screen);
        SDL_Flip(screen);//refrech
    }
    freeBackNGame(NGame);
}

void Settings(SDL_Surface *screen, int *Mode, int *niv_volume, int *volume)
{

    //////////////////////////////
    SDL_Event event;
    Buttons B;
    Background Set;
    int continuer = 2;
    //////////////////////////////
    SDL_WM_SetCaption("SETTINGS", NULL);
    initBackSet(&Set);
    initButSet(&B);
    //////////////////////////////
    SDL_EnableKeyRepeat(0,50);
    while (continuer)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            SaveScreenMode(screen, Mode);
            break;

        case SDL_KEYDOWN://chnst3ml clavier
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                SDL_BlitSurface(B.Quit, NULL, screen, &B.positionQuit);
                SDL_Flip(screen);
                SaveScreenMode(screen, Mode);//irj3ni menu principale 
                break;
            case SDLK_LEFT:
                volumeDown(niv_volume, volume);
                SDL_BlitSurface(B.Moins, NULL, screen, &B.positionMoins);
                SDL_Flip(screen);
                break;
            case SDLK_RIGHT:
                volumeUp(niv_volume, volume);
                SDL_BlitSurface(B.Plus, NULL, screen, &B.positionPlus);
                SDL_Flip(screen);
                break;
            case SDLK_f:
                SetFull(screen, Mode);

                break;
            case SDLK_n:
                SetNorm(screen, Mode);

                break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (event.button.x > 260 && event.button.x < 380 && event.button.y > 210 && event.button.y < 330)
                {
                    volumeDown(niv_volume, volume);
                    SDL_BlitSurface(B.Moins, NULL, screen, &B.positionMoins);
                    SDL_Flip(screen);
                }
                else if (event.button.x > 610 && event.button.x < 730 && event.button.y > 210 && event.button.y < 330)
                {
                    volumeUp(niv_volume, volume);
                    SDL_BlitSurface(B.Plus, NULL, screen, &B.positionPlus);
                    SDL_Flip(screen);
                }
                else if (event.button.x > 410 && event.button.x < 494 && event.button.y > 440 && event.button.y < 528)
                {
                    SetFull(screen, Mode);
                }
                /*else if (event.button.x > 494 && event.button.x < 560 && event.button.y >440  && event.button.y < 528)
                {
                    SetNorm(screen, Mode);
                }*/
                else if (event.button.x > 445 && event.button.x < 566 && event.button.y > 530 && event.button.y < 649)
                {
                    SDL_BlitSurface(B.Quit, NULL, screen, &B.positionQuit);
                    SDL_Flip(screen);//ba3ed sdlblitsurface n3ml flip
                    SaveScreenMode(screen, Mode);
                    continuer = 0;
                    break;
                }
            }
            break;
        }
        AfficherSet(Set, screen);
        AfficherButOption(B, screen);
        AfficherButMoins(B, screen);
        AfficherButPlus(B, screen);
        AfficherButScreen(B, screen, Mode);
        SDL_Flip(screen);
    }
    freeBackSet(Set);
    freeButSet(B);
}

void SaveScreenMode(SDL_Surface *screen, int *Mode)
{
    if (*Mode == 0)
    {
        SDL_Flip(screen);
        screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);//mode normal
    }
    else
    {
        SDL_Flip(screen);
        screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_FULLSCREEN);//mode fullscren
    }
    SDL_WM_SetCaption("Game Menu", NULL);
}

void SetFull(SDL_Surface *screen, int *Mode)
{
    *Mode = 1;
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
}
void SetNorm(SDL_Surface *screen, int *Mode)
{
    *Mode = 0;
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); //SDL_DOUBLEBUF 
}
