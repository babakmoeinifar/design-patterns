//Chain of responsibility
#include <iostream>
using namespace std;

//Handler : defines an interface for handling requests and
// optionally implements the successor link
class IHandler{
private:
    IHandler *successor;

public:
    virtual void setHandler (IHandler *s){
        successor = s;
    }
    virtual void handleRequest(){
        if (successor != 0){
            successor->handleRequest();
        }
    }
    //..
};

//Concrete Handlers : handle request they are responsible for
class ConcreteHandler1 : public IHandler{
public:
    bool canHandle(){
        //..
        return false;
    }

    virtual void handleRequest(){
        if(canHandle()){
            cout << "Handeled by CHandler1" << endl;
        }
        else{
            cout << "Can't Handle by CH1" << endl;
            IHandler::handleRequest();
        }
        //..
    }
    //..
};

class ConcreteHandler2 : public IHandler{
public:
    bool canHandle(){
        //..
        return true;
    }
    virtual void handleRequest(){
        if(canHandle()){
            cout << "Handled by CH2" << endl;
        }
        else{
            cout << "Can' handle by CH2" << endl;
            IHandler::handleRequest();
        }
        //..
    }
    //..
};

int main (){
    ConcreteHandler1 handler1;
    ConcreteHandler2 handler2;

    handler1.setHandler(&handler2);
    handler1.handleRequest();

    return 0;
}
