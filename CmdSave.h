/*************************************************************************
 CmdSave  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdSave> (fichier CmdSave.h) ------
#if ! defined ( CmdSave_H_ )
#define CmdSave_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdSave>
//
//
//------------------------------------------------------------------------

class CmdSave : public Command
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    bool execute();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool undo();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool canDoAnUndo(){return false;}
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    CmdSave(map<string,EltGeo *> *lE, vector<string> lP);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdSave();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
};

//--------------------------- Autres définitions dépendantes de <CmdSave>

#endif // CmdSave_H_
