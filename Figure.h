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
    bool virtual execute() = 0 ;
    bool virtual undo() = 0 ;
    
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
    
protected:
    //----------------------------------------------------- Méthodes protégées
    //vector<EltGeo>
    //----------------------------------------------------- Attributs protégés
    
};

//--------------------------- Autres définitions dépendantes de <Figure>

#endif // FIGURE_H_
