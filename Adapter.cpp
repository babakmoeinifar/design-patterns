//Adapter
#include <iostream>
using namespace std;

//target : defines specific interface that Client uses
class ITarget {
public:
	virtual void request() = 0;
	//..
};

//Adaptee : all requests get delegated to the Adaptee which defines
//an existing interface that nedss adapting
class Adaptee {
public:
	void specificRequest() {
		cout << "Specific Request" << endl;
		//..
	}
	//..
};

//Adapter : implements the target interface and lets the Adaptee
//respond to reauest on a Target by extending both classes
//ie adapts the interface of Adaptee to the Target interface
class Adapter : public ITarget, private Adaptee {
public:
	virtual void request() {
		specificRequest();
		//..
	}
	//..
};

int main() {
	ITarget *t = new Adapter();
	t->request();

	return 0;
}