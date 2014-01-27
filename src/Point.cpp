/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Point::depasserBorne(long a, long b)
// Algorithme :
//    Effectue la somme de a et b
//    Si a et b sont positif et leur somme est negative
//      On a depassé l'espace des longs
//      renvoyer vrai
//    Si a et b sont negatifs et leur somme est positive
//      On a depassé l'espace des longs
//      renvoyer faux
{
    long c = a + b ;
    if( (a > 0 && b > 0 &&  c < 0)  || (a < 0 && b < 0 &&  c > 0)  ){
        return true;
    }
    return false;
    
} //----- Fin de Méthode

bool Point::canBeMoved(long dx, long dy)
// Algorithme :
//  On verifie si il peut depasser les bornes en X et en Y
{
    if(depasserBorne(X, dx) || depasserBorne(Y, dy)){
        return false;
    }
    return true;
} //----- Fin de Méthode
void Point::deplacer(long dx, long dy)
// Algorithme :
//
{
    
    X+=dx;
    Y+=dy;
} //----- Fin de Méthode

string Point::description()
// Algorithme :
//
{
    return to_string(X) + " " + to_string(Y);
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Point::Point (long x,long y ): X(x), Y(y)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
