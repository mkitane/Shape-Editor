/*************************************************************************
 CmdExit  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdExit> (fichier CmdExit.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdExit.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdExit::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdExit::execute(){
        exit(2);
       return true;
}

bool CmdExit::undo(){
    return false;
}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdExit::CmdExit(map<string,string> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdExit>" << endl;
#endif
} //----- Fin de CmdExit


CmdExit::~CmdExit ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdExit>" << endl;
#endif
} //----- Fin de ~CmdExit


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
