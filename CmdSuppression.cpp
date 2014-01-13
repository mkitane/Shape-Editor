/*************************************************************************
 CmdSuppression  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdSuppression> (fichier CmdSuppression.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdSuppression.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdSuppression::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdSuppression::execute(){
    
    cout<<"on execute suppression" << endl;
    
    vector<string>::iterator it;
    for(it=listeParametres.begin(); it< listeParametres.end();it++){
        string nom = *it;
        cout<<"element a effacer :" << nom << endl;
        
        //On garde une reference sur lelement en cas de UNDO
        map<string, string>::iterator itLE;
        itLE = listeDesElements->find(nom);
        if(itLE != listeDesElements->end()){
            elementsSupprimes.push_back(&itLE->second);
            listeDesElements->erase(nom);
        }else{
            cout<<"Element :" << nom << "n'existe pas"<< endl;
            return false;
        }
    }
    return true;
}

bool CmdSuppression::undo(){
    
    return true; 
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdSuppression::CmdSuppression(map<string,string> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de CmdSuppression


CmdSuppression::~CmdSuppression ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de ~CmdSuppression


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
