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
    void decomposer(EltGeo *e);
    void moveAllSimpleObjects(long dx, long dy);
    bool canBeMoved(long dx, long dy);
    //----------------------------------------------------- Attributs protégés
    map<string, EltGeo*>listeElementsBouges;
};

//--------------------------- Autres définitions dépendantes de <CmdMove>

#endif // CmdMove_H_
