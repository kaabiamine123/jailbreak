/**
* @file map.c
* @brief Testing Program.
* @author kaabi amine
* @version 0.1
* @date Apr 2023
*
* Testing program for minimap
*
*/
#include "map.h"

/**
* @brief to inisialise map .
* @param screen screen
* @param m map  
* @param screen 
* @return nothing
*/
void initialiser_map (map *m,SDL_Surface *screen)
{
	m->map=IMG_Load("minimap.bmp");
	m->pos_map.x = 1000;
	m->pos_map.y = 100;
	m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0); 

	SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,255,0,0));
	m->perso_pos_map.x=0;
	m->perso_pos_map.y=0;

}

/**
* @brief to put perso in the right place in the minimap.
* @param screen the screen
* @param m map
* @param p personne 
* @param x cordonnee
* @return nothing
*/

void perso_map(map *m,personne *p,SDL_Surface *screen,int x)
{
	m->perso_pos_map.x=p->pos_perso.x/10+m->pos_map.x; 
	m->perso_pos_map.y=p->pos_perso.y/10+m->pos_map.y;

	SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,x,0,0));

}



/**
* @brief to affich the minimap
* @param screen the screen
* @param m map
* @return nothing
*/
void afficher (map m, SDL_Surface * screen)

{
	SDL_BlitSurface(m.map, NULL, screen,&m.pos_map);
	SDL_BlitSurface(m.mini_perso, NULL, screen,&m.perso_pos_map);
}

/**
* @brief to change color
* @param x valeur du coleur rouge
* @return nothing
*/
void incrimenter(int *x)
{
if(*x<255)
{
*x=*x+20;
}
else
{
*x=0;
}
}










