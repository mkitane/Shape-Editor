/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/

//---------- Réalisation de la classe <Polyligne> (fichier Polyligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Polyligne.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Polyligne::canBeMoved(long dx, long dy)
// Algorithme :
//      Verifie si chaque point de la liste peut etre bouge
{
    vector<Point>::iterator it2;
    for(it2=listeLignes.begin(); it2<listeLignes.end() ;it2++){
        if(!it2->canBeMoved(dx, dy)){
            return false;
        }
    }
    
    return true;
} //----- Fin de Méthode


void Polyligne::deplacer(long dx, long dy)
// Algorithme :
//
{
    vector<Point>::iterator it;
    for(it=listeLignes.begin(); it<listeLignes.end() ;it++){
        it->deplacer(dx, dy);
    }
} //----- Fin de Méthode

string Polyligne::description()
// Algorithme :
//
{
    string desc = "PL ";
    
    desc = desc + nom;
    vector<Point>::iterator it;
    for(it=listeLignes.begin(); it<listeLignes.end() ;it++){
        desc = desc + " " + it->description() ;
    }
    return desc;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Polyligne::Polyligne (string n, vector<long> lignes ) : EltGeo(n)
// Algorithme :
//
{
    
    vector<long>::iterator it;
    //On suppose que la ligne de point est toujours paire et modulo 4 = 0
    for(it=lignes.begin(); it< lignes.end() ; it++){
        long x1 = *it;
        long y1 = *(++it);

        Point p(x1,y1);
        listeLignes.push_back(p);
    }

#ifdef MAP
    cout << "Appel au constructeur de <Polyligne>" << endl;
#endif
} //----- Fin de Polyligne


Polyligne::~Polyligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyligne>" << endl;
#endif
} //----- Fin de ~Polyligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
