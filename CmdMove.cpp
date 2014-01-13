/*************************************************************************
 CmdMove  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdMove> (fichier CmdMove.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdMove.h"
#include "Analyseur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdMove::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdMove::execute(){
    
    cout<<"on execute move" << endl;
    
    vector<string>::iterator it;
        string nom = *it;
        cout<<"element a deplacer :" << nom << endl;
        
        map<string, string>::iterator itLE;
        itLE = listeDesElements->find(nom);
    
        if(itLE != listeDesElements->end()){
            it++;
            int x1;
            if(!Analyseur::checkIfNumber((*it).c_str(), &x1)){
                cout<<"Cmd Move is not valid" << endl;
                return false;
            }
            
            it++;
            int y1;
            
            if(!Analyseur::checkIfNumber((*it).c_str(), &y1)){
                cout<<"Cmd Move is not valid" << endl;
                return false;
            }
            
            

#pragma -mark a faire quand on a les classes ELT Geo
            //(*(itLE->second))->deplacer();
            
            
        
        }else{
            cout<<"Element :" << nom << "n'existe pas"<< endl;
            return false;
        }

    return true;
}

bool CmdMove::undo(){
    
    vector<string>::iterator it;
    string nom = *it;
    cout<<"element a deplacer :" << nom << endl;
    
    map<string, string>::iterator itLE;
    itLE = listeDesElements->find(nom);
    
    if(itLE != listeDesElements->end()){
        it++;
        int x1;
        if(!Analyseur::checkIfNumber((*it).c_str(), &x1)){
            cout<<"Cmd Move is not valid" << endl;
            return false;
        }
        
        it++;
        int y1;
        
        if(!Analyseur::checkIfNumber((*it).c_str(), &y1)){
            cout<<"Cmd Move is not valid" << endl;
            return false;
        }
        
        
        x1= -1 * x1 ;
        y1 = -1 *y1 ;
#pragma -mark a faire quand on a les classes ELT Geo
        //(*(itLE->second))->deplacer();
        
        
        
    }else{
        cout<<"Element :" << nom << "n'existe pas"<< endl;
        return false;
    }

    
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdMove::CmdMove(map<string,string> *lE, vector<string> lP) : Command(lE,lP)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdMove>" << endl;
#endif
} //----- Fin de CmdMove


CmdMove::~CmdMove ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdMove>" << endl;
#endif
} //----- Fin de ~CmdMove


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
