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
bool EltGeo::depasserBorne(long a, long b){
    long c = a + b ;
    if( (a > 0 && b > 0 &&  c < 0)  || (a < 0 && b < 0 &&  c > 0)  ){
        return true;
    }
    return false;
    
}
const string EltGeo::getNom(){
    return nom; 
}

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


EltGeo::EltGeo (string n) : nom(n)
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
