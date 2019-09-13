#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
#include <math.h>

void deplacerhero(Chedli *A,BG *B,Uint32 dt)
{
	/*Dx = vit + ½at2
	 * displacement = initial velocity * time + ½ acceleration * time2
	 * */
	A->velocity+=0.5*A->acceleration*dt;
	A->pos_Chedli.x+=A->velocity*dt;

}
void gravite_saut(Chedli *Bu,BG *Backg,Uint32 dt)
{
	/*Dx = vit + ½at2
	 * displacement = initial velocity * time + ½ acceleration * time2
	 * */
	Bu->Vel.Vx+= cos(Bu->dep.angle*M_PI/180); //Ax=0

	Bu->Vel.Vy-= sin(Bu->dep.angle*M_PI/180) - 0.5*Bu->Acc.Ay*dt; //Ay=-||g||

	Bu->pos_Chedli.x+=Bu->Vel.Vx*dt;

	Bu->pos_Chedli.y+=Bu->Vel.Vy*dt;

	//Backg->pos_bg.x+=Bu->Vel.Vx*dt;


}