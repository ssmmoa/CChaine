#include "iostream"
#include "CChaine.h"
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "string.h"

#define INCREMENT 10

using namespace std;

char* CreationChaine()
{
    char car;
    char* chaine;
    int index = 0;
    int position;

    chaine = (char*)malloc(sizeof(char) * INCREMENT);
    position = INCREMENT;

    assert(chaine != NULL);  // ASSERT KILL LE PROGRAMME SI CHAINE EST NULL

    cout << " Entrer votre texte : " << endl;
    do{
            car= getchar();
            chaine[index] = car;

            index ++;

            if(index == position)
            {
                position = position + INCREMENT;
                chaine = (char*)realloc(chaine,position * sizeof(char));
            }

    }while(car != '\n');

    chaine[index-1] = '\0'; // index - 1 car c'est le /n

    return chaine;
}
int main()
{
    //------------------------------
    // Creation d'une chaîne de char
    //------------------------------

    char *chaine1;
    char *chaine2;
    char *chaine3;
    char *chaine4;

    chaine1 = CreationChaine();
    chaine2 = CreationChaine();
    chaine3 = CreationChaine();
    chaine4 = CreationChaine();

    CChaine Otexte(chaine1);
    cout << "chaine 1" << endl;
    Otexte.affiche();

    CChaine Otexte2(Otexte);    // CChaine Otexte2 = Otexte ; c est la mm chose

    cout << "chaine 2 = copie de chaine 1" << endl;
    Otexte2.affiche();


    CChaine Otexte3(chaine2);

    Otexte3 = Otexte2;
    cout << "ochaine 3 = Ochaine 2" << endl;
    Otexte3.affiche();

    CChaine Otexte4(chaine3);

    cout << "ochaine3 + ochaine 4" << endl;
    Otexte3 += Otexte4;

    Otexte3.affiche();

    CChaine Otexte5;
    Otexte5 = chaine4;
    cout << "ochaine5 = chaine 4" << endl;
    Otexte5.affiche();

  //  char *chaineObtenue;
//    chaineObtenue = Otexte5.tableauChar(); ici version sans le const (la chaine peut être modifiée)
    const char * chaineObtenue = Otexte5;   // ici version ou la chaine ne peut être modifiée car const
    cout << chaineObtenue << endl;

    char Machaine[10] = "12345678\0";

    Otexte5 = Machaine;
    Otexte5.affiche();

    string chaineString = "987456123";
    CChaine Otexte6(chaineString);
    cout << "Objet apd une string" << endl;
    Otexte6.affiche();


    const string nouvelleString = Otexte2;
    cout << nouvelleString << endl;


    return 0;
}


