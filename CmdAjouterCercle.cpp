/*************************************************************************
 CmdAjouterCercle  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdAjouterCercle> (fichier CmdAjouterCercle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdAjouterCercle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdAjouterCercle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdAjouterCercle::execute(){
  
    
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    it++;
    int x1 = (int) strtol((*it).c_str(),nullptr,10);
    it++;
    int y1 = (int) strtol((*it).c_str(),nullptr,10);
    it++;
    int r = (int)  strtol((*it).c_str(),nullptr,10);
    
    
    cout<< "On cree un cercle de rayon " << r << " et de coordonnées (" << x1 << "," << y1 << ") " << endl;


    cercleAjoute = new string("");
    
    listeDesElements -> insert (pair<string,string>(nom,*cercleAjoute) );
    return true;
}

bool CmdAjouterCercle::undo(){
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;

    
    listeDesElements -> erase(nom); 
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdAjouterCercle::CmdAjouterCercle(map<string,string> *lE, vector<string> lP) : UndoableCommand(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjouterCercle>" << endl;
#endif
} //----- Fin de CmdAjouterCercle


CmdAjouterCercle::~CmdAjouterCercle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjouterCercle>" << endl;
#endif
} //----- Fin de ~CmdAjouterCercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
