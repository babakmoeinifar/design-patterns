//Command
#include <iostream>
using namespace std;

//Reciever : know how to perform the operation
//associated with carrying out a request
class Receiver{
public:
    void action(){
        cout << "Receiver: execute action" << endl;
        }
    //..
};

//Command : declares an interface for all commands
class ICommand{
protected:
    ICommand(){}

public:
    virtual ~ICommand(){}
    virtual void execute() = 0;
};

//Concrete Command : implements execute by invoking
//the corresponding operation(s) on Reciever
class ConcreteCommand : public ICommand{
private:
    Receiver *reciever;

public:
    ConcreteCommand(Receiver *r)
        :reciever(r){}

    ~ConcreteCommand(){
        if(reciever){
            delete reciever;
        }
    }

    void execute(){
        reciever->action();
    }
    //..
};

//Invoker : ask the command to carry out the request
class Invoker{
private:
    ICommand *icommand;

public:
    void set(ICommand *c){
        icommand = c;
    }

    void confirm(){
        if(icommand){
            icommand->execute();
        }
    }
    //..
};

int main()
{
    Receiver receiver = Receiver();
    ConcreteCommand icommand = ConcreteCommand(&receiver);

    Invoker invoker = Invoker();
    invoker.set(&icommand);
    invoker.confirm();

    return 0;
}
