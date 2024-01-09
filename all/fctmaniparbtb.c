#include "headerofall.h"

//fonction d'initialisation
arbre initialiserArb()
{
    arbre tree;
    tree.NbElem=0;
    tree.racine=-1;//-1 signifie que on a pas un racine
    return ((arbre)(tree));
}

//insertion ordonner dans l'arbre
int inserer(arbre* tree,int value,int pos)
{
    Noeud* tmp=NULL;
    if(!tree) return((int)-1);//verifier si l'arbre existe
    if((tree->NbElem==0))//si l'arbre n'a pas un racine
    {
        tmp=&(tree->noeuds[0]);
        tree->NbElem++;
        tree->racine=1;//position du racine
        tmp->droit=-1;
        tmp->gauche=-1;
        tmp->NbRepeat++;
        tmp->valeur=value;
        return((int)1);
    }
    tmp=&(tree->noeuds[pos-1]);/* si l'arbre a un racine dans le position pos, donc on doit parcourir l'arbre de la bonne maniere pour assurer qu'il va etre ordonner*/
    if(tmp->valeur==value)/*si vrai donc l'operation qu'on va faire est incrementer le nombre de repetition*/
    {
        tmp->NbRepeat++;
        return ((int)1);
    }

    if(tmp->valeur>value)
    {
        if(tmp->gauche==-1)
        {
            tmp->gauche=2*pos;
            tmp=&(tree->noeuds[2*pos-1]);
            tmp->droit=-1;
            tmp->gauche=-1;
            tmp->NbRepeat++;
            tmp->valeur=value;
        }
        else
            inserer(tree,value,2*pos);//parcourir l'arbre recursivement
        return((int)1);
    }
    if(tmp->valeur<value)
    {
        if(tmp->droit==-1)
        {
            tmp->droit=2*pos+1;
            tmp=&(tree->noeuds[2*pos]);
            tmp->droit=-1;
            tmp->gauche=-1;
            tmp->NbRepeat++;
            tmp->valeur=value;
        }
        else
            inserer(tree,value,2*pos+1);
        return((int)1);
    }
    return((int)0);
}
//affichage pre fixer de l'arbre
void preFix(arbre* tree,int pos)
{
    if (!tree) {//tester s'il existe
        printf("\n Arbre n'existe pas\n");
        return;
    }

    if (!tree->NbElem) {//tester s'il est vide
        printf("\nl'Arbre est vide\n");
        return;
    }

    if (pos == -1) return;//la condition d'arret,
    Noeud *tmp = NULL;
    tmp = &(tree->noeuds[pos-1]);//l'index de la racine
    //en prefix on a R->G->D(racine gauche droit)
    printf("%d (%d) ,",tmp->valeur,tmp->NbRepeat);
    preFix(tree,tmp->gauche);
    preFix(tree,tmp->droit);
}

void inFix(arbre* tree,int pos)
{
    if (!tree) {
        printf("\n Arbre n'existe pas\n");
        return;
    }

    if (!tree->NbElem) {
        printf("\nArbre est vide\n");
        return;
    }

    if (pos == -1) return;
    Noeud *tmp = NULL;
    tmp = &(tree->noeuds[pos-1]);//l'index de la racine
    //G->R->D
    inFix(tree,tmp->gauche);
    printf("%d (%d) ,",tmp->valeur,tmp->NbRepeat);
    inFix(tree,tmp->droit);
}

void postFix(arbre* tree,int pos)
{
    if (!tree) {
        printf("\n Arbre n'existe pas\n");
        return;
    }

    if (!tree->NbElem) {
        printf("\nArbre est vide\n");
        return;
    }

    if (pos == -1) return;
    Noeud *tmp = NULL;
    tmp = &(tree->noeuds[pos-1]);//l'index de la racine
    //G->D->R
    postFix(tree,tmp->gauche);
    postFix(tree,tmp->droit);
    printf("%d (%d) ,",tmp->valeur,tmp->NbRepeat);
}



