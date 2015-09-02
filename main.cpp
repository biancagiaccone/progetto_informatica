//
//  main.cpp
//  esame_prelz
//
//  Created by Ilaria Cazzaniga on 02/09/15.
//  Copyright (c) 2015 Ilaria Cazzaniga. All rights reserved.
//

#include <iostream>

//enumeratori
enum genre {classic, avdenture, historic, thriller, fantasy};
enum role {parent, student, teacher};

//classi
//note: per ora sto mettendo tutte le funzioni come void, non so se poi diventeranno magari funzioni che restituiscono un valore o rimangono void

//utente base
class user_0
{
public:
    //constructor
    user_0(std::string username, std::string pwd): m_username(username), m_pwd(pwd)
    {}
    //destructors
    ~user_0()
    {}
    
    void login();
    void show_list();
    void find();
    void show_book();
    void get_info();
    
private:
    //
    std::string m_username;
    std::string m_pwd;
    int m_n_books;
    //info personali
    std::string name;
    std::string birth_date;
    std::string kind;
    role m_role;
    
};

class user_1: public user_0
{
    
public:
    user_1(): m_n_books(0) //devo riinizializzare tutto??
    {}
    ~user_1()
    {}
    
    const static int max_no_books=3;
    void borrow_book();
    void reserve_book();
    //void show_statistics(); //panic
    void return_book();
private:
    int m_n_books;
    
};

class user_admin: public user_1
{
public:
    user_admin()
    {}
    ~user_admin()
    {}
    
    void add_book();
    
    void show_user_history(); //? mi sembra troppo complessa, ci vorrebbero molte sottofunzioni
    void show_reservations();
    void show_lendings();
    void show_returned();
    //void show_tot_statistics();
};

//libro
class book
{
    
public:
    std::string get_info(); //ne basta una o devo fare get per ogni elemento? secondo me una perchè sono tutti elementi di tipo string!
    
private:
    std::string book_title;
    std::string author;
    std::string book_code;
    std::string reader_age;
    genre m_genre;
    //descrizione? che tipo posso usare?!
};




int main(int argc, const char * argv[]) {
  
    
    
    return 0;
}
