/*************************************************************************
 CmdAjouterLigne  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdAjouterLigne> (fichier CmdAjouterLigne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdAjouterLigne.h"
#include "Analyseur.h"
#include "Rond.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdAjouterLigne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdAjouterLigne::execute(){
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    if(ligneAjoutee == NULL){
        if ( listeDesElements->find(nom) == listeDesElements->end() ) {
            
            ligneAjoutee = Analyseur::createObjectWithParameters(Analyseur::ajouterLigne, listeParametres,listeDesElements);
            if(ligneAjoutee == NULL){
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
    
    listeDesElements -> insert (pair<string,EltGeo *>(nom,ligneAjoutee) );
    return true;
}

bool CmdAjouterLigne::undo(){
    listeDesElements -> erase(listeParametres.at(0));

    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdAjouterLigne::CmdAjouterLigne(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
{
    ligneAjoutee = NULL;
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjouterLigne>" << endl;
#endif
} //----- Fin de CmdAjouterLigne


CmdAjouterLigne::~CmdAjouterLigne ( )
// Algorithme :
//
{
    
    //Si commande supprimee apres un undo
    delete ligneAjoutee;
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjouterLigne>" << endl;
#endif
} //----- Fin de ~CmdAjouterLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
