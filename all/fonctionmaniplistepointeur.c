#ifndef FONCTIONMANIPLISTEPOINTEUR_C_INCLUDED
#define FONCTIONMANIPLISTEPOINTEUR_C_INCLUDED

#include"headerofall.h"

/*creer une cellule */
PTliste *creerliste()
{
    PTliste* NE ; //declarer un nouveau element
    NE=(PTliste*)malloc(sizeof(PTliste));//allouer la memoire pour ce nouveau element
    if(!NE) exit(-1);//verifier si la memoire est allouer
    NE->suivant=NULL; // initialisation du champs pointuer
    return (PTliste*)(NE); // retourner l'adresse de nouveau element
}

/*----------------------------------------------------------------*/

/*verifier si la liste est vide*/
int estvide(PTliste* liste)
{
    return (int)(liste==NULL); //comparer la tete de la liste avec Null
}

/*----------------------------------------------------------------*/

/*taille liste*/
int taille_liste(PTliste* liste)
{
    PTliste *courant = liste ;//declarer un pointeur qui va parcourir toutes la liste et l'initialiser en tete de liste
    int taille =0; //compteur pour calculer la taile
    //boucle pour parcourir la liste
    while(courant)
    {
        taille++ ;
        courant=courant->suivant;//faire avancer le pointeur
    } //fin while
    return(int)(taille); //retourner la taille
}

/*----------------------------------------------------------------*/


/* afficher */
void afficher(PTliste* liste)
{
    PTliste *courant; //declarer un pointeur qui va parcourir toutes la liste
    //boucle pour parcourire la liste
    courant=liste;
    if(!liste)
    {
        printf("liste vide\n\n");
        return;

    }
    while(courant->suivant)
    {
        printf("%d --> ",courant->entier); //afficher les elements
        courant=courant->suivant;
    }
    printf("%d\n",courant->entier);
    printf("\n");
}

/*----------------------------------------------------------------*/

/*vider une liste*/
PTliste *vider_liste(PTliste *liste)
{
    PTliste *temp = liste ;//declarer un pointeur qui va parcourir toutes la liste et qui va prendre les cellules à supprimer
    //boucle de parcoure
    while(liste)

    {
        temp=liste;//temp recoit l ' element a supprimer
        liste=liste->suivant; //faire avancer la tete de la liste
        free(temp);//librer l'emplacement memoire
    }
    return (PTliste*)(liste);//retourner la tete de la liste
}

/*----------------------------------------------------------------*/

//inserer un element donnee a la tete de la liste
PTliste *inserer_debut(PTliste *liste , int donnee)
{
    PTliste*NE=creerliste();//declarer un nouveau element
    NE->entier=donnee;//remplir le champs entier
    if(estvide(liste)) return(PTliste*)(NE);
    NE->suivant=liste ;
    return (PTliste*)(NE); //returner la liste

}

/*----------------------------------------------------------------*/

//inserer un element donnee a la fin de la liste
PTliste *inserer_fin(PTliste* liste , int donnee)
{
    //declarer le nouveau element à a inserer avec un pointeur qui va chercher la fin de la liste
    PTliste *NE=creerliste(),*courant=liste ;
    NE->entier=donnee;//remplir le champs donnee
    //verifier si on a une liste vide , si oui on effectuer une insertion a la fin
    if(estvide(liste)) return(PTliste*)(NE);
    while(courant->suivant)
    {
        courant=courant->suivant;
    }//chercher la fin de la liste
    courant->suivant=NE ;//mettre a jour les pointeurs
    return (PTliste*)(liste);//returner l'adresse de la liste
}

/*----------------------------------------------------------------*/

