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
// type Point::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*
Point & Point::operator = ( const Point & unPoint )
// Algorithme :
//
{
}
 *///----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Point::Point ( const Point & unPoint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- Fin de Point (constructeur de copie)
*/

bool Point::depasserBorne(long a, long b){
    long c = a + b ;
    if( (a > 0 && b > 0 &&  c < 0)  || (a < 0 && b < 0 &&  c > 0)  ){
        return true;
    }
    return false;
    
}
bool Point::canBeMoved(long dx, long dy){
    if(depasserBorne(X, dx) || depasserBorne(Y, dy)){
        return false;
    }
    return true;
}
void Point::deplacer(long dx, long dy){
 
    X+=dx;
    Y+=dy;
}
string Point::description(){
    return to_string(X) + " " + to_string(Y);
}
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
