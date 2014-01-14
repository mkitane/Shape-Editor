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

<<<<<<< HEAD
Ligne::Ligne(string n,int x1,int y1,int x2,int y2):EltGeo(n)
=======
Ligne::Ligne(string n, int x1,int y1,int x2,int y2) : EltGeo(n), p1(x1,y2), p2(x2,y2)
>>>>>>> ef970b023593ccf18f790aed93b40127fc77ea52
// Algorithme :
{
} //----- Fin de Ligne


Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne

void Ligne::Deplacer(int x0, int y0){
    
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
