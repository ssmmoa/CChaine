#include "iostream"
#include "CChaine.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "assert.h"

using namespace std;

CChaine::CChaine() //: ChaineVide (1), chaine (NULL), position (0) marche pas
{
    ChaineVide = 1;
    chaine = NULL;
    position = 0;
}

CChaine::CChaine(char* chaine)
{
    if(chaine != NULL)
    {
        this->position = strlen(chaine);
        this->chaine = (char*)malloc(this->position*sizeof(char));
        strcpy(this->chaine,chaine);
        this->ChaineVide = 0;
    }
}

CChaine::CChaine(string schaine)
{
   //  this->chaine = schaine.c_str(); -> copie de l'adresse de la chaine mais la string est const donc doit avoir une chaine const !!

    position = schaine.size();
    chaine = (char*)malloc(position * sizeof(char));
    strcpy(chaine,schaine.c_str());

}

CChaine::CChaine(const CChaine& Ochaine)
{
    position = Ochaine.position;

    chaine = (char*)malloc(strlen(Ochaine.chaine)*sizeof(char));
    // chaine est allouée de la taille de la chaine de char de l'objet a copier

    strcpy(chaine,Ochaine.chaine);
    // copie de la chaine de carateres de l'objet a copier (Ochaine.chaine) dans la nouvelle chaine du nvel objet

    cout << "copy ok" << endl;
}

CChaine CChaine::operator = (const CChaine& Ochaine)
{
    free(this->chaine);
    this->position = Ochaine.position;

    this->chaine = (char*)malloc(Ochaine.position *sizeof(char));

    strcpy(chaine,Ochaine.chaine);

    return *this;
}

CChaine CChaine::operator += (CChaine const& Ochaine)
{
    int index = position;
    int i = 0;

    position = position + Ochaine.position;

    chaine = (char*)realloc(chaine, position *sizeof(char));

    chaine[index] = ' ';
    index ++;

    while(Ochaine.position != i)
    {
        chaine[index] = Ochaine.chaine[i];
        index ++;
        i ++;
    }
    chaine[index] = '\0';
 return *this;
}

CChaine::~CChaine()
{
    free(chaine);
    cout << "Nettoyage effectué" << endl;
}

CChaine::operator const string()
{
    string schaine;
    schaine = chaine;
    return schaine;
}

CChaine::operator const char*()
{
    return chaine;
}

void CChaine::affiche()
{
    int index = 0;

    if(chaine != NULL)
    {
        do{
            cout << chaine[index];
            index++;

        }while(chaine[index] != '\0');
    }
    else cout << "Vide";

    cout << endl;

}


