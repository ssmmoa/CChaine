#ifndef CCHAINE_H_INCLUDED
#define CCHAINE_H_INCLUDED
#include "iostream"
#include "CChaine.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "assert.h"
// #include "string"

using namespace std;

class CChaine
	{
	private:		 // données membres

    char* chaine;
    int position;
    int ChaineVide;


	public: 		 // fonctions membres

    // constructeurs

    CChaine(); // constructeur
	CChaine(char* chaine);		 // constructeur (c'tor)
    CChaine(string schaine); // constructeur apd d une string
	~CChaine();	 	 // destructeur
    CChaine(const CChaine& Ochaine);    // constructeur par copie
    // const NomClasse& car fait référence à un objet et const car l'objet a copier ne dois pas être modifié,
    // Ochaine est l'objet a copier

    CChaine operator = (const CChaine& Ochaine);    // surcharge de l'operateur d'assignation
    CChaine operator += (const CChaine& Ochaine);   // surcharge de l'operateur +=

    operator const string();    // renvoie un string depuis un Objet CChaine
    operator const char* ();  // renvoie un char* depuis un Objet CChaine, le const signal que la chaine ne peut être modifiée, le main devra donc y faire appel avec un const char*
	void affiche(); // affichage de la chaine contenue dans l'objet
	// ajout d'une string
	// ajout d'une chaine de char 
	};


#endif // CCHAINE_H_INCLUDED
