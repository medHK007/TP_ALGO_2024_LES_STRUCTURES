#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define BL ' '
#define MAX 30

typedef struct arb
{
    int donnee ;
    int nbr_elemnet ;
    struct arb *fgche;
    struct arb*fdrt ;
}Arbre ;
int lire_expression(char *expression);
Arbre *creercellule(int);
Arbre *inserer(Arbre*,int);
void afficher_infixe(Arbre*);



#endif // HEADER_H_INCLUDED
