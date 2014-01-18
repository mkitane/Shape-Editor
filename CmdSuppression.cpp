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
    map<string, EltGeo*>::iterator it;
    for(it=listeDesElements->begin(); it!=listeDesElements->end();it++){
        if (dynamic_cast<Agregat*>(it->second)) {
            Agregat *agg = dynamic_cast<Agregat*>(it->second);
            if((agg)->contains(e)){
                (agg)->deleteElt(e->getNom());
                fromWhereDeleted.push_back(agg);
            }
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
    
    vector<string>::iterator it;
    for(it=listeParametres.begin(); it< listeParametres.end();it++){
        string nom = *it;
        
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
            cout << "ERR" << endl;
            cout << "#invalid parameters" << endl;
            return false;
        }
    }
    
    cout << "OK" << endl; 
    return true;
}

bool CmdSuppression::undo(){
    
    vector<EltGeo *>::iterator itL;
    for(itL=elementsSupprimes.begin(); itL<elementsSupprimes.end();itL++){
        EltGeo *a = *itL;
        listeDesElements -> insert (pair<string,EltGeo*>(a->getNom(),a));
        addElementstoOAs(a);
        
    }

    elementsSupprimes.clear();
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdSuppression::CmdSuppression(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
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
    //On supprime les elements relié a la commande supprimée Si c'est pas !!!!un undo !! si c'est un undo, ne rien faire!!
    vector<EltGeo *>::iterator itElementsSupprimes;
    for(itElementsSupprimes= elementsSupprimes.begin(); itElementsSupprimes <= elementsSupprimes.end(); itElementsSupprimes++){
        delete *itElementsSupprimes;
    }
    
#ifdef MAP
    cout << "Appel au destructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de ~CmdSuppression


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
