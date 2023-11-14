# esirem-algo-tp3-
Le Document contient les Algorithmes des fonctions du TP3

En C tout a été implémenté mais pour le moment la fonction 'décode' ne prend en compte ni les signes négatifs ni les espaces.
 
Par manque de temps également, l'implémentation en python a été abordée mais non finalisée, le code ne compile pas.

Pour tout de même fournir un travail en python "fonctionnel", le répertoire "py" contient égalementles fonctions demandées à l'issue du TP2
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1.2	Fonction d’affichage
Réalisez la fonction d’affichage showSolution, qui, à partir d’une Solution, affichera :
-	Il y a deux solutions : x1 et x2
-	Il y a une solution : x
-	Il n’y a aucune solution
L’affichage dépendra du nombre de solutions ; x, x1 et x2 seront évidemment remplacés par leurs valeurs respectives.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

1.4	Fonction de résolution de premier degré
Réalisez la fonction de résolution d’un polynôme de premier degré resolveOne. Cette fonction prendra en argument deux entiers a et b et renverra une solution.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Algorithme de resolveOne 

DEBUT 
PARAM ENTIER A
PARAM ENTIER B
VAR FLOAT sol

SI (A = 0)
		Enum SolutionType <- 0
		BREAK
FIN SI
SI (A!=0)
		Enum SolutionType <- 1
		sol <- -B/A
FIN SI
RETURN sol
FIN
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

1.5	Fonction de résolution de second degré
Réalisez la fonction de résolution d’un polynôme de second degré resolveTwo. Cette fonction prendra en argument trois entiers a, b et c et renverra une solution.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
SI (DELTA >0)	X1 <- (-B + RACINE(DELTA))/(2*A)
		X2 <- (-B - RACINE(DELTA))/(2*A)
		Enum SolutionType <- 2
		RETURN X1
		RETURN X2
FIN SI
FIN
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

1.6	Fonction centrale
Réalisez la fonction de résolution centrale resolve. Cette fonction prendra en argument trois entiers a, b et c et appellera la bonne fonction parmi resolveOne et resolveTwo en fonction des arguments.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

1.7	Fonction de lecture et reconnaissance de base
Réalisez la fonction de lecture decode d’une chaîne prédéterminée de format « ax²+bx+c », extrayant a, b et c, et réalisant l’appel à resolve.
Enrichissez la fonction afin qu’elle puisse également gérer la forme « ax+b ». 
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

1.8	Fonction de reconnaissance
Enrichissez la fonction decode, afin qu’elle puisse prendre en compte tous les formats, en ignorant les espaces, et en permettant optionnellement une partie « = r » qui devra être interprétée correctement.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
cas non traité
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1.9	FInalisation
Remplacez l’appel à vos tests unitaires par une saisie utilisateur dans votre programme principal.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Algorithme du programme principal

DEBUT

VAR cHAINE EXPRESSION
EXPRESSION <- LIRE(AFFICHER "Entrez un polymome sous la forme ax2+bx+c pour calculer ses racines")
APPELER decode avec comme paramètre "EXPRESSION"

FIN

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
code dans C/main
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


   // déclaration de l'enum
   enum SolutionType { NONE=0, ONE=1, TWO=2 };

   // déclaration de la structure solution
    struct Solution {

    enum SolutionType type;
    float x0,x1,x2;

                    };


   // déclaration de l'équation
    struct Equation {

    struct Solution solution;
    int a,b,c;
                     };


// déclaration de la fonction d'affichage
    showSolution(struct Solution sol){

       if ( sol.type == NONE){
            printf("\n Il n'y a aucune solution ");
           }
        if ( sol.type == ONE){
        printf("\n Il y a une solution : %f",sol.x0 );
           }
        if ( sol.type == TWO){
        printf("\n Il y a 2 solutions : %f et %f",sol.x1,sol.x2 );
           }
   }

// déclaration de la fonction de résolution d’un polynôme de premier degré

resolveOne(int a,int b){
float af=a;                 // conversion des paramètres int en float pour éviter les surprises lors de la division
float bf=b;

float sol;
struct Solution test;
if (a != 0){
		test.type = ONE;
		sol = -bf/af;
		printf("la solution est %.3f",sol);                 // on arrondit les résultats à 3 chiffres après la virgule
}
else {
		test.type = NONE;
}

}

// déclaration de la fonction de résolution d’un polynôme de second degré

resolveTwo(int a,int b,int c){
float af=a;                 // conversion des paramètres int en float pour éviter les surprises lors de la division
float bf=b;
float cf=c;
float delta;

float sol0,sol1,sol2;
struct Solution test;

delta = (bf*bf)-4*af*cf;

if (delta > 0){
    test.type = TWO;
    test.x1 = (-bf+sqrt(delta))/2/af;
    test.x2 = (-bf-sqrt(delta))/2/af;
    sol1= test.x1;
    sol2= test.x2;
    printf("il y a 2 solutions :  x1=%.3f et x2=%.3f",sol1,sol2);
}
if (delta == 0){
		test.type = ONE;
		test.x0 = -bf/af/2;
		sol0= test.x0;
		printf("la solution unique est x0=%.3f ",sol0);                 // on arrondit les résultats à 3 chiffres après la virgule
}
if (delta < 0) {
		test.type = NONE;
		printf("il n'y a pas de solution dans R");
}


}

