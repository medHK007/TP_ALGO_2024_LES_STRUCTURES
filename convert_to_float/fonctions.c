#include"header.h"


/*fonction epurer blan à pour but de ignorer les espaces
s'il existe dans le buffer pour arriver au premier caractère*/

char epurer_blan()
{
    char c ;
    /*boucle pour sauter les espaces :
    vrai si le caractère est espaces donc boucle continue
    sinon on a arriver a un autre caractère*/
    while((c=getchar())==BL);
    return (char)(c);
}

/*contion est négatif pour distinger entre les nombre positif ou négatif*/
int est_negatif(char c)
{
    /*on utilise la fonction epurer blan pour éviter les espace dans le buffer*/
    if((c=getchar())=='-') return (int)(1);//1 signifie que le nombre est négatif
    return (int)(0);//0 donc le nombre est positif
}

/*cette fonction va retourner 1 si le caractère est un nombre, 0 sinon*/
int est_entier(char c)
{
    return(int)((c>='0') && (c<='9'));
}

/*fonction qui retourne le nombre conforme au caractère entrer on utilisons le code ascii de caractère*/
int convert_to_entier(char c)
{
    return (int)(c-'0');//'0' est égale à 48
}

//la fonction responsable de la conversion
double convertofloat()
{
    /*somme pour stocker la valeur du nombre
      signe est initialement positif
      indice est utiliser pour exprimer le numero des chiffres après la virgule
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
    if(c=='+') c=getchar();//si l'utilisateur à spécifier le signe
    do
    {
        if(est_entier(c))/*pour effectuer l'operation de la somme s.s.i
                           le caractère est un entier*/
        {
            /*la multiplication par 10 pour décaler chaque nombre vers
            la gauce puisque la lecture du nombre dans le buffer ce fait du gauche*/
            somme=somme*10 + convert_to_entier(c);
            if(indice>-1) indice++;
        }
        else if (c=='.' && indice ==-1) indice =0;/*initialiser l'indice pour savoir
                                            combien des nombres seront après la virgule*/
        else if(c=='.' && indice>-1)
        {
            erreur=1;//au cas ou l'utilisateur a entrer deux points
            type_erreur=0;//type d'erreur ou l'utilisatuer a entrer plus qu'un point
        }
        else if (c==BL) break ;/*s'il y a un espace après les nombres dans le buffer
                                 donc le traitement a terminer*/
        else// tous autres cas
        {
            erreur=type_erreur=1;/*type d'erreur ou l'utilisateur a entrer un caractère
                                    qui n'est pas un chiffre*/
        }
        /*le test de do while est vrai si on n'a pas arriver a un retour chariot
         et aucune erreur a occurer*/
    }while(((c=getchar())!=RC) && (erreur==0) );
    if(erreur==1)//test d'erreur
    {
        printf("erreur dans la saisie du nombre\n");//message d'erreur
        if(type_erreur==0) printf("il y a plus qu'une virgule dans le nombre saisie\n");
        else printf("il y a un caractère saisie qui n'est pas considerer un chiffre\n");
        exit (-1);
    }
    if(signe==1 )//cas ou le nombre est négatif
        {
        if (indice >-1) return (double)(((-1)*somme)*(pow(10,-indice)));/*cas ou le nombre
                                                                    négatif a des nombres
                                                                    après la virgule*/
        return (double)((-1)*somme);//cas ou le nombre négatif est un entier
        }
    else if(signe ==0 )//cas ou le nombre est positif
    {
        if(indice>-1) return (double)(somme*pow(10,-indice));/*cas ou le nombre positif a
                                                            des nombres après la virgule*/
        return (double)(somme);//cas ou le nombre positif est un entier
    }
    return ((double)0.0);//cas echeant
}
