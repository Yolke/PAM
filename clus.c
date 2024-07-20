#include "fonction.h"



void print_clus(clus *c,obj *o,int input){

     printf("	Affichage des Clusters finaux : \n");
     for(int i = 0;i < input;i++){
          printf(" 	Cluster  n°%d: \n",i+1);
          printf("  NOMS: ");
          for(int j = 1;j < c[i].size_l;j++){
               printf("%s, ",o[c[i].l[j]].Nom);
          }
          printf("\n");
     }
}

clus *init_clust(int input){
     clus *new = malloc(sizeof(clus)*input);

     for(int i = 0;i < input;i++){
          new[i].lead = -1; // le lead est affecter a aucun objet 
          new[i].l = NULL;
          new[i].size_l = 0;
     }

    return new;
}


clus *assign_lead(int input,int *l_lead){

     clus *new = init_clust(input);
     srand(time(NULL));
     int i = input-1;
     int l = 0;
     int rd = 0;
     while(i >= 0){
          rd = rand()%MAX;
          if(is_lead(new,rd,input)){
               l_lead[l] = rd;
               new[l].lead = rd;
               new[l].l = malloc(sizeof(int));
               new[l].l[0]=rd;
               new[l].size_l = 1;
               l++;
               i--;
          }
     }
     return new;
}


void print_lead(clus *c,obj *o,int input){

     for(int i = 0;i<input;i++){
          printf(" %s",o[c[i].lead].Nom);
     }
     printf("\n");
     
}

int is_lead(clus *c, int i,int input){

     for(int j = 0; j < input;j++){
          if(i == c[j].lead){
               return 0;
               }
     }
          
          return 1;
}

clus *assign_obj(clus *c,int **mat,int input){
     int xl;
     int min = 1000;
     int he;
     for (int i =0;i<MAX;i++){
          for(int j = 0;j < input;j++){
               xl = c[j].lead;
               if(min > mat[i][xl] && xl != i){
                    min = mat[i][xl];
                    he = j;
               }
          }  

          min = 1000;
          if(is_lead(c,i,input)){
          c[he].l = realloc(c[he].l,sizeof(int)*(c[he].size_l+1));
          c[he].l[c[he].size_l] = i;
          c[he].size_l++;
          }
     }
     return c;
}

int cost(clus *c,int **mat,int input){

     int sumt = 0;
     int x = 0;
     int y = 0;
     for(int i = 0;i < input;i++){
          for(int j = 0 ;j < c[i].size_l;j++){
               x = c[i].l[0];
               y = c[i].l[j]; 
               sumt += mat[x][y];
          } 
     }
     return sumt;
}

void free_clus(clus *c,int input){
    for(int i = 0;i < input;i++){
         free(c[i].l);
    }
    free(c);
}

int *new_lead(clus *c,int **mat,int input,int *new){

     int min = 1000;
     int index = 0;
     int x = 0;
     int y = 0;
     for(int i = 0;i < input;i++){
          for(int j = 1;j < c[i].size_l;j++){
               x = c[i].l[0];
               y = c[i].l[j];
               if(min > mat[x][y] && x != y){
                    min = mat[x][y];
                    index = j;                    
               }
          }
          min = 1000;
          new[i] = c[i].l[index];
     }
     return new;
}

clus *assign_loc_lead(int *l_lead,int input){
     clus *new = init_clust(input);


     for(int i = 0;i < input;i++){
          new[i].lead = l_lead[i];
          new[i].l = malloc(sizeof(int));
          new[i].l[0]=l_lead[i];
          new[i].size_l = 1;
     }
     return new;
}

void PAM(int input){

     obj *l_obj = fill_ges();
     int **mat = stk_distance(l_obj);
     clus *l_clu = NULL;
     clus *loc = NULL;
     int *l_lead = malloc(sizeof(int)*input);
     l_clu = assign_lead(input,l_lead);
     l_clu = assign_obj(l_clu,mat,input);
     int old_c = cost(l_clu,mat,input);

     printf("Initial Leaders : \n");
     print_lead(l_clu,l_obj,input);

     while(1){
          //printf("We're in PAM\n");
          l_lead = new_lead(l_clu,mat,input,l_lead);
          loc = assign_loc_lead(l_lead,input);
          loc = assign_obj(loc,mat,input);
          int new_c = cost(loc,mat,input);
          printf("	Previous cost : %d\n	New cost : %d\n",old_c,new_c);
          if(old_c > new_c){
               printf("New Leaders : \n");
               print_lead(loc,l_obj,input);
               
               free_clus(l_clu,input);
               l_clu = assign_loc_lead(l_lead,input);
               l_clu = assign_obj(l_clu,mat,input);
               free_clus(loc,input);
               old_c = new_c;
               continue;
          }
          else
          {    printf("Previous cost < New cost \n");
               break;
          }    
     }
     print_clus(l_clu,l_obj,input);
     // l_clus  cluster finale 

     free_clus(loc,input);
     free_clus(l_clu,input);
     free(l_lead);
     free_mat(mat);
     free_obj(l_obj);
}
