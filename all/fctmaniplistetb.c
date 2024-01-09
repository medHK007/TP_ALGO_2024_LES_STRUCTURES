#include"headerofall.h"
int Inittab(tab* ma_tab)//initialiser à vide
{
    ma_tab->NbElem=0;
    return ((int)1);
}

int estVideTab(tab matab)//verifier si vide
{
    return ((int)(matab.NbElem==0));
}



int EstSaturerTab(tab matab)
{
    return ((int)(matab.NbElem==maxElem));
}

int insererFintab(tab* matab,int valeur)//insertion d'un element a la fin du tableau
{
    if(EstSaturerTab(*matab)) return((int)0);
    matab->TabInt[matab->NbElem]=valeur;
    (matab->NbElem)+=1;
    return ((int)1);
}
//insertion d'un element a une position donner
int insererPositiontab(tab* matab,int position,int valeur)
{
    int ind;
    if(EstSaturerTab(*matab))  return((int)(-1));
    if(position >= 0 ||
        position <= matab->NbElem)
    {
        for(ind=matab->NbElem;ind>position;ind--)
        {
            matab->TabInt[ind]=matab->TabInt[ind-1];
        }
        matab->TabInt[position]=valeur;
        matab->NbElem++;
        return((int)1);
    }
    return((int)(-1));
}
//suppression d'un element on garde la liniaerité de tableau
int suppressionAIndicetab(tab* matab,int position)
{
    if(!matab) return((int)(-2));
    if(EstSaturerTab(*matab))  return((int)(-1));
    if(position < 0 ||
        position > matab->NbElem) return((int)0);
    for(int ind=position;ind<(matab->NbElem-1);ind++)
        matab->TabInt[ind]=matab->TabInt[ind+1];
    matab->NbElem--;
    return((int)1);
}
//suppression de la premiere occurence d'une valeur
int suppressionOccurencetab(tab* matab,int valeur)
{
    int ind=0;
    if(!matab) return((int)(-2));
    if(EstSaturerTab(*matab))  return((int)(-1));
    while(ind<matab->NbElem)
    {
        if(!((matab->TabInt[ind])==valeur))
            ind++;
        else
            return((int)suppressionAIndicetab(matab,ind));
    }
    return ((int)0);
}
//suppression d'une valuer et tout les autre valeur equivalente
int suppressionToutOccurencetab(tab* matab,int valeur)
{
    if(!matab) return((int)(-2));
    if(EstSaturerTab(*matab))  return((int)(-1));
    while(suppressionOccurencetab(matab,valeur));
    return((int)1);
}

void affichageTab(tab matab)
{
    int ind ;
    if(!matab.NbElem)
    {
        printf("liste vide\n\n");
        return;
    }
    for(ind=0;ind<matab.NbElem-1;ind++)
    {
        printf("%d --> ",matab.TabInt[ind]);
    }
    printf("%d\n",matab.TabInt[ind]);
    printf("\n");
}
int insererbonneplacetab(tab*matab,int val)
{
    int i , j ;
    if(!matab) return(int)(0);
    if(estVideTab(*matab))
    {
        matab->TabInt[0]=val ;
        matab->NbElem++;
    }
    else
    {
        for(i=0;i<matab->NbElem;i++)
            if(matab->TabInt[i]>val)
            break;
        for(j=matab->NbElem;j>i;j--)
            matab->TabInt[j]=matab->TabInt[j-1];

        matab->TabInt[i]=val;
        matab->NbElem++;
    }
    return(int)(1);
}
