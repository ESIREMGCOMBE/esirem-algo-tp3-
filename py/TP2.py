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



    
            