// déclaration de la la fonction de résolution centrale
resolve(int a,int b,int c){
if (a == 0) {resolveOne(b,c);
}
else{ resolveTwo(a,b,c);
}

}
// déclaration de la la fonction de lecture et reconnaissance de base
decode(char expression[])   {            // l'expression des de la forme AAAx2+BBBBBx+CCCCCCCCC
  int a,b,c;
  char chaineA[10];
  char chaineB[10];
  char chaineC[10];
  int i,j,k;
  int l=0;
  int m=0;
  int long_chain = strlen(expression);
  for(i=0;expression[i]!='x';i++)                      // boucle pour récupérer le terme de degré 2
         {
        chaineA[i]=expression[i];
      }
 for(j=i+3;expression[j]!='x';j++)                      // boucle pour récupérer le terme de degré 1
    // on "saute" la chaine de  caractères 'x2+' d'où j=i+3
        {
chaineB[l]=expression[j];
l++;
      }
for(k=j+2;k < long_chain;k++)                      // boucle pour récupérer le terme de degré 0
    // on "saute" la chaine de  caractères 'x+' d'où k=j+2
           {
chaineC[m]=expression[k];
m++;
      }
a = atoi(chaineA);                          // conversion des chaines constituées en entiers
b = atoi(chaineB);
c = atoi(chaineC);

resolve(a,b,c);             // appel de la fonction resolve avec les termes identifiés
}
int main()

{   struct Solution test;
char chaine_test[100];


printf("\ Entrez un polymome sous la forme ax2+bx+c pour calculer ses racines \n");
scanf("%s", chaine_test);
 printf("\n Votre polynome est: %s \n", chaine_test);

//  decode("3x2+5x+2");         // test avec un delta > 0
//  decode("4x2+4x+1");         // test avec un delta=0
//  decode("2x2+3x+4");         // test avec un delta < 0
//  decode("0x2+3x+4");         // test avec un polynome du 1er degré

 decode(chaine_test);



	return 0;
}

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
code dans py/TP2
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# TP2 
import math
                   
#définition de la fonction qui détermine si un nombre N est un nombre premier
def is_prime(N):

    cont=0
    prime=1

    for i in range(1,N):
                    if ((N % i)==0):
                                cont=cont+1
                    if (cont==2) : prime=0

    return(prime)

#définition de la fonction qui affiche les N nombres premiers à partin d'un seuil minimal
def generatePrimes01(mini,N):

    cont=0
    i=mini
    while (cont < N):
        if  (is_prime(i)== 1):
            cont=cont+1
            print(i)
        i=i+1
            

#définition de la fonction qui affiche les nombres premiers compris entre 2 bornes
def generatePrimes02(mini,maxi):
    i=mini
    while (i<maxi):
        if  (is_prime(i)== 1):
            print(i)
        i=i+1


# programme principal
choix12=0
#début saisie forcée pour 1 ou 2
while(choix12!=1)and(choix12!=2):
    choix12=int(input("mini et nombre (1) ou min et max (2)?: "))
#fin saisie forcée pour 1 ou 2
if choix12==1:
    mini=int(input("Valeur minimale?: "))
    N=int(input("Combien de nombres à afficher?: "))
    generatePrimes01(mini,N)

if choix12==2:
    mini=int(input("Valeur minimale?: "))
    maxi=int(input("Valeur maximale?: "))
#debut inverser les bornes si necessaire
    if(mini>maxi):
        mini = mini+maxi
        maxi = mini-maxi
        mini = mini-maxi
#fin inverser les bornes si necessaire
    generatePrimes02(mini,maxi)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
code dans py/TP3
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# TP3
import math
                         
# déclaration de l'énum
from enum import Enum
class SolutionType(Enum):
    NONE = 0
    ONE = 1
    TWO = 2


# déclaration de la structure solution
class Solution:
    enum SolutionType type
    x0 default 0
    x1 default 0
    x2 default 0

# déclaration de la structure equation
class Equation:
    a
    b
    c
    class Solution solution


    
# déclaration de la fonction d'affichage
def showSolution(class Solution sol):
    if sol.type = NONE:
        input(" Il n'y a aucune solution ")
    if sol.type == ONE:
        input(" Il y a une solution :")
        input(sol.x0)
    if sol.type = TWO:
        input(" Il y a 2 solutions : %f et %f" % (sol.x1,sol.x2))

# Fonction de résolution de premier degré
resolveOne(int a,int b):
    float af=a
    float bf=b
    float sol;
    Solution test
    if a != 0:
        test.type = ONE
        sol = -bf/af
        input("la solution est %.3f",sol)
    else:
        test.type = NONE

# Fonction de résolution de second degré
resolveTwo(int a,int b,int c):
    float af=a                 
    float bf=b
    float cf=c
    float delta=(bf*bf)-4*af*cf
    float sol0,sol1,sol2
    struct Solution test

    if delta > 0:
        test.type = TWO
        test.x1 = (-bf + math.sqrt(delta))/2/af;
        test.x2 = (-bf - math.sqrt(delta))/2/af;
        sol1= test.x1
        sol2= test.x2
        input("il y a 2 solutions :  x1=%.3f et x2=%.3f",sol1,sol2)

    if delta == 0:
        test.type = ONE
        test.x0 = -bf/af/2
        sol0= test.x0
        input("la solution unique est x0=%.3f ",sol0)

    if delta < 0:
        test.type = NONE
        input("il n'y a pas de solution")

        
# Fonction de résolution centrale
resolve(int a,int b,int c):
    if a == 0:
        resolveOne(b,c)
    else:
        resolveTwo(a,b,c)

# Fonction de lecture et reconnaissance de base : non implémentéé


# Programme principal

chaine_test= input("Entrez un polymome sous la forme ax2+bx+c pour calculer ses racines :")
decode(chaine_test)
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------





