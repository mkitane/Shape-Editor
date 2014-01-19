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
// type Figure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Figure::stockerEtExecuter(Command *c){
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
}


vector<Command *> * Figure::getPtrHistorique()
{
    return &historique;
}
vector<Command *>::iterator * Figure::getPtritActuel()
{
    return &itActuel;
}
map<string, EltGeo *> * Figure::getPtrListeDesElements()
{
    return &listeDesElements;
}
//------------------------------------------------- Surcharge d'opérateurs
/*
 Figure & Figure::operator = ( const Figure & unFigure )
 // Algorithme :
 //
 {
 }
 *///----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Figure::Figure ( const Figure & unFigure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Figure>" << endl;
#endif
} //----- Fin de Figure (constructeur de copie)


Figure::Figure ( )
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
    vector<Command *>::iterator itHisto;
    for(itHisto = historique.begin() ; itHisto < historique.end(); itHisto++){
        delete *itHisto;
    }
    map<string, EltGeo *>::iterator itList;
    for(itList = listeDesElements.begin() ; itList != listeDesElements.end(); itList++){
        delete itList->second;
    }
    
#ifdef MAP
    cout << "Appel au destructeur de <Figure>" << endl;
#endif
} //----- Fin de ~Figure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
