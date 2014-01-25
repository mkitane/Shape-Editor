/*************************************************************************
 CmdRedo  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <CmdRedo> (fichier CmdRedo.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "CmdRedo.h"
#include "CmdSuppression.h"
#include "CmdClear.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool CmdRedo::execute()
// Algorithme :
//      On recupere la prochaine commande a partir de itActuel
//      On l'execute
{
    
    if(*itActuel+1 == historique->end()){ //si on se trouve a la fin, on ne dois pas faire de redo
        //cout<<"rien a redo" << endl;
        cout<< "ERR" << endl;
        return false;
    }
    
    Command *c = *(*itActuel+1);
    c->execute();
    (*itActuel)++;
    
    
    if (!dynamic_cast<CmdSuppression*>(**itActuel) && !dynamic_cast<CmdClear*>(**itActuel)) {
        cout << "OK" << endl;
    }
    return true;
}//----- Fin de Méthode

bool CmdRedo::undo()
// Algorithme :
//
{
    return false;
}//----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CmdRedo::CmdRedo(map<string,EltGeo *> *lE, vector<string> lP, vector<Command *> *histo, vector<Command *>::iterator *itAct) : Command(lE,lP), historique(histo), itActuel(itAct)
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdRedo>" << endl;
#endif
} //----- Fin de CmdRedo


CmdRedo::~CmdRedo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdRedo>" << endl;
#endif
} //----- Fin de ~CmdRedo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
