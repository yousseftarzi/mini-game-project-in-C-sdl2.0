#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"


int collisionAB(Chedli Ball2, ennemie Enemie, SDL_Rect cordsPlayer, SDL_Rect cordsEnemie)
{ 
int Topj,TopE,Rightj,RightE,Leftj,LeftE,Bottomj,BottomE;

Topj=cordsPlayer.y;
TopE=cordsEnemie.y;

Bottomj=cordsPlayer.y+200;
BottomE=cordsEnemie.y+200;

Rightj=cordsPlayer.x+96;
RightE=cordsEnemie.x+96;

Leftj=cordsPlayer.x;
LeftE=cordsEnemie.x;

if(Bottomj>=TopE && Rightj>=LeftE && Topj<=BottomE && Leftj<=RightE)
{
return 1;
}
return 0;
}

int collisionfleche (ennemie Enemie, SDL_Rect cordsPlayer, SDL_Rect cordsEnemie)
{ 
int Topj,TopE,Rightj,RightE,Leftj,LeftE,Bottomj,BottomE;

Topj=cordsPlayer.y;
TopE=cordsEnemie.y;

Bottomj=cordsPlayer.y+75;
BottomE=cordsEnemie.y+200;

Rightj=cordsPlayer.x+50;
RightE=cordsEnemie.x+96;

Leftj=cordsPlayer.x;
LeftE=cordsEnemie.x;

if(Bottomj>=TopE && Rightj>=LeftE )
{
return 1;
}
return 0;
}

int collisionbullet (ennemie Enemie, SDL_Rect cordsPlayer, SDL_Rect cordsEnemie)
{ 
int Topj,TopE,Rightj,RightE,Leftj,LeftE,Bottomj,BottomE;

Topj=cordsPlayer.y;
TopE=cordsEnemie.y;

Bottomj=cordsPlayer.y+75;
BottomE=cordsEnemie.y+200;

Rightj=cordsPlayer.x+40;
RightE=cordsEnemie.x+40;

Leftj=cordsPlayer.x;
LeftE=cordsEnemie.x;

if(Bottomj>=TopE && Rightj>=LeftE )
{
return 1;
}
return 0;
}