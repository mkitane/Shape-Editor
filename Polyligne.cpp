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
// type Polyligne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Polyligne::Polyligne (string n, vector<int> lignes ) : EltGeo(n)
// Algorithme :
//
{
    
    vector<int>::iterator it;
    //On suppose que la ligne de point est toujours paire et modulo 4 = 0
    for(it=lignes.begin(); it< lignes.end() ; it++){
        int x1 = *it;
        int y1 = *it++;

        int x2 = *it++;
        int y2 = *it;
        
        
        Ligne l("",x1,y1,x2,y2);
        listeLignes.push_back(l);
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

void Polyligne::Deplacer(int x0, int y0){
    
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
