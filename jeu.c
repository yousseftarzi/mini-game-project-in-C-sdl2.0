#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "fonction.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


int jeu(int x,int y)   
{
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);



SDL_Surface *ecran = NULL;
Chedli c;
ennemie e;
fleche fl;
 
BG bg; 
int continuer = 1;
int cc;
int d1=500;
int d2=100;
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

bg = initialisation_bg(bg,x,y);
c = initialisation_Chedli(c,100,300);
e = initialisation_ennemie(e,750,300);
fl= initialisation_bullet(fl,0,0);
//e.vie=2;

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

         /*testcollision = collisionAB(c,e,c.pos_Chedli,e.pos_ennemie);
             if (testcollision==1)
             {
             	bg.pos_bg.x-=50;
             	c.pos_Chedli.x-=50;
             	e.pos_ennemie.x+=50;
             	blitBackground(&bg,ecran);
			 SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
			 afficher_ennemie(e,ecran);
			 SDL_Flip(ecran);
             }*/
            
    if (e.STATE==WAITING)
	 	{
	 		if (checkevent1(c,e,d1)==0)
	 		{
	 			e.STATE=WAITING;
	 		}
	 		if (checkevent1(c,e,d1)==1 && checkevent2(c,e,d2)==0)
	 		{
	 			e.STATE=FOLLOWING;
	 		}
	 	}	 
	 	if (e.STATE==FOLLOWING)
	 	{
	 		if (checkevent1(c,e,d1)==0)
	 		{
	 			e.STATE=WAITING;
	 		}
	 		if (checkevent2(c,e,d2)==1)
	 		{
	 			e.STATE=ATTACKING;
	 		}
	 		if (checkevent1(c,e,d1)==1 && checkevent2(c,e,d2)==0)
	 		{
	 			e.STATE=FOLLOWING;
	 		}
	 	}
	 	if (e.STATE==ATTACKING)
	 	{
	 		c.vie-=1;
	 		if (checkevent1(c,e,d1)==0 && checkevent3(c,e)==1)
	 		{
	 			e.STATE=WAITING;
	 		}
	 		if (checkevent1(c,e,d1)==1 && checkevent2(c,e,d2)==0 && checkevent3(c,e)==0)
	 		{
	 			e.STATE=FOLLOWING;
	 		}
	 		if (checkevent1(c,e,d1)==0 && checkevent2(c,e,d2)==1 && checkevent3(c,e)==0)
	 		{	 			
	 			e.STATE=ATTACKING;
	 		}
	 	}
	 	if (c.vie==0)
	 	{
	 		continuer=0;
	 	}
      
      e=UpdateEnnemi(e,c);
	 	afficher(bg,c,ecran);
		
		afficher_ennemie(e,ecran);
	
		SDL_Flip(ecran);


	SDL_PollEvent(&event);
 
	if (event.type == SDL_QUIT)
		{	
          save(&bg,1);
		   continuer = -1;
		   break;
		}
		else if(pas>15)
		{
			save(&bg,2);
			continuer=-1;
			//break;
			stage2(0,0);
		}
		
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
				/*SDL_PollEvent(&event);
				
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
			  SDL_Flip(ecran); 
			}
			 SDL_Flip(ecran); 
			}
			c.pos_Chedli.y=225;
			c=initialisation_Chedli(c,c.pos_Chedli.x,c.pos_Chedli.y);
			
			//c.pos_Chedli.y=225;
	}*/
		//else
		{
			 
			gr=0;
                c.pos_Chedli.y=300;
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
			 afficher_ennemie(e,ecran);
			 //SDL_Delay(10);
              //c.pos_Chedli.y=200;
			 SDL_Flip(ecran); 	
			}
			//SDL_Delay(60);
			while (c.pos_Chedli.y<300)
				{
				c.pos_Chedli.y+=gr;
				gr++;
				
				
			    blitBackground(&bg,ecran);
			 SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
			 afficher_ennemie(e,ecran);
			 SDL_Flip(ecran); 
			}
			}
			c.pos_Chedli.y=300;
		}
		if (event.key.keysym.sym == SDLK_LSHIFT)
	{
                while(c.pos_Chedli.y<=300)
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
           
			 e=initialisation_ennemie(e,750,300);
			   e.vie=2;
			   if (bg.pos_bg.x>=3840)
			   	e.vie=3;
			   e.Img=IMG_Load("indipos1.png");
			   afficher_ennemie(e,ecran);
			  SDL_Flip(ecran); 
			 }
			 SDL_Flip(ecran); 
			}
			c.pos_Chedli.y=300;
			c=initialisation_Chedli(c,c.pos_Chedli.x,c.pos_Chedli.y);
			
			//c.pos_Chedli.y=225;
		}



			if (event.key.keysym.sym == SDLK_RSHIFT)
              {
                //e.vie=2;
              	while(fl.pos_fleche.x<c.pos_Chedli.x+650)
              	{
              		fl.pos_fleche.x+=13;
              		blitBackground(&bg,ecran);
              		SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
              		SDL_BlitSurface(fl.Imgf,NULL,ecran,&fl.pos_fleche);
                    afficher_ennemie(e,ecran);
              		SDL_Flip(ecran);
              	  testcollisionfleche= collisionbullet(e,fl.pos_fleche,e.pos_ennemie);
                     
              	 if (testcollisionfleche==1)
              	  { 
              	  	e.vie--;
              	  	 if (e.vie==0)
              		{//e.Img=IMG_Load("indispos1Dead.png");
              		     e.ennemie[0][0]=IMG_Load("indispos1Dead.png");
              		     e.ennemie[0][1]=IMG_Load("indispos1Dead.png");
              		     e.ennemie[0][2]=IMG_Load("indispos1Dead.png");
              		     e.pos_ennemie.y=600;
              		     blitBackground(&bg,ecran);
              		     SDL_BlitSurface(c.Img_Actuel,NULL,ecran,&c.pos_Chedli);
              		    SDL_BlitSurface(fl.Imgf,NULL,ecran,&fl.pos_fleche);
              		    afficher_ennemie(e,ecran);
              		 SDL_Flip(ecran);
              		}
              		testcollisionfleche=0;
                      break;
              	  }
              	   
              	}
              }
              

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
			 c.pos_Chedli.x+=5;
			 //e.pos_ennemie.x-=5;
			 SDL_Delay(20);
			 if (c.pos_Chedli.x>=1280)
			{
			   c.pos_Chedli.x=0;
			   bg.pos_bg.x+=1280;
			   blitBackground(&bg,ecran);
			  
			   e=initialisation_ennemie(e,750,300);
			   e.vie=2;
                  if (bg.pos_bg.x>=3840)
			   	e.vie=3;
			   e.Img=IMG_Load("indipos1.png");
			   afficher_ennemie(e,ecran);
			 
			   SDL_Flip(ecran); 
			}
			 //pas++; 			
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
	        initscroll(&c,&bg,&ecran);
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