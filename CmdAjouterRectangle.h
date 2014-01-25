/*************************************************************************
 CmdAjouterRectangle  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdAjouterRectangle> (fichier CmdAjouterRectangle.h) ------
#if ! defined ( CmdAjouterRectangle_H_ )
#define CmdAjouterRectangle_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdAjouterRectangle>
//
//
//------------------------------------------------------------------------

class CmdAjouterRectangle : public Command
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
    CmdAjouterRectangle(map<string,EltGeo *> *lE, vector<string> lP);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdAjouterRectangle();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    EltGeo *rectangleAjoute;
    //int tab[1003938000000];
};

//--------------------------- Autres définitions dépendantes de <CmdAjouterRectangle>

#endif // CmdAjouterRectangle_H_
