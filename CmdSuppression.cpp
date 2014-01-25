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
bool CmdSuppression::execute()
// Algorithme :
//   Pour tous les elements spécifies dans la liste des parametres
//      Le supprimer de la liste des elements
//      Le rajouter dans la liste backup elementsSupprimes
//      Si il est contenu dans des objets Agreges
//          supprimer son pointeur de ces objets agreges
//      FinSi
//  Fin Pour
{
    
    vector<string>::iterator it;
    for(it=listeParametres.begin(); it< listeParametres.end();it++){
        string nom = *it;
        
        //On garde une reference sur lelement en cas de UNDO
        map<string, EltGeo *>::iterator itLE;
        itLE = listeDesElements->find(nom);
        if(itLE != listeDesElements->end()){
            //Verifier si cest OA, si cest OA cest bon
            //Sinon On doit aussi enlever OA des OA Correspondants
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
}//----- Fin de Méthode

bool CmdSuppression::undo()
// Algorithme :
//      Pour tous les elements supprimes
//          Les remetre dans la liste des elements
//          Si ils sont contenus dans des objets aggreges
//              Remetre leur pointeur dans ces objets agreges
//          FinSi
//      FinPour
//
{
    
    vector<EltGeo *>::iterator itL;
    for(itL=elementsSupprimes.begin(); itL<elementsSupprimes.end();itL++){
        EltGeo *a = *itL;
        listeDesElements -> insert (pair<string,EltGeo*>(a->getNom(),a));
        addElementstoOAs(a);
        
    }

    elementsSupprimes.clear();
    return true;
}//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdSuppression::CmdSuppression(map<string,EltGeo *> *lE, vector<string> lP) : Command(lE,lP)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de CmdSuppression


CmdSuppression::~CmdSuppression ( )
// Algorithme :
//
{
    
    //On supprime les elements relié a la commande supprimée Si c'est pas !!!!un undo !! si c'est un undo, ne rien faire!!
    
    /*
    vector<EltGeo *>::iterator itElementsSupprimes;
    for(itElementsSupprimes= elementsSupprimes.begin(); itElementsSupprimes < elementsSupprimes.end(); itElementsSupprimes++){
        delete *itElementsSupprimes;
    }
    */
    
#ifdef MAP
    cout << "Appel au destructeur de <CmdSuppression>" << endl;
#endif
} //----- Fin de ~CmdSuppression


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void CmdSuppression::deleteElementFromOAs(EltGeo *e)
// Algorithme :
//  Pour tous les elements agreges de la liste des elements
//      Verifier si l'EltGeo est present dans l'objet agreges
//      Si oui
//          Supprimer le pointeur de LeltGeo dans l'objet agreges
//          Rajouter l'objet agreges a la liste des objets agreges ou EltGeo a ete supprime
//      FinSi
//  FinPour
{
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
    
}//----- Fin de Méthode

void CmdSuppression::addElementstoOAs(EltGeo *e)
// Algorithme :
//      Parcourir tous les elements agreges ou l'EltGeo a ete supprime
//      rajouter le pointeur de l'eltGeo aux objets agreges
{
    vector<Agregat *>::iterator it;
    for(it=fromWhereDeleted.begin(); it<fromWhereDeleted.end();it++){
        (*it)->addElt(e);
    }
}//----- Fin de Méthode

