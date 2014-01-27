/*************************************************************************
 Figure  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <Figure> (fichier Figure.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "Figure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Figure::stockerEtExecuter(Command *c)
// Algorithme :

//      Si la commande c peut etre stockee (canDoAnUndo)
//          Si le curseur de l'historique n'est pas sur la fin
//              On supprime les commandes suivantes de l'historique pour pouvoir mettre notre commande cen tete de liste
//          Fin Si
//          Si l'execution de la commande c s'est bien deroulee
//              On stocke la commande dans l'historique
//          Sinon
//              On supprime son pointeur
//          Fin si
//      Sinon
//          On l'execute
//          On supprime son pointeur
//      Fin si
{
    if(c->canDoAnUndo()){
        
        if(itActuel != (historique.end() -1) ){
            //TODO: NE PAS OUBLIER DE DELETE AVANT D4EFFACER
            vector<Command *>::iterator i;
            for(i=(itActuel+1); i< historique.end();i++){
                //cout << "On dleete la commande " << *i << endl ;
                //Ne pas oublier de revoir l'historique a pas plus de 20 entrees
                delete *i;
            }
            historique.erase(itActuel+1, historique.end());
        }
        
        if(c->execute()){
            historique.push_back(c);
            itActuel= historique.end() - 1;
        }else{
            delete c; 
        }
    }else{
        c->execute();
        delete c;
    }
}//----- Fin de Méthode


vector<Command *> * Figure::getPtrHistorique()
// Algorithme :
//

{
    return &historique;
}//----- Fin de Méthode

vector<Command *>::iterator * Figure::getPtritActuel()
// Algorithme :
//
{
    return &itActuel;
}//----- Fin de Méthode

map<string, EltGeo *> * Figure::getPtrListeDesElements()
// Algorithme :
//
{
    return &listeDesElements;
}//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Figure::Figure ( const Figure & unFigure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Figure>" << endl;
#endif
} //----- Fin de Figure (constructeur de copie)


Figure::Figure ( ) : run(true)
// Algorithme :
//
{
    itActuel = historique.end() - 1 ;
#ifdef MAP
    cout << "Appel au constructeur de <Figure>" << endl;
#endif
} //----- Fin de Figure


Figure::~Figure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Figure>" << endl;
#endif
    vector<Command *>::iterator itHisto;
    for(itHisto = historique.begin() ; itHisto < historique.end(); itHisto++){
        delete *itHisto;
    }
    
    /*
    map<string, EltGeo *>::iterator itList;
    for(itList = listeDesElements.begin() ; itList != listeDesElements.end(); itList++){
        delete itList->second;
    }
     */
    

} //----- Fin de ~Figure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
