/*************************************************************************
 CmdAjouterPolyLigne  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdAjouterPolyLigne> (fichier CmdAjouterPolyLigne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdAjouterPolyLigne.h"
#include "Analyseur.h"
#include "Rond.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdAjouterPolyLigne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdAjouterPolyLigne::execute(){
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    if(polyLigneAjoutee == NULL){
        if ( listeDesElements->find(nom) == listeDesElements->end() ) {
            
            polyLigneAjoutee = Analyseur::createObjectWithParameters(Analyseur::ajouterPolyligne, listeParametres,listeDesElements);
            if(polyLigneAjoutee == NULL){
                return false;
            }
            cout<< "OK" << endl;
            cout << "# New object : " << nom << endl;
        }else{
            cout << "ERR" << endl;
            cout << "#" <<  nom << " already existing" << endl;
            return false;
        }
    }else{
        //cout<<"Cercle Remis dans la liste" << endl;
    }
    
    listeDesElements -> insert (pair<string,EltGeo *>(nom,polyLigneAjoutee) );
    return true;
}

bool CmdAjouterPolyLigne::undo(){
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    
    listeDesElements -> erase(nom);
    //cout<< "Suprresion Cercle"<<endl;
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdAjouterPolyLigne::CmdAjouterPolyLigne(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjouterPolyLigne>" << endl;
#endif
} //----- Fin de CmdAjouterPolyLigne


CmdAjouterPolyLigne::~CmdAjouterPolyLigne ( )
// Algorithme :
//
{
    
    //Si commande supprimee apres un undo
    delete polyLigneAjoutee;
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjouterPolyLigne>" << endl;
#endif
} //----- Fin de ~CmdAjouterPolyLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
