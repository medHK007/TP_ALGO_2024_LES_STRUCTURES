#include"headerofall.h"
PTfile *creerfile()
{
    PTfile*file; //declarer un nouveau element pour la file
    file =(PTfile*)malloc(sizeof(PTfile));//allouer l'emplacement memoire
    //verifier si l'allocation memoire n'est pas passer correctement
    if(!file)
    {
        printf("ERROR");
        exit(-1);//quitter le programme en cas d'echec
    }//fin if
    //initialiser les champs debut et fin
    file->debut=NULL;
    file->fin=NULL ;
    return (PTfile*)(file);//returner l'adresse de la file
}

/*-----------------------------------------*/

//creer une cellule à inseré
PTliste *creer_cellule()
{
    PTliste *NE;//declarer une nouvelle cellule
    //allouer l'emplacement memoire pour ce nouveau element
    NE=(PTliste*)malloc(sizeof(PTliste));
    //verifier si l'allocation dynamique reussie
    if(!NE)
    {
        printf("ERROR");
        return (PTliste*)(NULL); //returner NULL en cas d'echec
    }//fin if
    NE->suivant=NULL;//initialiser le champs suivant par NULL
    return (PTliste*)(NE); //retourner l'adresse de ce nouveau element
}

/*-----------------------------------------*/

//vider une file
int raze_file(PTfile*mafile)
{
    PTliste *temp ;//declarer un pointeur qui va stocker l'element à supprimer
    if(!mafile) //verifier si la file existe
    {
        printf("ERROR");
        return (int)(-1); //retourner -1 en cas de n'est pas trouver la file
    }//fin if
    //verifier si la file est vide
    if(mafile->debut==NULL)
    {
        printf("file vide");
        return (int)(0);
    }
    while(mafile->debut)//tant que la file n'est pas vide
    {
       temp=mafile->debut;//le pointeur temp recevoir l'adresse du premier element à supprimer
       mafile->debut=mafile->debut->suivant; //faire avancer le pointeur dans la file
       free(temp);//liberer l'espace memoire pour cet element
    }//fin while
    //initialiser le champs fin par NULL
    mafile->fin=NULL;
    return (int)(1);
}

/*-----------------------------------------*/

// verifier si la file est vide
int file_vide (PTfile*mafile)
{
    if(!mafile)
    {
        return (int)(-1);
    }//fin if
    return (mafile->debut==NULL);
}

/*-----------------------------------------*/

//enfiler un element
int enfiler(PTfile *mafile,int donnee)
{
    PTliste *NE ;//declarer un nouveau element
    if(!mafile) //verifier si la file existe
    {
        printf("ERROR");
        return (int)(0);//sortir de la fonction en cas d'inexistance de la file
    }//fin if
    NE=creer_cellule();//creer ce nouveau element
    NE->entier=donnee ;//remplir le champs donnee
    //verifier si la file est vide
    if(file_vide(mafile)) mafile->debut=mafile->fin=NE ;//pointer debut et fin sue le NE
    //si la file n'est pas vide
    else
    {
        //mise a jour des pointeurs
        mafile->fin->suivant=NE;
        mafile->fin=NE ;
    }//fin else
    return (int)(1);
}

/*-----------------------------------------*/

//defiler un elemnt
int defiler(PTfile *mafile)
{
    //declarer un pointeur pour stocker la cellule à supprimer
    PTliste*temp ;
    //verifier si la file existe
    if(!mafile)
    {
        printf("ERROR");
        return (int)(-1);
    }//fin file
    //verifier si la file est vide
    if(file_vide(mafile)) return (int)(0);


    //si il y a un seul element dans la file
    if(mafile->debut==mafile->fin)
    {
        raze_file(mafile);

    }//fin if
    //si il y plusieurs element dans la liste
    else
    {
    //affecter la tete de la file au pointeur temp
    temp=mafile->debut;
    //faire avancé le pointeur dans la file
    mafile->debut=mafile->debut->suivant ;
    //librer l'espace memoire pour cette veriale
    free(temp);
    }//fin else
    return (int)(1);
}

/*-----------------------------------------*/

