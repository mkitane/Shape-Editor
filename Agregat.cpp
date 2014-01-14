/*************************************************************************
                           Agregat  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <Agregat> (fichier Agregat.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "Agregat.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Agregat::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Agregat::deplacer(int dx, int dy)
{
    map<string, EltGeo *>::iterator it;
    for(it = listEltGeo.begin(); it != listEltGeo.end() ;it++){
        EltGeo *actuel = it->second;
        actuel->deplacer(dx, dy);
    }
    
 
}
//------------------------------------------------- Surcharge d'opérateurs
/*
Agregat & Agregat::operator = ( const Agregat & unAgregat )
// Algorithme :
//
{
}
 *///----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Agregat::Agregat ( const Agregat & unAgregat )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Agregat>" << endl;
#endif
} //----- Fin de Agregat (constructeur de copie)
*/


Agregat::Agregat(string n,map<string, EltGeo*> lEG):EltGeo(n),listEltGeo(lEG)
// Algorithme :
//
{

} //----- Fin de Agregat


 Agregat::~Agregat ( )
// Algorithme :
//
{

} //----- Fin de ~Agregat


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
