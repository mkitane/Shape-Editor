/*************************************************************************
 CmdAjouterOA  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdAjouterOA> (fichier CmdAjouterOA.h) ------
#if ! defined ( CmdAjouterOA_H_ )
#define CmdAjouterOA_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdAjouterOA>
//
//
//------------------------------------------------------------------------

class CmdAjouterOA : public Command
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
    CmdAjouterOA(map<string,EltGeo *> *lE, vector<string> lP,map<string,Agregat *> *lA);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdAjouterOA();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    Agregat *OAAjoute;
    map<string,Agregat *> *listeAgreges;

    //int tab[1000000000];
};

//--------------------------- Autres définitions dépendantes de <CmdAjouterOA>

#endif // CmdAjouterOA_H_
