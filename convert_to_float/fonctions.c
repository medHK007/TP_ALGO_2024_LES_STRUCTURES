#include"header.h"


/*fonction epurer blan � pour but de ignorer les espaces
s'il existe dans le buffer pour arriver au premier caract�re*/

char epurer_blan()
{
    char c ;
    /*boucle pour sauter les espaces :
    vrai si le caract�re est espaces donc boucle continue
    sinon on a arriver a un autre caract�re*/
    while((c=getchar())==BL);
    return (char)(c);
}

/*contion est n�gatif pour distinger entre les nombre positif ou n�gatif*/
int est_negatif(char c)
{
    /*on utilise la fonction epurer blan pour �viter les espace dans le buffer*/
    if((c=getchar())=='-') return (int)(1);//1 signifie que le nombre est n�gatif
    return (int)(0);//0 donc le nombre est positif
}

/*cette fonction va retourner 1 si le caract�re est un nombre, 0 sinon*/
int est_entier(char c)
{
    return(int)((c>='0') && (c<='9'));
}

/*fonction qui retourne le nombre conforme au caract�re entrer on utilisons le code ascii de caract�re*/
int convert_to_entier(char c)
{
    return (int)(c-'0');//'0' est �gale � 48
}

//la fonction responsable de la conversion
double convertofloat()
{
    /*somme pour stocker la valeur du nombre
      signe est initialement positif
      indice est utiliser pour exprimer le numero des chiffres apr�s la virgule
      erreur pour verifier si l'utilisateur a mis deux point dans la saisie ou bien
      d'autre erreur dans la saisie*/
    double somme=0 , signe =0,indice=-1,erreur=0,type_erreur;
    char c ;
    printf("entrer un nomber : ");
    if(est_negatif())//test de signe
    {
        signe= 1;
        c=getchar();
    }
    if(c=='+') c=getchar();//si l'utilisateur � sp�cifier le signe
    do
    {
        if(est_entier(c))/*pour effectuer l'operation de la somme s.s.i
                           le caract�re est un entier*/
        {
            /*la multiplication par 10 pour d�caler chaque nombre vers
            la gauce puisque la lecture du nombre dans le buffer ce fait du gauche*/
            somme=somme*10 + convert_to_entier(c);
            if(indice>-1) indice++;
        }
        else if (c=='.' && indice ==-1) indice =0;/*initialiser l'indice pour savoir
                                            combien des nombres seront apr�s la virgule*/
        else if(c=='.' && indice>-1)
        {
            erreur=1;//au cas ou l'utilisateur a entrer deux points
            type_erreur=0;//type d'erreur ou l'utilisatuer a entrer plus qu'un point
        }
        else if (c==BL) break ;/*s'il y a un espace apr�s les nombres dans le buffer
                                 donc le traitement a terminer*/
        else// tous autres cas
        {
            erreur=type_erreur=1;/*type d'erreur ou l'utilisateur a entrer un caract�re
                                    qui n'est pas un chiffre*/
        }
        /*le test de do while est vrai si on n'a pas arriver a un retour chariot
         et aucune erreur a occurer*/
    }while(((c=getchar())!=RC) && (erreur==0) );
    if(erreur==1)//test d'erreur
    {
        printf("erreur dans la saisie du nombre\n");//message d'erreur
        if(type_erreur==0) printf("il y a plus qu'une virgule dans le nombre saisie\n");
        else printf("il y a un caract�re saisie qui n'est pas considerer un chiffre\n");
        exit (-1);
    }
    if(signe==1 )//cas ou le nombre est n�gatif
        {
        if (indice >-1) return (double)(((-1)*somme)*(pow(10,-indice)));/*cas ou le nombre
                                                                    n�gatif a des nombres
                                                                    apr�s la virgule*/
        return (double)((-1)*somme);//cas ou le nombre n�gatif est un entier
        }
    else if(signe ==0 )//cas ou le nombre est positif
    {
        if(indice>-1) return (double)(somme*pow(10,-indice));/*cas ou le nombre positif a
                                                            des nombres apr�s la virgule*/
        return (double)(somme);//cas ou le nombre positif est un entier
    }
    return ((double)0.0);//cas echeant
}
