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
void Point::deplacer(int dx, int dy){
    X+=dx;
    Y+=dy; 
}
Point::Point (int x,int y ): X(x), Y(y)
// Algorithme :
//
{
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
