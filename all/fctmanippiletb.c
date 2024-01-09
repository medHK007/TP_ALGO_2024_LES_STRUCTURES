#include"headerofall.h"

//taille de la pile

int tailleTpile(TPILE Mapile)
{
    return((int)(Mapile.sommet+1));
}

//vider la pile

int razTpile(TPILE *Mapile)
{
    if(!Mapile) return ((int)0);
    Mapile->sommet=-1;
    return ((int)1);
}

//vérifier si la pile est vider

int estVideTpile(TPILE Mapile)
{
    return ((int)Mapile.sommet==-1);
}

//vérifier si la pile est saturer

int estSaturerTpile(TPILE Mapile)
{
    return ((int)(Mapile.sommet==(maxElem-1)));
}

//depiler une pile

int depilerTpile(TPILE *Mapile)
{
    if(!Mapile) return((int)0);
    if(!estVideTpile(*Mapile))
        Mapile->sommet--;
    return((int)1);
}

//enmpiler une pile

int empilerTpile(TPILE *Mapile,int val)
{
    if(!Mapile) return((int)-1);
    if(estSaturerTpile(*Mapile)) return((int)0);
    Mapile->table[++Mapile->sommet]=val;
    return ((int)1);
}

//affichage du sommet
//on doit effectuer les tests nécessaire dans le main avant d'appeler cette fonction
int sommetTpile(TPILE Mapile)
{

        return((int)Mapile.table[Mapile.sommet]);

}
