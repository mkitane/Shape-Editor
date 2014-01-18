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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void stockerEtExecuter(Command *c);
    //------------------------------------------------- Surcharge d'opérateurs
    Figure & operator = ( const Figure & unFigure );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
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
    
    //----------------------------------------------------- Méthodes protégées
    //vector<EltGeo>

    
    vector<Command *> historique;
    vector<Command *>::iterator itActuel;
    map<string, EltGeo *> listeDesElements;
    protected:

    //----------------------------------------------------- Attributs protégés
    
};

//--------------------------- Autres définitions dépendantes de <Figure>

#endif // FIGURE_H_
