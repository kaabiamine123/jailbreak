#ifndef map_H_INCLUDED
#define map_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//#include <SDL/SDL_mixer.h>
#include "pres.h"
/**
* @struct map
* @brief struct for map
*/
typedef struct 
{	
	SDL_Surface *map ;/*!< image map*/
	SDL_Rect pos_map;/*!< pos map*/
	SDL_Surface *mini_perso;/*!< image minimap*/
	SDL_Rect perso_pos_map;/*!< pos minimap*/

}map;//structure  bich tnks 3lina les variables 

	void initialiser_map (map *m,SDL_Surface *screen) ;
	void perso_map(map *m,personne *p,SDL_Surface *screen,int x);
	void afficher(map m, SDL_Surface *screen);

        void incrimenter(int *x);
#endif
