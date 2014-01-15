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
#include "Analyseur.h"


using namespace std;
using namespace Analyseur;

int main(int argc, const char * argv[])
{

    // insert code here...

    cout << "Hello World" << endl ;
    
    
    Figure f;
    
    while(true){
        //on recupere la commande de l'utilisateur
        string commandEntry;
        vector <string> parameters ;
        TypeCommand t;
        
        
        getline(cin, commandEntry);
       
        t = analyseCommand(commandEntry);
        
        if( t!= errorCommand ){
            
            remplirParametres(&parameters, commandEntry);

            Command *c = createCommand(t, parameters, &f);
            f.stockerEtExecuter(c);

            
        }else{
            cout<<"Erreur Command"<<endl;
        }
       
        
        //On cree la commande en fonction des parametres entres
        
        
    
    }
    return 0;
}

