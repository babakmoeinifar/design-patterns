// C++ Design Patterns : Abstract Factory

#include<iostream>
using namespace std;

//abstract class
class ProductA {
public:
	virtual string getName() = 0;
	//..
};

class ConcreteProductA1 :public ProductA {
public:
	string getName() {
		return "A-1";
	}
	//..
};
class ConcreteProductA2 : public ProductA {
public:
	string getName() {
		return "A-2";
	}
	//..
};

//abstract class
class ProductB {
public:
	virtual string getName() = 0;
	//..
};

class ConcreteProductB1 :public ProductB {
public:
	string getName() {
		return "B-1";
	}
	//..
};
class ConcreteProductB2 : public ProductB {
public:
	string getName() {
		return "B-2";
	}
	//..
};

//Abstract Factory : abstract  for creating a family of products
class AbstractFactory {
public:
	virtual ProductA *createProductA() = 0;
	virtual ProductB *createProductB() = 0;
};

//Concrete Factory 1 : Interface
class IConcreteFactory1 : public AbstractFactory {
public:
	ProductA *createProductA() {
		return new ConcreteProductA1();
	}
	ProductB *createProductB() {
		return new ConcreteProductB1();
	}
};

//Concrete Factory 2 : Interface
class IConcreteFactory2 : public AbstractFactory {
public:
	ProductA *createProductA() {
		return new ConcreteProductA2();
	}
	ProductB *createProductB() {
		return new ConcreteProductB2();
	}
};

int main() {
	IConcreteFactory1 *factory1 = new IConcreteFactory1();
	IConcreteFactory2 *factory2 = new IConcreteFactory2();

	ProductA *p1 = factory1->createProductA();
	cout << "Product: " << p1->getName << endl;

	ProductB *p2 = factory2->createProductB();
	cout << "Product: " << p2->getName << endl;

	return 0;
}