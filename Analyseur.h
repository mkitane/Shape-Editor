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
    // Verifie si un point a dépassé l'espace des longs
    // Contrat :
    //
    
    int nbParams(string command);
    // Mode d'emploi :
    //  Renvoie le nombre de parametre a partir de la commande
    // Contrat :
    //
    
    bool checkIfNumber(string supposedNumber, long * number);
    // Mode d'emploi :
    //  Verifie si le string rentre est bien un nombre
    // Contrat :
    //
    
    TypeCommand analyseCommand(string command);
    // Mode d'emploi :
    //  Analyse notre commande et nous renvoie le type correspondant
    // Contrat :
    //
    
    void remplirParametres(vector<string> * parameters, const string command);
    // Mode d'emploi :
    //  Remplis notre liste des parametres a partir du string command
    // Contrat :
    //
    
    Command * createCommand(TypeCommand t, vector<string> parameters, Figure *f);
    // Mode d'emploi :
    //  Cree la commande a partir des parametres et du type de la commande
    // Contrat :
    //
    
    EltGeo * createObjectWithParameters(TypeCommand t, vector<string> parameters, map<string,EltGeo *> *listeElements);
    // Mode d'emploi :
    //  Cree un objet a partir du type de la commande
    // Contrat :
    //
}




#endif // Analyseur_H_
