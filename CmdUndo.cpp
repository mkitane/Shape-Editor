/*************************************************************************
 CmdUndo  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdUndo> (fichier CmdUndo.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdUndo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdUndo::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdUndo::execute(){
    Command *c = **itActuel;
    c->undo();
    (*itActuel)--;
    return true;
}

bool CmdUndo::undo(){
    return false;
}
bool CmdUndo::canDoAnUndo(){
    return false; 
}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdUndo::CmdUndo(map<string,string> *lE, vector<string> lP, vector<Command *> *histo, vector<Command *>::iterator *itAct) : Command(lE,lP), historique(histo), itActuel(itAct)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdUndo>" << endl;
#endif
} //----- Fin de CmdUndo


CmdUndo::~CmdUndo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdUndo>" << endl;
#endif
} //----- Fin de ~CmdUndo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
