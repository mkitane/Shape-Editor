/*************************************************************************
 CmdAjouterRectangle  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdAjouterRectangle> (fichier CmdAjouterRectangle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdAjouterRectangle.h"
#include "Analyseur.h"
#include "Rond.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdAjouterRectangle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdAjouterRectangle::execute(){
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    if(rectangleAjoute == NULL){
        if ( listeDesElements->find(nom) == listeDesElements->end() ) {
            
            rectangleAjoute = Analyseur::createObjectWithParameters(Analyseur::ajouterRectangle, listeParametres,listeDesElements);
            if(rectangleAjoute == NULL){
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
        // cout<<"Cercle Remis dans la liste" << endl;
    }
    
    listeDesElements -> insert (pair<string,EltGeo *>(nom,rectangleAjoute) );
    return true;
}

bool CmdAjouterRectangle::undo(){
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    
    listeDesElements -> erase(nom);
    //cout<< "Suprresion Cercle"<<endl;
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdAjouterRectangle::CmdAjouterRectangle(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
{
    rectangleAjoute = NULL;
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjouterRectangle>" << endl;
#endif
} //----- Fin de CmdAjouterRectangle


CmdAjouterRectangle::~CmdAjouterRectangle ( )
// Algorithme :
//
{
    
    //Si commande supprimee apres un undo
    delete rectangleAjoute;
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjouterRectangle>" << endl;
#endif
} //----- Fin de ~CmdAjouterRectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
