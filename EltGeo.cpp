/*************************************************************************
                           EltGeo  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <EltGeo> (fichier EltGeo.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "EltGeo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type EltGeo::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*
EltGeo & EltGeo::operator = ( const EltGeo & unEltGeo )
// Algorithme :
//
{
}
 *///----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EltGeo::EltGeo ( const EltGeo & unEltGeo )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <EltGeo>" << endl;
#endif
} //----- Fin de EltGeo (constructeur de copie)


EltGeo::EltGeo (string n) : Nom(n)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <EltGeo>" << endl;
#endif
} //----- Fin de EltGeo


EltGeo::~EltGeo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <EltGeo>" << endl;
#endif
} //----- Fin de ~EltGeo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
