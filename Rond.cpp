/*************************************************************************
                           Rond  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <Rond> (fichier Rond.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Rond.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Rond::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Rond::Deplacer(x0,y0)
// Algorithme :
//
{
        centre=centre.Deplacer(x0,y0);
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/*Rond & Rond::operator = ( const Rond & unRond )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Rond::Rond ( const Rond & unRond )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rond>" << endl;
#endif
} //----- Fin de Rond (constructeur de copie)
*/

Rond::Rond (int r, int x0, int y0 ) : Point(int,int)
// Algorithme :
//
{

} //----- Fin de Rond

 Rond::~Rond ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rond>" << endl;
#endif
} //----- Fin de ~Rond


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
