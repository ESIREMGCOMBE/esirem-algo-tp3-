# esirem-algo-tp3-
Le Document contient les Algorithmes des fonctions du TP3

En C tout a été implémenté mais pour le moment la fonction 'décode' ne prend en compte ni les signes négatifs ni les espaces.
 
Par manque de temps également, l'implémentation en python a été abordée mais non finalisée, le code ne compile pas.

Pour tout de même fournir un travail en python "fonctionnel", le répertoire "py" contient égalementles fonctions demandées à l'issue du TP2


-------------------------------------------------------------------------------------------------------------------------------------------------
1.2	Fonction d’affichage
Réalisez la fonction d’affichage showSolution, qui, à partir d’une Solution, affichera :
-	Il y a deux solutions : x1 et x2
-	Il y a une solution : x
-	Il n’y a aucune solution
L’affichage dépendra du nombre de solutions ; x, x1 et x2 seront évidemment remplacés par leurs valeurs respectives.
-------------------------------------------------------------------------------------------------------------------------------------------------
Algorithme de showSolution
DEBUT 

PARAM solution sol

VAR FLOAT X

VAR FLOAT X1

VAR FLOAT X2

SI (sol.type)=SolutionType.NONE

AFFICHER 'il n'y a aucune solution'		

FIN SI

SI (sol.type)=SolutionType.ONE

AFFICHER 'il n'y a une solution :' + X		

FIN SI

SI (sol.type)=SolutionType.TWO

AFFICHER 'il n'y a 2 solutions :' + X1 + 'et' + X2		

FIN SI

FIN
-------------------------------------------------------------------------------------------------------------------------------------------------
1.4	Fonction de résolution de premier degré
Réalisez la fonction de résolution d’un polynôme de premier degré resolveOne. Cette fonction prendra en argument deux entiers a et b et renverra une solution.
-------------------------------------------------------------------------------------------------------------------------------------------------
Algorithme de resolveOne 

DEBUT 

PARAM ENTIER A

PARAM ENTIER B

VAR FLOAT sol

SI (A = 0)

Enum SolutionType <- 0

FIN SI

SI (A!=0)

Enum SolutionType <- 1

sol <- -B/A

FIN SI

RETURN sol

FIN
-------------------------------------------------------------------------------------------------------------------------------------------------
1.5	Fonction de résolution de second degré
Réalisez la fonction de résolution d’un polynôme de second degré resolveTwo. Cette fonction prendra en argument trois entiers a, b et c et renverra une solution.
-------------------------------------------------------------------------------------------------------------------------------------------------
Algorithme de resolveTwo

DEBUT 

PARAM ENTIER A

PARAM ENTIER B

PARAM ENTIER C

VAR FLOAT DELTA

vAR FLOAT X0

VAR FLOAT X1

VAR FLOAT X2

delta <- (B*B)-4*A*C

SI (DELTA <0) Enum SolutionType <- 0

FIN SI

SI (DELTA =0) 	X0 <- -B/(2*A)

Enum SolutionType <- 1

RETURN X0

FIN SI

SI (DELTA >0)	

X1 <- (-B + RACINE(DELTA))/(2*A)

X2 <- (-B - RACINE(DELTA))/(2*A)

Enum SolutionType <- 2

RETURN X1

RETURN X2

FIN SI

FIN
-------------------------------------------------------------------------------------------------------------------------------------------------
1.6	Fonction centrale
Réalisez la fonction de résolution centrale resolve. Cette fonction prendra en argument trois entiers a, b et c et appellera la bonne fonction parmi resolveOne et resolveTwo en fonction des arguments.
-------------------------------------------------------------------------------------------------------------------------------------------------
Algorithme de resolve

DEBUT 

PARAM ENTIER A

PARAM ENTIER B

PARAM ENTIER C

SI (A = 0) APPELER resolveOne avec comme paramètres B et C

FIN SI

SI (A !=0) APPELER resolveTwo avec comme paramètres A,B et C

FIN SI

FIN
-------------------------------------------------------------------------------------------------------------------------------------------------
1.7	Fonction de lecture et reconnaissance de base
Réalisez la fonction de lecture decode d’une chaîne prédéterminée de format « ax²+bx+c », extrayant a, b et c, et réalisant l’appel à resolve.
Enrichissez la fonction afin qu’elle puisse également gérer la forme « ax+b ». 
-------------------------------------------------------------------------------------------------------------------------------------------------
Algorithme de decode

DEBUT

PARAM cHAINE expression

VAR CHAINE chaineA

VAR CHAINE chaineB

VAR CHAINE chaineC

VAR ENTIER A

VAR ENTIER B

VAR ENTIER C

VAR ENTIER I

FAIRE PARCOURIR expression

chaineA= sous chaine de expression qui va du début jusqu'au caractère 'x' exclu

chaineB= sous chaine de expression comprise entre le 1er caractére '+' et le second caractère '+' exclus

chaineC= sous chaine de expression comprise entre le second caractére '+' exclu et la fin de expression

FIN FAIRE

A <- CONVERSION EN ENTIER(chaineA)

B <- CONVERSION EN ENTIER(chaineB)

C <- CONVERSION EN ENTIER(chaineC)

APPELER resolve avec comme paramètres A,B et C

FIN
-------------------------------------------------------------------------------------------------------------------------------------------------
1.8	Fonction de reconnaissance
Enrichissez la fonction decode, afin qu’elle puisse prendre en compte tous les formats, en ignorant les espaces, et en permettant optionnellement une partie « = r » qui devra être interprétée correctement.
-------------------------------------------------------------------------------------------------------------------------------------------------
cas non traité
-------------------------------------------------------------------------------------------------------------------------------------------------
1.9	FInalisation
Remplacez l’appel à vos tests unitaires par une saisie utilisateur dans votre programme principal.
-------------------------------------------------------------------------------------------------------------------------------------------------
Algorithme du programme principal

DEBUT

VAR cHAINE EXPRESSION

EXPRESSION <- LIRE(AFFICHER "Entrez un polymome sous la forme ax2+bx+c pour calculer ses racines")

APPELER decode avec comme paramètre "EXPRESSION"

FIN
