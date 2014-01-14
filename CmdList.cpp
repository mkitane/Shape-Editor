/*************************************************************************
 CmdList  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdList> (fichier CmdList.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdList.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdList::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdList::execute(){
    //Pour tous les elements, ecrire leur description
    
    
    map<string, EltGeo *>::iterator it;
    
    for(it = listeDesElements->begin() ; it!= listeDesElements->end() ; it++){
        // A modifier plustard
        EltGeo *a = it->second;
        cout << a->description() << endl; 
    }


    return true;
}

bool CmdList::undo(){
    return false;
}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdList::CmdList(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdList>" << endl;
#endif
} //----- Fin de CmdList


CmdList::~CmdList ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdList>" << endl;
#endif
} //----- Fin de ~CmdList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
