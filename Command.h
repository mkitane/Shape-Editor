/*************************************************************************
 Command  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if ! defined ( COMMAND_H_ )
#define COMMAND_H_


#include <iostream>
#include <map>
#include <vector>
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Command>
//
//
//------------------------------------------------------------------------

class Command
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool virtual execute() = 0 ;
    bool virtual undo() = 0 ;
    bool virtual canDoAnUndo()=0;
    
    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur

     Command (map<string,string> *listeDesElements, vector<string> lP );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Command ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    

    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    vector<string> listeParametres;
    map<string,string> *listeDesElements;

};

//--------------------------- Autres définitions dépendantes de <Command>

#endif // COMMAND_H_
