/*************************************************************************
                           Agregat  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Interface de la classe <Agregat> (fichier Agregat.h) ------

#ifndef _H_INCLUDED
#define _H_INCLUDED

#include <iostream>
#include <vector>
#include "EltGeo.h"
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Agregat>
//
//
//------------------------------------------------------------------------

class Agregat : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Deplacer(int w0, int y0);



//------------------------------------------------- Surcharge d'opérateurs
    Agregat & operator = ( const Agregat & unAgregat );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    /*Agregat ( const Agregat & unAgregat );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
*/
    Agregat();


    virtual ~Agregat();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector <EltGeo> ListEltGeo;

};

//--------------------------- Autres définitions dépendantes de <Agregat>

#endif // Agregat_H_
