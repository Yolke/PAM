# PAM

## Description

PAM (Partitioning Around Medoids) est un algorithme de clustering basé sur les médoïdes. Ce projet est une implémentation en C de l'algorithme PAM avec la gestion de clusters. Il est conçu pour organiser des objets en clusters en fonction de leurs attributs, en cherchant à minimiser la somme des distances au sein des clusters.

## Structure du Projet

### Fichiers Principaux

- **`main.c`** : Contient la fonction principale et gère les opérations de clustering.
- **`fonction.h`** : Déclaration des structures et des fonctions utilisées dans le projet.
- **`choixpeauMagique.csv`** : Fichier CSV contenant les données des objets à clusteriser. Chaque ligne représente un objet avec ses attributs.

### Structures de Données

- **`obj`** : Structure représentant un objet avec des attributs comme le Courage, la Loyauté, la Sagesse, et la Malice, ainsi que le nom et la maison de l'objet.
- **`clus`** : Structure représentant un cluster, avec un leader et une liste d'objets associés.

## Compilation

Pour compiler le projet, utilisez la commande suivante :
```sh
    gcc -o pam main.c
```
Assurez-vous que `fonction.h` est dans le même répertoire que votre fichier source.

## Utilisation

Pour exécuter le programme, utilisez la commande suivante en spécifiant le nombre de clusters souhaité :
```sh
    ./pam [Nombre_de_Clusters]
```
### Exemple
```sh
    ./pam 3
```
Ce qui affichera les clusters finaux après exécution de l'algorithme PAM avec 3 clusters.

## Fonctionnalités

- **Remplir les Structures** : La fonction `fill_ges` lit les données du fichier CSV et remplit les structures `obj` avec les attributs des objets.
- **Calcul des Distances** : La fonction `stk_distance` calcule une matrice des distances entre tous les objets.
- **Clustering PAM** : L'algorithme PAM est exécuté par la fonction `PAM`, qui gère l'assignation des objets aux clusters, le recalcul des leaders, et la mise à jour des clusters jusqu'à convergence.
- **Affichage des Résultats** : Les fonctions `print_lead` et `print_clus` affichent les leaders des clusters et les clusters finaux, respectivement.

## Code Source

Les fichiers sources sont en C et incluent la gestion des clusters, des distances, et des objets. Vous pouvez trouver le code dans les fichiers suivants :

- `main.c` : Code principal et fonction d'exécution.
- `fonction.h` : Déclarations des fonctions et structures.
- `choixpeauMagique.csv` : Fichier de données pour les objets.

## Exemples de Données

Le fichier `choixpeauMagique.csv` contient des données sous la forme :

"Nom";"Courage";"Loyauté";"Sagesse";"Malice";"Maison"  
"Adrian";9;4;7;10;"Serpentard"  
"Andrew";9;3;4;7;"Gryffondor"  
...

Chaque ligne représente un objet avec des attributs spécifiques.

## Contact

Pour toute question ou suggestion, veuillez me contacter à [jeremygago@hotmail.fr].
