#ifndef MENU
#define MENU

//////////////////////////////
void NewGame(SDL_Surface *screen, int *Mode);
void Settings(SDL_Surface *screen, int *Mode, int *niv_volume, int *volume);
//////////////////////////////
void SetFull(SDL_Surface *screen, int *Mode);
void SetNorm(SDL_Surface *screen, int *Mode);
void SaveScreenMode(SDL_Surface *screen, int *Mode);


#endif /* MENU */
