//
//  Header.h
//  esame_prelz
//
//  Created by Ilaria Cazzaniga on 06/09/15.
//  Copyright (c) 2015 Ilaria Cazzaniga. All rights reserved.
//

#ifndef esame_prelz_Header_h
#define esame_prelz_Header_h

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
    std::string looking_for;
    
    bool login(std::string u, std::string p);
    bool compare(std::string to_search, std::string to_find);
    void show_list(std::vector book &bv, int num);
    void find_per_title(std::vector book &bv, int num);
    void find_per_author(std::vector book &bv, int num);
    void show_book(std::vector book &bv, int num);
    
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

class user_1: public user_0()
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

void user_0::show_list(std::vector book &bv)
{
    for (int i=0; i<num; i++) { std::cout << bv[i] << std::endl; }
}

bool user_0::compare(std::string to_search, std::string to_find)
{
    if (std::regex_match(to_search, to_find)) { return true; }
    else { return false; }
}

void user_0::find_per_title(std::vector book &bv, int num)
{
    int counter=0;
    for(int i=0; i<num; i++)
    {
        bool a=compare(looking_for, bv[i]->get_title);
        if (a==true)  sb[i]=bv[counter];
        ++counter;
    }
    std::cout << "Trovati " << counter+1 << " elementi!" << std::endl;
    show_book(sb, counter);
}

void user_0::find_per_author(std::vector book &bv, std::vector book &sb, int num)
{
    int counter=0;
    for(int i=0; i<num; i++)
    {
        bool a=compare(looking_for, bv[i]->get_author);
        if (a==true)  sb[i]=bv[counter];
        ++counter;
    }
    std::cout << "Trovati " << counter+1 << " elementi!" << std::endl;
    show_book(sb, counter);
}

void user_0::show_book(std::vector book &sb, int num)
{
    for (int i=0; i<num; i++) std::cout << sb[i] << std::endl;
}


#endif
