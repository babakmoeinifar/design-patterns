//Interpreter
#include <iostream>
#include <map>
using namespace std;

//Context : contains information that's global to the interpreter
class Context{
    private:
    map<string,bool> vars;
    //..

    public:
    void set (string var, bool value){
        vars.insert(pair<string, bool>(var, value));
    }
    bool get(string exp){
        return vars[exp];
    }
    //..
};

//Abstract Expression: declares an abstract Interpret
//operation that is common to all nodes in the abstract syntax tree
class AbstractExpression{
    public:
    virtual ~AbstractExpression(){}
    virtual bool interpret(Context*){
        return false;
    }
    //..
};

//Terminal Expression: implements an Interpret operation
//associated with terminal symbols in the grammar(an 
//instance is required for every terminal symbol in a sentence)
class TerminalExpression : public AbstractExpression{
private:
string value;
//..

public:
TerminalExpression(string val)
    : value(val){}

    ~TerminalExpression(){}

    bool interpret(Context *context){
        return context->get(value);
    }
    //..
} ;

//Nonterminal Expression : implements an Interpret operation
//for nonterminal symbols in the grammar (one such is 
//required for every rule in the grammar)
class NonterminalExpression : public AbstractExpression{
    private:
    AbstractExpression *lop;
    AbstractExpression *rop;
    //..

    public:
    NonterminalExpression(AbstractExpression *left,AbstractExpression *right)
        :lop(left), rop(right){}

        ~NonterminalExpression(){
            delete lop;
            delete rop;
        }

        bool interpret(Context *context){
            return lop->interpret(context) && 
                    rop->interpret(context);
        }
        //..
};

int main() {
    //An example of very simple expression tree
    //that corrsponds to expression (A AND B)
    AbstractExpression *A = new TerminalExpression("A");
    AbstractExpression *B = new TerminalExpression("B");
    AbstractExpression *exp = new NonterminalExpression(A,B);

    Context context;
    context.set("A",true);
    context.set("B",false);

    cout << context.get("A") << "AND" << context.get("B");
    cout << " = " << exp->interpret(&context) << endl;

    delete exp;

    return 0;
}








