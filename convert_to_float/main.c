#include"header.h"

int main()
{
    double nombre=convertofloat();//un variable qui resoit le retour de la fonction
    double duplicate_nombre=nombre;//un duplicate pour effectuer le cast sans modification de la valeur du retour de la fonction
    int number=(int)duplicate_nombre;//un int pour stocker la valeur entière du nombre
        if(!(nombre-number))//ce test va retourner 1 si la valeur est entier
            printf("\nle nombre saisie est : %.0lf",nombre);//.0 pour ignorer la virgule
        else//cas ou la valeur est un réelle
            printf("\nle nombre saisie est : %lf",nombre);
    return 1;
}
