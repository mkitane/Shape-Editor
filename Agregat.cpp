/*************************************************************************
                           Agregat  -  description
                             -------------------
    d�but                : 20 d�c. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- R�alisation de la classe <Agregat> (fichier Agregat.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
//------------------------------------------------------ Include personnel
#include "Agregat.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Agregat::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void Agregat::deplacer(int dx, int dy)
{
    map<string, EltGeo *>::iterator it;
    for(it = listEltGeo.begin(); it != listEltGeo.end() ;it++){
        EltGeo *actuel = it->second;
        actuel->deplacer(dx, dy);
    }
    
 
}
//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es
