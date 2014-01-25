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
    bool depasserBorne(long a, long b);
    
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
    
    
    long getX(){return X;}
    // Mode d'emploi :
    //  Renvoie la coordonnee X du point
    // Contrat :
    //
    
    long getY(){return Y;}
    // Mode d'emploi :
    //  Renvoie la coordonnee Y du point
    // Contrat :
    //
    
//------------------------------------------------- Surcharge d'opérateurs
  

//-------------------------------------------- Constructeurs - destructeur
    Point (long x, long y);
    // Mode d'emploi :
    // Verifie si un point a dépassé l'espace des longs
    // Contrat :
    //

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
