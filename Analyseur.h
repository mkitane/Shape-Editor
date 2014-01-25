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

namespace Analyseur {

//------------------------------------------------------------------ Types
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
    
    //----------------------------------------------------- Méthodes publiques
    bool depasserBorne(long a, long b);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    int nbParams(string command);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool checkIfNumber(string supposedNumber, long * number);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    TypeCommand analyseCommand(string command);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void remplirParametres(vector<string> * parameters, const string command);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Command * createCommand(TypeCommand t, vector<string> parameters, Figure *f);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    EltGeo * createObjectWithParameters(TypeCommand t, vector<string> parameters, map<string,EltGeo *> *listeElements);
    // Mode d'emploi :
    //
    // Contrat :
    //
}




#endif // Analyseur_H_
