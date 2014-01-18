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
#include "CmdExit.h"
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
    
    
    bool checkIfNumber(string supposedNumber, int * number ){
        //Accepte un espace avant, mais pas apres
        char* end;
        *number = (int)strtol(supposedNumber.c_str(),&end,10);
        if (*end){
            return false;
        }
        
        return true;
    }
    int nbParams(string command){
        int nb = 1; // Car on considere qu'il n'y a pas d'espace apres le dernier char
        
        for(int i=0; i < command.size(); i++){
            if(command.at(i) == ' '){
                nb++;
            }
        }
        return nb;
    }
    TypeCommand analyseCommand(string command){
        string firstWord;
        stringstream in(command);
        getline(in, firstWord, ' '); //On decompose le mot suivant l'espace
        
        
        
        //Dans les commentaires, on compte aussi le premier param, càd, le premier Param ex "C"
        if(firstWord.compare("C") == 0 ){
            //Il faut absolument 5 params
            if(nbParams(command) != 5){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return errorCommand;
            }
            return ajouterCercle;
        }
        
        if(firstWord.compare("R") == 0 ){
            //Il faut absolument 6 params
            if(nbParams(command) != 6){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return errorCommand;
            }
            return ajouterRectangle;
        }
        
        if(firstWord.compare("L") == 0 ){
            //Il faut absolument 6 params
            if(nbParams(command) != 6){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return errorCommand;
            }
            return ajouterLigne;
        }
        
        if(firstWord.compare("PL") == 0 ){
            //Il faut absolument un nombre pair de parametre superieur ou egal a 6
            int nb = nbParams(command);
            if(  (nb%2 != 0)  || (nb < 6) ){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return errorCommand;
            }
            return ajouterPolyligne;
        }
        
        if(firstWord.compare("OA") == 0 ){
            //Il faut absolument un nombre de param supérieur OU EGAL a 2
            if(nbParams(command) <= 2){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return errorCommand;
            }
            return ajouterObjetAgrege;
        }
        
        if(firstWord.compare("DELETE") == 0 ){
            //Pas de restriction sur le nombre de params apparement (en supposant qu'il ya tjrs le premier)
            return suppression;
        }
        
        if(firstWord.compare("MOVE") == 0 ){
            //Il faut absolument 4 params
            if(nbParams(command) != 4){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return errorCommand;
            }
            return deplacement;
        }
        
        if(firstWord.compare("LIST") == 0 ){
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return enumeration;
        }
        
        if(firstWord.compare("UNDO") == 0 ){
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return annuler;
        }
        
        if(firstWord.compare("REDO") == 0 ){
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return reprendre;
        }
        
        if(firstWord.compare("LOAD") == 0 ){
            //Il faut absolument 2 params
            if(nbParams(command) != 2){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return errorCommand;
            }
            return charger;
        }
        
        if(firstWord.compare("SAVE") == 0 ){
            //Il faut absolument 2 params
            if(nbParams(command) != 2){
                cout << "ERR" << endl;
                cout << "#invalid parameters" << endl;
                return errorCommand;
            }
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
        if(firstWord.at(0) == '#'){
            return commentaire;
        }
        return errorCommand;
    }
    void remplirParametres(vector<string> * parameters, const string command){
        std::istringstream iss(command);
        
        std::string line;
        
        
        getline(iss, line,' '); // Permet de ne pas prendre en compte la premiere partie
        // Cad le nom de la commande
        
        while (getline(iss, line,' '))
        {
            //cout<< "le parametre a push back est " << line << endl;
            parameters->push_back(line);
        }
    }
    Command * createCommand(TypeCommand t, vector<string> parameters, Figure *f){
        
        Command *c;
        switch (t) {
            case ajouterCercle:
            {
                c = new CmdAjouterCercle(&(f->listeDesElements),parameters);
            }
                break;
                
            case suppression:
            {
                c = new CmdSuppression(&(f->listeDesElements), parameters);
            }
                break;
            case annuler:
            {
                c = new CmdUndo(&(f->listeDesElements), parameters, &(f->historique), &(f->itActuel));
            }
                break;
            case reprendre:
            {
                c = new CmdRedo(&(f->listeDesElements), parameters, &(f->historique), &(f->itActuel));
            }
                break;
            case sauvegarder:
            {
                c = new CmdSave(&(f->listeDesElements), parameters);
            }
                break;
            case fermer:
            {
                c = new CmdExit(&(f->listeDesElements), parameters); 
            }
                break;
            case charger:
            {
                c = new CmdLoad(&(f->listeDesElements),parameters);
            }
                break;
            case enumeration:
            {
                c = new CmdList(&(f->listeDesElements),parameters);
            }
                break;
            case deplacement:
            {
                c = new CmdMove(&(f->listeDesElements), parameters); 
            }
                break; 
            case ajouterObjetAgrege:
            {
                c = new CmdAjouterOA(&(f->listeDesElements),parameters);
            }
                break;
            case ajouterRectangle:
            {
                c = new CmdAjouterRectangle(&(f->listeDesElements),parameters);
            }
                break;
            case ajouterLigne:
            {
                c = new CmdAjouterLigne(&(f->listeDesElements),parameters);
            }
                break;
            case ajouterPolyligne:
            {
                c = new CmdAjouterPolyLigne(&(f->listeDesElements),parameters);
            }
                break;
            case vider:
            {
                c = new CmdClear(&(f->listeDesElements),parameters);
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
        }
        
        return c; 
    }
    EltGeo* createObjectWithParameters(TypeCommand t, vector<string> parameters,map<string,EltGeo *> *listeDesElements){
        vector<string>::iterator it;
        
        it= parameters.begin();
        string nom = *it;
        
        
        EltGeo *a = NULL;
        switch (t) {
            case ajouterCercle:
            {
                    it++;
                    int x1;
                    if(!Analyseur::checkIfNumber((*it).c_str(), &x1)){
                        cout << "ERR" << endl;
                        cout << "#invalid parameters" << endl;
                        return NULL;
                    }
                    
                    it++;
                    int y1;
                    
                    if(!Analyseur::checkIfNumber((*it).c_str(), &y1)){
                        cout << "ERR" << endl;
                        cout << "#invalid parameters" << endl;
                        return NULL;
                    }
                
                    
                    it++;
                    int r;
                    if(!Analyseur::checkIfNumber((*it).c_str(), &r)){
                        cout << "ERR" << endl;
                        cout << "#invalid parameters" << endl;
                        return NULL;
                    }
                
                    a = new Rond(nom,r,x1,y1);
                
                
            }
                break;
            case ajouterLigne:
            {
                it++;
                int x1;
                if(!Analyseur::checkIfNumber((*it).c_str(), &x1)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                it++;
                int y1;
                
                if(!Analyseur::checkIfNumber((*it).c_str(), &y1)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                
                it++;
                int x2;
                if(!Analyseur::checkIfNumber((*it).c_str(), &x2)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                it++;
                int y2;
                
                if(!Analyseur::checkIfNumber((*it).c_str(), &y2)){
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
                        objetsOA.insert(pair<string,EltGeo *>(e->Nom,e));
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
                vector<int> xy;
                
                it++;
                while(it<parameters.end()){
                    int x1;
                    if(!Analyseur::checkIfNumber((*it).c_str(), &x1)){
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
                int x1;
                if(!Analyseur::checkIfNumber((*it).c_str(), &x1)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                it++;
                int y1;
                
                if(!Analyseur::checkIfNumber((*it).c_str(), &y1)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                
                it++;
                int x2;
                if(!Analyseur::checkIfNumber((*it).c_str(), &x2)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                it++;
                int y2;
                
                if(!Analyseur::checkIfNumber((*it).c_str(), &y2)){
                    cout << "ERR" << endl;
                    cout << "#invalid parameters" << endl;
                    return NULL;
                }
                
                a = new Rectangle(nom,x1,y1,x2,y2);

            }
                break;
            default:
                break;
        }
        return a;
    }
    
}


//}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
