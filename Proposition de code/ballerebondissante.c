#include <stdio.h>
#include <string.h>
/************PROTOTYPES DES FONCTIONS ***************************/
/* Initialise la grille de façon à ce qu'elle contienne ce qu'il 
   y a à la figure de droite 
*/
void init_grille (char grille[][10],int pos_balle_x,int pos_balle_y);
/* Affiche le rectangle d'étoiles et la balle (tout ceci en même
   temps et non pas le rectangle puis la balle...) 
*/
void affiche_grille (char grille[][10]); /* 10 lignes 10 colonnes */
/* Calcule la nouvelle position de la balle en fonction de 
   l'ancienne position de la balle (old_pos_balle_x, old_pos_balle_y) 
   et du vecteur de déplacement (deplacement_x, deplacement_y).
*/
void  calcule_position_balle (char grille[][10], int *pos_balle_x, 
                             int *pos_balle_y, int *deplacement_x, int *deplacement_y);
/***************** IMPLEMENTATION ******************************/
void init_grille(char grille[][10],int pos_balle_x,int pos_balle_y){
   int ligne, colonne;
   memset (grille,' ',100);
   for (colonne=0; colonne <10; colonne++) {
      grille [0][colonne]='*';
      grille [9][colonne]='*';
   }
   for (ligne=0; ligne<10; ligne++) {
      grille [ligne][0]='*';
      grille [ligne][9]='*';
   }
   grille [pos_balle_x][pos_balle_y]='O';
}
void affiche_grille (char grille[][10]) {
   int ligne, colonne;
   for (ligne=0; ligne<10; ligne++ ) {
      for (colonne=0; colonne <10; colonne++) {
         printf ("%c",grille[ligne][colonne]);
      }
      printf ("\n");
   }
}
void  calcule_position_balle (char grille[][10], int *pos_balle_x, 
                             int *pos_balle_y,int *deplacement_x,int *deplacement_y) {
   int theo_pos_x=0;
   int theo_pos_y=0;
   // On efface l'ancienne balle
   grille[*pos_balle_x][*pos_balle_y]=' ';
   printf ("Position actuelle : %d / %d\n",*pos_balle_x,*pos_balle_y);
   printf ("Déplacement : %d / %d\n",*deplacement_x,*deplacement_y);
   // On calcule la future position théorique de la balle
   theo_pos_x = *pos_balle_x + *deplacement_x;
   theo_pos_y = *pos_balle_y + *deplacement_y;
   // En fonction de la position théorique de la balle 
   // on modifie les vecteurs de déplacement
   if (grille[theo_pos_x][theo_pos_y]=='*') {
      // Si on tape sur l'axe vertical
      if (( theo_pos_x == 0 ) || ( theo_pos_x == 9 ))
         *deplacement_x = - *deplacement_x;
      // Si on tape sur l'axe horizontal
      if (( theo_pos_y == 0 ) || ( theo_pos_y == 9 ))
         *deplacement_y = - *deplacement_y;
   }
   // On calcule la nouvelle position de la balle
   *pos_balle_x += *deplacement_x;
   *pos_balle_y += *deplacement_y;
   printf ("Nouvelle Pos : %d/%d\n",*pos_balle_x,*pos_balle_y);
   // On met la balle dans la grille
   grille[*pos_balle_x][*pos_balle_y]='O';
}
int main () {
   int pos_balle_x=4, pos_balle_y=4;     /* position  balle au départ  */
   int deplacement_x=1, deplacement_y=1; /* déplacement balle  */
   char grille[10][10]; /* grille qui contiendra 3 caractères : */
                         /* '*' ou 'O' ou le caractère espace ' '*/
   init_grille (grille, pos_balle_x, pos_balle_y);
   while (1)  {
      system("clear");
      affiche_grille(grille);
      calcule_position_balle (grille, &pos_balle_x, &pos_balle_y, &deplacement_x, &deplacement_y);
      usleep(500000);  /* Pause de 500 000 micro secondes donc 1/2 seconde */
   }
}
