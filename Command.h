/*************************************************************************
 Command  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if ! defined ( COMMAND_H_ )
#define COMMAND_H_




//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <map>
#include <vector>
#include "Agregat.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Command>
//
//
//------------------------------------------------------------------------
using namespace std;

class Command
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool execute() = 0 ;
    // Mode d'emploi :
    //  Execute la commande
    //      et les instructions associees
    // Contrat :
    //
    
    
    virtual bool undo() = 0 ;
    // Mode d'emploi :
    // Annule la commande deja executee
    // Contrat :
    //
    
    virtual bool canDoAnUndo()=0;
    // Mode d'emploi :
    //  Verifie si c'est une commande que l'on peux stocker dans l'historique
    // Contrat :
    //
    
    
    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur

     Command (map<string,EltGeo *> *listeDesElements, vector<string> lP );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Command ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    

    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    vector<string> listeParametres;
    map<string,EltGeo *> *listeDesElements;

};

//--------------------------- Autres définitions dépendantes de <Command>

#endif // COMMAND_H_
