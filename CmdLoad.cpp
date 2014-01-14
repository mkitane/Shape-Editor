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
            Analyseur::remplirParametres(&parameters, temp);
            
            
            vector<string>::iterator it2;
            
            it2= parameters.begin();
            string nom = *it2;
            
            //listeDesElements -> insert (pair<string,string>(nom,Analyseur::createObjectWithParameters(t, parameters)));
            loadedElements.push_back(nom);
            
            //On clear l'historique
            //on erase tous les elements du tableau element et de l'historique
            //on delete tout (grace a delete)
            //on remet le itActuel a historique.end()-1;
            //
#pragma Load incomplet !
        }
    }else{
        cout<<"Error opening file" << endl;
    }
    
    return true;
}

bool CmdLoad::undo(){
    
    vector<string>::iterator itLoaded;
    for(itLoaded=loadedElements.begin() ; itLoaded != loadedElements.end(); itLoaded++){
        string loaded = *itLoaded;
        listeDesElements->erase(loaded);
        cout<< "unload" << loaded << endl;
    }
    return false;
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
#ifdef MAP
    cout << "Appel au destructeur de <CmdLoad>" << endl;
#endif
} //----- Fin de ~CmdLoad


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
