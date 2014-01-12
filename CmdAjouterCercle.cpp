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
#include "Analyseur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdAjouterCercle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdAjouterCercle::canDoAnUndo(){
    return true; 
}
bool CmdAjouterCercle::execute(){
  
    
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    it++;
    int x1;
    if(!Analyseur::checkIfNumber((*it).c_str(), &x1)){
        cout<<"Cmd AjouterCercle is not valid" << endl;
        return false;
    }
    
    it++;
    int y1;
    
    if(!Analyseur::checkIfNumber((*it).c_str(), &y1)){
        cout<<"Cmd AjouterCercle is not valid" << endl;
        return false;
    }
    
    
    it++;
    int r;
    if(!Analyseur::checkIfNumber((*it).c_str(), &r)){
        cout<<"Cmd AjouterCercle is not valid" << endl;
        return false;
    }
    
    
    cout<< "On cree un cercle de rayon " << r << " et de coordonnées (" << x1 << "," << y1 << ") " << endl;


    cercleAjoute = new string("demerde");
    
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
CmdAjouterCercle::CmdAjouterCercle(map<string,string> *lE, vector<string> lP) : Command(lE,lP)
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
