/*************************************************************************
 CmdSuppression  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdSuppression> (fichier CmdSuppression.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdSuppression.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdSuppression::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdSuppression::execute(){
    
    cout<<"on execute suppression" << endl; 
    return true;
}

bool CmdSuppression::undo(){
    
    return true; 
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdSuppression::CmdSuppression(map<string,string> *lE, vector<string> lP) : UndoableCommand(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de CmdSuppression


CmdSuppression::~CmdSuppression ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de ~CmdSuppression


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
