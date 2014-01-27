/*************************************************************************
                           EltGeo  -  description
                             -------------------
    d�but                : 20 d�c. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- R�alisation de la classe <EltGeo> (fichier EltGeo.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
//------------------------------------------------------ Include personnel
#include "EltGeo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type EltGeo::M�thode ( liste des param�tres )

bool EltGeo::depasserBorne(long a, long b)
// Algorithme :
//    Effectue la somme de a et b
//    Si a et b sont positif et leur somme est negative
//      On a depass� l'espace des longs
//      renvoyer vrai
//    Si a et b sont negatifs et leur somme est positive
//      On a depass� l'espace des longs
//      renvoyer faux
{
    long c = a + b ;
    if( (a > 0 && b > 0 &&  c < 0)  || (a < 0 && b < 0 &&  c > 0)  ){
        return true;
    }
    return false;
    
}//----- Fin de M�thode


const string EltGeo::getNom()
// Algorithme :
//
{
    return nom; 
}//----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs


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

//----------------------------------------------------- M�thodes prot�g�es
