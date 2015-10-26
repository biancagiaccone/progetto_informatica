#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WString>

class UserzeroApplication : public Wt::WApplication
{
public:
    UserzeroApplication(const Wt::WEnvironment& env);
    
    
private:
    
    Wt::WLineEdit *searchEdit_;

    Wt::WPushButton *listButton_;
    Wt::WPushButton *searchButton_;
    
    // Wt::WText *us_correct;
    void user();
};


UserzeroApplication::UserzeroApplication(const Wt::WEnvironment& env)
: Wt::WApplication(env)
{
    setTitle("Biblioteca - Area utente");
    
    root()->addWidget(new Wt::WText("Visualizza lista libri"));
    listButton_ = new Wt::WPushButton("Lista libri", root());
    root()->addWidget(new Wt::WBreak());
    root()->addWidget(new Wt::WBreak());
    listButton_ ->clicked().connect(this, &UserzeroApplication::user);
    
    root()->addWidget(new Wt::WText("Cerca un libro"));
    searchEdit_ = new Wt::WLineEdit(root());
    searchButton_ = new Wt::WPushButton("Cerca", root());
    root()->addWidget(new Wt::WBreak());
    root()->addWidget(new Wt::WBreak())
    searchButton_ ->clicked().connect(this, &UserzeroApplication::user);
}

void UserzeroApplication::user()
{
    if (passwordEdit_->text()==password2Edit_->text()) {
        //chiamata a funzione ila per creare nuovo utente
        root()->addWidget(new Wt::WText("Complimenti, hai creato un nuovo utente!"));
        accessButton_ = new Wt::WPushButton("Accedi", root());
        // accessButton_ ->clicked().connect(this, &LoginApplication::LoginApplication);
    }
}

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    return new UserzeroApplication(env);
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, &createApplication);
}