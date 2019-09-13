#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "fonction.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
Chedli animation_Chedli(Chedli c,int d)
{//SDL_Delay(100);
if (c.j>2)
c.j=0;
else
c.j++;

c.Img_Actuel=c.Chedli[d][c.j];
return(c);
}
ennemie animation_ennemie(ennemie e,int d)
{//SDL_Delay(100);
if (e.j>2)
e.j=0;
else
e.j++;

e.Img=e.ennemie[d][e.j];
return(e);
}