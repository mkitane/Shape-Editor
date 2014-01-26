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

bool CmdClear::execute()
// Algorithme :
//      On supprime tous les elements de notre liste des elements principale
//      On les backup sur une liste provisoire propre a la commande Clear
//      Pour un eventuel undo
{
    
    map<string,EltGeo *>::iterator it;
    for(it = listeDesElements->begin(); it!=listeDesElements->end(); it++){
        elementsSupprimes.push_back(it->second);
    }
    
    listeDesElements->clear();
    cout<< "OK" << endl; 
    
    return true;
}//----- Fin de Méthode

bool CmdClear::undo()
// Algorithme :
//      On supprime tous les elements de notre liste provisoire
//      On les remet dans notre liste des elements principale
{
    vector<EltGeo *>::iterator it;
    for(it = elementsSupprimes.begin(); it!=elementsSupprimes.end(); it++){
        listeDesElements->insert(pair<string, EltGeo*>((*it)->getNom(),(*it)));
    }
    
    //vector<EltGeo *>().swap(elementsSupprimes);
    elementsSupprimes.clear();
    //elementsSupprimes.shrink_to_fit();
    return true;
}//----- Fin de Méthode

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
    /*
    vector<EltGeo *>::iterator it;
    for(it = elementsSupprimes.begin(); it!=elementsSupprimes.end(); it++){
        delete *it;
    }
    
    elementsSupprimes.clear();
     */
    
    //elementsSupprimes.shrink_to_fit();
#ifdef MAP
    cout << "Appel au destructeur de <CmdClear>" << endl;
#endif
} //----- Fin de ~CmdClear


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
