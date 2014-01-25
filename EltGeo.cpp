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

bool EltGeo::depasserBorne(long a, long b)
// Algorithme :
//    Effectue la somme de a et b
//    Si a et b sont positif et leur somme est negative
//      On a depassŽ l'espace des longs
//      renvoyer vrai
//    Si a et b sont negatifs et leur somme est positive
//      On a depassŽ l'espace des longs
//      renvoyer faux
{
    long c = a + b ;
    if( (a > 0 && b > 0 &&  c < 0)  || (a < 0 && b < 0 &&  c > 0)  ){
        return true;
    }
    return false;
    
}//----- Fin de MŽthode


const string EltGeo::getNom()
// Algorithme :
//
{
    return nom; 
}//----- Fin de MŽthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
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
