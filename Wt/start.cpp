#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WString>

class StartApplication : public Wt::WApplication
{
public:
    StartApplication(const Wt::WEnvironment& env);
    
    
private:
    
    Wt::WPushButton *newuserButton_;
    Wt::WPushButton *olduserButton_;

};

StartApplication::StartApplication(const Wt::WEnvironment& env)
: Wt::WApplication(env)
{
    setTitle("Biblioteca");
    
    root()->addWidget(new Wt::WText("Benvenuto in biblioteca!"));
    root()->addWidget(new Wt::WBreak());
    newuserButton_ = new Wt::WPushButton("Registrati", root());
    root()->addWidget(new Wt::WBreak());
    olduserButton_ = new Wt::WPushButton("Accedi", root());
    root()->addWidget(new Wt::WBreak());
    root()->addWidget(new Wt::WText("Se vuoi solamente visualizzare la lista dei libri disponibili puoi eseguire l'accesso con l'account guest/guest"));
    root()->addWidget(new Wt::WBreak());
    // olduserButton_ ->clicked().connect(this, &LoginApplication::username);
    // newuserButton_ ->clicked().connect(this, &NewuserApplication::username);

}

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    return new StartApplication(env);
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, &createApplication);
}