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
    
    //------------------------------------------------- Surcharge d'opérateurs
    Command & operator = ( const Command & unCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //-------------------------------------------- Constructeurs - destructeur
    Command ( const Command & unCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    Command ( );
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
    
};

//--------------------------- Autres définitions dépendantes de <Command>

#endif // COMMAND_H_
