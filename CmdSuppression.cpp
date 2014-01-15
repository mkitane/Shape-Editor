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
void CmdSuppression::deleteElementFromOAs(EltGeo *e){
    map<string, Agregat*>::iterator it;
    for(it=listeAgreges->begin(); it!=listeAgreges->end();it++){
        if((it->second)->contains(e)){
            (it->second)->deleteElt(e->Nom);
            fromWhereDeleted.push_back(it->second);
        }
    }
    
}

void CmdSuppression::addElementstoOAs(EltGeo *e){
    vector<Agregat *>::iterator it;
    for(it=fromWhereDeleted.begin(); it<fromWhereDeleted.end();it++){
        (*it)->addElt(e);
    }
}
bool CmdSuppression::execute(){
    
    cout<<"on execute suppression" << endl;
    
    vector<string>::iterator it;
    for(it=listeParametres.begin(); it< listeParametres.end();it++){
        string nom = *it;
        cout<<"element a effacer :" << nom << endl;
        
        //On garde une reference sur lelement en cas de UNDO
        map<string, EltGeo *>::iterator itLE;
        itLE = listeDesElements->find(nom);
        if(itLE != listeDesElements->end()){
#pragma -mark Verifier si cest OA, si cest OA cest bon
#pragma -mark Sinon On doit aussi enlever OA des OA Correspondants
            deleteElementFromOAs(itLE->second);
            
            elementsSupprimes.push_back(itLE->second);
            listeDesElements->erase(nom);
        }else{
            cout<<"Element :" << nom << "n'existe pas"<< endl;
            return false;
        }
    }
    return true;
}

bool CmdSuppression::undo(){
    
    vector<EltGeo *>::iterator itL;
    for(itL=elementsSupprimes.begin(); itL<elementsSupprimes.end();itL++){
        EltGeo *a = *itL;
        listeDesElements -> insert (pair<string,EltGeo*>(a->Nom,a));
        addElementstoOAs(a);
    }

    
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdSuppression::CmdSuppression(map<string,EltGeo *> *lE, vector<string> lP,  map<string,Agregat *> *lA) : Command(lE,lP), listeAgreges(lA)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de CmdSuppression


CmdSuppression::~CmdSuppression ( )
// Algorithme :
//
{
    
#pragma -mark Delete elements supprimés??
#ifdef MAP
    cout << "Appel au destructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de ~CmdSuppression


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
