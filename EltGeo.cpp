/*************************************************************************
                           EltGeo  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par tescure
*************************************************************************/

//---------- Réalisation de la classe <EltGeo> (fichier EltGeo.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

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
EltGeo & EltGeo::operator = ( const EltGeo & unEltGeo )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EltGeo::EltGeo ( const EltGeo & unEltGeo )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <EltGeo>" << endl;
#endif
} //----- Fin de EltGeo (constructeur de copie)


EltGeo::EltGeo ( )
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
