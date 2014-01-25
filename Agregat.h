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
    bool canBeMoved(long dx, long dy);
    // Mode d'emploi :
    // Verifie si l'objet peux etre bougŽ sans dŽpasser l'espace des longs et renvoie
    // vrai si c'est possible
    // Contrat :
    //
    
    void deplacer(long dx, long dy);
    // Mode d'emploi :
    // Deplace l'objet de dx en coordonnees horizontales et dy en coordonnes verticales
    // Contrat :
    //
    string description();
    // Mode d'emploi :
    //  Renvoie la description servant a recreer l'objet
    // Contrat :
    //
    
    
    
    void deleteElt(string n);
    // Mode d'emploi :
    //  Supprime un element geometrique de l'objet aggrege a partir de son nom
    // Contrat :
    //
    void addElt(EltGeo *e);
    // Mode d'emploi :
    //  ajoute un element geometrique de l'objet aggrege a partir de son nom
    // Contrat :
    //
    bool contains(EltGeo *e);
    // Mode d'emploi :
    //  verifie si un element geometrique appartient a cet Objet agrege
    // Contrat :
    //
    map<string,EltGeo *>* getListeltGeo(){return &listEltGeo;}
    // Mode d'emploi :
    //  Renvoie un pointeur vers la map des elements geometriques propres de cet objet agrege
    // Contrat :
    //
    
    
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    
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
