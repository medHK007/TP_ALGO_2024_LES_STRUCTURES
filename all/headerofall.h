#ifndef HEADEROFALL_H_INCLUDED
#define HEADEROFALL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define maxElem 50
typedef struct lst
{
    int entier ; //le champs donnée
    struct lst *suivant ; // le pointeur que va pointer sur l'element suivant
}PTliste , PTpile  ;

typedef struct Tb //un tableau qui va representer une liste chaînée
{
    int TabInt[maxElem];// tableau des données
    int NbElem;//nombre d'éléments de notre liste
}tab;

typedef struct PL
{
    int table[maxElem];// table des données
    int sommet;// indique le sommet de la pile
}TPILE;

typedef struct
{
    PTliste *debut ; //un pointeur qui va pointer sur la debut de la file
    PTliste *fin  ; //une pointeur que va pointer sur la fin de la file
}PTfile;

typedef struct Tfl
{
    int table[maxElem];
    int debut;
    int fin;
}TFILE;

typedef struct arb
{
    int donnee ;
    int nbr_elemnet ;
    struct arb *fgche;
    struct arb*fdrt ;
}Arbre;

typedef struct Elem
{
    int valeur;
    int NbRepeat;
    int droit;
    int gauche;
}Noeud;

typedef struct Arb
{
    Noeud noeuds[maxElem];
    int racine;
    int NbElem;
}arbre;


/*fonction de manipulation de liste*/
PTliste *creerliste();//creation de la liste
int estvide(PTliste*);//verifier si la liste est vide
int taille_liste(PTliste*);//retourne la taille de la liste
void afficher(PTliste*);//affichage de la liste
PTliste *vider_liste(PTliste*);//suppression de tous element dans la liste
PTliste *inserer_debut(PTliste*, int);//insertion en debut
PTliste *inserer_fin(PTliste*, int);//ensertion dans la fin
PTliste *inserer_position_donnee(PTliste*,int,int);//insertion dans une position donner
int emplacement_premiere_occ(PTliste*,int);//retourne la position de la premiere occurence d'un element dans la liste
int nbr_occurence(PTliste* , int);//retourne nombre d'occurence d'un element dans la liste
int Somme(PTliste*);//la somme des elements dans la liste
PTliste *supprimerOccurence(PTliste*,int);//suppression d'un element de la liste
PTliste *supprimertouteOccurence(PTliste*,int);//suppression de toute occurence d'un element de la liste
PTliste*insererbonneplace(PTliste* , int);//insertion nonne place dans la liste
PTliste*supprimerdebutliste(PTliste*L); //fonction qui supprimer la tete de la liste

/*fonction de manipulation de liste avec tb*/

void affichageTab(tab );
tab* creer_tab();
int Inittab(tab*);
int estVideTab(tab);
int EstSaturerTab (tab);
int insererFintab(tab*,int);
int insererPositiontab(tab*,int,int);
int suppressionAIndicetab(tab*,int);
int suppressionOccurencetab(tab*,int);
int suppressionToutOccurencetab(tab*,int);
int insererbonneplacetab(tab*,int);

/*fonction de manipulation de pile avec ptr*/

PTpile *creerpile();
PTpile *razepile(PTpile*);
int pile_vide(PTpile*);
PTpile *empiler(PTpile*,int);
PTpile *depiler(PTpile *);
int taille_pile(PTpile*);
void afficher_pile(PTpile*);
PTpile*insererbonneplacepile(PTpile*,int);
PTpile*insererpositionpileptr(PTpile*,int, int);
PTpile*supprimervaleurpileptr(PTpile*,int );

/*fonction de manipulation de pile avec tb*/
int tailleTpile(TPILE );
int razTpile(TPILE*);
int estVideTpile(TPILE);
int estSaturerTpile(TPILE);
int depilerTpile(TPILE*);
int empilerTpile(TPILE*,int);
int sommetTpile(TPILE);


/*fonction de manipulation de file avec ptr*/
PTfile *creerfile();
PTliste *creer_cellule();
int raze_file(PTfile*);
int file_vide (PTfile*);
int enfiler(PTfile*,int);
int defiler(PTfile*);
void afficher_file(PTfile*);
void supprimernbrfileptr(PTfile*,int);
int taille_file(PTfile*);
void supprimerposfileptr(PTfile*,int);


/*fonction de manipulation de file avec tb*/
int initTfile(TFILE*);
int EstvideTfile(TFILE);
int razTfile(TFILE*);
int tailleTfile(TFILE);
int estSaturerTfile(TFILE);
int tasserTfile(TFILE *);
int enfilerTfile(TFILE *,int);
int defileTfile(TFILE *);
void afficherfile(TFILE*);

/*fonction de manipulation d'arbre avec ptr*/

Arbre *creercellule(int);
Arbre *insererarbre(Arbre*,int);
void afficher_infixe(Arbre*);
void afficher_prefixe(Arbre*);
void afficher_postfixe(Arbre*);
int existe(Arbre*,int );
Arbre*mini(Arbre *);
Arbre*maxi(Arbre*);
Arbre*supprimerarbre(Arbre*,int);
void Aff_Arbre_horiz(Arbre*,int);

/*fonction de manipulation d'arbre avec tb*/
arbre initialiserArb();
int inserer(arbre*,int,int);
void preFix(arbre*,int);
void inFix(arbre*,int);
void postFix(arbre*,int);
int MaxArb(arbre,int);
int MinArb(arbre,int);
void afficherArbre(arbre*,int,int);
void supprimerNoeud(arbre*,int);


/*fonctions de transfere*/
PTliste*listetab_to_listeprt(PTliste*,tab*);
PTpile*listeptr_to_pileptr(PTpile*,PTliste*);
int pileptr_to_fileptr(PTpile*,PTfile*);
Arbre*fileptr_to_arbreptr(Arbre*,PTfile*);
#endif // HEADEROFALL_H_INCLUDED
