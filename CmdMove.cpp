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
bool CmdMove::execute()
// Algorithme :
//          Verifier si les parametres rentres sont corrects
//          Decomposer notre objet si c'est un objet agrege
//          Verifier si tous les elements peuvent etre deplaces
//          Si vrai
//              Deplacer tous les elements
//          Sinon
//              Renvoyer faux
//          Fin si
//          Renvoyer vrai
{
    
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
            
            
            if(size==0){ // Pas besoin de decomposer si c'est un REDO les elements sont deja presents
                decomposer(itLE->second);
            }
            
            if(canBeMoved(x1, y1)){
                moveAllSimpleObjects(x1, y1);
            }else{
                cout << "ERR" << endl;
                cout << "#reached out of field " << endl; 
                return false;
            }
        
        }else{
            cout << "ERR" << endl;
            cout << "#invalid parameters" << endl;
            return false;
        }

    
    if(size == 0){ //Si c'est un redo, on ne reecrit pas deux fois OK
        cout << "OK" << endl;
    }
    return true;
}//----- Fin de Méthode

bool CmdMove::undo()
// Meme principe que execute
// en deplacant de -x et de -y
//
{
    
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
            
        }else{
            cout << "ERR" << endl;
            cout << "#invalid parameters" << endl;
            return false;
        }
        
        return true;
}//----- Fin de Méthode

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

void CmdMove::decomposer(EltGeo *e)
// Algorithme :
//  Decompose un ObjetAgrege en elements simples
//  et les rajoute a la listedeselement a bouger

{
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
    
}//----- Fin de Méthode


bool CmdMove::canBeMoved(long dx, long dy)
// Algorithme :
//  Verifie si tous les elements peuvent etre bouges avant de les bouger
{
    for(map<string,EltGeo *>::iterator it = listeElementsBouges.begin(); it!=listeElementsBouges.end() ; it++){
        if(!(it->second)->canBeMoved(dx, dy)){
            return false;
        }
    }
    
    return true;
}//----- Fin de Méthode


void CmdMove::moveAllSimpleObjects(long dx, long dy)
// Algorithme :
//   Deplace tous les elements simples
{
    for(map<string,EltGeo *>::iterator it = listeElementsBouges.begin(); it!=listeElementsBouges.end() ; it++){
        (it->second)->deplacer(dx, dy);
    }
}//----- Fin de Méthode


