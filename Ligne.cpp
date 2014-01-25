/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ligne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

/* type Ligne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
//Ligne & Ligne::operator = ( const Ligne & unLigne )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Ligne::Ligne ( const Ligne & unLigne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif
} //----- Fin de Ligne (constructeur de copie)
*/


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
bool Ligne::canBeMoved(long dx, long dy){
    if(depasserBorne(point1.getX(), dx) || depasserBorne(point1.getY(), dy)){
        return false;
    }
    if(depasserBorne(point2.getX(), dx) || depasserBorne(point2.getY(), dy)){
        return false;
    }

    return true; 
}
void Ligne::deplacer(long dx, long dy){
    point1.deplacer(dx, dy);
    point2.deplacer(dx, dy);
}

string Ligne::description(){
    string desc = "L ";
    desc = desc + nom + " " + point1.description() + " " + point2.description();
    return desc;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
