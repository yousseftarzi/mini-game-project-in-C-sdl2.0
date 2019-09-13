#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
#include <math.h>


Chedli initialisation_Chedli(Chedli c,int x,int y)
{
	c.Chedli[0][0]=IMG_Load("kristinapos1.png");
	c.Chedli[0][1]=IMG_Load("kristinapos2.png");
	c.Chedli[0][2]=IMG_Load("kristinapos3.png");
	c.vie=4;
	c.score=0;
	c.pos_Chedli.x=x;
	c.pos_Chedli.y=y;
	c.i=0;c.j=0;	
	c.Img_Actuel = c.Chedli[c.i][c.j];
	c.velocity=0; //5km/h
	c.acceleration=0;
	c.Mass=70;
	c.moving=0;
	c.dep.magnitude=40;
	c.dep.angle=60;

	c.Vel.Vx=c.dep.magnitude*cos(c.dep.angle*M_PI/180);
	c.Vel.Vy=-c.dep.magnitude*sin(c.dep.angle*M_PI/180);

	c.Acc.Ax=0;
	c.Acc.Ay=9.8;
	return c;
}
fleche initialisation_fleche(fleche fl,int x,int y)
{
	fl.Imgf=IMG_Load("fleche.png");
	fl.pos_fleche.x=x;
	fl.pos_fleche.y=y;
	return fl;
}
fleche initialisation_bullet(fleche fl,int x,int y)
{
	fl.Imgf=IMG_Load("bullet.png");
	fl.pos_fleche.x=x;
	fl.pos_fleche.y=y;
	return fl;
}

Chedli initialisation_Kristina(Chedli c,int x,int y)
{
	c.Chedli[0][0]=IMG_Load("indipos1.png");
	c.Chedli[0][1]=IMG_Load("indipos2.png");
	c.Chedli[0][2]=IMG_Load("indipos3.png");
	c.vie=4;
	c.score=0;
	c.pos_Chedli.x=x;
	c.pos_Chedli.y=y;
	c.i=0;c.j=0;	
	c.Img_Actuel = c.Chedli[c.i][c.j];
	c.velocity=0; //5km/h
	c.acceleration=0;
	c.Mass=70;
	c.moving=0;
	c.dep.magnitude=40;
	c.dep.angle=60;

	c.Vel.Vx=c.dep.magnitude*cos(c.dep.angle*M_PI/180);
	c.Vel.Vy=-c.dep.magnitude*sin(c.dep.angle*M_PI/180);

	c.Acc.Ax=0;
	c.Acc.Ay=9.8;
	return c;
}


ennemie initialisation_ennemie(ennemie e,int x,int y)
{
   e.pos_ennemie.x=x;
   e.pos_ennemie.y=y;
   e.vie=1;
   e.ennemie[0][0]=IMG_Load("indipos1.png");
   e.ennemie[0][1]=IMG_Load("indipos2.png");
   e.ennemie[0][2]=IMG_Load("indipos3.png");
   e.i=0;
   e.j=0;
   e.Img= e.ennemie[e.i][e.j];
     return e;
}

BG initialisation_bg(BG bg,int x,int y)
{
	bg.image= IMG_Load("bg.jpg");
	bg.pos_bg.x = x;
	bg.pos_bg.y = y;
	bg.pos_bg.w = 10000;
	bg.pos_bg.h = 600;
	return bg;
}


BG initialisation_bg2(BG bg,int x,int y)
{
	bg.image= IMG_Load("bg2.jpg");
	bg.pos_bg.x = x;
	bg.pos_bg.y = y;
	bg.pos_bg.w = 10000;
	bg.pos_bg.h = 600;
	return bg;
}
BG initialisation_bg3(BG bg,int x,int y)
{
    bg.image= IMG_Load("bg3.jpg");
	bg.pos_bg.x = x;
	bg.pos_bg.y = y;
	bg.pos_bg.w = 10000;
	bg.pos_bg.h = 600;
	return bg;
}


void freehero(Chedli *A)
{
	int i;
	for(i=0; i<4; i++)
		SDL_FreeSurface(A->Chedli[0][i]);
}
void save(BG *bg,int numero)
{
	FILE *f;
	int x,y;
	f=fopen("save.txt", "w");
			x=bg->pos_bg.x;
            y=bg->pos_bg.y;            
fprintf(f,"%d %d %d",x,y,numero);
fclose(f);
}
int Load_game(int *x,int *y,int numero)
       {
                  	FILE *f;
                 f=fopen("save.txt", "r");
                fscanf(f,"%d %d %d",x,y,&numero);
                fclose(f);
                return numero;
       
          }
/*Textes initialisation_texte(Textes T)
{ 
	int i;
	SDL_Color c = {0,0,0};

	 for (i=0;i<6;i++)
	{ 
		T.tab[i].police = TTF_OpenFont("angelina.TTF", 40); 
	}

	T.tab[6].police = TTF_OpenFont("angelina.TTF", 100); 


	strcpy(T.tab[0].t, "0");
	strcpy(T.tab[1].t, "4");
	strcpy(T.tab[2].t, "0");
	strcpy(T.tab[3].t, "score");
	strcpy(T.tab[4].t, "vie");
	strcpy(T.tab[5].t, "arme");
	strcpy(T.tab[6].t, "1");

	//les positions
	for (i=0;i<7;i++)
	{	T.tab[i].texte = TTF_RenderText_Blended(T.tab[i].police, T.tab[i].t, c); 
	}

	return T; 
}*/
int checkevent1(Chedli h,ennemie E,int d1)
{
   if (E.pos_ennemie.x-h.pos_Chedli.x<=d1 && E.pos_ennemie.y==h.pos_Chedli.y)
   {
   	return 1;
   }
   return 0;
}

int checkevent2(Chedli h,ennemie E,int d2)
{
	if (E.pos_ennemie.x-h.pos_Chedli.x<=d2 && E.pos_ennemie.y==h.pos_Chedli.y)
	{
		return 1;
	}
	return 0;
}

int checkevent3(Chedli h,ennemie E)
{
	if (h.vie==0)
	{
		return 1;
	}
	return 0;
}

ennemie UpdateEnnemi(ennemie E, Chedli hero)
{
   switch(E.STATE)
   {
    case WAITING :
     	//E=animation_ennemie(E,0);
      	break;
    case FOLLOWING :
      E=animation_ennemie(E,0);
      MoveEnnemi(&E,hero);
      break;
    case ATTACKING :
      //E=animation_ennemie(E,0);
      break; 
    }
      return E;
}
void MoveEnnemi(ennemie *E,Chedli hero)
{
   if (hero.pos_Chedli.x<E->pos_ennemie.x)
        E->pos_ennemie.x -=10; 
   else    
        E->pos_ennemie.x +=10; 
}