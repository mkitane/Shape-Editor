/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------
#if ! defined ( Ligne_H_ )
#define Ligne_H_
#include "EltGeo.h"
#include <vector>
#include <string>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ligne>
//
//
//------------------------------------------------------------------------

class Ligne : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void deplacer(int dx, int dy);
    string description();

//------------------------------------------------- Surcharge d'opérateurs
   /* Ligne & operator = ( const Ligne & unLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //
*/

//-------------------------------------------- Constructeurs - destructeur
  /*  Ligne ( const Ligne & unLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
*/
    Ligne (string n,int x1,int y1, int x2, int y2);

    // Mode d'emploi :
    //
    // Contrat :
    //

    ~Ligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
    Point p1;
    Point p2;
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Ligne>

#endif // Ligne_H_
