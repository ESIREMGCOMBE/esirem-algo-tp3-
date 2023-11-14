
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
decode(char expression[])   {            // l'expression des de la forme AAAx2+BBBx+CCC
  int a,b,c;
  char chaineA[10];
  char chaineB[10];
  char chaineC[10];
  int signeA=1;
  int signeB=1;
  int signeC=1;

  int i,j,k;
  int l=0;
  int m=0;
  int long_chain = strlen(expression);

 // printf("\n premier charA %c",expression[0]);    // affichage pour vérifier le premier caractère du terme de degré 2

    if (expression[0]=='-')
      {
         signeA = -1;                            // détection du caractère '-' pour le terme de degré2 et changement de signe
      }



  for(i=0;expression[i]!='x';i++)                      // boucle pour récupérer le terme de degré 2
         {

      if (signeA==1){
        chaineA[i]=expression[i];
      }
        else{
        chaineA[i]=expression[i+1];                     // gestion du décalage dans la chaine si le premier caractère du terme de degré 2 est '-'
      }

         }

            if ((expression[i+1]=='-')&&(signeA==1))
      {
         signeB= -1;               // attribution du signe de B en fonction du 1er caractère juste après l'indice (exp)2 modulo signe du terme de degre 1
      }
                  if ((expression[i]=='-')&&(signeA==-1))
      {
         signeB= -1;
      }
//printf("\n premier charB %c",expression[i]);    // affichage pour vérifier le premier caractère du terme de degré 1 modulo signe du terme de degre 1
//printf("\n premier charB %c",expression[i+1]);

     if (signeA==-1){
        i--;                                        // décalage de la suite de la chaine si son premier caractère est '-'
      }


 for(j=i+3;expression[j]!='x';j++)                      // boucle pour récupérer le terme de degré 1
    // on "saute" la chaine de  caractères 'x2+' d'où j=i+3
        {
chaineB[l]=expression[j];
l++;
      }
            if (expression[j+1]=='-')
      {
         signeC= -1;                            // attribution du signe de C en fonction du 1er caractère juste après le second x dans la chaine
      }
//printf("\n premier charC %c",expression[j+2]);    // affichage pour vérifier le premier caractère du terme de degré 0

for(k=j+2;k < long_chain;k++)                      // boucle pour récupérer le terme de degré 0
    // on "saute" la chaine de  caractères 'x+' d'où k=j+2
           {
chaineC[m]=expression[k];
m++;
      }
a = signeA*atoi(chaineA);                          // conversion des chaines constituées en entiers
b = signeB*atoi(chaineB);
c = signeC*atoi(chaineC);
//printf("\n a,b,c = %d,%d,%d ",a,b,c);            // affichage pour vérifier si les 3 termes sont bien identifiés


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


// decode("-5x2+5x+1);          // test changement signe de A
// decode("-5x2-5x+1);          // test changement signe de B
// decode("5x2+5x-1);          // test changement signe de C

 decode(chaine_test);



	return 0;
}






