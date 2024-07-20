#include "fonction.h"




obj *remplir_list(obj* loc,char *nom,int c,int l, int s,int m,char *mai,int num){
    loc[num].Nom = malloc(sizeof(char)*strlen(nom)+1);
    loc[num].Maison = malloc(sizeof(char)*strlen(mai)+1);


    strcpy(loc[num].Nom,nom);
    loc[num].Courage = c;
    loc[num].Loyaute = l;
    loc[num].Sagesse = s;
    loc[num].Malice = m;
    strcpy(loc[num].Maison,mai);


    return loc;
}

int **stk_distance(obj* l_obj){

     int **mat;
     int x=0;
     mat =  (int**)malloc(sizeof(int*)*MAX);
     for(int i = 0;i < MAX;i++){
          mat[i] = (int*)malloc(sizeof(int)*MAX);
     }
     for(int i = 0;i<MAX;i++){
          for(int j = 0;j < MAX ;j++){
               mat[i][j]=0;
          }
     }
     
     for(int i = 0;i < MAX;i++){ 
          for(int j = 0;j < MAX ;j++){
               x = abs(l_obj[i].Courage - l_obj[j].Courage) + abs(l_obj[i].Loyaute - l_obj[j].Loyaute) + abs(l_obj[i].Sagesse - l_obj[j].Sagesse) + abs(l_obj[i].Malice- l_obj[j].Malice);
               mat[i][j]= x;
               //printf("%d ",mat[i][j]);
          }
     }

     return mat;

}

void print_mat(int **mat){
     for(int i = 0;i < MAX ;i++){
          printf("\n");
          for(int j = 0;j < MAX;j++){
               printf("%d ",mat[i][j]);

          }
     }
}

void free_obj(obj *o){
     for(int i = MAX-1;i >= 0;i--){
          free(o[i].Maison);
          free(o[i].Nom); 
     }
     free(o);  
}

void free_mat(int **mat){
     for(int i = 0; i < MAX ; i++){
          free(mat[i]);
     }
     free(mat);
}

obj *fill_ges(){
     
     obj *list_obj = malloc(sizeof(obj)*MAX);
     int i= 0;
     char *buf = malloc(sizeof(char)*128);
     int c,l,s,m;
     char *nom;
     char *mai;
     FILE *f = fopen("choixpeauMagique.csv","r");
     if(!f){
        printf("Erreur dans l'ouverture du fichier !");
    }
     fgets(buf,128,f); // On ignore la première ligne    
     while(fgets(buf,128,f) != NULL){
          nom = strtok(buf,";");
          c = atoi(strtok(NULL,";"));
          l = atoi(strtok(NULL,";"));
          s = atoi(strtok(NULL,";"));
          m = atoi(strtok(NULL,";"));
          mai = strtok(NULL,";");
          list_obj = remplir_list(list_obj,nom,c,l,s,m,mai,i);
          i++;
     }

     fclose(f);
     free(buf);

     return list_obj;
}