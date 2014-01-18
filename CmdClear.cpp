/*************************************************************************
 CmdClear  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdClear> (fichier CmdClear.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdClear.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdClear::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool CmdClear::execute(){
    
   
    
    map<string,EltGeo *>::iterator it;
    for(it = listeDesElements->begin(); it!=listeDesElements->end(); it++){
        elementsSupprimes.insert(pair<string, EltGeo*>(it->first,it->second));
    }
    
    listeDesElements->clear();
    
    
    /*
    elementsSupprimes = listeDesElements;
    // ==> on garde une reference sur le tableau et
    
    listeDesElements = new map<string, EltGeo *>;
    */ //Methode Provisoire
    return true;
}

bool CmdClear::undo(){
    map<string,EltGeo *>::iterator it;
    for(it = elementsSupprimes.begin(); it!=elementsSupprimes.end(); it++){
        listeDesElements->insert(pair<string, EltGeo*>(it->first,it->second));
    }
    
    elementsSupprimes.clear();
    
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdClear::CmdClear(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdClear>" << endl;
#endif
} //----- Fin de CmdClear


CmdClear::~CmdClear ( )
// Algorithme :
//
{
    //ON SUPPRIME SEULEMENT SI C'EST PAS UN UNDO
    map<string,EltGeo *>::iterator it;
    for(it = elementsSupprimes.begin(); it!=elementsSupprimes.end(); it++){
        delete it->second;
    }
#pragma -mark Delete elements supprimés??
#ifdef MAP
    cout << "Appel au destructeur de <CmdClear>" << endl;
#endif
} //----- Fin de ~CmdClear


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
