/*************************************************************************
                           Rond  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <Rond> (fichier Rond.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


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

void Rond::deplacer(int dx,int dy)
// Algorithme :
//
{
        centre.deplacer(dx,dy);
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

Rond::Rond (string n,int r, int x0, int y0 ) : EltGeo(n), centre(Point(x0, y0)), R(r)
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

string Rond::description(){
    string desc = "C ";
    desc = desc + Nom + " " + to_string(centre.X) + " " +to_string(centre.Y) + " " + to_string(R);
    return desc;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
