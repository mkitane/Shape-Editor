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


Ligne::Ligne(string n, int x1,int y1,int x2,int y2) : EltGeo(n), p1(x1,y2), p2(x2,y2)
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

void Ligne::deplacer(int dx, int dy){
    cout<<"Utilisation Ligne" << endl; 
    p1.deplacer(dx, dy);
    p2.deplacer(dx, dy);
}

string Ligne::description(){
    string desc = "L ";
    desc = desc + Nom + " " + to_string(p1.X) + " " +to_string( p1.Y) + " " + to_string(p2.X) + " " +to_string(p2.Y);
    return desc;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
