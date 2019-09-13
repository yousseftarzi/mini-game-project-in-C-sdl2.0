#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "fonction.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


void blitBackground(BG *bg,SDL_Surface *ecran)
{
	//Blit the bachground to the backbuffer
	if(bg->pos_bg.x>bg->image->w)
		bg->pos_bg.x=50;
	if(bg->pos_bg.x<0)
		bg->pos_bg.x=bg->image->w;
	SDL_BlitSurface(bg->image, &(bg->pos_bg), ecran,NULL);
}

void initscroll(Chedli *c,BG *bg,SDL_Surface *ecran)
    {         
    	if (c->pos_Chedli.x>=1280)
			 {
			 c->pos_Chedli.x=0;
			 bg->pos_bg.x+=1280;
			 blitBackground(&bg,ecran);
			  SDL_Flip(ecran); 
			 }
	}