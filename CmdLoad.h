/*************************************************************************
 CmdLoad  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdLoad> (fichier CmdLoad.h) ------
#if ! defined ( CmdLoad_H_ )
#define CmdLoad_H_


#include <iostream>
#include "Command.h"
#include "Analyseur.h"
#include <vector>
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdLoad>
//
//
//------------------------------------------------------------------------

class CmdLoad : public Command
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
    bool canDoAnUndo(){return true;}
    void eraseCreated();
    
    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    CmdLoad(map<string,EltGeo *> *lE, vector<string> lP);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdLoad();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    vector<EltGeo *> loadedElements;
    vector<string> pool; //on cree les aggregats en dernier pour eviter tt pb
    //----------------------------------------------------- Attributs protégés
};

//--------------------------- Autres définitions dépendantes de <CmdLoad>

#endif // CmdLoad_H_
