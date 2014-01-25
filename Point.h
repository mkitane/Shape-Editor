/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H_ )
#define POINT_H_


#include <iostream>
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Point>
//
//
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool depasserBorne(long a, long b);
    bool canBeMoved(long dx, long dy);
    void deplacer(long dx, long dy);
    string description();
    long getX(){return X;}
    long getY(){return Y;}
//------------------------------------------------- Surcharge d'opérateurs
    /*Point & operator = ( const Point & unPoint );
    // Mode d'emploi :
    //
    // Contrat :
    */


//-------------------------------------------- Constructeurs - destructeur
    /*Point ( const Point & unPoint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    */
    Point (long x, long y);


    ~Point ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
   
protected:
//----------------------------------------------------- Méthodes protégées
 
//----------------------------------------------------- Attributs protégés
    long X;
    long Y;
};

//--------------------------- Autres définitions dépendantes de <Point>

#endif // POINT_H_
