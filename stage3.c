#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "fonction.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


int stage3(int x,int y)   
{
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);



SDL_Surface *ecran = NULL;
Chedli c;
ennemie e;
fleche fl;
 
BG bg; 
int continuer = 1;
int cc;
int testcollision;
int testfleche=0,testcollisionfleche=0;
int randdir;
int i;
int gr=0;
int gru=0;
int continuer4=1;
/////////wa9t/////////
Uint32 t_prev,dt=1;
//////////////////
SDL_Event event;
SDL_Rect camera;
	int xb,yb,xp,yp;
	FILE *f;
	int pas=0;



ecran = SDL_SetVideoMode(1280,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

bg = initialisation_bg3(bg,x,y);
c = initialisation_Kristina(c,100,225);
e = initialisation_ennemie(e,750,225);
fl= initialisation_fleche(fl,0,0);


SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
while(continuer==1)
{
	 t_prev = SDL_GetTicks();



	 if(c.velocity>0) { //when moving
			c.acceleration=-0.0001; //frottement + vent
			//i+=1;
			c.moving=1;
		}

		if(c.velocity <0) {
			c.acceleration=0;
			c.velocity=0;
			c.moving=0;
		}
		fl.pos_fleche.x=c.pos_Chedli.x;
              fl.pos_fleche.y=c.pos_Chedli.y+50;

         testcollision = collisionAB(c,e,c.pos_Chedli,e.pos_ennemie);
             if (testcollision==1)
             {
             	bg.pos_bg.x-=50;
             	c.pos_Chedli.x-=50;
             	e.pos_ennemie.x+=50;
             	blitBackground(&bg,ecran);
			 SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
			 afficher_ennemie(e,ecran);
			 SDL_Flip(ecran);
             }
            

	SDL_PollEvent(&event);
 
	if (event.type == SDL_QUIT)
		{	
          save(&bg,3);
		   continuer = -1;
		   break;
		}
		/*else if(pas>15)
		{
			save(&bg,2);
			continuer=-1;
			//break;
			stage3(0,0);
		}*/
		
	else if (event.type == SDL_KEYDOWN)
         {
         	if (event.key.keysym.sym == SDLK_ESCAPE)
         	{
         		continuer=0;
         	}
                    if (event.key.keysym.sym == SDLK_SPACE)
                         {
                               c.acceleration+=0.0004;
                               c=animation_Chedli(c,0);
                         }

		      if (event.key.keysym.sym == SDLK_UP)
			{
				SDL_PollEvent(&event);
				
	if (event.key.keysym.sym == SDLK_RIGHT)
	{
                while(c.pos_Chedli.y<=225)
			 {
			 gravite_saut(&c,&bg,1);
			 blitBackground(&bg,ecran);
			 SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
			 if(c.pos_Chedli.x>=1280)
			 {
			 c.pos_Chedli.x=0;
			 bg.pos_bg.x+=1280;
			 blitBackground(&bg,ecran);
			  
			}
			 SDL_Flip(ecran); 
			}
			c.pos_Chedli.y=225;
			c=initialisation_Kristina(c,c.pos_Chedli.x,c.pos_Chedli.y);
			SDL_Flip(ecran); 
			
			//c.pos_Chedli.y=225;
		}
		else
		{
			 
			gr=0;
                c.pos_Chedli.y=225;
			 while (c.pos_Chedli.y>60)
				{
					if (c.pos_Chedli.y>150)
				{
				c.pos_Chedli.y-=gru;
				gru++;
			
				}
				
				   if (c.pos_Chedli.y<150)
				{
				c.pos_Chedli.y-=gru;
				gru--;
				
				}
			    blitBackground(&bg,ecran);
			 SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
			 //SDL_Delay(10);
              //c.pos_Chedli.y=200;
			 SDL_Flip(ecran); 	
			}
			//SDL_Delay(60);
			while (c.pos_Chedli.y<225)
				{
				c.pos_Chedli.y+=gr;
				gr++;
				
				
			    blitBackground(&bg,ecran);
			 SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
			 SDL_Flip(ecran); 
			}
			}
		}
		if (event.key.keysym.sym == SDLK_LSHIFT)
	{
                while(c.pos_Chedli.y<=225)
			 {
			 gravite_saut(&c,&bg,1);
			 blitBackground(&bg,ecran);
			 SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
			 afficher_ennemie(e,ecran);
			 if(c.pos_Chedli.x>=1280)
			 {
			 c.pos_Chedli.x=0;
			 bg.pos_bg.x+=1280;
			 blitBackground(&bg,ecran);
			  SDL_Flip(ecran); 
			}
			 SDL_Flip(ecran); 
			}
			c.pos_Chedli.y=225;
			c=initialisation_Kristina(c,c.pos_Chedli.x,c.pos_Chedli.y);
			
			//c.pos_Chedli.y=225;
		}



			if (event.key.keysym.sym == SDLK_RSHIFT)
              {

              	while(fl.pos_fleche.x<c.pos_Chedli.x+650)
              	{
              		fl.pos_fleche.x+=13;
              		blitBackground(&bg,ecran);
              		SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
              		SDL_BlitSurface(fl.Imgf,NULL,ecran,&fl.pos_fleche);
                    afficher_ennemie(e,ecran);
              		SDL_Flip(ecran);
              	testcollisionfleche= collisionfleche(e,fl.pos_fleche,e.pos_ennemie);
              	if (testcollisionfleche==1)
              	  { 
              		e.Img=IMG_Load("indispos1Dead.png");
              		e.pos_ennemie.y=600;
              		blitBackground(&bg,ecran);
              		SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
              		SDL_BlitSurface(fl.Imgf,NULL,ecran,&fl.pos_fleche);
                    afficher_ennemie(e,ecran);
              	    SDL_Flip(ecran);
              	  }
              	}
              	
              }
              testcollisionfleche=0;

		      if (event.key.keysym.sym == SDLK_DOWN)
			  {//Scrolling_bg(&camera,3);
			 c=animation_Chedli(c,0);
			 afficher(bg,c,ecran);
			  }
		      if (event.key.keysym.sym == SDLK_LEFT)
			{
				//Scrolling_bg(&camera,2);
			 c=animation_Chedli(c,0);
			 bg.pos_bg.x-=5;
			 e.pos_ennemie.x+=5;
			 
			 	blitBackground(&bg,ecran);
			 	afficher_ennemie(e,ecran);
	        deplacerhero(&c,&bg,dt);
	        SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);

			}
		      if (event.key.keysym.sym == SDLK_RIGHT)
			{
			 c=animation_Chedli(c,0);
			 bg.pos_bg.x+=5;
			 e.pos_ennemie.x-=5;
			 SDL_Delay(20);
			 pas++; 			
			}
			/*if(event.key.keysym.sym == SDLK_RSHIFT && c.velocity >0) //brake
			{ 
			c.acceleration-=0.002;

		    }*/
         }
         else if (event.type == SDL_KEYUP && c.velocity >0)
         {
         	if (event.key.keysym.sym == SDLK_SPACE)
         	{
               c.acceleration-=0.002;
         	}
         }
	/////////////////afficher_melowel//////////init_affichage
         ///////////////////////////////////////////
        	blitBackground(&bg,ecran);
        	afficher_ennemie(e,ecran);
	        deplacerhero(&c,&bg,dt);
	        SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
	        SDL_Flip(ecran);
//////////////////////////////////////////////////////////////////
	        ////////////////////////////////////////////
		dt=(SDL_GetTicks()-t_prev);

		if(1000/60 > SDL_GetTicks() - t_prev)
			SDL_Delay(1000/60 - (SDL_GetTicks() - t_prev)); //to a constant FPS


 
}
//freehero(&c);

return(0);


}