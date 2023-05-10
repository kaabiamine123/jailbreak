
#include "Header/Constantes.h"
#include "Header/Music.h"
#include "Header/Text.h"
#include "Header/Buttons.h"
#include "Header/Menu.h"
#include "Header/Background.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "time.h"
#include "map.h"
#include <string.h>
#include"collisionparfaite.h"
int main(int argc, char *args[])
{
    /////////////////////////////
    int continuer1=1,done1=1;
    int x2=0;
    SDL_Event event;
    int done=1;
    int continuer = 3;
    int hover1 = 1;
    int hover2 = 1;
    int hover3 = 1;
    int Presses = 5;
    int Mode = 0;
    int i, j;
    int volume = 128;
    int niv_volume = 1;
    SDL_Surface *screen,*backg,*backgm,*enig;
    SDL_Rect backg_pos,backgm_pos,enigpos;
    Buttons B;
    Text t;
    Music M;
    Background Main;
    /////////////////////////////
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Game Menu", NULL);
    screen = SDL_SetVideoMode(1360,765, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    /////////////////////////////
    initMus(&M, &volume);
    /////////////////////////////
    initButMain(&B);//o fil boucle j howa chy3mili annimation
    /////////////////////////////
    initBackMain(&Main);
    initText(&t);
enig = IMG_Load("1.png");
	enigpos.x=100;
	enigpos.y=100;
	
	backg = IMG_Load("backgg1.bmp");
	backg_pos.x = 0;
	backg_pos.y = 0;
	backgm = IMG_Load("mapMasque.bmp");
	backg_pos.x = 0;
	backg_pos.y = 0;
    /////////////////////////////
        Time temps;
	Time tempsenig;
	map m;
	personne p;
	
	inittemps(&temps);
	inittempsenig(&tempsenig);
	initialiser_map (&m,screen) ;
	initialiserperso(&p);

    SDL_EnableKeyRepeat(0, 0);//bich ya9rali min clavier taktak
    while (continuer)
    {
       // for (i = 0; i < 10 && continuer; i++)
        //{
            for (j = 0; j < 2; j++)
            {
                AfficherMain(Main, screen, j);
                displayText(t, screen);
                AfficherBut1(B, screen, hover1, Presses);
                AfficherBut2(B, screen, hover2, Presses);
                AfficherBut3(B, screen, hover3, Presses);
                SDL_Flip(screen);
                hover1 = 1;
                hover2 = 1;
                hover3 = 1;
                SDL_PollEvent(&event);
                switch (event.type)
                {
                case SDL_QUIT:
                    continuer = 0;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;

                    case SDLK_j:
                        while (continuer1)
	{	
	SDL_PollEvent(&event);
	switch(event.type)
        {

        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
            case SDLK_k:{
		while(done){
		update_timeenig(&tempsenig);
		SDL_BlitSurface(enig,NULL,screen,&enigpos);
		displaytime(tempsenig,screen);
		SDL_Flip(screen);
		if(tempsenig.ss==temps.ss+7)
		{
                  done=0;
		}
		}}
                break ;

	
	    
	}}	
		
                collision(backgm,&p);
		update_time(&temps);
		deplacer_perso(&p,event);
                 incrimenter(&x2);
		perso_map(&m,&p,screen,x2);
		SDL_BlitSurface(backg,NULL,screen,&backg_pos);
		
		displaytime(temps,screen);
		
		afficher(m,screen);
		afficher_perso(screen,p);
		SDL_Flip(screen);
                        break;

                    case SDLK_s:
                        Mix_PlayChannel(-1, M.bref, 0);
                        Settings(screen, &Mode, &niv_volume, &volume);
                        break;
		    case SDLK_k:
                    {
		while(done){
		update_timeenig(&tempsenig);
		SDL_BlitSurface(enig,NULL,screen,&enigpos);
		displaytime(tempsenig,screen);
		SDL_Flip(screen);
		if(tempsenig.ss==temps.ss+7)
		{
                  done=0;
		}
		}}
                break ;
                    case SDLK_UP:
                        Presses = Presses % 3 - 1;
                        if (Presses == 0)
                            Presses = 3;
                        if (Presses == -1)
                            Presses = 2;
                        SDL_Delay(100);
                        break;

                    case SDLK_DOWN:
                        Presses = Presses % 3 + 1;
                        SDL_Delay(100);
                        break;

                    case SDLK_SPACE:
                        switch (Presses)
                        {
                        case 1:
                             while (continuer1)
	{	
	SDL_PollEvent(&event);
	switch(event.type)
        {

        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
            case SDLK_k:{
		while(done){
		update_timeenig(&tempsenig);
		SDL_BlitSurface(enig,NULL,screen,&enigpos);
		displaytime(tempsenig,screen);
		SDL_Flip(screen);
		if(tempsenig.ss==temps.ss+7)
		{
                  done1=0;
		}
		}}
                break ;

	
	    
	}}	
		
                collision(backgm,&p);
		update_time(&temps);
		deplacer_perso(&p,event);
                 incrimenter(&x2);
		perso_map(&m,&p,screen,x2);
		SDL_BlitSurface(backg,NULL,screen,&backg_pos);
		
		displaytime(temps,screen);
		
		afficher(m,screen);
		afficher_perso(screen,p);
		SDL_Flip(screen);

	}

                            break;
                        case 2:
                            Settings(screen, &Mode, &niv_volume, &volume);
                            break;
                        case 3:
                            continuer = 0;
                            break;
                        }
                        break;
                    }
                    break;

                case SDL_MOUSEMOTION://win bich n7arek el souris
                    if (event.motion.x > 430 && event.motion.x < 580 && event.motion.y > 250 && event.motion.y < 291)
                    {
                        hover1 = 0;
                        Presses = 5;//5tr cest bon m3ach nst3ml clavier nfrechi
                        Mix_FadeInChannel(-1, M.bref, 0, 0);
                    }
                    else if (event.motion.x > 430 && event.motion.x < 580 && event.motion.y > 350 && event.motion.y < 391)
                    {
                        hover2 = 0;
                        Presses = 5;
                        Mix_FadeInChannel(-1, M.bref, 0, 0);
                    }
                    else if (event.motion.x > 430 && event.motion.x < 580 && event.motion.y > 450 && event.motion.y < 491)
                    {
                        hover3 = 0;
                        Presses = 5;
                        Mix_FadeInChannel(-1, M.bref, 0, 0);
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        if (event.button.x > 430 && event.button.x < 580 && event.button.y > 250 && event.button.y < 291)
                        {
                           collision(backgm,&p);
		update_time(&temps);
		deplacer_perso(&p,event);
                 incrimenter(&x2);
		perso_map(&m,&p,screen,x2);
		SDL_BlitSurface(backg,NULL,screen,&backg_pos);
		
		displaytime(temps,screen);
		
		afficher(m,screen);
		afficher_perso(screen,p);
		SDL_Flip(screen);
                        }
                        else if (event.button.x > 430 && event.button.x < 580 && event.button.y > 350 && event.button.y < 391)
                        {
                            Settings(screen, &Mode, &niv_volume, &volume);
                        }
                        else if (event.button.x > 430 && event.button.x < 580 && event.button.y > 450 && event.button.y < 491)
                        {
                            continuer = 0;
                            break;
                        }
                    }
                    break;
		
                }
            }
        }
    }
    freeBackMain(Main);
    freeButMain(B);
    freeText(t);
    freeMusic(M);
    TTF_CloseFont(t.font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
