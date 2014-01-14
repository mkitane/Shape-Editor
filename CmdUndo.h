/*************************************************************************
 CmdUndo  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdUndo> (fichier CmdUndo.h) ------
#if ! defined ( CmdUndo_H_ )
#define CmdUndo_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdUndo>
//
//
//------------------------------------------------------------------------

class CmdUndo : public Command
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool execute();
    bool undo();
    bool canDoAnUndo(){return false;}
    
    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    CmdUndo(map<string,EltGeo *> *lE, vector<string> lP, vector<Command *> * historique,vector<Command *>::iterator *itAct);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdUndo();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    //Pour le redo
    vector<Command *> *historique;
    vector<Command *>::iterator *itActuel;
};

//--------------------------- Autres définitions dépendantes de <CmdUndo>

#endif // CmdUndo_H_
