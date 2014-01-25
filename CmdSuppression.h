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
    CmdSuppression(map<string,EltGeo *> *lE, vector<string> lP);
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
    
    void deleteElementFromOAs(EltGeo *e);
    void addElementstoOAs(EltGeo *e);
    //----------------------------------------------------- Attributs protégés
    vector<EltGeo *> elementsSupprimes ; //On garde une reference aux elements supprimés juste in case;
    vector<Agregat *> fromWhereDeleted;  //Pour remettre l'objet dans les OA si on redo

};

//--------------------------- Autres définitions dépendantes de <CmdSuppression>

#endif // CmdSuppression_H_
