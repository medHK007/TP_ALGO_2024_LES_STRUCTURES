#include"headerofall.h"
//initialisation du file
int initTfile(TFILE* Mafile)//initialisation de la file a zero
{
    if(!Mafile) return((int)0);
    Mafile->debut=-1;
    Mafile->fin=-1;
    return((int)1);
}
//vérifier si vide
int EstvideTfile(TFILE Mafile)
{
    /*puisque le passage dans la fonction intifile est par adresse alors
                            on stock la valeur de la liste dans une autre liste pour ne pas
                             modifier la valeur */
    return ((int)(Mafile.fin-Mafile.debut+1==0));//tester si vide
}
//vider la file
int razTfile(TFILE *Mafile)
{
    return((int)initTfile(Mafile));//pour vider la file
}
//retourne la taille de la file
int tailleTfile(TFILE Mafile)
{
    if(EstvideTfile(Mafile)) return((int)0);//si la file est vide donc il y n'a pas d'élément dans la file
    return((int)((Mafile.fin-Mafile.debut)+1 ));
}
//vérifier si la file est saturer
int estSaturerTfile(TFILE Mafile)
{
    return((int)(Mafile.fin-Mafile.debut+1==maxElem));/*puisuqe la file sera iindexer de 0 jusqu'au
                                                        MAXELEM-1 donc on doit ajouter un pour être précis */
}
//tasser les éléments de la file
int tasserTfile(TFILE *Mafile)
{
    int ind,taille;//ind pour l'indice de la boucle for
    if(!Mafile) return((int)0);
    taille=tailleTfile(*Mafile);//on stock la la taille de la file dans la variable taille
    for(ind=0;ind<taille;ind++)/*boucle for pour decaler les éléments de la position debut vers
                                la pocition 0 pour liberer de la espace dans la fin de la file*/
    {
        Mafile->table[ind]=Mafile->table[(Mafile->debut)+ind];
        Mafile->debut=0;
    }
    Mafile->fin=taille-1;

        return((int)1);
}
//Enfiler la file
int enfilerTfile(TFILE *Mafile,int val)
{   //les tests necessaire pour éviter les erreurs dans le programme
    if(!Mafile) return((int)-1);
    if(estSaturerTfile(*Mafile)) return((int)0);
    if(EstvideTfile(*Mafile))//cas ou la file est vide donc le nouveau element est le premier et dernier element de notre file
    {
        Mafile->debut=0;
        Mafile->fin=0;
        Mafile->table[Mafile->debut]=val;
        return((int)1);
    }
    Mafile->table[Mafile->fin++]=val;
//    if(Mafile->fin==(MaxElem-1))//on tasse la file si le dernier element se situe de la position Maxelem dans l'index Maxelem-1
//        tasserTfile(Mafile);
//    //on ajoute l'element après effectuer tous les tests et les cas possible
    return ((int)0);
}
//Defiler la file
 int defileTfile(TFILE *Mafile)
 {  //les tests necessaire pour le bon fonctionnement de la fonction
    if(!Mafile) return((int)-1);
    if(EstvideTfile(*Mafile)) return((int)0);
    if(Mafile->debut==Mafile->fin)//cas oû la file contient un seule element
        return((int)razTfile(Mafile));
    Mafile->debut++;
    return((int)1);
 }
//Affichage de la file
 void afficherfile (TFILE *Mafile)
 {

//     if(Mafile) return ((int)0);
     if(EstvideTfile(*Mafile)) printf("\nvide");

for(int i=Mafile->debut;i<Mafile->fin;i++)
    printf("%d\t",Mafile->table[i]);

 }
