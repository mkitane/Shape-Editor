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

bool Rond::canBeMoved(long dx , long dy)
// Algorithme :
//
{
    if(!centre.canBeMoved(dx, dy)){
        return false;
    }
    
    //si on arrive a ce point,  cela veux dire que le point X apres le deplacement ne depasse pas la limite
    if(depasserBorne(centre.getX()+dx, rayon) || depasserBorne(centre.getX()+dx, -rayon) || depasserBorne(centre.getY()+dy, rayon) || depasserBorne(centre.getY()+dy, -rayon)){
        return false;
    }
    return true;
} //----- Fin de Méthode

void Rond::deplacer(long dx,long dy)
// Algorithme :
//
{
    centre.deplacer(dx,dy);
} //----- Fin de Méthode

string Rond::description(){
    string desc = "C ";
    desc = desc + nom + " " + centre.description() + " " + to_string(rayon);
    return desc;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Rond::Rond (string n,long r, long x0, long y0 ) : EltGeo(n), centre(Point(x0, y0)), rayon(r)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rond>" << endl;
#endif
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
