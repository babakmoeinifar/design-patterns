//Mediator
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//abstract Mediator : defines an interface for communicating with colleague objects
class Mediator {
protected:
	Mediator() {}

public:
	virtual ~Mediator() {}
	virtual void add(Colleague *c) = 0;
	virtual void distribute(Colleague *sender, string msg) = 0;
};

//(Abstract) Colleague classes : each colleague communicates with its mediator
//whenever it whould have otherwise communicated with another colleague
class Colleague {
protected:
	Mediator *mediator;
	unsigned int id;

public:
	Colleague(Mediator *m, unsigned int i)
		: mediator(m), id(i) {}

	virtual ~Colleague() {}

	unsigned int getID() {
		return id;
	}

	virtual void send(string) = 0;
	virtual void receive(string) = 0;

};

class ConcreteColleague : public Colleague {
public:
	ConcreteColleague(Mediator *m, unsigned int i)
		:Colleague(m, i) {}

	void send(string msg);
	void receive(string msg) {
		cout << "Message '" << msg << "' received by Colleague " << id << endl;
	}
};

//ConcreteMediator : implements cooperative behavior by coordinating
//Colleague objects and know its colleagues
class ConcreteMediator : public Mediator {
private:
	vector<Colleague *> colleagues;

public:
	~ConcreteMediator() {
		for (unsigned int i = 0; i < colleagues.size(); i++) {
			delete colleagues[i];
		}
		colleagues.clear();
	}

	void add(Colleague *c) {
		colleagues.push_back(c);
	}

	void distribute(Colleague *sender, string msg) {
		for (unsigned int i = 0; i < colleagues.size(); i++) {
			if (colleagues.at(i)->getID() != sender->getID()) {
				colleagues.at(i)->receive(msg);
			}
		}
	}
};

void ConcreteColleague::send(string msg) {
	cout << "Message '" << msg << "' send by Colleague " << id << endl;
	mediator->distribute(this, msg);
}

int main() {
	Mediator *mediator = new ConcreteMediator;

	Colleague *c1 = new ConcreteColleague(mediator, 1);
	Colleague *c2 = new ConcreteColleague(mediator, 2);
	Colleague *c3 = new ConcreteColleague(mediator, 3);

	mediator->add(c1);
	mediator->add(c2);
	mediator->add(c3);

	c1->send("Hi");
	c3->send("Hello");

	delete mediator;

	return 0;
}