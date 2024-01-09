#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define OPER1 '+'
#define OPER2 '-'
#define OPER3 '*'
#define OPER4 '/'

#define RC '\n'
#define BL ' '

typedef union ch
{
    float oprnd;
    char operation;
}champ;

typedef struct A
{
    champ variable;//l'variable soit operation soit un operande
    struct A *gch;//fils gauche
    struct A *drt;//fils droit
}Arbre;

// deja fait dans les TP qui precede
Arbre *creer()
{
    Arbre *NE;
    NE = (Arbre *)malloc(sizeof(Arbre));// Allocation de la memoire
    if (!NE)  exit(0);// mal allocation
    NE->gch = NE->drt = NULL;// Initialiser les fils au NULL
    return ((Arbre *)NE);
}

char epurer_blanc(char c)
{
    return ((char)(c == BL) ? epurer_blanc(getchar()):c);
}

int EstNumerique(char c)
{
    if(('0'<=c) && (c<='9')) return ((int)(c-'0')); // le caractere est un numerique
    if(c == ' ') return ((int)11); // le caractere est un blanc
    if(c == '.') return ((int)12); // le caractere est un point
    return ((int)(-1));//sinon
}

int est_oper(char c)
{
    switch (c)
    {
        case RC : return ((int)0);
        case OPER1 : return ((int)1);
        case OPER2 : return ((int)2);
        case OPER3 : return ((int)3);
        case OPER4 : return ((int)4);
        default : return ((int)-1);
    }
}

char char_to_float(float *oprnd)
{
    int numer; //resultat de la fonction "EstNumerique(char)"
    int prem_car = 1; // pour tester la premiere lecture
    int f = 0; // pour distinguer la partie entiere et la partie reel
    int signe = 1; // pour stocker le signe du nombre
    float result = 0; // pour stocker le nombre extrait
    char c = getchar();
    c = epurer_blanc(c); // Epeurer blanc
    do
    {
        if(prem_car == 1) // Lors de la lecture du premier caractere
        {
            prem_car = 0; // pour indiquer qu'on a lu le premier caractere
            if ((c == '-') || (c == '+'))
            {   // recuperer le signe du nombre
                if (c == '-') signe = -1;
                c = getchar();
                continue; // passer a l'iteration suivante
            }
        }
        numer = EstNumerique(c);
        switch (numer)
        {
            case -1:
                printf("\nErreur: caractere non numerique!");
                exit(0);
            case 11: // un blanc
                c = epurer_blanc(c);
                *oprnd = (float)(result*signe);
                return ((char)c);


        case 12: // un point
                if(f == 0) // on y encore dans la partie entiere
                {
                    f = -1; // passer a la partier reel
                    break;
                }
                printf("\nErreur: un autre point est tape!");
                exit(0);
            default: // caractere numerique
                if (f == 0) result = result*10 + (float)numer;
                else result += (float)((float)(numer)*pow(10,f--));
        }
        c = getchar();
    } while ((c != OPER1) && (c != OPER2) && (c != OPER3) && (c != OPER4) && (c != RC));
    *oprnd = (float)(result*signe);
    return ((char)c);
}

