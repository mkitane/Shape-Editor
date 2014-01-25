/*************************************************************************
 CmdMove  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <CmdMove> (fichier CmdMove.h) ------
#if ! defined ( CmdMove_H_ )
#define CmdMove_H_


#include <iostream>
#include "Command.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdMove>
//
//
//------------------------------------------------------------------------

class CmdMove : public Command
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
    
    void decomposer(EltGeo *e);
    void moveAllSimpleObjects(long dx, long dy);
    bool canBeMoved(long dx, long dy);
    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    CmdMove(map<string,EltGeo *> *lE, vector<string> lP);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ~CmdMove();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    map<string, EltGeo*>listeElementsBouges;
    //----------------------------------------------------- Attributs protégés
};

//--------------------------- Autres définitions dépendantes de <CmdMove>

#endif // CmdMove_H_
