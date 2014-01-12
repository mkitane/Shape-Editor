/*************************************************************************
 UndoableCommand  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <UndoableCommand> (fichier UndoableCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "UndoableCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type UndoableCommand::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
UndoableCommand::UndoableCommand (map<string,string> *lE, vector<string> lP ) : Command(lE,lP)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <UndoableCommand>" << endl;
#endif
} //----- Fin de UndoableCommand


UndoableCommand::~UndoableCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <UndoableCommand>" << endl;
#endif
} //----- Fin de ~UndoableCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