int MaxArb(arbre tree,int pos)
{
    while(tree.noeuds[pos-1].droit!=-1) pos=2*pos+1;/*en parcour l'arbre jusqu'au l"element le plus droit*/
    return((int)tree.noeuds[pos-1].valeur);
}

int MinArb(arbre tree,int pos)
{
    while(tree.noeuds[pos-1].gauche!=-1) pos=2*pos;/*en parcour l'arbre jusqu'au l"element le plus gauche*/
    return((int)tree.noeuds[pos-1].valeur);
}

int trouverSuccesseur(arbre *monArbre, int noeudCourant)
{
    int successeur = monArbre->noeuds[noeudCourant].droit;
    while (monArbre->noeuds[successeur].gauche != -1)
    {
        successeur = monArbre->noeuds[successeur].gauche;
    }
    return successeur;
}

int supprimerNoeudRecursif(arbre *monArbre, int noeudCourant, int valeur)
{
    if (noeudCourant == -1)
    {
        // La valeur n'existe pas dans l'arbre.
        return -1;
    }

    if (valeur < monArbre->noeuds[noeudCourant].valeur)
    {
        // La valeur à supprimer est dans le sous-arbre gauche.
        monArbre->noeuds[noeudCourant].gauche = supprimerNoeudRecursif(monArbre, monArbre->noeuds[noeudCourant].gauche, valeur);
    }
    else if (valeur > monArbre->noeuds[noeudCourant].valeur)
    {
        // La valeur à supprimer est dans le sous-arbre droit.
        monArbre->noeuds[noeudCourant].droit = supprimerNoeudRecursif(monArbre, monArbre->noeuds[noeudCourant].droit, valeur);
    }
    else
    {
        // Nous avons trouvé la valeur à supprimer.
        if (monArbre->noeuds[noeudCourant].NbRepeat > 1)
        {
            // Si NbRepeat est supérieur à 1, décrémentez-le.
            monArbre->noeuds[noeudCourant].NbRepeat--;
        }
        else
        {
            // Si NbRepeat est égal à 1, supprimez le nœud.
            if (monArbre->noeuds[noeudCourant].gauche == -1)
            {
                int temp = monArbre->noeuds[noeudCourant].droit;
                monArbre->noeuds[noeudCourant] = monArbre->noeuds[temp];
                monArbre->noeuds[temp].valeur = -1;  // Marquer le nœud supprimé
                monArbre->noeuds[temp].NbRepeat = 0;
                monArbre->noeuds[temp].droit = -1;
                monArbre->noeuds[temp].gauche = -1;
                monArbre->noeuds[temp].NbRepeat = 0;
            }
            else if (monArbre->noeuds[noeudCourant].droit == -1)
            {
                int temp = monArbre->noeuds[noeudCourant].gauche;
                monArbre->noeuds[noeudCourant] = monArbre->noeuds[temp];
                monArbre->noeuds[temp].valeur = -1;  // Marquer le nœud supprimé
                monArbre->noeuds[temp].NbRepeat = 0;
                monArbre->noeuds[temp].droit = -1;
                monArbre->noeuds[temp].gauche = -1;
                monArbre->noeuds[temp].NbRepeat = 0;
            }
            else
            {
                int successeur = trouverSuccesseur(monArbre, noeudCourant);
                monArbre->noeuds[noeudCourant].valeur = monArbre->noeuds[successeur].valeur;
                monArbre->noeuds[noeudCourant].NbRepeat = monArbre->noeuds[successeur].NbRepeat;
                monArbre->noeuds[noeudCourant].droit = supprimerNoeudRecursif(monArbre, monArbre->noeuds[noeudCourant].droit, monArbre->noeuds[successeur].valeur);
            }
        }
    }

    return noeudCourant;
}

void supprimerNoeud(arbre *monArbre, int valeur)
{
    supprimerNoeudRecursif(monArbre, monArbre->racine, valeur);
}


