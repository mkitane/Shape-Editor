/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Ligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Ligne::canBeMoved(long dx, long dy)
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

void Ligne::deplacer(long dx, long dy)
// Algorithme :
//
{
    point1.deplacer(dx, dy);
    point2.deplacer(dx, dy);
}//----- Fin de Méthode

string Ligne::description()
// Algorithme :
//
{
    string desc = "L ";
    desc = desc + nom + " " + point1.description() + " " + point2.description();
    return desc;
}//----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Ligne::Ligne(string n, long x1,long y1,long x2,long y2) : EltGeo(n), point1(x1,y1), point2(x2,y2)
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif
} //----- Fin de Ligne


Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
