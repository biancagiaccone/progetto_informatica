//
//  users.h
//  esame_prelz
//
//  Created by Ilaria Cazzaniga on 04/09/15.
//  Copyright (c) 2015 Ilaria Cazzaniga. All rights reserved.
//

#ifndef esame_prelz_users_h
#define esame_prelz_users_h


//enum role {parent, student, teacher};//is that useful?

//utente base
class user_0
{
public:
    //constructor
    user_0(std::string username, std::string pwd): m_username(username), m_pwd(pwd) {}
    user_0() {}
    //destructors
    ~ user_0() {}
    
    const std::string &get_username() const { return m_username; }
    const std::string &get_pwd() const { return m_pwd; }
    
    bool login(std::string u, std::string p);
    void show_list(std::vector book &bv);
    void find();
    void show_book();
    
private:
    //
    std::string m_username;
    std::string m_pwd;
    int m_n_books;
    //info personali
    std::string name;
    std::string birth_date;
    std::string kind;
    //role m_role;
    
};

class user_1: public user_0
{
    
public:
    user_1(std::string username, std::string pwd): m_n_books(0) //devo riinizializzare tutto?? che errore è?!
    
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
    {};
    ~user_admin()
    {}
    
    void add_book();
    
    void show_user_history(); //? mi sembra troppo complessa, ci vorrebbero molte sottofunzioni
    void show_reservations();
    void show_lendings();
    void show_returned();
    //void show_tot_statistics();
};

//prima devo ciclare sugli users
bool user_0::login()
{
    if (p==get_pwd) { return true; }
    else { return false; }
}

void user_0::show_list()
{
    
}

void find();
void show_book();
void get_info();


#endif
