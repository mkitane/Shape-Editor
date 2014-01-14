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
#include <string>

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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Deplacer(int x0, int y0);

//------------------------------------------------- Surcharge d'opérateurs
   /* Ligne & operator = ( const Ligne & unLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //
*/

//-------------------------------------------- Constructeurs - destructeur
  /*  Ligne ( const Ligne & unLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
*/
<<<<<<< HEAD
    Ligne (string n,int x1,int y1, int x2, int y2);
=======
    Ligne (string nom, int x1,int y1, int x2, int y2);
>>>>>>> ef970b023593ccf18f790aed93b40127fc77ea52
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
    Point p1;
    Point p2;
};

//--------------------------- Autres définitions dépendantes de <Ligne>

#endif // Ligne_H_
