/*************************************************************************
 Command  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if ! defined ( COMMAND_H_ )
#define COMMAND_H_


#include <iostream>
#include <map>
#include <vector>
#include "EltGeo.h"
#include "Agregat.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Command>
//
//
//------------------------------------------------------------------------

class Command
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool execute() = 0 ;
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    virtual bool undo() = 0 ;
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual bool canDoAnUndo()=0;
    // Mode d'emploi :
    //
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
