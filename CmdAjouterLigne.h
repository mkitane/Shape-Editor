/*************************************************************************
 CmdAjouterLigne  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdAjouterLigne> (fichier CmdAjouterLigne.h) ------
#if ! defined ( CmdAjouterLigne_H_ )
#define CmdAjouterLigne_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdAjouterLigne>
//
//
//------------------------------------------------------------------------

class CmdAjouterLigne : public Command
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
    CmdAjouterLigne(map<string,EltGeo *> *lE, vector<string> lP);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdAjouterLigne();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    EltGeo *ligneAjoutee;
    //int tab[1003938000000];
};

//--------------------------- Autres définitions dépendantes de <CmdAjouterLigne>

#endif // CmdAjouterLigne_H_
