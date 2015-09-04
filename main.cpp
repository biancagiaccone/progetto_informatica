//
//  main.cpp
//  esame_prelz
//
//  Created by Ilaria Cazzaniga on 02/09/15.
//  Copyright (c) 2015 Ilaria Cazzaniga. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cerrno>
#include <system_error>
//#include "users.h"
#include "books.h"
#include <sqlite3.h>
#include "f_database.h"

//volevo che le funsioni per il db stessero in un .h a parte, ma se le tolgo da qui non le legge più....perchè?? :(
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char * argv[]) {
  
    //errore comando per eseguire
    /*if (argc <= 1)
    {
        std::cerr << "Usage: " << argv[0] << " <books file name to read>"
        << std::endl;
        return 1;
    }*/

    
    //variabili per gestione db
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    
    //apro db
    rc = sqlite3_open("test.db", &db);
    
    //verifico apertura db a schermo
    if( rc )
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cerr << "Opened database successfully" << std::endl;
    }
    
    //implemento i template libri
    typedef book<double> book_t; //book_t è una classe di tipo book con book_code di tipo double
    typedef std::vector<book_t> book_container_t; //book_container_t è un tipo "vettore di classi book_t"

    book_container_t books; //vettore di classi book_t
    
    std::string a, t, e, gen;
    double bc, c;
    int q, aq;
    genre g;
    
    //devo capire condizione per finire l'input (da tastiera)
    int i=1;
    std::cout << "Inserisci i dati dei record." << std::endl;
    while (1) {
        
        std::cout << "Book code: ";
        std::cin >> bc;
        std::cout << std::endl << "Author(s): ";
        std::cin >> a;
        std::cout << std::endl << "Title: ";
        std::cin >> t;
        std::cout << std::endl << "Genre: ";
        std::istringstream gen;
        gen >> g;
        std::cout << std::endl << "Edition: ";
        std::cin >> e;
        std::cout << std::endl << "Cost: ";
        std::cin >> c;
        std::cout << std::endl << "Quantity: ";
        std::cin >> q;
        
        book_t b(&bc, a, t, g, e, c, q, q);
    
        
        
        //db:inserisco elementi in BOOKS
        sql = "INSERT INTO BOOKS (ID,AUTHOR,TITLE,EDITION,PRICE,QUANTITY,AVAILABLE_QUANTITY) "  \
        "VALUES (b.book_code, b.get_author, b.get_title, b.get_edition, b.get_cost, b. get_quantity, b.get_a_quantity ); " ;
    
        // Execute SQL statement
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
        if( rc != SQLITE_OK )
        {
            std::cerr << "SQL error: " << zErrMsg << std::endl;
            sqlite3_free(zErrMsg);
        }
        else
        {
            std::cerr << "Record #" << i << "created successfully" << std::endl;
        }
        
        i++;
    }
    
    
    
    
    
    
    
    
    
    //controllo quanti elementi legge -- serve?
    std::cout << "Successfully read " << books.size() << " elements."
    << std::endl;
    
    
    
    
    

    sqlite3_close(db);

    return 0;
}