//afficher une liste
void afficher_file(PTfile*mafile)
{
    PTfile *aux=creerfile() ;
    PTliste*temp=NULL;
    if(!mafile)
    {
        printf("ERROR");
        return ;
    }
    if(file_vide(mafile))
    {
        printf("file vide ");
        return ;
    }

    while(!file_vide(mafile))
    {

        printf("%d <-- ",mafile->debut->entier);
        temp=mafile->debut;
        mafile->debut=mafile->debut->suivant;
        temp->suivant=NULL;
        if(!aux->debut)
        {
            aux->debut=aux->fin=temp;
        }
        else
        {
            aux->fin->suivant=temp;
            aux->fin=temp;
        }
    }
    while(!file_vide(aux))
    {
        temp=aux->debut;
        aux->debut=aux->debut->suivant;
        temp->suivant=NULL;
        if(!mafile->debut)
        {
            mafile->debut=mafile->fin=temp;
        }
        else
        {
            mafile->fin->suivant=temp;
            mafile->fin=temp;
        }
    }
    printf("\n");

}
void supprimernbrfileptr(PTfile*F,int val)
{
    PTfile*aux=creerfile();
    PTliste*temp=NULL,*sup;
    if(file_vide(F))
    {
        printf("file vide\n");
        return ;
    }
    while(!file_vide(F))
    {
        if(F->debut->entier!=val)
        {
            temp=F->debut;
            F->debut=F->debut->suivant;
            temp->suivant=NULL;
            if(file_vide(aux))
            {
                aux->debut=aux->fin=temp;
            }
            else
            {
                aux->fin->suivant=temp;
                aux->fin=temp;
            }
        }
        else
        {
            sup=F->debut;
            F->debut=F->debut->suivant;
            sup->suivant=NULL;
            free(sup);
            break ;
        }
    }
     while(!file_vide(F))

    {
        temp=F->debut;
        F->debut=F->debut->suivant;
        temp->suivant=NULL;
        if(file_vide(aux))
        {
            aux->debut=aux->fin=temp;
        }
        else
        {
        aux->fin->suivant=temp;
        aux->fin=temp;
        }

    }
    while(!file_vide(aux))
    {
        temp=aux->debut;
        aux->debut=aux->debut->suivant;
        temp->suivant=NULL;
        if(file_vide(F))
        {
            F->debut=F->fin=temp;
        }
        else
        {
        F->fin->suivant=temp;
        F->fin=temp;
        }
    }

}
int taille_file(PTfile*F)
{
    int taille=0;
    PTfile*aux=creerfile();
    PTliste*temp=NULL;
    if(!F) return(int)(-1);
    while(!file_vide(F))
    {
        temp=F->debut;
        F->debut=F->debut->suivant;
        temp->suivant=NULL;
        if(file_vide(aux))
        {
            aux->debut=aux->fin=temp;
        }
        else
        {
            aux->fin->suivant=temp;
            aux->fin=temp;
        }
        taille++;
    }
    while(!file_vide(aux))
    {
        temp=aux->debut;
        aux->debut=aux->debut->suivant;
        temp->suivant=NULL;
        if(file_vide(F))
        {
            F->debut=F->fin=temp;
        }
        else
        {
            F->fin->suivant=temp;
            F->fin=temp;
        }
    }
    return(int)(taille);

}
void supprimerposfileptr(PTfile*F,int pos)
{
    PTfile*aux=creerfile();
    PTliste*temp=NULL,*sup;
    int i =1;
    if(file_vide(F))
    {
        printf("file vide\n");
        return ;
    }
    if(pos<=0 || pos >taille_file(F))
    {
        printf("position invalid");
        return;
    }

    while(!file_vide(F))
    {
        if(i<pos)
        {
            temp=F->debut;
            F->debut=F->debut->suivant;
            temp->suivant=NULL;
            if(file_vide(aux))
            {
                aux->debut=aux->fin=temp;
            }
            else
            {
                aux->fin->suivant=temp;
                aux->fin=temp;
            }
            i++;
        }
        else
        {
            sup=F->debut;
            F->debut=F->debut->suivant;
            sup->suivant=NULL;
            free(sup);
            break ;
        }
    }
     while(!file_vide(F))

    {
        temp=F->debut;
        F->debut=F->debut->suivant;
        temp->suivant=NULL;
        if(file_vide(aux))
        {
            aux->debut=aux->fin=temp;
        }
        else
        {
        aux->fin->suivant=temp;
        aux->fin=temp;
        }

    }
    while(!file_vide(aux))
    {
        temp=aux->debut;
        aux->debut=aux->debut->suivant;
        temp->suivant=NULL;
        if(file_vide(F))
        {
            F->debut=F->fin=temp;
        }
        else
        {
        F->fin->suivant=temp;
        F->fin=temp;
        }
    }

}
int insererpositionfile(PTfile*F,int val ,int pos)
{
    PTfile*aux=NULL;
    PTliste *NE,*temp ;
    int i=1;
    if(!F) return(int)(-1);
    if(pos<0 || pos >taille_file(F))
    {
        printf("position invalide");
        return(int)(0);
    }
    aux=creerfile();
    NE=creerliste();
    NE->entier=val;
     while(!file_vide(F))
    {
        if(i<pos)
        {
            temp=F->debut;
            F->debut=F->debut->suivant;
            temp->suivant=NULL;
            if(file_vide(aux))
            {
                aux->debut=aux->fin=temp;
            }
            else
            {
                aux->fin->suivant=temp;
                aux->fin=temp;
            }
            i++;
        }
        else
        {
           if(file_vide(aux))
            {
                aux->debut=aux->fin=NE;
            }
            else
            {
                aux->fin->suivant=NE;
                aux->fin=NE;
            }
            break;
        }
    }
     while(!file_vide(F))

    {
        temp=F->debut;
        F->debut=F->debut->suivant;
        temp->suivant=NULL;
        if(file_vide(aux))
        {
            aux->debut=aux->fin=temp;
        }
        else
        {
        aux->fin->suivant=temp;
        aux->fin=temp;
        }

    }
    while(!file_vide(aux))
    {
        temp=aux->debut;
        aux->debut=aux->debut->suivant;
        temp->suivant=NULL;
        if(file_vide(F))
        {
            F->debut=F->fin=temp;
        }
        else
        {
        F->fin->suivant=temp;
        F->fin=temp;
        }
    }
    return(int)(1);

}


