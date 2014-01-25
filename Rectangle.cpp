/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Rectangle::canBeMoved(long dx , long dy)
// Algorithme :
//
{
    if(!point1.canBeMoved(dx, dy)){
        return false;
    }
    if(!point2.canBeMoved(dx, dy)){
        return false;
    }
    return true; 
} //----- Fin de Méthode

void Rectangle::deplacer(long dx, long dy)
// Algorithme :
//
{

    point1.deplacer(dx, dy);
    point2.deplacer(dx, dx);
} //----- Fin de Méthode

string Rectangle::description()
// Algorithme :
//
{
    string desc = "R ";
    desc = desc + nom + " " + point1.description() + " " + point2.description();
    return desc;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Rectangle::Rectangle (string n,long x1, long y1, long x2, long y2 ):EltGeo(n), point1(Point(x1,y1)), point2(Point(x2, y2))
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle


Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
