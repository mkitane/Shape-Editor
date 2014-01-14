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
#include "Point.h"
#include <string>
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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

void Deplacer(int x0, int y0);
    // Mode d'emploi : translate le centre du rond selon le vecteur (x0,y0)
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
  /*  Rond & operator = ( const Rond & unRond );
    // Mode d'emploi :
    //
    // Contrat :
    //
*/

//-------------------------------------------- Constructeurs - destructeur
    /*Rond ( const Rond & unRond );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
*/
    Rond ( string n,int R, int x0, int y0);
    // Mode d'emploi : cree le rond de centre (x0,y0) et de rayon R
    //
    // Contrat :
    //

    virtual ~Rond ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int R; //rayon du rond
Point centre;
};

//--------------------------- Autres définitions dépendantes de <Rond>

#endif // Rond_H_
