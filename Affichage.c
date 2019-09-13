#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonction.h"
void afficher(BG bg,Chedli c,SDL_Surface *ecran)
{
	SDL_BlitSurface((bg.image),NULL,ecran,(&bg.pos_bg));
	SDL_BlitSurface((c.Img_Actuel),NULL,ecran,&c.pos_Chedli);
	SDL_Flip(ecran); 
}
void afficher_ennemie(ennemie e,SDL_Surface *ecran)
{
	SDL_BlitSurface((e.Img),NULL,ecran,&e.pos_ennemie);
	SDL_Flip(ecran); 
}
/*int randomnumber(int a,int b)
{
time_t t;
int x;
srand((unsigned) time(&t));
x=rand()%(b-a)+a;
return x;
}*/