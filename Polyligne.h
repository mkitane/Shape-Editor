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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void deplacer(int dx, int dy);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    /*Polyligne & operator = ( const Polyligne & unPolyligne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Polyligne ( const Polyligne & unPolyligne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
*/
    Polyligne (string n, vector<int> lignes);
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
    vector<Ligne> listeLignes;
//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Polyligne>

#endif // Polyligne_H_
