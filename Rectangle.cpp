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
// type Rectangle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Rectangle::canBeMoved(long dx , long dy){
    if(depasserBorne(point1.getX(), dx) || depasserBorne(point1.getY(), dy)){
        return false;
    }
    if(depasserBorne(point2.getX(), dx) || depasserBorne(point2.getY(), dy)){
        return false;
    }
    return true; 
}
void Rectangle::deplacer(long dx, long dy)
{

    point1.deplacer(dx, dy);
    point2.deplacer(dx, dx);
}

//------------------------------------------------- Surcharge d'opérateurs
/*µRectangle & Rectangle::operator = ( const Rectangle & unRectangle )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Rectangle::Rectangle ( const Rectangle & unRectangle )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)
*/

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

string Rectangle::description(){
    string desc = "R ";
    desc = desc + nom + " " + point1.description() + " " + point2.description();
    return desc;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
