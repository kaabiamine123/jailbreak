/**
* @file pers.c
* @brief Testing Program.
* @author kaabi amine
* @version 0.1
* @date Apr 2023
* Testing program for minimap
*/
#include "pres.h"
/**
* @brief to inisialise perso .
* @param p perso
* @return nothing
*/
void initialiserperso(personne *p)
{	
	p->image_p=IMG_Load("pr1.png");
	p->pos_perso.x=0;
	p->pos_perso.y=500;
	p->pos_perso.w=50;
	p->pos_perso.h=70;
}
/**
* @brief to affich perso .
* @param  screen secreen
* @param p perso
* @return nothing
*/
void afficher_perso(SDL_Surface *screen,personne p)
{	
	SDL_BlitSurface(p.image_p,NULL,screen,&p.pos_perso);
}
/**
* @brief perso moving.
* @param event SDL_Event
* @param p perso
* @return nothing
*/
void deplacer_perso(personne *p,SDL_Event event)
{	
	SDL_PollEvent(&event);
         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            p->pos_perso.y=p->pos_perso.y-10;
                            break;
                        case SDLK_DOWN:
                            p->pos_perso.y=p->pos_perso.y+10;
                            break;
                        case SDLK_RIGHT:
                            p->pos_perso.x=p->pos_perso.x+10;
                            break;
                        case SDLK_LEFT:
                            p->pos_perso.x=p->pos_perso.x-10;
                            break;
                        }
                 break;
             }
}
/**
* @brief to liberer perso  .
* @param p perso
* @return nothing
*/
void free_perso(personne p)
{
	SDL_FreeSurface(p.image_p);
}
