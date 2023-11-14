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






        


    





    
            
