#include "Header/Constantes.h"
#include "Header/Text.h"

void initText(Text *t)//n3mr les donnes du text 
{
    t->position.x = 410;
    t->position.y = 35;
    t->textColor.r = 0;
    t->textColor.g = 0;
    t->textColor.b = 0;
    t->font = TTF_OpenFont("Text/pol.ttf", 50);
}
void freeText(Text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}
void displayText(Text t, SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "Welcome", t.textColor);//fi west el variable t.surfacetext ctji el klma bil font o taille o colleur
    SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);//chnhot el kelma fil screen fil position ili 3amartha
}
