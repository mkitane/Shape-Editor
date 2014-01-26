/*************************************************************************
 Figure  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.h) ------
#if ! defined ( FIGURE_H_ )
#define FIGURE_H_



//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <vector>
#include <map>
#include "Command.h"
#include "EltGeo.h"
#include "Agregat.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Figure>
//
//
//------------------------------------------------------------------------

class Figure
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    void stockerEtExecuter(Command *c);
    // Mode d'emploi :
    //  Stocke dans l'historique la commande et l'execute
    // Contrat :
    //
    
    bool isRunning(){return run;};
    // Mode d'emploi :
    //  Renvoie la valeur de la variable run
    // Contrat :
    //
    
    void setRun(bool r){run = r;};
    // Mode d'emploi :
    //  Change la valeur de la variable run
    // Contrat :
    //
    
    vector<Command *> * getPtrHistorique();
    // Mode d'emploi :
    //  Renvoie un pointeur vers l'historique
    // Contrat :
    //
    vector<Command *>::iterator * getPtritActuel();
    // Mode d'emploi :
    //  Renvoie un pointeur vers le curseur present sur l'historique
    // Contrat :
    //
    map<string, EltGeo *> * getPtrListeDesElements();
    // Mode d'emploi :
    // Renvoie un pointeur vers la liste des elements
    // Contrat :
    //
    
    
    
    //------------------------------------------------- Surcharge d'opérateurs
    
    //-------------------------------------------- Constructeurs - destructeur
    Figure ( const Figure & unFigure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    Figure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Figure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    

protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    bool run;
    vector<Command *> historique;
    vector<Command *>::iterator itActuel; // Correspond au curseur dans notre specifications !
    map<string, EltGeo *> listeDesElements;
    
};

//--------------------------- Autres définitions dépendantes de <Figure>

#endif // FIGURE_H_
