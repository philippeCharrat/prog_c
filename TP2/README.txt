# Bibliothèque :
	*stido.h
	*string.h
	*stdlib.h
	*time.h

# Références :
   Pour l'exercice 2.9 -tableauptr.c-, nous avons utilisé comme base le code de la page suivante : https://stackoverflow.com/questions/686353/random-float-number-generation/17798317
   Le code de variables.c était requis pour écrire le programme ptrvariables.c.

# Commentaires :
   Chaque code est commenté.
   Le code de l'exercice 2 : bit.c a été réalisé à l'aide de l'exercice 1.10 binaire.c, la méthode de convertion de decimal vers bits utilise une boucle et un tableau de 32 élements avec des opérations de modulo.Nous allons ensuite parcorir le tableau voir si les bits 4 et 20 sont à 0 ou 1 et retourné un resultat en fonction. Pour l'entrée, nous avons opté pour une solution d'argument récupéré via la foncion scanf. Une dernière partie est consacrée à l'affichage. 
   exemple : entrée : 15, sortie : 00000000000000000000000000001111 et le résultat vaut : 0
