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

void CmdMove::decomposer(EltGeo *e){
    if (dynamic_cast<Agregat*>(e)) {
        Agregat *agg = dynamic_cast<Agregat*>(e);
        for(map<string, EltGeo *>::iterator itAgg = agg->getListeltGeo()->begin() ; itAgg != agg->getListeltGeo()->end(); itAgg++){
            if (dynamic_cast<Agregat*>(itAgg->second)) {
                Agregat *second = dynamic_cast<Agregat*>(itAgg->second);
                decomposer(second);
            }else{
                listeElementsBouges.insert(pair<string, EltGeo *>(itAgg->second->getNom(),itAgg->second));
            }
            
        }

    }else{
        listeElementsBouges.insert(pair<string, EltGeo *>(e->getNom(),e));
    }
    
}

void CmdMove::moveAllSimpleObjects(long dx, long dy){
    for(map<string,EltGeo *>::iterator it = listeElementsBouges.begin(); it!=listeElementsBouges.end() ; it++){
        (it->second)->deplacer(dx, dy);
    }
}
bool CmdMove::execute(){
    
    unsigned long size = listeElementsBouges.size();
    
    vector<string>::iterator it;
    it=listeParametres.begin();

        string nom = *it;
    
        map<string, EltGeo *>::iterator itLE;
        itLE = listeDesElements->find(nom);
    
        if(itLE != listeDesElements->end()){
            it++;
            long x1;
            if(!Analyseur::checkIfNumber((*it).c_str(), &x1)){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return false;
            }
            
            it++;
            long y1;
            
            if(!Analyseur::checkIfNumber((*it).c_str(), &y1)){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return false;
            }
            
            
            if(size==0){ // Pas besoin de decomposer si c'est un REDO
                decomposer(itLE->second);
            }
            moveAllSimpleObjects(x1, y1);

#pragma -mark a faire quand on a les classes ELT Geo
        
        }else{
            cout << "ERR" << endl;
            cout << "#invalid parameters" << endl;
            return false;
        }

    
    if(size == 0){ // on verifie si les elements n'ont pas deja ete ajoutes si oui, pas besoin de refaire
        cout << "OK" << endl;
    }
    return true;
}

bool CmdMove::undo(){
    
        vector<string>::iterator it;
        it=listeParametres.begin();
        
        string nom = *it;
        
        map<string, EltGeo *>::iterator itLE;
        itLE = listeDesElements->find(nom);
        
        if(itLE != listeDesElements->end()){
            it++;
            long x1;
            if(!Analyseur::checkIfNumber((*it).c_str(), &x1)){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return false;
            }
            
            it++;
            long y1;
            
            if(!Analyseur::checkIfNumber((*it).c_str(), &y1)){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return false;
            }
            
            
            x1= -1 * x1 ;
            y1 = -1 *y1 ;
            
            
            decomposer(itLE->second);
            moveAllSimpleObjects(x1, y1);
            
#pragma -mark a faire quand on a les classes ELT Geo
            
        }else{
            cout << "ERR" << endl;
            cout << "#invalid parameters" << endl;
            return false;
        }
        
        return true;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdMove::CmdMove(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
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
