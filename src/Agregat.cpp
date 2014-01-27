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
void Agregat::deleteElt(string n)
// Algorithme :
//  Recherche Si l'element existe
//  Si oui
//      Supprime element de la map
//
{
    map<string, EltGeo *>::iterator itLE;
    itLE = listEltGeo.find(n);
    if(itLE != listEltGeo.end()){
        listEltGeo.erase(n);
    }
} //----- Fin de MŽthode

void Agregat::addElt(EltGeo *e)
// Algorithme :
//
{
    listEltGeo.insert(pair<string, EltGeo*>(e->getNom(), e));
} //----- Fin de MŽthode

bool Agregat::contains(EltGeo *e)
// Algorithme :
//  Recherche Si l'element existe
//  Si oui
//      renvoie vrai
//  Si non
//      renvoie faux
//
{
    map<string, EltGeo *>::iterator itLE;
    itLE = listEltGeo.find(e->getNom());
    if(itLE != listEltGeo.end()){
        return true;
    }else{
        return false;
    }
} //----- Fin de MŽthode

bool Agregat::canBeMoved(long dx, long dy)
// Algorithme :
//      Parcours tous les elements de l'objet agreges
//      Si ils peuvent tous etres bouges
//          Renvoie vrai
//      Sinon
//          Revoie faux
{
    
    map<string, EltGeo *>::iterator it2;
    for(it2 = listEltGeo.begin(); it2 != listEltGeo.end() ;it2++){
        EltGeo *actuel = it2->second;
        if(!(actuel->canBeMoved(dx, dy))){
            return false;
        }
    }
    
    return true;
} //----- Fin de MŽthode

void Agregat::deplacer(long dx, long dy)
// Algorithme :
//
{
    map<string, EltGeo *>::iterator it;
    for(it = listEltGeo.begin(); it != listEltGeo.end() ;it++){
        EltGeo *actuel = it->second;
        actuel->deplacer(dx, dy);
    }
} //----- Fin de MŽthode

string Agregat::description()
// Algorithme :
//
{
    string desc = "OA ";
    desc = desc + nom + " ";

    map<string, EltGeo *>::iterator it;
    for(it = listEltGeo.begin(); it != listEltGeo.end() ;it++){
        EltGeo *actuel = it->second;
        desc = desc + actuel->getNom();
    }
    return desc;
} //----- Fin de MŽthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Agregat::Agregat(string n,map<string, EltGeo*> lEG):EltGeo(n),listEltGeo(lEG)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Agregat>" << endl;
#endif
} //----- Fin de Agregat


 Agregat::~Agregat ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Agregat>" << endl;
#endif
} //----- Fin de ~Agregat


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
