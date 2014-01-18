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
// type Agregat::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Agregat::deleteElt(string n){
    map<string, EltGeo *>::iterator itLE;
    itLE = listEltGeo.find(n);
    if(itLE != listEltGeo.end()){
        listEltGeo.erase(n);
    }
}

void Agregat::addElt(EltGeo *e){
    listEltGeo.insert(pair<string, EltGeo*>(e->getNom(), e));
}

bool Agregat::contains(EltGeo *e){
    map<string, EltGeo *>::iterator itLE;
    itLE = listEltGeo.find(e->getNom());
    if(itLE != listEltGeo.end()){
        return true;
    }else{
        return false;
    }
}

void Agregat::deplacer(int dx, int dy)
{
    map<string, EltGeo *>::iterator it;
    for(it = listEltGeo.begin(); it != listEltGeo.end() ;it++){
        EltGeo *actuel = it->second;
        actuel->deplacer(dx, dy);
    }
    
 
}

string Agregat::description(){
    string desc = "OA ";
    desc = desc + nom + " ";

    map<string, EltGeo *>::iterator it;
    for(it = listEltGeo.begin(); it != listEltGeo.end() ;it++){
        EltGeo *actuel = it->second;
        desc = desc + actuel->getNom() + " ";
    }
    return desc;
}
//------------------------------------------------- Surcharge d'opérateurs
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

//----------------------------------------------------- Méthodes protégées
