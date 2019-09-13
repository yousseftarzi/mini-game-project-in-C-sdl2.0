#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "fonction.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



int main(int argc, char *argv[])
{
   int continuer = 1,test=0,test2=0,test3=0,test4=0,testdown=0,pos=0,posup=0,posoptions=0,posoup=0,posr=0,posvm=0,posve=0;
   int vmusique=50,veffets=50;
   int continuer2=1,continuer3=1,continuer4=1,aeffect=64,a=64;
   char ae[100];
    SDL_Surface *ecran = NULL, *Newgame = NULL,*Continue=NULL,*Options=NULL,*Quit=NULL,*Back=NULL;
    SDL_Surface *newgameblue=NULL,*continueblue=NULL,*optionsblue=NULL,*quitblue=NULL;
    SDL_Surface *text_resolution,* text_fullscreen,*text_vmusique,*text_veffets;
    SDL_Rect positionFond,positionContinue,positionOptions,positionQuit,positionBack,positiontext_resolution,positiontext_vmusique,positiontext_veffets,positiontext_fullscreen;
    SDL_Surface *p_resolution=NULL,*p_volume_musique=NULL,*p_volume_effets=NULL,*blue_resolution=NULL,*blue_musique=NULL,*blue_effects=NULL;
    SDL_Rect pos_resolution,pos_vmusique,pos_veffet;



TTF_Init();    
    TTF_Font *police = NULL;
    Mix_Music *musique;
    SDL_Event event;
    int testjeu,x,y,xp,yp;
    FILE *f;
int pas;
int numero_stage;
    positionBack.x=0;
    positionBack.y=0;
    positionFond.x = 50;
    positionFond.y = 20;
    positionContinue.x=50;
    positionContinue.y=200;
    positionOptions.x=50;
    positionOptions.y=380;
    positionQuit.x=50;
    positionQuit.y=560;
    positiontext_resolution.x=850;
    positiontext_resolution.y=50;
    positiontext_fullscreen.x=800;
    positiontext_fullscreen.y=50;
    positiontext_vmusique.x=900;
    positiontext_vmusique.y=220;
    positiontext_veffets.x=900;
    positiontext_veffets.y=400;
    pos_resolution.x=50;
    pos_resolution.y=20;
    pos_vmusique.x=50;
    pos_vmusique.y=200;
    pos_veffet.x=50;
    pos_veffet.y=380;
    char ac[128];
    SDL_Color couleurNoire = {0 ,0, 0};
    SDL_Color couleurBlanche ={255, 255, 255};
    police =TTF_OpenFont("angelina.ttf",65);
    text_fullscreen= TTF_RenderText_Blended(police,"FULLSCREEN",couleurNoire);
    text_resolution= TTF_RenderText_Blended(police,"1280x720",couleurNoire);
    SDL_Init(SDL_INIT_VIDEO);
    SDL_ShowCursor(SDL_DISABLE);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
    

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    musique = Mix_LoadMUS("musique.mp3");
     Mix_PlayMusic(musique, -1);
    ecran = SDL_SetVideoMode(1280,720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
     SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
     Back = SDL_LoadBMP("back.bmp");
     Newgame=SDL_LoadBMP("newgame.bmp");
     Continue=SDL_LoadBMP("continue.bmp");
     Options=SDL_LoadBMP("options.bmp");
     Quit=SDL_LoadBMP("quit.bmp");
     newgameblue=SDL_LoadBMP("newgameblue.bmp");
     continueblue=SDL_LoadBMP("continueblue.bmp");
     optionsblue=SDL_LoadBMP("optionsblue.bmp");
     quitblue=SDL_LoadBMP("quitblue.bmp");
     ////////////////////sous_menu/////////////////
     p_resolution=IMG_Load("resolutionbleu.jpg");
     p_volume_effets=IMG_Load("effectsbleu.jpg");
     p_volume_musique=IMG_Load("musicbleu.jpg");
     blue_resolution=IMG_Load("resolutionrouge.jpg");
     blue_musique=IMG_Load("musicrouge.jpg");
     blue_effects=IMG_Load("effectsrouge.jpg");
     ////////////////////////////////////////////
       Mix_AllocateChannels(32); //Allouer 32 canaux
       a=MIX_MAX_VOLUME/2;
       Mix_VolumeMusic(MIX_MAX_VOLUME / 2); //volume musique
       Mix_Chunk *son;//Créer un pointeur pour stocker un .WAV
      son = Mix_LoadWAV("son.wav"); //Charger un wav dans un pointeur
  
   Mix_VolumeChunk(son, aeffect); //Mettre un volume pour ce wav
    //Mettre à mi-volume le post 1
   //testjeu=jeu();
        SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
            SDL_BlitSurface(Newgame, NULL, ecran, &positionFond);
            SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
            SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
            SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
SDL_Flip(ecran);
int continuer5=1;

   
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
               break;

         case SDL_KEYDOWN:
         if(event.key.keysym.sym==SDLK_ESCAPE)
             {
                    continuer = 0;
                    break;
                }
             if(event.key.keysym.sym==SDLK_DOWN && pos==0)
             {
            Mix_PlayChannel(1, son, 0);
            SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
            SDL_BlitSurface(Newgame, NULL, ecran, &positionFond);
            SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
            SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
            SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
            SDL_BlitSurface(newgameblue, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
            pos=1;
            posup=0;
            break;
             }
             if(event.key.keysym.sym==SDLK_RETURN && pos==1)
             {
                testjeu=jeu(0,0);
                //return EXIT_SUCCESS;
              SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
            SDL_BlitSurface(Newgame, NULL, ecran, &positionFond);
            SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
            SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
            SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
            SDL_BlitSurface(newgameblue, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
              break;
}
             if(event.key.keysym.sym==SDLK_DOWN && pos==1)
             {
               Mix_PlayChannel(1, son, 0);
               SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
               SDL_BlitSurface(Newgame, NULL, ecran, &positionFond);
               SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
               SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
               SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
               SDL_BlitSurface(continueblue, NULL, ecran, &positionContinue);
               SDL_Flip(ecran);
               pos=2;
               posup=3;
               break;
             }
             if(event.key.keysym.sym==SDLK_DOWN && pos==2)
             {
                 Mix_PlayChannel(1, son, 0);
                 SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
                 SDL_BlitSurface(Newgame, NULL, ecran,&positionFond);
                 SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
                 SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
                 SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
                 SDL_BlitSurface(optionsblue, NULL, ecran, &positionOptions);
                 SDL_Flip(ecran);
                 pos=3;
                 posup=2;
                 break;
             }
             if (event.key.keysym.sym==SDLK_DOWN && pos==3)
             {
                Mix_PlayChannel(1, son, 0);
                 SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
                 SDL_BlitSurface(Newgame, NULL, ecran,&positionFond);
                 SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
                 SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
                 SDL_BlitSurface(quitblue, NULL, ecran, &positionQuit);
                 //SDL_BlitSurface(optionsblue, NULL, ecran, &positionOptions);
                 SDL_Flip(ecran);
                 pos=4;
                 posup=1;
                 break;
             }
             if (event.key.keysym.sym==SDLK_DOWN && pos==4)
             {
                Mix_PlayChannel(1, son, 0);
                 SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
                 SDL_BlitSurface(newgameblue, NULL, ecran,&positionFond);
                 SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
                 SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
                 SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
                 //SDL_BlitSurface(newgameblue, NULL, ecran, &positionOptions);
                 SDL_Flip(ecran);
                 pos=1;
                 posup=4;
                 break;
             }
             if (event.key.keysym.sym==SDLK_RETURN && pos==2)
             {
                numero_stage = Load_game(&x,&y,numero_stage);
                
                if(numero_stage==1)
                testjeu=jeu(x,y);
             if(numero_stage==2) 
                testjeu=stage2(x,y);
             if (numero_stage==3)
             {
                testjeu=stage3(x,y);
            
            continuer=-1;
            break;}
             }
             ////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////
             ////////////////SOUUUUUUUUS MEEEEEEEEEEENUUUUUUUUUUUU///////////////////////////////
             ////////////////////////////////////////////////////////////////////////////////
             if (event.key.keysym.sym==SDLK_RETURN && pos==3 && posup==2)
             {
                posoptions=0;
                SDL_BlitSurface(Back, NULL, ecran, &positionBack);
                SDL_BlitSurface(p_resolution, NULL, ecran, &pos_resolution);
                SDL_BlitSurface(p_volume_musique, NULL, ecran, &pos_vmusique);
                SDL_BlitSurface(p_volume_effets,NULL,ecran,&pos_veffet);
                SDL_BlitSurface(blue_resolution,NULL,ecran,&pos_resolution);
                /////text////
                 sprintf(ac,"%d",a);
                 sprintf(ae,"%d",aeffect);
                 text_vmusique = TTF_RenderText_Shaded(police,ac,couleurNoire, couleurBlanche);
                 text_veffets = TTF_RenderText_Shaded(police,ae,couleurNoire, couleurBlanche);
            SDL_SetColorKey(text_veffets, SDL_SRCCOLORKEY, SDL_MapRGB(text_veffets->format, 255, 255, 255));

                 SDL_SetColorKey(text_vmusique, SDL_SRCCOLORKEY, SDL_MapRGB(text_vmusique->format, 255, 255, 255));
                 SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
                 SDL_BlitSurface(text_veffets,NULL,ecran,&positiontext_veffets);
                SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
                            SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
                            SDL_Flip(ecran);

                SDL_Flip(ecran);
                posr=0;
                while (continuer2)
                  {
                     SDL_WaitEvent(&event);
                       switch(event.type)
                     {
                        case SDL_QUIT:
                        continuer2=0;
                        break;
                        case 
                         SDL_KEYDOWN:
                         if(event.key.keysym.sym==SDLK_ESCAPE)
                         {
                            continuer2=0;
                            break;
                         }
                         if(event.key.keysym.sym==SDLK_RIGHT && posr==0)
                         { 
                            SDL_BlitSurface(Back, NULL, ecran, &positionBack);
                            SDL_BlitSurface(p_volume_musique, NULL, ecran, &pos_vmusique);
                SDL_BlitSurface(p_volume_effets,NULL,ecran,&pos_veffet);
                SDL_BlitSurface(blue_resolution,NULL,ecran,&pos_resolution);
                            SDL_BlitSurface(text_resolution,NULL,ecran,&positiontext_resolution);
                            SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
                            SDL_BlitSurface(text_veffets,NULL,ecran,&positiontext_veffets);
                            SDL_Flip(ecran);
                            posr=1;
                         break;
                         }
                         if(event.key.keysym.sym==SDLK_RIGHT && posr==1)
                         {
                            SDL_BlitSurface(Back, NULL, ecran, &positionBack);
                            SDL_BlitSurface(p_volume_musique, NULL, ecran, &pos_vmusique);
                SDL_BlitSurface(p_volume_effets,NULL,ecran,&pos_veffet);
                SDL_BlitSurface(blue_resolution,NULL,ecran,&pos_resolution);
                            SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
                          SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
                          SDL_BlitSurface(text_veffets,NULL,ecran,&positiontext_veffets);
                          SDL_Flip(ecran);
                          posr=0;
                         break;
                         }
                         if(event.key.keysym.sym==SDLK_RETURN && posr==0)
                         {
                                //something similar to free//
                              ecran = SDL_SetVideoMode(1280,720, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);
                                SDL_BlitSurface(Back, NULL, ecran, &positionBack);
                                SDL_BlitSurface(p_volume_musique, NULL, ecran, &pos_vmusique);
                SDL_BlitSurface(p_volume_effets,NULL,ecran,&pos_veffet);
                SDL_BlitSurface(blue_resolution,NULL,ecran,&pos_resolution);
                SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
                SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
                SDL_BlitSurface(text_veffets,NULL,ecran,&positiontext_veffets);
                SDL_Flip(ecran);
                         break;
                         }
                         if(event.key.keysym.sym==SDLK_RETURN && posr==1)
                         {

                              ecran = SDL_SetVideoMode(1280,720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                              SDL_BlitSurface(Back, NULL, ecran, &positionBack);
                              SDL_BlitSurface(p_volume_musique, NULL, ecran, &pos_vmusique);
                SDL_BlitSurface(p_volume_effets,NULL,ecran,&pos_veffet);
                SDL_BlitSurface(blue_resolution,NULL,ecran,&pos_resolution);
                SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
                SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
                SDL_BlitSurface(text_veffets,NULL,ecran,&positiontext_veffets);
                SDL_Flip(ecran);
                         break;
                         } 
                         if (event.key.keysym.sym==SDLK_DOWN)
                         {
                            Mix_PlayChannel(1, son, 0);
                            continuer2=0;
                            break;
                         }
                         
                        }

                     }
                     continuer2=1;


                //ecran = SDL_SetVideoMode(1280,720, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF)
                
             }

             ////////////position=volume_musique///////////////
             /////////////////////////////////////////////

             if (event.key.keysym.sym==SDLK_DOWN && posoptions==0)
             {
                //posr=0;
                posvm=1;
                posoptions=1;
                SDL_BlitSurface(blue_musique, NULL, ecran, &pos_vmusique);
                SDL_BlitSurface(p_resolution,NULL,ecran,&pos_resolution);
                SDL_Flip(ecran);
                while (continuer3)
                  {

                     SDL_WaitEvent(&event);
                       switch(event.type)
                     {
                        case SDL_QUIT:
                        continuer3=0;
                        break;
                        case 
                         SDL_KEYDOWN:

                         if (event.key.keysym.sym==SDLK_ESCAPE)
                         {
                            continuer3=0;
                            break;
                         }
                         if (event.key.keysym.sym==SDLK_DOWN)
                         {
                            continuer3=0;
                            break;
                         }

                        if (event.key.keysym.sym==SDLK_LEFT && posvm==1)
                        {
                            a--;
                            //a=50;
if(a<=0)
{
    a=0;
    if(posr==0)
        SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
    else
        SDL_BlitSurface(text_resolution,NULL,ecran,&positiontext_resolution);
    SDL_Flip(ecran);

}

                            Mix_VolumeMusic(a);
                            sprintf(ac,"%d",a);

                            SDL_BlitSurface(Back, NULL, ecran, &positionBack);
    SDL_BlitSurface(p_resolution,NULL,ecran,&pos_resolution);
    SDL_BlitSurface(blue_musique, NULL, ecran, &pos_vmusique);
    SDL_BlitSurface(p_volume_effets,NULL,ecran,&pos_veffet);
   text_vmusique = TTF_RenderText_Shaded(police,ac,couleurNoire, couleurBlanche);
   SDL_SetColorKey(text_vmusique, SDL_SRCCOLORKEY, SDL_MapRGB(text_vmusique->format, 255, 255, 255));
    SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
    SDL_BlitSurface(text_veffets,NULL,ecran,&positiontext_veffets);
                            
                            if(posr==0)
        SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
    else
        SDL_BlitSurface(text_resolution,NULL,ecran,&positiontext_resolution);

    
                     SDL_Flip(ecran);
break;

                        }
                        if (event.key.keysym.sym==SDLK_RIGHT && posvm==1)
                        {
                            a++;
                            //a=50;
if(a>=100)
{
    a=100;
    SDL_BlitSurface(Back, NULL, ecran, &positionBack);
    if(posr==0)
        SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
    else
        SDL_BlitSurface(text_resolution,NULL,ecran,&positiontext_resolution);

}

                            Mix_VolumeMusic(a);
                            sprintf(ac,"%d",a);
                            
                            SDL_BlitSurface(Back, NULL, ecran, &positionBack);
    SDL_BlitSurface(p_resolution,NULL,ecran,&pos_resolution);
    SDL_BlitSurface(blue_musique, NULL, ecran, &pos_vmusique);
    SDL_BlitSurface(p_volume_effets,NULL,ecran,&pos_veffet);
   text_vmusique = TTF_RenderText_Shaded(police,ac,couleurNoire, couleurBlanche);
   SDL_SetColorKey(text_vmusique, SDL_SRCCOLORKEY, SDL_MapRGB(text_vmusique->format, 255, 255, 255));
    SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
    SDL_BlitSurface(text_veffets,NULL,ecran,&positiontext_veffets);

                            if(posr==0)
        SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
    else
        SDL_BlitSurface(text_resolution,NULL,ecran,&positiontext_resolution);
    SDL_Flip(ecran);
break;

                        }
                   }
                
                }
                continuer3=1;
             }

            ////////////////////////////////////////////////////////
             //////////////////////////////////////////////////
             // VOLUUUUUUUME EFFEEEEEEEEEEEEEEEEEECTS//
             //////////////////////////////////////////////
             //////////////////////////////////////////////

          if (event.key.keysym.sym==SDLK_DOWN && posoptions==1)
             {
                //posr=0;
                posve=1;
                posoptions=2;
                SDL_BlitSurface(blue_effects, NULL, ecran, &pos_veffet);
                SDL_BlitSurface(p_volume_musique,NULL,ecran,&pos_vmusique);
                Mix_PlayChannel(1, son, 0);
                SDL_Flip(ecran);

                while (continuer4)
                  {
                     SDL_WaitEvent(&event);
                       switch(event.type)
                     {
                        case SDL_QUIT:
                        continuer4=0;
                        break;
                        case 
                         SDL_KEYDOWN:

                         if (event.key.keysym.sym==SDLK_ESCAPE)
                         {
                            continuer4=0;
                            break;
                         }
                        if (event.key.keysym.sym==SDLK_LEFT && posve==1)
                        {
                            aeffect--;
                            //a=50;
if(aeffect<=0)
{
    aeffect=0;
     SDL_BlitSurface(Back, NULL, ecran, &positionBack);
    if(posr==0)
        SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
    else
        SDL_BlitSurface(text_resolution,NULL,ecran,&positiontext_resolution);

}

                             
                             Mix_VolumeChunk(son,aeffect);
                            sprintf(ae,"%d",aeffect);
                            SDL_BlitSurface(Back, NULL, ecran, &positionBack);
    SDL_BlitSurface(p_resolution,NULL,ecran,&pos_resolution);
    SDL_BlitSurface(p_volume_musique, NULL, ecran, &pos_vmusique);
    SDL_BlitSurface(blue_effects,NULL,ecran,&pos_veffet);
  text_veffets = TTF_RenderText_Shaded(police,ae,couleurNoire, couleurBlanche);
SDL_SetColorKey(text_veffets, SDL_SRCCOLORKEY, SDL_MapRGB(text_veffets->format, 255, 255, 255));
    SDL_BlitSurface(text_veffets,NULL,ecran,&positiontext_veffets);
    SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
    
                            
                            if(posr==0)
        SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
    else
        SDL_BlitSurface(text_resolution,NULL,ecran,&positiontext_resolution);

    
                     SDL_Flip(ecran);
break;

                        }
                        if (event.key.keysym.sym==SDLK_RIGHT && posvm==1)
                        {
                            aeffect++;
                            //a=50;
if(aeffect>=100)
{
    aeffect=100;
    //SDL_BlitSurface(Back, NULL, ecran, &positionBack);
    if(posr==0)
        SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
    else
        SDL_BlitSurface(text_resolution,NULL,ecran,&positiontext_resolution);
    SDL_Flip(ecran);

}

                           Mix_VolumeChunk(son,aeffect);
                            sprintf(ae,"%d",aeffect);
                            SDL_BlitSurface(Back, NULL, ecran, &positionBack);
    SDL_BlitSurface(p_resolution,NULL,ecran,&pos_resolution);
    SDL_BlitSurface(p_volume_musique, NULL, ecran, &pos_vmusique);
    SDL_BlitSurface(blue_effects,NULL,ecran,&pos_veffet);
  text_veffets = TTF_RenderText_Shaded(police,ae,couleurNoire, couleurBlanche);
SDL_SetColorKey(text_veffets, SDL_SRCCOLORKEY, SDL_MapRGB(text_veffets->format, 255, 255, 255));
    SDL_BlitSurface(text_veffets,NULL,ecran,&positiontext_veffets);
    SDL_BlitSurface(text_vmusique,NULL,ecran,&positiontext_vmusique);
    if(posr==0)
        SDL_BlitSurface(text_fullscreen,NULL,ecran,&positiontext_fullscreen);
    else
        SDL_BlitSurface(text_resolution,NULL,ecran,&positiontext_resolution);
    SDL_Flip(ecran);
    
break;

                        }
                   }
                }
                continuer4=1;
             }
             ///////////////////////////////////:
             ///END OF EFFECTS////
             /////////////////////////////:

             if(event.key.keysym.sym==SDLK_DOWN && pos==3)
             {
                
               Mix_PlayChannel(1, son, 0);
               SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
                     SDL_BlitSurface(Newgame, NULL, ecran, &positionFond);
                     SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
                     SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
                     SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
                 SDL_BlitSurface(quitblue, NULL, ecran, &positionQuit);
                 SDL_Flip(ecran);
            pos=0;
            posup=1;
            break;

     }

             if(event.key.keysym.sym==SDLK_UP && posup==0)
             {
               Mix_PlayChannel(1, son, 0);
               SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
                     SDL_BlitSurface(Newgame, NULL, ecran, &positionFond);
                     SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
                     SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
                     SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
               SDL_BlitSurface(quitblue, NULL, ecran, &positionQuit);
               SDL_Flip(ecran);
               posup=1;
               pos=0;
            break;
             }
             /////////////////quitter///////////////
             if(event.key.keysym.sym==SDLK_RETURN && ((pos==0 && posup==1) || (pos=3 && posup==1)) )
             {
               continuer=0;
            break;
             }
             ////////////////////////////////////////////



             if(event.key.keysym.sym==SDLK_UP  && posup==1)
             {
                 Mix_PlayChannel(1, son, 0);
                 SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
                     SDL_BlitSurface(Newgame, NULL, ecran, &positionFond);
                     SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
                     SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
                     SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
                 SDL_BlitSurface(optionsblue, NULL, ecran, &positionOptions);
                 SDL_Flip(ecran);
                 posup=2;
                 pos=3;
                 break;
             }
             if(event.key.keysym.sym==SDLK_UP  && posup==2)
             {
               Mix_PlayChannel(1, son, 0);
               SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
                     SDL_BlitSurface(Newgame, NULL, ecran, &positionFond);
                     SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
                     SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
                     SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
                 SDL_BlitSurface(continueblue, NULL, ecran, &positionContinue);
            SDL_Flip(ecran);
            posup=3;
            pos=2;
            break;
             }
             if(event.key.keysym.sym==SDLK_UP  && posup==3)
             {
               Mix_PlayChannel(1, son, 0);
                SDL_BlitSurface(Back, NULL, ecran, &positionBack);               
                     SDL_BlitSurface(Newgame, NULL, ecran, &positionFond);
                     SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
                     SDL_BlitSurface(Options, NULL, ecran, &positionOptions);
                     SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
                 SDL_BlitSurface(newgameblue, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
            posup=0;
            pos=1;
            break;
             }


    }}
   Mix_FreeChunk(son);
   Mix_FreeMusic(musique);    
   SDL_FreeSurface(Newgame);
   SDL_FreeSurface(Continue);
   SDL_FreeSurface(Options);
   SDL_FreeSurface(Quit);
   SDL_FreeSurface(Back);
   SDL_FreeSurface(newgameblue);
   SDL_FreeSurface(continueblue);
   SDL_FreeSurface(optionsblue);
   SDL_FreeSurface(quitblue);
   Mix_CloseAudio();
   TTF_CloseFont(police);
   TTF_Quit();
   SDL_Quit();
   return EXIT_SUCCESS;
}