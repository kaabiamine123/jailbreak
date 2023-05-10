#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>


/**
* @struct text
* @brief struct for texte
*/
typedef struct  {
    SDL_Surface* textSurface;/*!< render du text*/
    SDL_Rect positionText;/*!< pos texte*/
    char txt[20];/*!< image map*/
    SDL_Color couleurTxt;/*!<couleur*/
    TTF_Font* police;/*!< police*/
}text;// structure text besh tekteb l temps 

/**
* @struct time
* @brief struct for time
*/
typedef struct
{
    int tempsdebut;/*!< temps du debut*/
    int mm; /*!< minutes*/
    int ss;/*!< isecondes*/
    text temps;/*!< image map*/
    
} Time;



void inittemps(Time *t);// initialisaton lel temps l koulo 
void inittempsenig(Time *t);
void Timer(int *tempsdebut);// tehseb l temps 
int initTexttime(text* T);//initialisation du text  khw eli besh nektbo bih
int initTexttimeenig(text* T);
int loadFonttime(text* T, char* angelina);//tloadi l font mtaa l text
void update_time(Time* T);//mise a jour du temps 
void update_timeenig(Time* T);
void displaytime(Time T,SDL_Surface *screen);//afficher le temps aal back
void freeTexttime(text T);//besh ykoun fema optimisation 


#endif
