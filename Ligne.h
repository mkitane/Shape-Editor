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
    bool canBeMoved(long dx, long dy);
    // Mode d'emploi :
    // Verifie si l'objet peux etre bougé sans dépasser l'espace des longs et renvoie
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

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Ligne (string n,long x1,long y1, long x2, long y2);

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

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Point point1;
    Point point2;
};

//--------------------------- Autres définitions dépendantes de <Ligne>

#endif // Ligne_H_
