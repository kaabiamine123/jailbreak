#include <stdio.h>
#include "entete.h"
int main()
{
tic t; int coup=1;
SDL_Surface * ecran;
TTF_Init();
SDL_Event event;
    int continuer=1;
SDL_Init(SDL_INIT_VIDEO);
    ecran=SDL_SetVideoMode(552,541,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    initialisation(&t);
    int a,b;
    while(continuer)
    {//
printf("t=%d, j=%d", t.tour,t.joueur);
affichage(t,ecran); 
SDL_Flip(ecran);
if( t.tour<9 &&atilganer(t.tabsuivi)==0)
{//
if((t.tour)%2==0)//tour du PC
            {//
 calcul_coup(t.tabsuivi);
printf("\nhellooo before switch\n");
 t.tour++;
}///
        else
       {//
        SDL_WaitEvent(&event);
        switch(event.type)
        {//
printf("\nhellooo dans switch\n");
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_MOUSEBUTTONUP:
 if (event.button.button == SDL_BUTTON_LEFT)
                {
            a=event.button.x/184;
            b=event.button.y/180;
            coup=3*b+a;
            t.tour++;
    t.tabsuivi[coup]=-1;
          }
            break;
        }///
printf("\nhellooo dans switch2\n");


}///

}///
else
{ 
 Resultat(t,ecran);
 continuer=0;   
printf("%d", t.tour);

}
}
   SDL_Quit();
   TTF_Quit();
    liberationmemoire(t);
    return 0;
}


