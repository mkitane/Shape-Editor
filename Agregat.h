/*************************************************************************
                           Agregat  -  description
                             -------------------
    d�but                : 20 d�c. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Interface de la classe <Agregat> (fichier Agregat.h) ------

#ifndef _H_INCLUDED
#define _H_INCLUDED

#include <iostream>
#include <map>
#include "EltGeo.h"
using namespace std;

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Agregat>
//
//
//------------------------------------------------------------------------

class Agregat : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    void deplacer(int dx, int dy);
    string description();
    void deleteElt(string n);
    void addElt(EltGeo *e);
    bool contains(EltGeo *e);

//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    map <string, EltGeo *> listEltGeo;

};

//--------------------------- Autres d�finitions d�pendantes de <Agregat>

#endif // Agregat_H_
