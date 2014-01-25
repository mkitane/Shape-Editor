/*************************************************************************
 CmdRedo  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdRedo> (fichier CmdRedo.h) ------
#if ! defined ( CmdRedo_H_ )
#define CmdRedo_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdRedo>
//
//
//------------------------------------------------------------------------

class CmdRedo : public Command
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    bool execute();
    bool undo();
    bool canDoAnUndo(){return false;}
    
    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    CmdRedo(map<string,EltGeo *> *lE, vector<string> lP, vector<Command *> * historique,vector<Command *>::iterator *itAct);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdRedo();
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

//--------------------------- Autres définitions dépendantes de <CmdRedo>

#endif // CmdRedo_H_
