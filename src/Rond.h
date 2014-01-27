/*************************************************************************
                           Rond  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Interface de la classe <Rond> (fichier Rond.h) ------
#if ! defined ( Rond_H_ )
#define Rond_H_

//--------------------------------------------------- Interfaces utilisées
#include "EltGeo.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Rond>
//
//
//------------------------------------------------------------------------

class Rond : public EltGeo
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
    Rond ( string n,long r, long x0, long y0);
    // Mode d'emploi : cree le rond de centre (x0,y0) et de rayon R
    //
    // Contrat :
    //

    ~Rond ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
long rayon;
Point centre;
};

//--------------------------- Autres définitions dépendantes de <Rond>

#endif // Rond_H_
