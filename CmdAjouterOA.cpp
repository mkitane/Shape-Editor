/*************************************************************************
 CmdAjouterOA  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdAjouterOA> (fichier CmdAjouterOA.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdAjouterOA.h"
#include "Analyseur.h"
#include "Rond.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdAjouterOA::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdAjouterOA::execute(){
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    if(OAAjoute == NULL){
        map<string, EltGeo*> objetsOA;

        it++;
        while(it<listeParametres.end()){
            string nomEltGeo = *it;
            
            map<string, EltGeo *>::iterator itLE;
            itLE = listeDesElements->find(nomEltGeo);
            if(itLE != listeDesElements->end()){
                EltGeo *e = itLE->second;
                objetsOA.insert(pair<string,EltGeo *>(e->Nom,e));
            }else{
                cout<<"Mauvais ObjetAgrege" <<endl;
                return false;
            }
            it++;

        }
      
        
        OAAjoute = new Agregat(nom,objetsOA);
    }else{
        cout<<"OA Remis dans la liste" << endl;
    }
    
    listeDesElements->insert(pair<string,EltGeo *> (nom,OAAjoute));
    
    return true;
}

bool CmdAjouterOA::undo(){
    vector<string>::iterator it;
    
    it= listeParametres.begin();
    string nom = *it;
    
    
    listeDesElements -> erase(nom);
    cout<< "Suprresion OA"<<endl;
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdAjouterOA::CmdAjouterOA(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjouterOA>" << endl;
#endif
} //----- Fin de CmdAjouterOA


CmdAjouterOA::~CmdAjouterOA ( )
// Algorithme :
//
{
    delete OAAjoute;
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjouterOA>" << endl;
#endif
} //----- Fin de ~CmdAjouterOA


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
