//
//  main.cpp
//  TPHeritage
//
//  Created by Mehdi Kitane on 05/01/2014.
//  Copyright (c) 2014 B3424. All rights reserved.
//


//On accepte que les Maj pour l'instant
#include <iostream>
#include <sstream>
#include <stdlib.h>     /* strtol */
#include "Figure.h"
#include "CmdAjouterCercle.h"
#include "CmdSuppression.h"


using namespace std;

typedef enum{
    ajouterCercle,
    ajouterRectangle,
    ajouterLigne,
    ajouterPolyligne,
    ajouterObjetAgrege,
    suppression,
    deplacement,
    enumeration,
    annuler,
    reprendre,
    charger,
    sauvegarder,
    vider,
    fermer
}TypeCommand;



bool checkIfNumber(string supposedNumber){
    //Accepte un espace avant, mais pas apres
    char* end;
    strtol(supposedNumber.c_str(),&end,10);
    if (*end){
        cerr<<"You need to specify an integer number" <<endl;
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
bool analyseTypeCommande(string command){
    string firstWord;
    stringstream in(command);
    getline(in, firstWord, ' '); //On decompose le mot suivant l'espace

    
    
    //Dans les commentaires, on compte aussi le premier param, càd, le premier Param ex "C"
    if(firstWord.compare("C") == 0 ){
        cout<<"Commande a effectuer : Cercle" << endl;
        //Il faut absolument 5 params
        if(nbParams(command) != 5){
            cout<<"Invalid number of Params" << endl;
            return false;
        }
        return true;
    }
    
    if(firstWord.compare("R") == 0 ){
        cout<<"Commande a effectuer : Rectangle" << endl;
        //Il faut absolument 6 params
        if(nbParams(command) != 6){
            cout<<"Invalid number of Params" << endl;
            return false;
        }
        return true;
    }
    
    if(firstWord.compare("L") == 0 ){
        cout<<"Commande a effectuer : Ligne" << endl;
        //Il faut absolument 6 params
        if(nbParams(command) != 6){
            cout<<"Invalid number of Params" << endl;
            return false;
        }
        return true;
    }
    
    if(firstWord.compare("PL") == 0 ){
        cout<<"Commande a effectuer : Polyligne" << endl;
        //Il faut absolument un nombre pair de parametre superieur ou egal a 6
        int nb = nbParams(command);
        if(  (nb%2 != 0)  || (nb < 6) ){
            cout<<"Invalid number of Params" << endl;
            return false;
        }
        return true;
    }
    
    if(firstWord.compare("OA") == 0 ){
        cout<<"Commande a effectuer : Objet Agrege" << endl;
        //Il faut absolument un nombre de param supérieur OU EGAL a 2
        if(nbParams(command) >= 2){
            cout<<"Invalid number of Params" << endl;
            return false;
        }
        return true;
    }
    
    if(firstWord.compare("DELETE") == 0 ){
        cout<<"Commande a effectuer : DELETE" << endl;
        //Pas de restriction sur le nombre de params apparement (en supposant qu'il ya tjrs le premier)
        return true;
    }
    
    if(firstWord.compare("MOVE") == 0 ){
        cout<<"Commande a effectuer : MOVE" << endl;
        //Il faut absolument 4 params
        if(nbParams(command) != 4){
            cout<<"Invalid number of Params" << endl;
            return false;
        }
        return true;
    }
    
    if(firstWord.compare("LIST") == 0 ){
        cout<<"Commande a effectuer : LIST" << endl;
        //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
        return true;
    }
    
    if(firstWord.compare("UNDO") == 0 ){
        cout<<"Commande a effectuer : UNDO" << endl;
        //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
        return true;
    }
    
    if(firstWord.compare("REDO") == 0 ){
        cout<<"Commande a effectuer : REDO" << endl;
        //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
        return true;
    }
    
    if(firstWord.compare("LOAD") == 0 ){
        cout<<"Commande a effectuer : LOAD" << endl;
        //Il faut absolument 2 params
        if(nbParams(command) != 2){
            cout<<"Invalid number of Params" << endl;
            return false;
        }
        return true;
    }
    
    if(firstWord.compare("SAVE") == 0 ){
        cout<<"Commande a effectuer : SAVE" << endl;
        //Il faut absolument 2 params
        if(nbParams(command) != 2){
            cout<<"Invalid number of Params" << endl;
            return false;
        }
        return true;
    }
    
    
    if(firstWord.compare("CLEAR") == 0 ){
        cout<<"Commande a effectuer : CLEAR" << endl;
        //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
        return true;
    }
    
    if(firstWord.compare("EXIT") == 0 ){
        cout<<"Commande a effectuer : EXIT" << endl;
        //Il faut aucun autre param, ou alors on s'en fout et on l'ignore
        exit(0);
        return true;
    }
    
    return false;
}
void remplirParametres(vector<string> * parameters, TypeCommand *t, const string command){
    std::istringstream iss(command);
    
    std::string line;
    
    
    getline(iss, line,' '); // Permet de ne pas prendre en compte la premiere partie
                            // Cad le nom de la commande
    
    while (getline(iss, line,' '))
    {
        // Do something with `line
        cout<< "le parametre a push back est " << line << endl;
        parameters->push_back(line);
    }
}
//Command & createCommand(TypeCommand t, vector<string> parameters){
  
    
//}

int main(int argc, const char * argv[])
{

    // insert code here...

    cout << "Hello World" << endl ;
    
    
    Figure f;
    
    while(true){
        //on recupere la commande de l'utilisateur
        char commandEntry[80];
        vector <string> parameters ;
        TypeCommand t;
        
        
        cin.getline(commandEntry, sizeof(commandEntry));
       
        
        if(analyseTypeCommande(commandEntry)){
            
            remplirParametres(&parameters, &t, commandEntry);

            
            if(t == ajouterCercle){
                if(t == ajouterCercle){
                    CmdAjouterCercle *c = new CmdAjouterCercle(&f.listeDesElements,parameters);
                    f.stockerEtExecuter(c); 
                }else if(t == suppression){
                    CmdSuppression *c = new CmdSuppression(&f.listeDesElements, parameters);
                    f.stockerEtExecuter(c);
                }
                
            }
            
        }else{
            cout<<"Erreur Command"<<endl;
        }
       
        
        //On cree la commande en fonction des parametres entres
        
        
    
    }
    return 0;
}

