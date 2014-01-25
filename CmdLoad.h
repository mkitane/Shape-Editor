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
    bool execute();
    // Mode d'emploi :
    //  Execute la commande
    //      et les instructions associees
    // Contrat :
    //
    bool undo();
    // Mode d'emploi :
    // Annule la commande deja executee
    // Contrat :
    //
    
    bool canDoAnUndo(){return true;}
    // Mode d'emploi :
    //  Verifie si c'est une commande que l'on peux stocker dans l'historique
    // Contrat :
    //
    
    
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
    bool loadOAs();
    bool loadElements(string temp);
    void eraseCreated();

    //----------------------------------------------------- Attributs protégés
    vector<EltGeo *> loadedElements;
    vector<string> pool; //permet de creer les aggregats en dernier pour eviter tt pb
};

//--------------------------- Autres définitions dépendantes de <CmdLoad>

#endif // CmdLoad_H_
