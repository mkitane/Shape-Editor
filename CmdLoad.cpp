/*************************************************************************
 CmdLoad  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdLoad> (fichier CmdLoad.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdLoad.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdLoad::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdLoad::execute(){
    //Pour tous les elements, ecrire leur description
    
    if(loadedElements.empty()){
        vector<string>::iterator it;
        
        it= listeParametres.begin();
        string nomFichier = *it;
        
        
        ifstream file(nomFichier);
        string temp;
        
        
        if(file.is_open()){
            while(getline(file, temp)) {
                Analyseur::TypeCommand t;
                vector <string> parameters ;
                
                
                t = Analyseur::analyseCommand(temp);
                if(t!=Analyseur::ajouterObjetAgrege){
                    Analyseur::remplirParametres(&parameters, temp);
                    
                    
                    vector<string>::iterator it2;
                    
                    it2= parameters.begin();
                    string nom = *it2;
                    
                    
                    if ( listeDesElements->find(nom) == listeDesElements->end() ) {
                        // not found
                        EltGeo *a =Analyseur::createObjectWithParameters(t, parameters,listeDesElements);
                        listeDesElements -> insert (pair<string,EltGeo*>(nom,a));
                        loadedElements.push_back(a);
                    } else {
                        cout<< nom << "Already Loaded " << endl;
                    }
                    
                }else{
                    pool.push_back(temp);
                }
                //On clear l'historique
                //on erase tous les elements du tableau element et de l'historique
                //on delete tout (grace a delete)
                //on remet le itActuel a historique.end()-1;
                //
#pragma Load incomplet !
            }
            
            //On Load a present les objets agreges
            vector<string>::iterator poolObjects;
            for(poolObjects=pool.begin(); poolObjects<pool.end();poolObjects++){
                Analyseur::TypeCommand t;
                vector <string> parameters ;
                
                
                t = Analyseur::analyseCommand(*poolObjects);
                Analyseur::remplirParametres(&parameters, *poolObjects);
                
                
                vector<string>::iterator it2;
                
                it2= parameters.begin();
                string nom = *it2;
                
                if ( listeDesElements->find(nom) == listeDesElements->end() ) {
                    EltGeo *a =Analyseur::createObjectWithParameters(t, parameters,listeDesElements);
                    listeDesElements -> insert (pair<string,EltGeo*>(nom,a));
                    loadedElements.push_back(a);
                }else{
                    cout<< "Already Loaded" << nom << endl;
                }
            }
            
        }else{
            cout<<"Error opening file" << endl;
        }
    }else{
        
        vector<EltGeo *>::iterator itL;
        for(itL=loadedElements.begin(); itL<loadedElements.end();itL++){
            EltGeo *a = *itL;
            listeDesElements -> insert (pair<string,EltGeo*>(a->Nom,a));
        }
        
    }
    return true;
}

bool CmdLoad::undo(){
    
    vector<EltGeo *>::iterator itLoaded;
    for(itLoaded=loadedElements.begin() ; itLoaded != loadedElements.end(); itLoaded++){
        EltGeo *loaded = *itLoaded;
        listeDesElements->erase(loaded->Nom);
        cout<< "unload" << loaded->Nom << endl;
    }
    
    return true;
}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdLoad::CmdLoad(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdLoad>" << endl;
#endif
} //----- Fin de CmdLoad


CmdLoad::~CmdLoad ( )
// Algorithme :
//
{
    
    //Si cmd doit etre suppriméee apres un UNDO
    //On supprime les pointeurs crees
    vector<EltGeo *>::iterator itL;
    for(itL=loadedElements.begin(); itL<loadedElements.end();itL++){
        delete *itL;
    }
#ifdef MAP
    cout << "Appel au destructeur de <CmdLoad>" << endl;
#endif
} //----- Fin de ~CmdLoad


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
