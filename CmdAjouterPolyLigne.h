/*************************************************************************
 CmdAjouterPolyLigne  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdAjouterPolyLigne> (fichier CmdAjouterPolyLigne.h) ------
#if ! defined ( CmdAjouterPolyLigne_H_ )
#define CmdAjouterPolyLigne_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdAjouterPolyLigne>
//
//
//------------------------------------------------------------------------

class CmdAjouterPolyLigne : public Command
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
    
    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    CmdAjouterPolyLigne(map<string,EltGeo *> *lE, vector<string> lP);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdAjouterPolyLigne();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    EltGeo *polyLigneAjoutee;
    //int tab[1003938000000];
};

//--------------------------- Autres définitions dépendantes de <CmdAjouterPolyLigne>

#endif // CmdAjouterPolyLigne_H_
