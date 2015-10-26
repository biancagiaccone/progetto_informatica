#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WString>

class NewuserApplication : public Wt::WApplication
{
public:
    NewuserApplication(const Wt::WEnvironment& env);
    
    
private:
    
    Wt::WLineEdit *nameEdit_;
    Wt::WLineEdit *surnameEdit_;
    Wt::WLineEdit *usernameEdit_;
    Wt::WLineEdit *passwordEdit_;
    Wt::WLineEdit *password2Edit_;
    
    Wt::WPushButton *userButton_;
     Wt::WPushButton *accessButton_;
    
    // Wt::WText *us_correct;
    void user();
};


NewuserApplication::NewuserApplication(const Wt::WEnvironment& env)
: Wt::WApplication(env)
{
    setTitle("Biblioteca - Nuovo utente");
    root()->addWidget(new Wt::WText("Crea nuovo utente"));
    root()->addWidget(new Wt::WBreak());
    
    root()->addWidget(new Wt::WText("Nome  "));
    nameEdit_ = new Wt::WLineEdit(root());
    root()->addWidget(new Wt::WBreak());
    root()->addWidget(new Wt::WBreak());
    
    root()->addWidget(new Wt::WText("Cognome   "));
    surnameEdit_ = new Wt::WLineEdit(root());
    root()->addWidget(new Wt::WBreak());
    root()->addWidget(new Wt::WBreak());
    
    root()->addWidget(new Wt::WText("Password   "));
    passwordEdit_ = new Wt::WLineEdit(root());
    root()->addWidget(new Wt::WBreak());
    root()->addWidget(new Wt::WBreak());
    root()->addWidget(new Wt::WText("Conferma password  "));
    password2Edit_ = new Wt::WLineEdit(root());
    root()->addWidget(new Wt::WBreak());
    
    userButton_ = new Wt::WPushButton("Invia", root());
    root()->addWidget(new Wt::WBreak());
    root()->addWidget(new Wt::WBreak());
    
    root()->addWidget(new Wt::WText("Se vuoi solamente visualizzare la lista dei libri disponibili puoi eseguire l'accesso con l'account guest/guest"));
    root()->addWidget(new Wt::WBreak());
    root()->addWidget(new Wt::WBreak());
    userButton_ ->clicked().connect(this, &NewuserApplication::user);
}

void NewuserApplication::user()
{
    if (passwordEdit_->text()==password2Edit_->text()) {
        //chiamata a funzione ila per creare nuovo utente
        root()->addWidget(new Wt::WText("Complimenti, hai creato un nuovo utente!"));
        root()->addWidget(new Wt::WBreak());
        root()->addWidget(new Wt::WText("Il tuo nome utente e' " + nameEdit_->text() + "." + surnameEdit_->text()));
        root()->addWidget(new Wt::WBreak());
        accessButton_ = new Wt::WPushButton("Accedi", root());
        // accessButton_ ->clicked().connect(this, &LoginApplication::LoginApplication);
    }
    
    else{
        root()->addWidget(new Wt::WText("La password di conferma non corrisponde, assicurati di immettere la stessa password in entrambi i campi facendo attenzione a maiuscole e minuscole."));
    }


}

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    return new NewuserApplication(env);
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, &createApplication);
}