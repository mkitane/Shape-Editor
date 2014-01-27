/*************************************************************************
 Analyseur  -  description
 -------------------
 début                : 20 déc. 2013
 copyright            : (C) 2013 par mkitane
 *************************************************************************/

//---------- Réalisation de la classe <Analyseur> (fichier Analyseur.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "Analyseur.h"
#include "CmdAjouterCercle.h"
#include "CmdSuppression.h"
#include "CmdUndo.h"
#include "CmdRedo.h"
#include "CmdSave.h"
#include "CmdLoad.h"
#include "CmdList.h"
#include "CmdMove.h"
#include "CmdAjouterOA.h"
#include "CmdAjouterLigne.h"
#include "CmdAjouterPolyLigne.h"
#include "CmdAjouterRectangle.h"
#include "CmdClear.h"
#include "Rond.h"
#include "Rectangle.h"
#include "Polyligne.h"
#include "Ligne.h"
#include "Agregat.h"

namespace Analyseur {

    bool depasserBorne(long a, long b)
    // Algorithme :
    //    Effectue la somme de a et b
    //    Si a et b sont positif et leur somme est negative
    //      On a depassé l'espace des longs
    //      renvoyer vrai
    //    Si a et b sont negatifs et leur somme est positive
    //      On a depassé l'espace des longs
    //      renvoyer faux
    {
        long c = a + b ;
        if( (a > 0 && b > 0 &&  c < 0)  || (a < 0 && b < 0 &&  c > 0)  ){
            return true;
        }
        return false;
        
    }//----- Fin de Méthode
    
    
    bool checkIfNumber(string supposedNumber, long * number )
    // Algorithme :
    //
    {
        //Accepte un espace avant, mais pas apres
        char* end;
        *number = strtol(supposedNumber.c_str(),&end,10);
        if (*end){
            return false;
        }
        if(*number == LONG_MAX || *number == LONG_MIN){
            return false; 
        }
        return true;
    }//----- Fin de Méthode
    
    
    bool nbParams(TypeCommand t, int nbParams)
    // Algorithme :
    //  Verifie si le nombre despace est le bon en fonction du type
    {
        
        nbParams ++; //On recupere le nombre de parametres, on teste sur le nombre total delements de la commande, donc +1
        
        switch (t) {
            case ajouterCercle:
            {
                //Il faut absolument 5 params
                if(nbParams != 5){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return false;
                }
                return true;
            }
                break;
            case ajouterRectangle:
            {
                //Il faut absolument 6 params
                if(nbParams != 6){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return false;
                }
                return true;
            }
                break;
            case ajouterLigne:
            {
                //Il faut absolument 6 params
                if(nbParams!= 6){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return false;
                }
                return true;
            }
                break;
            case ajouterPolyligne:
            {
                 //Il faut absolument un nombre pair de parametre superieur ou egal a 6
                if(  (nbParams%2 != 0)  || (nbParams < 6) ){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return false;
                }
                return true;
            }
                break;
            case ajouterObjetAgrege:
            {
                 //Il faut absolument un nombre de param supérieur OU EGAL a 2
                if(nbParams <= 2){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return false;
                }
                return true;
            }
                break;
            case suppression:
            {
                return true;
            }
                break;
            case deplacement:
            {
                //Il faut absolument 4 params
                if(nbParams != 4){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return false;
                }
                return true;
            }
                break;
            case enumeration:
            {
                //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
                return true;

            }
                break;
            case annuler:
            {
                 //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
                return true;

            }
                break;
            case reprendre:
            {
                   //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
                return true;

            }
                break;
            case charger:
            {
                //Il faut absolument 2 params
                if(nbParams != 2){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return false;
                }
                return true;

            }
                break;
            case sauvegarder:
            {
                //Il faut absolument 2 params
                if(nbParams != 2){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return false;
                }
                return true;

            }
                break;
            case vider:
            {
                //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
                return true;

            }
                break;
            case fermer:
            {
                //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
                return true;

            }
                break;
            case commentaire:
            {
                return false;

            }
                break;
            case errorCommand:
            {
                return false;

            }
                break;
        }
        
        return true;
    }//----- Fin de Méthode
    
    
    TypeCommand analyseCommand(string command)
    // Algorithme :
    //  Si la premiere lettre du string correpond a un des types predefini
    //      Renvoyer type correspondant
    //  Sinon
    //      Si c'est un commentaire renvoyer type commentaire
    //  Sinon
    //      renvoyer type erreur
    //  FinSi
    {
        string firstWord;
        stringstream in(command);
        getline(in, firstWord, ' '); //On decompose le mot suivant l'espace
        
        
        
        //Dans les commentaires, on compte aussi le premier param, càd, le premier Param ex "C"
        if(firstWord.compare("C") == 0 ){
            return ajouterCercle;
        }
        
        if(firstWord.compare("R") == 0 ){
            return ajouterRectangle;
        }
        
        if(firstWord.compare("L") == 0 ){
            return ajouterLigne;
        }
        
        if(firstWord.compare("PL") == 0 ){
            return ajouterPolyligne;
        }
        
        if(firstWord.compare("OA") == 0 ){
            return ajouterObjetAgrege;
        }
        
        if(firstWord.compare("DELETE") == 0 ){
            return suppression;
        }
        
        if(firstWord.compare("MOVE") == 0 ){
            return deplacement;
        }
        
        if(firstWord.compare("LIST") == 0 ){
            return enumeration;
        }
        
        if(firstWord.compare("UNDO") == 0 ){
            return annuler;
        }
        
        if(firstWord.compare("REDO") == 0 ){
            return reprendre;
        }
        
        if(firstWord.compare("LOAD") == 0 ){
            return charger;
        }
        
        if(firstWord.compare("SAVE") == 0 ){
            return sauvegarder;
        }
        
        
        if(firstWord.compare("CLEAR") == 0 ){
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return vider;
        }
        
        if(firstWord.compare("EXIT") == 0 ){
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return fermer;
        }
        
        //On verifie si c'est un commentaire
        if(firstWord.size() != 0 && firstWord.at(0) == '#'){
            return commentaire;
        }
        cout << "ERR" << endl; 
        return errorCommand;
    }//----- Fin de Méthode
    
    
    void remplirParametres(vector<string> * parameters, const string command)
    // Algorithme :
    //      Decompose le string en fonction des espaces
    //
    {
        std::istringstream iss(command);
        
        std::string line;
        
        
        getline(iss, line,' '); // Permet de ne pas prendre en compte la premiere partie
        // Cad le nom de la commande
        
        while (getline(iss, line,' '))
        {
            //cout<< "le parametre a push back est " << line << endl;
            parameters->push_back(line);
        }
        
    }//----- Fin de Méthode
    
    
    Command * createCommand(TypeCommand t, vector<string> parameters, Figure *f)
    // Algorithme :
    //      Si Type = un des types possibles
    //          Creer commande correspondante
    //          Renvoyer commande
    //      Sinon
    //          Renvoyer pointeur null
    //      FinSi
    {
        
        Command *c;
        switch (t) {
            case ajouterCercle:
            {
                c = new CmdAjouterCercle(f->getPtrListeDesElements(),parameters);
            }
                break;
                
            case suppression:
            {
                c = new CmdSuppression(f->getPtrListeDesElements(), parameters);
            }
                break;
            case annuler:
            {
                c = new CmdUndo(f->getPtrListeDesElements(), parameters, f->getPtrHistorique(),f->getPtritActuel());
            }
                break;
            case reprendre:
            {
                c = new CmdRedo(f->getPtrListeDesElements(), parameters, f->getPtrHistorique(), f->getPtritActuel());
            }
                break;
            case sauvegarder:
            {
                c = new CmdSave(f->getPtrListeDesElements(), parameters);
            }
                break;
            case charger:
            {
                c = new CmdLoad(f->getPtrListeDesElements(),parameters);
            }
                break;
            case enumeration:
            {
                c = new CmdList(f->getPtrListeDesElements(),parameters);
            }
                break;
            case deplacement:
            {
                c = new CmdMove(f->getPtrListeDesElements(), parameters);
            }
                break; 
            case ajouterObjetAgrege:
            {
                c = new CmdAjouterOA(f->getPtrListeDesElements(),parameters);
            }
                break;
            case ajouterRectangle:
            {
                c = new CmdAjouterRectangle(f->getPtrListeDesElements(),parameters);
            }
                break;
            case ajouterLigne:
            {
                c = new CmdAjouterLigne(f->getPtrListeDesElements(),parameters);
            }
                break;
            case ajouterPolyligne:
            {
                c = new CmdAjouterPolyLigne(f->getPtrListeDesElements(),parameters);
            }
                break;
            case vider:
            {
                c = new CmdClear(f->getPtrListeDesElements(),parameters);
            }
                break;
            case fermer:
            {
                f->setRun(false);
                c = NULL; 
            }
                break;
            case commentaire:
            {
                c= NULL;
            }
            case errorCommand:
            {
                c = NULL;
            }
                break;
            default:
            {
                c = NULL;
            }
                break;

        }
        
        return c; 
    }//----- Fin de Méthode
    
    
    EltGeo * createObjectWithParameters(TypeCommand t, vector<string> parameters,map<string,EltGeo *> *listeDesElements)
    // Algorithme :
    //      Si Type = ajouterCercle ou autre EltGeo
    //          Verifier que les parametres sont valides
    //          Si oui
    //              Renvoyer pointeur vers EltGeo Cree
    //          Sinon
    //              Renvoyer pointeur null
    //          FinSi
    //      Sinon
    //          Renvoyer pointeur null
    //      FinSi
    {
        vector<string>::iterator it;
        
        it= parameters.begin();
        string nom = *it;
        
        
        EltGeo *a = NULL;
        switch (t) {
            case ajouterCercle:
            {
                    it++;
                    long x1;
                    if(!Analyseur::checkIfNumber((*it), &x1)){
                        cout << "ERR" << endl;
                        cout << "#invalid parameters" << endl;
                        return NULL;
                    }
                    
                    it++;
                    long y1;
                    
                    if(!Analyseur::checkIfNumber((*it), &y1)){
                        cout << "ERR" << endl;
                        cout << "#invalid parameters" << endl;
                        return NULL;
                    }
                
                    
                    it++;
                    long r;
                    if(!Analyseur::checkIfNumber((*it), &r)){
                        cout << "ERR" << endl;
                        cout << "#invalid parameters" << endl;
                        return NULL;
                    }
                
                
                    //On verifie si x+r et y+r ne dépassent pas les limites aussi
                    /* long extremiteDroite = x1 + r;
                    long extremiteGauche = x1 - r ;
                    long extremiteHaut = y1 + r ;
                    long extremiteBas = y1 - r ;
                    */
                
                
                    if(depasserBorne(x1, r) || depasserBorne(x1, -r) || depasserBorne(y1, r) || depasserBorne(y1, -r)){
                        cout << "ERR" << endl;
                        cout << "#Circle is out of field" << endl;
                        return NULL;
                    }
                
                                
                    a = new Rond(nom,r,x1,y1);
                
                
            }
                break;
            case ajouterLigne:
            {
                it++;
                long x1;
                if(!Analyseur::checkIfNumber((*it), &x1)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                it++;
                long y1;
                
                if(!Analyseur::checkIfNumber((*it), &y1)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                
                it++;
                long x2;
                if(!Analyseur::checkIfNumber((*it), &x2)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                it++;
                long y2;
                
                if(!Analyseur::checkIfNumber((*it), &y2)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                
                a = new Ligne(nom,x1,y1,x2,y2);

            }
                break;
            case ajouterObjetAgrege:
            {
                map<string, EltGeo*> objetsOA;
                
                it++;
                while(it<parameters.end()){
                    string nomEltGeo = *it;
                    
                    map<string, EltGeo *>::iterator itLE;
                    itLE = listeDesElements->find(nomEltGeo);
                    if(itLE != listeDesElements->end()){
                        EltGeo *e = itLE->second;
                        objetsOA.insert(pair<string,EltGeo *>(e->getNom(),e));
                    }else{
                        cout << "ERR" << endl;
                        return NULL;
                    }
                    it++;
                    
                }
                
                
                a = new Agregat(nom,objetsOA);
            }
                break;
            case ajouterPolyligne:
            {
                vector<long> xy;
                
                it++;
                while(it<parameters.end()){
                    long x1;
                    if(!Analyseur::checkIfNumber((*it), &x1)){
                        cout << "ERR" << endl;
                        cout << "#invalid parameters" << endl;
                        return NULL;
                    }
                    
                    xy.push_back(x1);
                    it++;
                }
                
                
                a = new Polyligne(nom,xy);
            }
                break;
            case ajouterRectangle:
            {
                it++;
                long x1;
                if(!Analyseur::checkIfNumber((*it), &x1)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                it++;
                long y1;
                
                if(!Analyseur::checkIfNumber((*it), &y1)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                
                it++;
                long x2;
                if(!Analyseur::checkIfNumber((*it), &x2)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                it++;
                long y2;
                
                if(!Analyseur::checkIfNumber((*it), &y2)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                a = new Rectangle(nom,x1,y1,x2,y2);

            }
                break;
            default:
            {
                a = NULL;
            }
                break;
        }
        return a;
    }//----- Fin de Méthode
    
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
