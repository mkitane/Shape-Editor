
/*************************************************************************
                           EltGeo  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Interface de la classe <EltGeo> (fichier EltGeo.h) ------

#ifndef ELTGEO_H_INCLUDED
#define ELTGEO_H_INCLUDED

#include <iostream>
#include "Point.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EltGeo>
//
//
//------------------------------------------------------------------------

class EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Deplacer(int x0, int y0) =0;
    // Mode d'emploi : deplace l'element geometrique selon la translation de vecteur(x0,y0)
    //
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
    EltGeo & operator = ( const EltGeo & unEltGeo );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EltGeo ( const EltGeo & unEltGeo );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    EltGeo (string n);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~EltGeo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string Nom;
};

//--------------------------- Autres définitions dépendantes de <EltGeo>

#endif // EltGeo_H_




