#include <iostream>
using namespace std;

class IElement {
public:
	virtual void accept(IVisitor &visitor) = 0;
	//..
};
class ConcreteElementA;
class ConcreteElementB;

//Visitor: declares a Visit operation for each class of
//ConcreteElement in the object structure
class IVisitor {
public:
	virtual void visitElementA(ConcreteElementA *element) = 0;
	virtual void visitElementB(ConcreteElementB *element) = 0;
	//..
};

//Concrete Visitors: implements each operation declare by IVisitor
class ConcreteVisitor1 : public IVisitor {
public:
	void visitElementA(ConcreteElementA *) {
		cout << "C Visitor1: Element A visited." << endl;
	}

	void visitElementB(ConcreteElementB *) {
		cout << "C Visitor1: Element B visited." << endl;
	}
	//..
};

class ConcreteVisitor2 : public IVisitor {
public:
	void visitElementA(ConcreteElementA *) {
		cout << "C Visitor2: Element A visited." << endl;
	}

	void visitElementB(ConcreteElementB *) {
		cout << "C Visitor2: Element B visited." << endl;
	}
	//..
};

class ConcreteElementA : public IElement {
public:
	void accept(IVisitor &visitor) {
		visitor.visitElementA(this);
	}
};

class ConcreteElementB : public IElement {
public:
	void accept(IVisitor &visitor) {
		visitor.visitElementB(this);
	}
};

int main() {
	ConcreteElementA elementA;
	ConcreteElementB elementB;

	ConcreteVisitor1 visitor1;
	ConcreteVisitor2 visitor2;

	elementA.accept(visitor1);
	elementA.accept(visitor2);

	elementB.accept(visitor1);
	elementB.accept(visitor2);

	return 0;
}