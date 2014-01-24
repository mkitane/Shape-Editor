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
        elementsSupprimes.push_back(it->second);
    }
    
    listeDesElements->clear();
    cout<< "OK" << endl; 
    
    /*
    elementsSupprimes = listeDesElements;
    // ==> on garde une reference sur le tableau et
    
    listeDesElements = new map<string, EltGeo *>;
    */ //Methode Provisoire
    return true;
}

bool CmdClear::undo(){
    vector<EltGeo *>::iterator it;
    for(it = elementsSupprimes.begin(); it!=elementsSupprimes.end(); it++){
        listeDesElements->insert(pair<string, EltGeo*>((*it)->getNom(),(*it)));
    }
    
    //vector<EltGeo *>().swap(elementsSupprimes);
    elementsSupprimes.clear();
    //elementsSupprimes.shrink_to_fit();
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
    vector<EltGeo *>::iterator it;
    for(it = elementsSupprimes.begin(); it!=elementsSupprimes.end(); it++){
        delete *it;
    }
    
    elementsSupprimes.clear();
    //elementsSupprimes.shrink_to_fit();
#pragma -mark Delete elements supprimés??
#ifdef MAP
    cout << "Appel au destructeur de <CmdClear>" << endl;
#endif
} //----- Fin de ~CmdClear


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
