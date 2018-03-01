#include<iostream>
#include "Singleton.h"
using namespace std;

Singleton* Singleton::_instance = 0;

Singleton* Singleton::GetInstance() {
	if (_instance == 0) {
		_instance = new Singleton;
	}
	return _instance;
}
void tell() {
	cout << "This is Singleton";
}