Arbre *Construire_Arbre_champ()
{
    Arbre *Arb = NULL, *Noperation, *Noprnd, *courant;
    char operation; // pour stocker l'operation lue
    float oprnd; // pour stocker l'oprnd extrait
    int numer; // pour stocker la valeur retournee par "est_oper(char)"
    int direction = 1; // pour indiquer la direction d'insertion d'un sous arbre
    printf("\nEntrer une champression arithmetique : ");
    while ((operation = char_to_float(&oprnd)) != RC)
    {
        numer = est_oper(operation);
        if (numer == -1)
        {
            printf("\noperation non defini!");
            exit(0);
        }
        Noprnd = creer(); // Creer un Arbre pour l'oprnd
        Noprnd->variable.oprnd = oprnd; // affecte la valeur de l'oprnd
        Noperation = creer(); // Creer un Arbre pour l'operation
        Noperation->variable.operation = operation; // affecter le l'operation
        if (!Arb) // Arbre vide
        {
            Arb = Noperation; // l'operation devient racine de l'arbre
            Arb->gch = Noprnd; // l'oprnd devient son fils gauche
            courant = Arb; // initialiser courant par la racine de l'arbre
        }
        else
        {   // l'oprnd devient le fils libre de dernier operation inserer
            if (!courant->drt) courant->drt = Noprnd;
            else courant->gch = Noprnd;
            // si l'operation est un '+' ou '-'
            if ((numer == 1) || (numer == 2))
            {
                if (numer == 1) // le cas d'un '+'
                {
                    if (direction == 0) Noperation->gch = Arb;
                    else Noperation->drt = Arb;
                    direction = 1-direction; // changer direction pour la prochaine insertion
                }
                // cas d'un '-' l'arbre devient sous arbre gauche de l'operation
                else Noperation->gch = Arb;
                Arb = Noperation; // l'operation devient la racine de l'arbre
            }
            else // l'operation est '*' ou '/'
            {   // le dernier operation inserer est '+'
                if (courant->variable.operation == OPER1)
                {
                    if (direction == 0)
                    {
                        Noperation->gch = Arb->gch;
                        Arb->gch = Noperation;
                    }
                    else
                    {
                        Noperation->gch = Arb->drt;
                        Arb->drt = Noperation;
                    }
                    direction = 1 - direction; // changer direction pour la prochaine insertion
                }
                else
                {   // le dernier operation inserer est '-'
                    if (courant->variable.operation == OPER2)
                    {
                        Noperation->gch = Arb->drt;
                        Arb->drt = Noperation;
                    }
                    else // le dernier operation inserer est '*' ou '/'
                    {   // le dernier operation devient fils gauche
                        Noperation->gch = courant;
                        if (Arb == courant) Arb = Noperation;
                        else Arb->drt = Noperation;
                    }
                }
            }
            courant = Noperation;
        }
    }
    Noprnd = creer(); // Creer un Arbre pour l'oprnd
    Noprnd->variable.oprnd = oprnd; // affecte la valeur de l'oprnd
    if (!Arb) return ((Arbre *)Noprnd); // si l'arbre est vide
    if (!courant->drt) courant->drt = Noprnd;
    else courant->gch = Noprnd;
    return ((Arbre *)Arb);
}
/* **************************************************************************
    Nom         : Calculer_champ;
    Entrees     : float op1      : le premier oprnd
                  char operation : un operation
                  float op2      : le deuxieme oprnd
    Sorties     : float result   : le resultat de l'operation
    Description : la fonction permet d'effectuer une operation arithmetique
                de deux oprnds et de retourner le resultat.
************************************************************************** */
float Calculer_champ(float Op1, char operation, float Op2)
{
    switch (operation)
    {
        case '+': return ((float)Op1 + Op2);
        case '-': return ((float)Op1 - Op2);
        case '*': return ((float)Op1 * Op2);
        case '/':
            if (Op2 != 0) return ((float)Op1 / Op2);
            // Cas de division par 0
            printf("\nErreur: Division par 0!!");
            exit(0);
    }
    return ((float)0.0);
}
/* **************************************************************************
    Nom         : Evaluer_Arbre_champ;
    Entrees     : Arbre *Arb : la racine de l'arbre
    Sorties     : float      : le resultat d'evaluation de l'champression
                arithmetique
    Description : la fonction permet d'evaluer l'champression arithmetique qui
                est represente sous forme d'un arbre binaire en effectuant un
                parcour infixe de l'arbre.
************************************************************************** */
float Evaluer_Arbre_champ(Arbre *Arb)
{
    if (Arb)
    {
        if (!Arb->gch && !Arb->drt) return ((float)Arb->variable.oprnd);
        return ((float)Calculer_champ(Evaluer_Arbre_champ(Arb->gch),
                                    Arb->variable.operation,
                                    Evaluer_Arbre_champ(Arb->drt)));
    }
    return((float)0.0);
}

int main()
{
    Arbre *A=NULL;
    A=Construire_Arbre_champ();
    printf("%f",Evaluer_Arbre_champ(A));

    return 0;
}
