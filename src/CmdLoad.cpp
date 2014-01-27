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

bool CmdLoad::execute()
// Algorithme :
//   Pour toutes les lignes du fichier
//      Executer la commande correspondante
//      Ajoute lelement a la liste des elements et a une liste provisoire en cas de redo
//   Laisser les Objets Agreges a la fin
{
    
    if(loadedElements.empty()){
        vector<string>::iterator it;
        
        it= listeParametres.begin();
        string nomFichier = *it;
        
        
        ifstream file(nomFichier);
        string temp;
        
        
        if(file.is_open()){
            while(getline(file, temp)) {
                if(!loadElements(temp)){
                    return false;
                }
            }
            
            
            if(!loadOAs()){
                return false;
            }
            
            
        }else{
            cout<< "ERR" << endl;
            cout<<"#Error opening file" << endl;
            return false;
        }
        
        
        cout << "OK" << endl;
    }else{
        
        vector<EltGeo *>::iterator itL;
        for(itL=loadedElements.begin(); itL<loadedElements.end();itL++){
            EltGeo *a = *itL;
            listeDesElements -> insert (pair<string,EltGeo*>(a->getNom(),a));
        }
        
    }
    
    return true;
}//----- Fin de Méthode

bool CmdLoad::undo()
// Algorithme :
//  Supprime dans la liste principale
//  tous les elements present de la liste provisoire
{
    
    vector<EltGeo *>::iterator itLoaded;
    for(itLoaded=loadedElements.begin() ; itLoaded != loadedElements.end(); itLoaded++){
        EltGeo *loaded = *itLoaded;
        listeDesElements->erase(loaded->getNom());
    }
    
    return true;
}//----- Fin de Méthode


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
    

    if(loadedElements.size() > 0){
        vector<EltGeo *>::iterator itL;
        for(itL=loadedElements.begin(); itL<loadedElements.end();itL++){
            delete *itL;
        }
    }
    loadedElements.clear();
#ifdef MAP
    cout << "Appel au destructeur de <CmdLoad>" << endl;
#endif
} //----- Fin de ~CmdLoad


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void CmdLoad::eraseCreated()
// Algorithme :
//
// Supprime tous les elements deja crees en cas d'erreur
{
    
    vector<EltGeo *>::iterator itLoaded;
    for(itLoaded=loadedElements.begin() ; itLoaded != loadedElements.end(); itLoaded++){
        EltGeo *loaded = *itLoaded;
        listeDesElements->erase(loaded->getNom());
        delete loaded;
        //cout<< "unload" << loaded->Nom << endl;
    }
    
    loadedElements.clear();
}//----- Fin de Méthode


bool CmdLoad::loadElements(string temp)
// Algorithme :
//  Analysela commande
//  Si renvoi = ajouterLigne ou ajouterCercle ou ajouterPolyligne ou ajouterRectangle
//      Parcourir les parametres
//      Creer objet correspondant
//      Si erreur
//          Supprimer tous les elements deja crees
//      Fin si
//  Sinon si renvoi = ajouterObjetAgrege
//      le rajouter a "pool" pour charger ulterieurement ObjetAgrege
//  FinSi
//

{
    Analyseur::TypeCommand t;
    vector <string> parameters ;
    
    
    t = Analyseur::analyseCommand(temp);
    if (t == Analyseur::errorCommand){
        eraseCreated();
        return false;
    }else if(t==Analyseur::ajouterLigne || t==Analyseur::ajouterCercle || t==Analyseur::ajouterPolyligne || t==Analyseur::ajouterRectangle){
        Analyseur::remplirParametres(&parameters, temp);
        
        if(!nbParams(t,(int)parameters.size())){
            eraseCreated();
            return false;
        }
        
        vector<string>::iterator it2;
        
        it2= parameters.begin();
        string nom = *it2;
        
        
        if ( listeDesElements->find(nom) == listeDesElements->end() ) {
            // not found
            EltGeo *a =Analyseur::createObjectWithParameters(t, parameters,listeDesElements);
            if(a != NULL){
                listeDesElements -> insert (pair<string,EltGeo*>(nom,a));
                loadedElements.push_back(a);
            }else{
                eraseCreated();
                cout << "ERR" << endl;
                cout<< "#Error Loading File" << endl;
                return false;
            }
        } else {
            eraseCreated();
            cout << "ERR" << endl;
            cout<< "#Error Loading File" << endl;
            return false;
        }
        
    }else if(t==Analyseur::ajouterObjetAgrege){
        pool.push_back(temp);
    }

    return true;
}//----- Fin de Méthode


bool CmdLoad::loadOAs()
// Algorithme :
//  Meme principe que load elements simples
{
    
    //On Load a present les objets agreges
    vector<string>::iterator poolObjects;
    for(poolObjects=pool.begin(); poolObjects<pool.end();poolObjects++){
        Analyseur::TypeCommand t;
        vector <string> parameters ;
        
        
        t = Analyseur::analyseCommand(*poolObjects);
        Analyseur::remplirParametres(&parameters, *poolObjects);
        
        if(!nbParams(t,(int)parameters.size())){
            eraseCreated();
            return false;
        }
        
        vector<string>::iterator it2;
        
        it2= parameters.begin();
        string nom = *it2;
        
        if ( listeDesElements->find(nom) == listeDesElements->end() ) {
            EltGeo *a =Analyseur::createObjectWithParameters(t, parameters,listeDesElements);
            if(a != NULL){
                listeDesElements -> insert (pair<string,EltGeo*>(nom,a));
                loadedElements.push_back(a);
            }else{
                
                eraseCreated();
                cout << "ERR" << endl;
                cout<< "#Error Loading File" << nom << endl;
                return false;
            }
        } else {
            eraseCreated();
            cout << "ERR" << endl;
            cout<< "#Error Loading File" << nom << endl;
            return false;
        }
    }

    return true;
}//----- Fin de Méthode
