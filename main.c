
#include "fonction.h"



int main(int argc, char* argv[]){
    
    if(argc != 2){
          printf("Erreur attente du format ./main Number\n");
          return 2;
     }
     int input = atoi(argv[1]);
     printf("%d Cluster \n",input);
     if(input > MAX){
          printf("Error expect less then %d!",MAX);
          return 1;
     }
     PAM(input);
     
    return 0;
}