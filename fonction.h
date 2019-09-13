
#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_
struct Deplacement{
  Sint16 angle;
  Sint16 magnitude;
};
typedef enum STATE STATE;
enum STATE
{
   WAITING,FOLLOWING,ATTACKING
};
typedef struct Deplacement Deplacement;
struct Velocity{
  double Vx;
  double Vy;
};
typedef struct Velocity Velocity;

struct Acceleration{
  double Ax;
  double Ay;
};
typedef struct Acceleration Acceleration;

typedef struct Chedli
{
  SDL_Surface *Chedli[1][3];
  SDL_Surface *Img_Actuel;
  SDL_Rect pos_Chedli;
  int j;
  int i;
 int score;
  int vie;
  int moving;
  float Mass;
  double velocity;
  double acceleration;
  Deplacement dep;
  
  Velocity Vel;
  Acceleration Acc;
}Chedli;

typedef struct fleche
{
  SDL_Surface *Imgf;
  SDL_Rect pos_fleche;
}fleche;

typedef struct ennemie
{
  SDL_Surface *Img;
  SDL_Rect pos_ennemie;
  int vie;
  STATE STATE;
  int i;
  int j;
  SDL_Surface *ennemie[1][3];
}ennemie;

typedef struct
{
  SDL_Surface *image;
  SDL_Rect pos_bg;
  int i;
  
}BG; 
typedef struct
{
  SDL_Surface *texte;
  SDL_Rect pos;
  char t[10];
  //TTF_Font *police;
}Texte;

typedef struct
{
  Texte tab[7];
}Textes;




Chedli initialisation_Chedli(Chedli c,int x,int y);
BG initialisation_bg(BG bg,int x,int y);
void initscroll(Chedli *c,BG *bg,SDL_Surface *ecran);
ennemie initialisation_ennemie(ennemie e,int x,int y);
fleche initialisation_fleche(fleche fl,int x,int y);
fleche initialisation_bullet(fleche fl,int x,int y);
ennemie animation_ennemie(ennemie e,int d);
int collisionAB(Chedli Ball2, ennemie Enemie, SDL_Rect cordsPlayer, SDL_Rect cordsEnemie);
int collisionfleche(ennemie Enemie, SDL_Rect cordsPlayer, SDL_Rect cordsEnemie);
int collisionbullet (ennemie Enemie, SDL_Rect cordsPlayer, SDL_Rect cordsEnemie);
int randomnumber(int a,int b);
void deplacerhero(Chedli *A,BG *B,Uint32 dt);
void blitBackground(BG*bg,SDL_Surface *ecran);
//Textes initialisation_texte(Textes T);
void afficher(BG bg,Chedli c,SDL_Surface *ecran);
void afficher_ennemie(ennemie e,SDL_Surface *ecran);
Chedli animation_Chedli(Chedli c,int d);
Chedli initialisation_Kristina(Chedli c,int x,int y);
BG initialisation_bg2(BG bg,int x,int y);
BG initialisation_bg3(BG bg,int x,int y);
//initialisation_Kristina(c,0,225);// normalement chedli
void save(BG *bg,int numero);
int Load_game(int *x,int *y,int numero);
void gravite_saut(Chedli *Bu,BG *Backg,Uint32 dt);

void MoveEnnemi(ennemie *E,Chedli hero);
ennemie UpdateEnnemi(ennemie E, Chedli hero);





#endif

