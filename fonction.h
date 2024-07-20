#define MAX 50 // Nombre de ligne dans le doc
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


/*----- Structure 'Objet' -----*/
/// Cette structure permet de stocker tous les attributs du document .csv

typedef struct obj { 
    char* Nom;
    int Courage;
    int Loyaute;
    int Sagesse;
    int Malice;
    char* Maison;
}obj;

/*----- Structure 'Cluster' -----*/
/// Cette structure permet de créer les clusters 
/// Avec à leur tête un leader

typedef struct cluster
{     
    int lead;
    int *l;      
    int size_l;       
}clus;



/*------------ Fonctions pour remplir la structure 'obj' ------------*/

/* Fonction qui ouvre le fichier et remplie la structure de données 'obj' */
obj *fill_ges();

/* Prend en arguments les differents éléments du doc puis les place dans une struct obj*/
obj *remplir_list(obj* loc,char *nom,int c,int l, int s,int m,char *mai,int num);

/* Fonction qui calcul chacune des distances entre chacun des objets et les stock sous forme de matrice */
int **stk_distance(obj* l_obj);

/* Affiche la matrice */
void print_mat(int **mat);




/*------------ Fonctions pour remplir la structure clus ------------*/

/* Initialise une struct 'clus' */
clus *init_clust(int input);

/* Assigne de manière aléatoire les leaders des clusters */
clus *assign_lead(int input,int *l_lead);

/* Chaque objet rejoint le cluster du leader le plus proche */
clus *assign_obj(clus *c,int **mat,int input);

/* Cherche l'objet le plus proche du leader pour le stocker dans un tab */
int *new_lead(clus *c,int **mat,int input,int *new);

/* Assigne le leader de manière non aléatoire avec un tableau  */
clus *assign_loc_lead(int *l_lead,int input);

/* Return 0 si 'i' est leader sinon 1 */
int is_lead(clus *c, int i,int input);

/* Affiche tous les leaders de chaque cluster */
void print_lead(clus *c,obj *o,int input);

/* Affiche tout les clusters */
void print_clus(clus *c,obj *o,int input);

/* Calcul le coût correspondant à la distance entre le leader et chacun des noeuds au sein du cluster*/
int cost(clus *c,int **mat,int input);

/* Fonctions qui utilisent toutes les fonctions précédentes pour implémenter PAM */
void PAM(int input);

/*------------ Free ------------*/
/* Ensemble des fonctions qui libérent la mémoire lorsque nécessaire */
void free_obj(obj *o);
void free_mat(int **mat);
void free_clus(clus *c,int input);