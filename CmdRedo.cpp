/*************************************************************************
 CmdRedo  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdRedo> (fichier CmdRedo.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdRedo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdRedo::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdRedo::execute(){
    
    if(*itActuel+1 == historique->end()){
        cout<<"rien a redo" << endl; 
        return false;
    }
    Command *c = *(*itActuel+1);
    c->execute();
    (*itActuel)++;
    return true;
}

bool CmdRedo::undo(){
    return false;
}



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdRedo::CmdRedo(map<string,string> *lE, vector<string> lP, vector<Command *> *histo, vector<Command *>::iterator *itAct) : Command(lE,lP), historique(histo), itActuel(itAct)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdRedo>" << endl;
#endif
} //----- Fin de CmdRedo


CmdRedo::~CmdRedo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdRedo>" << endl;
#endif
} //----- Fin de ~CmdRedo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
