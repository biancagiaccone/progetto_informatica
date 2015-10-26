#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WString>

class LoginApplication : public Wt::WApplication
{
public:
    LoginApplication(const Wt::WEnvironment& env);
    
    
private:
    
    Wt::WLineEdit *usernameEdit_;
    Wt::WText *us_correct;
    Wt::WPushButton *usernameButton_;
    
    //i bool serviranno impostati vero ma ora non c'è la funzione quindi programma non andrebbe avanti
    //bool ID=false;
    //bool PASS=false;
    
    //bool ID= true;
    bool ID;
    bool PASS= true;
    void username();
    
    
    Wt::WLineEdit *passwordEdit_;
    Wt::WText *password;
    Wt::WPushButton *passwordButton_;
};


LoginApplication::LoginApplication(const Wt::WEnvironment& env)
: Wt::WApplication(env)
{
    setTitle("Biblioteca - Login");
    root()->addWidget(new Wt::WText("Inserisci le tue credenziali per accedere ai servizi"));
    root()->addWidget(new Wt::WText("Nome utente "));
    root()->addWidget(new Wt::WText("(es: nome.cognome) "));
    usernameEdit_ = new Wt::WLineEdit(root());
    usernameButton_ = new Wt::WPushButton("Invia", root());
    root()->addWidget(new Wt::WBreak());
     root()->addWidget(new Wt::WText("Se vuoi solamente visualizzare la lista dei libri disponibili puoi eseguire l'accesso con l'account guest/guest"));
    us_correct = new Wt::WText(root());
    usernameButton_ ->clicked().connect(this, &LoginApplication::username);
    
    //qui serve funzione per controllare che username sia corretto
}

void LoginApplication::username()
{
    
        if(ID==true){
        us_correct->setText("Username corretto, ora inserisci la password  ");
        passwordEdit_ = new Wt::WLineEdit(root());
        passwordButton_ = new Wt::WPushButton("Invia", root());
            
        root()->addWidget(new Wt::WBreak());
        password = new Wt::WText(root());
        
        if(PASS==true){
            //vai a schermata successiva
           // passwordButton_ ->clicked().connect(this, nuovaschermata);
            
        }
        if(PASS==false){
            root()->addWidget(new Wt::WText("Password sbagliata, riprovare"));
        }
        
    }
    
    if(ID==false){
        root()->addWidget(new Wt::WText("Username sbagliato, reinserirlo corretto"));
        // root()->hideWidget();
    }

    
}

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    return new LoginApplication(env);
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, &createApplication);
}