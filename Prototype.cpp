//Prototype
#include <string>
#include <iostream>
using namespace std;

// Interface of cloning itself
class IPrototype {
public:
	virtual IPrototype *clone() = 0;
	virtual string type() = 0;
	//..
};

//Concrete Prototypes : implement an operation for cloning itself
class ConcretePrototypeA : public IPrototype {
public:
	IPrototype *clone() {
		return new ConcretePrototypeA;
	}
	string type() {
		return "type-A";
	}
	//..
};

class ConcretePrototypeB : public IPrototype {
public:
	IPrototype *clone() {
		return new ConcretePrototypeB;
	}
	string type() {
		return "type-B";
	}
	//..
};

//Client creates a new object by asking a prototype to clone itself
class Client {
private:
	static IPrototype *types[2];

public:
	static IPrototype *make(int index) {
		return types[index]->clone();
	}
	//..
};

//enum list
IPrototype *Client::types[] =
{
	new ConcretePrototypeA,
	new ConcretePrototypeB
	//..
};

int main() {
	IPrototype *prototype;

	prototype = Client::make(0);
	cout << "Prototype: " << prototype->type() << endl;

	prototype = Client::make(1);
	cout << "Prototype: " << prototype->type() << endl;

	return 0;
}




