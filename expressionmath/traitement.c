#include"header.h"
char epurerblanc()
{
    char c;
    while((c=getchar())==BL);
    return(char)(c);
}
int est_entier(char c)
{
    return(int)('0'<=c || c<='9');
}

int est_operande(char c)
{
    return(int)((c=='+') || (c=='-')||(c=='*')||(c=='/'));
}

int lire_expression(char expression[MAX])
{
    char c;
    int i=0;
    printf("donner une expression mathematique : ");
    c=epurerblanc();
    do
    {
        if(est_entier(c))
        {
            expression[i++]=c;
            c=epurerblanc();
            if(est_operande(c))
            {
                expression[i++]=c;
            }
            else if (c=='\n')
                break ;
            else
            {   printf("\nexrpression mathemtique invalide\n");
                return (int)(0);
            }
        }
        else
        {
            printf("\nexrpression mathemtique invalide\n");
            return(int)(0);
        }

    }while((c=epurerblanc(c))!='\n');
    expression[i]='\0';
    return(int)(1);
}
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
Arbre *inserer(Arbre *A,int info)
{
    if(!A) return (Arbre*)(creercellule(info));
    if(info>A->donnee)
        A->fdrt=inserer(A->fdrt,info);
    if(info <A->donnee)
        A->fgche=inserer(A->fgche,info);
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


