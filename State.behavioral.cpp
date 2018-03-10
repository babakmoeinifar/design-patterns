//State : Behavioral
#include <iostream>
using namespace std;

//State: interface for encapsulating the behavior associated
//with a particular state of the Context
class IState {
public:
	virtual ~IState() {}
	virtual void handle() = 0;
	//..
};

//ConcreteSates: each subclass implements a behavior associated
//with a state of the Context
class ConcreteStateA : public IState {
public:
	~ConcreteStateA() {}
	void handle() {
		cout << "State A handled." << endl;
	}
	//..
};

class ConcreteStateB : public IState {
public:
	~ConcreteStateB() {}
	void handle() {
		cout << "State B handled." << endl;
	}
	//..
};

//Context: interface of interest to clients
class IContext {

public:
	IContext() : state() {}

	~IContext() {
				   delete state;
	}

	void setState(IState *s) {
		if (state) {
			delete state;
		}
		state = s;
	}

	void request() {
		state->handle();
	}
	//..
private:
	IState *state;
	//..
};

int main() {
	IState *stateA = new ConcreteStateA;
	IState *stateB = new ConcreteStateB;

	IContext *context = new IContext;

	context->setState(stateA);
	context->request();

	return 0;
}