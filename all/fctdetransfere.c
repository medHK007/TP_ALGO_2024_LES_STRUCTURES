#include"headerofall.h"

PTliste*listetab_to_listeprt(PTliste*L,tab*T)
{
    int i ;
    for(i=0;i<T->NbElem;i++)
        L=inserer_fin(L,T->TabInt[i]);
    Inittab(T);
    return(PTliste*)(L);
}
PTpile*listeptr_to_pileptr(PTpile*P,PTliste*L)
{
    if(!L)
    {
        printf("la liste est vide \n\n");
    }
    while(!estvide(L))
    {
        P=empiler(P,L->entier);
        L=supprimerdebutliste(L);
    }
    return(PTpile*)(P);
}
int pileptr_to_fileptr(PTpile*P,PTfile*F)
{
    if(pile_vide(P))
    {
        printf("pile vide\n\n");
        return 0;
    }
    while(!pile_vide(P))
    {
        enfiler(F,P->entier);
        P=depiler(P);
    }
    return 1;
}
Arbre*fileptr_to_arbreptr(Arbre*A,PTfile*F)
{
    if(file_vide(F))
    {
        printf("file est vide");
        return(Arbre*)(A);
    }
    while(!file_vide(F))
    {
        A=insererarbre(A,F->debut->entier);
        defiler(F);
    }
    return(Arbre*)(A);
}
