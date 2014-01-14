/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

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

Ligne::Ligne(int x1,int y1,int x2,int y2):
// Algorithme :
{
    point1=Point(x1,y1);
    point2=Point(x2,y2);
    ListLigne.push_back(point1);
    ListLigne.push_back(point2);
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
