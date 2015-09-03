//
//  users_and_books_.h
//  esame_prelz
//
//  Created by Ilaria Cazzaniga on 03/09/15.
//  Copyright (c) 2015 Ilaria Cazzaniga. All rights reserved.
//



#ifndef users_and_books_h
#define users_and_books_h

//enumeratori

enum role {parent, student, teacher};
enum genre {classic, avdenture, historic, thriller, fantasy};


//classi
//note: per ora sto mettendo tutte le funzioni come void, non so se poi diventeranno magari funzioni che restituiscono un valore o rimangono void

//libro
template<typename CODE> class book;
template<typename CODE>
std::ostream &operator<< (std::ostream &os, const book<CODE> b);
template<typename CODE>
std::istream &operator>> (std::istream &is, book<CODE> &b);


template<typename CODE> class book
{
    friend std::ostream &operator<<<CODE> (std::ostream &os, const book<CODE> b);
    friend std::istream &operator>><CODE> (std::istream &is, book<CODE> &b);
    
public:
    typedef CODE book_code_type;
    //creator
    book(CODE& book_code, std::string title, std::string author, genre b_genre): m_book_code(book_code), m_title(title), m_author(author), m_genre(b_genre) {}
    //denstructor
    ~book(){}
    
    CODE  book_code() const { return m_book_code; }
    CODE& book_code()       { return m_book_code; }
    void  book_code(const CODE& new_book_code) { m_book_code = new_book_code; } // book_code assignment
    
    const std::string &get_title() const { return m_title; }
    const std::string &get_author() const { return m_author; }
    const genre &get_genre() const { return m_genre; }
    const std::string &get_reader_age() const { return reader_age; }
    

private:
    std::string m_title;
    std::string m_author;
    std::string m_book_code;
    std::string reader_age;
    genre m_genre;
    //manca descrizione: che tipo posso usare?!
};


template<typename CODE>
std::ostream &operator<< (std::ostream &os, const book<CODE> b)
{
    return os << b.m_book_code << ": " << b.m_author << ", " << b.m_title
    << " - " << b.m_genre << ", età consigliata " << b.reader_age << " anni. ";
    //capire come è scritto reader_age
}

template<typename CODE>
std::istream &operator>> (std::istream &is, book<CODE> &b)
{
    
    bool input_done = false;
    
    while(!input_done)
    {
        std::stringbuf rsbuf;
        std::string    line;
        
        is.get(rsbuf);
        line=rsbuf.str();
        
        if (!line.empty())
        {
            is.clear(); // We may be at EOF after reading a valid record.
            
            std::string::size_type pos_n1 = line.find_first_of('/n');
            std::string::size_type pos_n2 = line.find_last_of('/n');
            std::string::size_type pos_n3 = line.find_last_of('/n');
            std::string::size_type pos_n4 = line.find_last_of('/n');
            std::string::size_type pos_n5 = line.find_last_of('/n');

            //ho messo tutti /n ma potrebbe essere il caso di cambiare
            
            if (pos_n1 == std::string::npos || pos_n2 == std::string::npos)
                continue; // Skip malformed lines ??
            
            b.m_book_code = line.substr(0,pos_n1-1);
            b.m_author = line.substr(pos_n1+2, (pos_n2-pos_n1-3));
            b.m_title = line.substr(pos_n2+2, (pos_n3-pos_n2-3));
            b.m_genre = line.substr(pos_n3+2, (pos_n4-pos_n3-3));//controllare come viene acquisito, perchè è un tipo enum
            b.reader_age = line.substr(pos_n4+2, (pos_n5-pos_n4-3));
            
            //controllare le acquisizioni, se avvengono giuste
            
            
            std::istringstream codestr(line.substr(0,pos_n1-1));
            codestr >> b.m_book_code;
            input_done = true;
        }
        
        // cosa fa qui?
        // Reading an empty string will set std::ios::failbit, which we
        // don't want to consider an error.
        if (is.rdstate() == std::ios::failbit) is.clear();
        if (! is.good()) input_done = true;
        else
        {
            is.get();   // Skip past delimiter (newline).
            is.clear(); // Be happy if it doesn't succeed.
        }
    }
    
    return is;
}




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


void user_0::login()
{
    
}

void user_0::show_list()
{
    
}

void find();
void show_book();
void get_info();




#endif
