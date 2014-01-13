/*************************************************************************
 CmdSuppression  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdSuppression> (fichier CmdSuppression.h) ------
#if ! defined ( CmdSuppression_H_ )
#define CmdSuppression_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdSuppression>
//
//
//------------------------------------------------------------------------

class CmdSuppression : public Command
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
    CmdSuppression(map<string,string> *lE, vector<string> lP);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdSuppression();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    vector<string *> elementsSupprimes ; //On garde une reference aux elements supprimés juste in case;
                                    //Pour le redo
};

//--------------------------- Autres définitions dépendantes de <CmdSuppression>

#endif // CmdSuppression_H_
