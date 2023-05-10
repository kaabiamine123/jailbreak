#ifndef BACKGROUND
#define BACKGROUND

typedef struct
{
    SDL_Surface *back[4];
    SDL_Rect positionBack;
} Background;

//////////////////////////////
void initBackMain(Background *Back);
void initBackNGame(Background *Back);
void initBackSet(Background *Back);

//////////////////////////////
void AfficherMain(Background Main, SDL_Surface *screen, int i);
void AfficherNGame(Background NGame, SDL_Surface *screen);
void AfficherSet(Background Set, SDL_Surface *screen);

//////////////////////////////
void freeBackMain(Background Back);
void freeBackNGame(Background Back);
void freeBackSet(Background Back);

///


#endif /* BACKGROUND */
