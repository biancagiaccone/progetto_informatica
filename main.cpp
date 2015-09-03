//
//  main.cpp
//  esame_prelz
//
//  Created by Ilaria Cazzaniga on 02/09/15.
//  Copyright (c) 2015 Ilaria Cazzaniga. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cerrno>
#include <system_error>
#include "users_and_books.h"


int main(int argc, char * argv[]) {
  
    typedef book<double> book_t;
    typedef std::vector<book_t> book_container_t;

    book_container_t books;
    std::ifstream input;
    
    if (argc <= 1)
    {
        std::cerr << "Usage: " << argv[0] << " <books file name to read>"
        << std::endl;
        return 1;
    }
    
    
    input.open(argv[1],std::ios::in);
    if (!input)
    {
        std::cerr << argv[0] << ": Error: Cannot read from " << argv[1] << ": "
        << std::system_error(errno, std::system_category()).what()
        << "." << std::endl;
        return 1;
    }
    
    while (input.good())
    {
        book_t b; //che errore èèèèèèèèèèèèè
        input >> b;
        
        if (input.good()) books.push_back(b);
    }
    



    return 0;
}
