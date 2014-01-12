/*************************************************************************
 UndoableCommand  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <UndoableCommand> (fichier UndoableCommand.h) ------
#if ! defined ( UndoableCommand_H_ )
#define UndoableCommand_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <UndoableCommand>
//
//
//------------------------------------------------------------------------

class UndoableCommand : public Command
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool virtual execute() = 0 ;
    bool virtual undo() = 0 ;
    
    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    
    UndoableCommand (map<string,string> *listeDesElements, vector<string> lP );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~UndoableCommand ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    
};

//--------------------------- Autres définitions dépendantes de <UndoableCommand>

#endif // UndoableCommand_H_
