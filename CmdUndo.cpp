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

bool CmdUndo::execute()
// Algorithme :
//      On recupere la commande precedente a partir de itActuel
//      On effectue un undo
{
    if(*itActuel == (historique->begin()-1)){ //Si on se trouve au debut de la pile, on peut pas undo
        //cout<<"Rien a undo" <<endl;
        cout<< "ERR" << endl; 
        return false;
    }
    Command *c = **itActuel;
    c->undo();
    (*itActuel)--;
    
    cout << "OK" << endl;
    return true;
}//----- Fin de Méthode

bool CmdUndo::undo()
// Algorithme :
//
{
    return false;
}//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdUndo::CmdUndo(map<string,EltGeo *> *lE, vector<string> lP, vector<Command *> *histo, vector<Command *>::iterator *itAct) : Command(lE,lP), historique(histo), itActuel(itAct)
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
