/*************************************************************************
 CmdSave  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdSave> (fichier CmdSave.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdSave.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool CmdSave::execute()
// Algorithme :
//  Pour tous nos elements de la liste des elements
//  On charge dans notre fichier la description de chaque element
{

   //Pour tous les elements, ecrire leur description
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nomFichier = *it;

    
    ofstream o;
    o.open (nomFichier, ofstream::out | ofstream::trunc);
    
    if(o.is_open()){
        
        map<string, EltGeo *>::iterator it;
        
        for(it = listeDesElements->begin() ; it!= listeDesElements->end() ; it++){
            EltGeo *a = it->second;
            o << a->description() << endl;
        }
        o.close();
        cout<<"OK" << endl;
    }else{
        cout<< "ERR" << endl;
        cout<<"#Error opening file" << endl;
    }

    return true;
}//----- Fin de Méthode

bool CmdSave::undo()
// Algorithme :
//
{
    return false;
}//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdSave::CmdSave(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSave>" << endl;
#endif
} //----- Fin de CmdSave


CmdSave::~CmdSave ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSave>" << endl;
#endif
} //----- Fin de ~CmdSave


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
