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
#include <map>
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
    void deplacer(int dx, int dy);
    string description();
    void deleteElt(string n);
    void addElt(EltGeo *e);
    bool contains(EltGeo *e);

//------------------------------------------------- Surcharge d'opérateurs
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
    Agregat(string n, map<string, EltGeo*> lEG);


    virtual ~Agregat();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map <string, EltGeo *> listEltGeo;

};

//--------------------------- Autres définitions dépendantes de <Agregat>

#endif // Agregat_H_
