/*************************************************************************
 Analyseur  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <Analyseur> (fichier Analyseur.h) ------
#if ! defined ( Analyseur_H_ )
#define Analyseur_H_



//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <iostream>
#include <sstream>
#include <stdlib.h>     /* strtol */
#include <vector>
#include "Command.h"
#include "Figure.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
namespace Analyseur {
    typedef enum{
        ajouterCercle,
        ajouterRectangle,
        ajouterLigne,
        ajouterPolyligne,
        ajouterObjetAgrege,
        suppression,
        deplacement,
        enumeration,
        annuler,
        reprendre,
        charger,
        sauvegarder,
        vider,
        fermer,
        commentaire,
        errorCommand
    }TypeCommand;
    
    int nbParams(string command);
    bool checkIfNumber(string supposedNumber, int * number);
    TypeCommand analyseCommand(string command);
    void remplirParametres(vector<string> * parameters, const string command);
    Command * createCommand(TypeCommand t, vector<string> parameters, Figure *f);
    EltGeo * createObjectWithParameters(TypeCommand t, vector<string> parameters, map<string,EltGeo *> *listeElements);
}




#endif // Analyseur_H_
