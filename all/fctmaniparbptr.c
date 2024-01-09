#include"headerofall.h"
#/*preparer un noued pour l'inserer*/
Arbre *creercellule(int info)
{
    Arbre *NE ; //declarer un nouveau element
    NE=(Arbre*)malloc(sizeof(Arbre));//allouer l'espace memoire pour NE
    if(!NE) return(Arbre*)(NULL);
    NE->donnee=info;
    NE->fdrt=NULL;
    NE->fgche=NULL;
    NE->nbr_elemnet=1;
    return (Arbre*)(NE);
}
Arbre *insererarbre(Arbre *A,int info)
{
    if(!A) return (Arbre*)(creercellule(info));
    if(info>A->donnee)
        A->fdrt=insererarbre(A->fdrt,info);
    if(info <A->donnee)
        A->fgche=insererarbre(A->fgche,info);
    if(A->donnee==info) A->nbr_elemnet++;
    return (Arbre*)(A);

}
void afficher_infixe(Arbre*A)
{
    if(!A) return ;
    afficher_infixe(A->fgche);
    printf("%d (%d)\n",A->donnee,A->nbr_elemnet);
    afficher_infixe(A->fdrt);
}
void afficher_prefixe(Arbre*A)
{
    if(!A) return ;
    printf("%d (%d)\n",A->donnee,A->nbr_elemnet);
    afficher_prefixe(A->fgche);
    afficher_prefixe(A->fdrt);

}
void afficher_postfixe(Arbre*A)
{
    if(!A) return;
    afficher_postfixe(A->fgche);
    afficher_postfixe(A->fdrt);
    printf("%d (%d)\n",A->donnee,A->nbr_elemnet);
}

int existe(Arbre*A,int info)
{
    if(!A)  return (int)(0);
    if(A->donnee==info) return(int)(1);
    if(A->donnee<info) existe(A->fdrt,info);
    if(A->donnee>info) existe(A->fgche,info);
    return (int)(1);
}

Arbre*mini(Arbre *A)
{
    while(A->fgche)
        A=A->fgche;
    return (Arbre*)(A);
}
Arbre*maxi(Arbre*A)
{
    while(A->fdrt)
        A=A->fdrt;
    return (Arbre*)(A);
}
Arbre*supprimerarbre(Arbre*A,int info)
{
    if(!A)
    {
        printf("l'element n'existe pas");
        return (Arbre*)(A);
    }

    if(info>A->donnee) A->fdrt=supprimerarbre(A->fdrt,info);
    else if(info<A->donnee ) A->fgche=supprimerarbre(A->fgche,info);
    else
    {
        if(A->nbr_elemnet>1)
        {
            A->nbr_elemnet--;
            return(Arbre*)(A);
        }
        Arbre*temp=NULL;
        if(!A->fdrt && !A->fgche)
        {
            free(A);
            return(Arbre*)(temp);
        }
        else if (!A->fdrt)
        {
        temp = A->fgche;
        free(A);
        return (Arbre*)(temp);
        }
        else if (!A->fgche)
        {
        temp = A->fdrt;
        free(A);
        return (Arbre*)(temp);
        }
        else
        {
       temp=mini(A->fdrt);
       A->donnee=temp->donnee;
       A->nbr_elemnet=temp->nbr_elemnet;
       temp->nbr_elemnet=1;
       A->fdrt=supprimerarbre(A->fdrt,temp->donnee);
        }


    }
    return(Arbre*)(A);
}