//inserer un element à une position donnee
PTliste *inserer_position_donnee(PTliste *liste,int donnee,int position)
{
    //declarer un element qui va chercher la position recommander avec un nouveau element à inserer
    PTliste *courant=liste,*NE ;
    int indice =1 ; //initialiser le compteur
    if(position<1 || position >taille_liste(liste)+1)//verifier si la position est validée
    {
        printf("position invalid");
        return (PTliste*)(NULL);
    }
    //verifier si la position passé est egale à 1 cad insertion au debut
    if(position==1) return (PTliste*)inserer_debut(liste,donnee);
    //verifier si la position passé est egale à la taille de la liste  cad insertion a la fin
    else if (position==taille_liste(liste)+1) return (PTliste*)inserer_fin(liste,donnee);
    else
    {
    NE=creerliste();
    NE->entier=donnee;
    while(courant->suivant)
    {
        if(indice<position-1)
        {
        courant=courant->suivant;
        indice++;
        }
        else break;
    }//fin while
    //metre a jour les pointeurs
    if(courant->suivant)
    {

    NE->suivant=courant->suivant;
    courant->suivant=NE ;
    }
    return (PTliste*)(liste);//returner la tete de la liste
    }
}
//retourner l'emplacement du premier occurence d'un nombre
int emplacement_premiere_occ(PTliste *liste,int donne)
{
    PTliste *courant ; //pointeur pour parcourir la liste
    int position =1 ;//un compteur utilisier pour determiner la position
    //verifier si la liste est vide
    if(estvide(liste))
    {
        printf("liste est vide ");
        return (int)(-1);
    }
    //boucle pour chercher la position de l'element
    for(courant=liste;courant;courant=courant->suivant)
    {
        if(courant->entier!=donne) position++;
        else
        {
                return (int)(position);
        }
    }

    return (int)(0);//l'element n'existe pas
 }

/*----------------------------------------------------------------*/

//retourner le nombre d'occurence d'un nombre
int nbr_occurence(PTliste *liste , int donnee)
{
    PTliste *courant ; // pour parcourir la liste
    long int occurence =0;//pour stocker le nombre d'occurence
    if(estvide(liste)) //verifier si la liste est vide
    {
        printf("liste vide");
        return (int)(-1);
    }
    //parcourir la liste pour savoir le nombre d'occurence d'un entier
    for(courant=liste ; courant;courant=courant->suivant)
    {
        if(courant->entier==donnee)occurence++;
    }
    return(int)(occurence);
}

/*----------------------------------------------------------------*/

//somme des elements de la liste
int Somme(PTliste *liste)
{
    PTliste *courant ;//pour parcourir la liste
    unsigned long int somme =0 ;//variable pour stocker la somme
    if(estvide(liste))
    {
        printf("liste vide");
        return (long int)(-1);
    }
    //parcourire la liste
    for(courant=liste ;courant;courant=courant->suivant)
        somme+=courant->entier;
    return (int)(somme);
}

PTliste *supprimerOccurence(PTliste*L,int val)
{
    PTliste*temp ,*courant=L;
    if(!L) return(PTliste*)(NULL);
    if(L->entier==val)
    {
        temp=L;
        L=L->suivant;
        free(temp);
        return(PTliste*)(L);
    }
    while(courant->suivant)
    {
        if(courant->suivant->entier==val)
        {
            temp=courant->suivant;
            courant->suivant=courant->suivant->suivant;
            free(temp);
            return(PTliste*)(L);
        }
        courant=courant->suivant;
    }
    printf("element non trouver!!\n");
    return(PTliste*)(L);
}

PTliste *supprimertouteOccurence(PTliste*L,int val)
{
    PTliste*temp ,*courant=L;
    if(!L) return(PTliste*)(L);
    if(L->entier==val)
    {
        temp=L;
        L=L->suivant;
        free(temp);
        return(PTliste*)(L);
    }
    while(courant->suivant)
    {
        if(courant->suivant->entier==val)
        {
            temp=courant->suivant;
            courant->suivant=courant->suivant->suivant;
            free(temp);
            break;
        }
        courant=courant->suivant;
    }
    L=supprimerOccurence(L,val);
    return(PTliste*)(L);
}

PTliste*insererbonneplace(PTliste*liste , int val)
{
    PTliste*NE=creerliste(),*courant=liste;
    NE->entier=val;
    if(!liste) return(PTliste*)(NE);
    if(liste->entier>=val) return(PTliste*)(inserer_debut(liste,val));
    while(courant->suivant)
    {
        if(courant->suivant->entier<val)
            courant=courant->suivant;
        else break;
    }
    if(!courant->suivant) return(PTliste*)(inserer_fin(liste,val));
    NE->suivant=courant->suivant;
    courant->suivant=NE;
    return(PTliste*)(liste);


}
PTliste*supprimerdebutliste(PTliste*L)
{
    PTliste*temp=L;
    if(!L) return(PTliste*)(L);
    temp=L;
    L=L->suivant;
    free(temp);
    return(PTliste*)(L);
}
#endif // FONCTIONMANIPLISTEPOINTEUR_C_INCLUDED
