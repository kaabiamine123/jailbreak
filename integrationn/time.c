/**
* @file time.c
* @brief Testing Program.
* @author kaabi amine
* @version 0.1
* @date Apr 2023
* Testing program for minimap
*/
#include "time.h"
/**
* @brief to get how many seconds from starting .
* @param  tempsdebut  game starting time
* @return nothing
*/
void Timer(int *tempsdebut)//t5rjli kdch 3ndi min seconde mili bdit nl3eb 
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 )//kain el wkt b3ed ili bdit fih -wakt bdit fih 3mlt seconde rw tempsdebut hot fih wakt el jdid 
    {
        *tempsdebut = SDL_GetTicks() ;
      
      
    }
  
}
/**
* @brief to inisialis time .
* @param t time
* @return nothing
*/
void inittemps(Time *t)
{   int test; 
	t->tempsdebut=SDL_GetTicks();//thseblk kdch el wakt ili bdit fih execution 
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
}
/**
* @brief to inisialis time enigme .
* @param t time
* @return nothing
*/
void inittempsenig(Time *t)
{   int test; 
	t->tempsdebut=0;
	t->mm=0;
	t->ss=0;
	test=initTexttimeenig(&t->temps);
}
/**
* @brief to inisialis text for time .
* @param T text
* @return testload
*/
int initTexttime(text* T)
{ int testload;
    T->couleurTxt.r = 0; 
    T->couleurTxt.g = 0; 
    T->couleurTxt.b = 0;

    strcpy(T->txt,"");
    T->positionText.x = 850;
    T->positionText.y = 20; 
    testload=loadFonttime(T,"angelina.TTF");//fct 3mltha bich tlodili el font trj3li zero kain loadfont sar mrigl  
    T->textSurface=NULL;
    return testload;   
}
/**
* @brief to inisialis text for enigm time .
* @param T text
* @return testload
*/
int initTexttimeenig(text* T)
{ int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;

    strcpy(T->txt, "");
    T->positionText.x = 140;
    T->positionText.y = 540; 
    testload=loadFonttime(T,"angelina.TTF");
    T->textSurface=NULL;
    return testload;   
}
/**
* @brief to download font .
* @param T text
* @param path font
* @return 0
*/
int loadFonttime(text* T, char* path)
{
    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police= TTF_OpenFont(path,60);//pathn hoa esm l font o 60 l taile 
    if (T->police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
/**
* @brief to update time .
* @param T time
* @return nothing
*/
void update_time(Time* T)
{   int ts;
    Timer(&T->tempsdebut);//raj3tli kdch min milliseconde
    ts=T->tempsdebut/1000;//rdithom b seconde 
    T->mm=ts/60;//kdch min min
    T->ss=ts % 60;//kdch min seconde ts mode 60
    if(T->mm<10&&T->ss<10)
       sprintf(T->temps.txt,"*** time :0%d:0%d  ***",T->mm,T->ss);
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps.txt,"*** time :0%d:%d  ***",T->mm,T->ss);
    else if(T->mm>10&&T->ss<10)
          sprintf(T->temps.txt,"*** time :%d:0%d  ***",T->mm,T->ss);//s y3ni chnktb fi variable chaine 
    else
         sprintf(T->temps.txt,"*** time :%d:%d  ***",T->mm,T->ss); 
  
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);//ttfrender tekho l police o txt o couleur taa l text eli besh taficchiih
}
/**
* @brief to update enigm time .
* @param T time
* @return nothing
*/
void update_timeenig(Time* T)
{   int ts;
    
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    T->mm=ts/ 60;
    T->ss=ts % 60;
    if(T->mm<10&&T->ss<10)//idhkain minute et seconde asgher min 10 
       sprintf(T->temps.txt,"*** time :0%d:0%d  ***",T->mm,T->ss);
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps.txt,"*** time :0%d:%d  ***",T->mm,T->ss);
    else if(T->mm>10&&T->ss<10)
          sprintf(T->temps.txt,"*** time :%d:0%d  ***",T->mm,T->ss);
    else
         sprintf(T->temps.txt,"*** time :%d:%d  ***",T->mm,T->ss); 
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);//ttfrender tekho l police o txt o couleur taa l text eli besh taficchiih
}
/**
* @brief to display time .
* @param T text
* @param T screen screen
* @return nothing
*/
void displaytime(Time T,SDL_Surface *screen)
{
    
     
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));

}
/**
* @brief to libere time .
* @param T text
* @return nothing
*/
void freeTexttime(text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}

