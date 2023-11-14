
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






