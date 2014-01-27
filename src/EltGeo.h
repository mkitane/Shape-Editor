
/*************************************************************************
                           EltGeo  -  description
                             -------------------
    d�but                : 20 d�c. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Interface de la classe <EltGeo> (fichier EltGeo.h) ------

//#define MAP

#ifndef ELTGEO_H_INCLUDED
#define ELTGEO_H_INCLUDED

#include <iostream>
#include "Point.h"
using namespace std;

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <EltGeo>
//
//
//------------------------------------------------------------------------

class EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    bool depasserBorne(long a, long b);
    // Mode d'emploi :
    // Verifie si un point a d�pass� l'espace des longs
    // Contrat :
    //
    const string getNom();
    // Mode d'emploi :
    //  Renvoie le nom de l'objet
    // Contrat :
    //
    virtual bool canBeMoved(long dx, long dy) =0;
    // Mode d'emploi :
    // Verifie si l'objet peux etre boug� sans d�passer l'espace des longs et renvoie
    // vrai si c'est possible
    // Contrat :
    //
    virtual void deplacer(long dx, long dy) =0;
    // Mode d'emploi :
    // Deplace l'objet de dx en coordonnees horizontales et dy en coordonnes verticales
    // Contrat :
    //
    
    virtual string description() = 0 ;
    // Mode d'emploi :
    //  Renvoie la description servant a recreer l'objet
    // Contrat :
    //
//------------------------------------------------- Surcharge d'op�rateurs


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
//----------------------------------------------------- M�thodes prot�g�es
//----------------------------------------------------- Attributs prot�g�s
    string nom;
};

//--------------------------- Autres d�finitions d�pendantes de <EltGeo>

#endif // EltGeo_H_




