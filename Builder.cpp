//Builder

#include <iostream>
#include <string>
using namespace std;

//Product : final object that will be created using Builder
class Product {
private:
	string partA, partB, partC;

public:
	void makeA(const string &part) {
		partA = part;
	}
	void makeB(const string &part) {
		partB = part;
	}
	void makeC(const string &part) {
		partC = part;
	}

	string get() {
		return (partA + " " + partB + " " + partC);
	}
	
	//..
};

//Biulder : abstract interface for creating products
class Builder {
protected:
	Product product;

public:
	virtual ~Builder() {
		//..
	}
	Product get() {
		return product;
	}

	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
	//..
};

//ConcreteBuilder1 : create real products and stores them in the composition structure
class ConcreteBuilder1 : public Builder {


public:
	void buildPartA() {
		product.makeA("A-1");
	}
	void buildPartB() {
		product.makeB("B-1");
	}
	void buildPartC() {
		product.makeC("C-1");
	}
	//..
};
//ConcreteBuilder2 : create real products and stores them in the composition structure
class ConcreteBuilder2 : public Builder {


public:
	void buildPartA() {
		product.makeA("A-2");
	}
	void buildPartB() {
		product.makeB("B-2");
	}
	void buildPartC() {
		product.makeC("C-2");
	}
	//..
};

//Director : responsible for managing the correct squence of object creation
class Director {
private:
	Builder *builder;

public:
	Director() : builder(nullptr) {}
	~Director() {
		if (builder) {
			delete builder;
		}
	}

	void set(Builder *b) {
		if (builder) {
			delete builder;
		}
		builder = b;
	}

	Product get() {
		return builder->get();
	}

	void construct() {
		builder->buildPartA();
		builder->buildPartB();
		builder->buildPartC();
		//..
	}
	//..

};

int main() {

	Director director;
	director.set(new ConcreteBuilder1);
	director.construct();

	Product productX = director.get();
	cout << "1st product parts: " << productX.get() << endl;

	director.set(new ConcreteBuilder2);
	director.construct();

	Product productY = director.get();
	cout << "2nd product parts: " << productY.get() << endl;

	return 0;
}










