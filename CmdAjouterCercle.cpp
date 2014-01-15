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
#include "Rond.h"

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
    
    if(cercleAjoute == NULL){
        cercleAjoute = Analyseur::createObjectWithParameters(Analyseur::ajouterCercle, listeParametres,listeDesElements);
        if(cercleAjoute == nullptr){
            return false; 
        }
    }else{
        
        cout<<"Cercle Remis dans la liste" << endl; 
    }
    
    listeDesElements -> insert (pair<string,EltGeo *>(nom,cercleAjoute) );
    return true;
}

bool CmdAjouterCercle::undo(){
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    
    listeDesElements -> erase(nom);
    cout<< "Suprresion Cercle"<<endl;
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdAjouterCercle::CmdAjouterCercle(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjouterCercle>" << endl;
#endif
} //----- Fin de CmdAjouterCercle


CmdAjouterCercle::~CmdAjouterCercle ( )
// Algorithme :
//
{
    delete cercleAjoute;
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjouterCercle>" << endl;
#endif
} //----- Fin de ~CmdAjouterCercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
