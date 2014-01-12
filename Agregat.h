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
#include <vector>
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
    void Deplacer(int w0, int y0);



//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
vector <EltGeo> ListEltGeo;

};

//--------------------------- Autres d�finitions d�pendantes de <Agregat>

#endif // Agregat_H_
