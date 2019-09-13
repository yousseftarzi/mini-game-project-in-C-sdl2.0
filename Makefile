prog:Main.o Main.o Affichage.o Initialisation.o Scrolling.o Animation_Chedly.o Collision.o dep.o jeu.o stage2.o stage3.o
	gcc Main.o Affichage.o Initialisation.o Scrolling.o Animation_Chedly.o Collision.o dep.o jeu.o stage2.o stage3.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o prog -lm -g
main.o:Main.c
	gcc -lSDL -lSDL_image -lSDL_ttf  -lSDL_mixer -c Main.c -w
Affichage.o:Affichage.c
	gcc -lSDL -lSDL_image -lSDL_ttf -c  -lSDL_mixer Affichage.c -w
Initialisation.o:Initialisation.c
	gcc -lSDL -lSDL_image -lSDL_ttf -c  -lSDL_mixer Initialisation.c -w
Scrolling.o:Scrolling.c
	gcc -lSDL -lSDL_image -lSDL_ttf  -lSDL_mixer -c Scrolling.c -w
Animation_Chedly.o:Animation_Chedly.c
	gcc -lSDL -lSDL_image -lSDL_ttf -c  -lSDL_mixer Animation_Chedly.c -w
Collision.o:Collision.c
	gcc -lSDL -lSDL_image -lSDL_ttf  -lSDL_mixer -c Collision.c -w
dep.o:dep.c
	gcc -lSDL -lSDL_image -lSDL_ttf  -lSDL_mixer -c dep.c -w
jeu.o:jeu.c
	gcc -lSDL -lSDL_image -lSDL_ttf  -lSDL_mixer -c jeu.c -w
stage2.o:stage2.c
	gcc -lSDL -lSDL_image -lSDL_ttf  -lSDL_mixer -c stage2.c -w
stage3.o:stage3.c
	gcc -lSDL -lSDL_image -lSDL_ttf  -lSDL_mixer -c stage3.c -w
