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
#include "CmdClear.h"
#include "Rond.h"
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
            cout<<"Commande a effectuer : Cercle" << endl;
            //Il faut absolument 5 params
            if(nbParams(command) != 5){
                cout<<"Invalid number of Params" << endl;
                return errorCommand;
            }
            return ajouterCercle;
        }
        
        if(firstWord.compare("R") == 0 ){
            cout<<"Commande a effectuer : Rectangle" << endl;
            //Il faut absolument 6 params
            if(nbParams(command) != 6){
                cout<<"Invalid number of Params" << endl;
                return errorCommand;
            }
            return ajouterRectangle;
        }
        
        if(firstWord.compare("L") == 0 ){
            cout<<"Commande a effectuer : Ligne" << endl;
            //Il faut absolument 6 params
            if(nbParams(command) != 6){
                cout<<"Invalid number of Params" << endl;
                return errorCommand;
            }
            return ajouterLigne;
        }
        
        if(firstWord.compare("PL") == 0 ){
            cout<<"Commande a effectuer : Polyligne" << endl;
            //Il faut absolument un nombre pair de parametre superieur ou egal a 6
            int nb = nbParams(command);
            if(  (nb%2 != 0)  || (nb < 6) ){
                cout<<"Invalid number of Params" << endl;
                return errorCommand;
            }
            return ajouterPolyligne;
        }
        
        if(firstWord.compare("OA") == 0 ){
            cout<<"Commande a effectuer : Objet Agrege" << endl;
            //Il faut absolument un nombre de param supérieur OU EGAL a 2
            if(nbParams(command) <= 2){
                cout<<"Invalid number of Params" << endl;
                return errorCommand;
            }
            return ajouterObjetAgrege;
        }
        
        if(firstWord.compare("DELETE") == 0 ){
            cout<<"Commande a effectuer : DELETE" << endl;
            //Pas de restriction sur le nombre de params apparement (en supposant qu'il ya tjrs le premier)
            return suppression;
        }
        
        if(firstWord.compare("MOVE") == 0 ){
            cout<<"Commande a effectuer : MOVE" << endl;
            //Il faut absolument 4 params
            if(nbParams(command) != 4){
                cout<<"Invalid number of Params" << endl;
                return errorCommand;
            }
            return deplacement;
        }
        
        if(firstWord.compare("LIST") == 0 ){
            cout<<"Commande a effectuer : LIST" << endl;
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return enumeration;
        }
        
        if(firstWord.compare("UNDO") == 0 ){
            cout<<"Commande a effectuer : UNDO" << endl;
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return annuler;
        }
        
        if(firstWord.compare("REDO") == 0 ){
            cout<<"Commande a effectuer : REDO" << endl;
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return reprendre;
        }
        
        if(firstWord.compare("LOAD") == 0 ){
            cout<<"Commande a effectuer : LOAD" << endl;
            //Il faut absolument 2 params
            if(nbParams(command) != 2){
                cout<<"Invalid number of Params" << endl;
                return errorCommand;
            }
            return charger;
        }
        
        if(firstWord.compare("SAVE") == 0 ){
            cout<<"Commande a effectuer : SAVE" << endl;
            //Il faut absolument 2 params
            if(nbParams(command) != 2){
                cout<<"Invalid number of Params" << endl;
                return errorCommand;
            }
            return sauvegarder;
        }
        
        
        if(firstWord.compare("CLEAR") == 0 ){
            cout<<"Commande a effectuer : CLEAR" << endl;
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return vider;
        }
        
        if(firstWord.compare("EXIT") == 0 ){
            cout<<"Commande a effectuer : EXIT" << endl;
            //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
            return fermer;
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
            case vider:
            {
                c = new CmdClear(&(f->listeDesElements),parameters);
            }
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
                        cout<<"Cmd AjouterCercle is not valid" << endl;
                        return NULL;
                    }
                    
                    it++;
                    int y1;
                    
                    if(!Analyseur::checkIfNumber((*it).c_str(), &y1)){
                        cout<<"Cmd AjouterCercle is not valid" << endl;
                        return NULL;
                    }
                
                    
                    it++;
                    int r;
                    if(!Analyseur::checkIfNumber((*it).c_str(), &r)){
                        cout<<"Cmd AjouterCercle is not valid" << endl;
                        return NULL;
                    }
                
                    
                    cout<< "On cree un cercle de rayon " << r << " et de coordonnées (" << x1 << "," << y1 << ") " << endl;
                
                    a = new Rond(nom,r,x1,y1);
                
                
            }
                break;
            case ajouterLigne:
            {
                
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
                        cout<<"Mauvais ObjetAgrege" <<endl;
                        return NULL;
                    }
                    it++;
                    
                }
                
                
                a = new Agregat(nom,objetsOA);
            }
                break;
            case ajouterPolyligne:
            {
                
            }
                break;
            case ajouterRectangle:
            {
                
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
