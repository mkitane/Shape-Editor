/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Interface de la classe <Polyligne> (fichier Polyligne.h) ------
#if ! defined ( Polyligne_H_ )
#define Polyligne_H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "EltGeo.h"
#include "Ligne.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Polyligne>
//
//
//------------------------------------------------------------------------

class Polyligne : public EltGeo
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

    Polyligne (string n, vector<long> lignes);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Polyligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    
//----------------------------------------------------- Attributs protégés
    vector<Point> listeLignes;

};

//--------------------------- Autres définitions dépendantes de <Polyligne>

#endif // Polyligne_H_
