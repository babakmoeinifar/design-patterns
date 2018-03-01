#pragma once
class Singleton
{
private:
	Singleton();
	static Singleton* _instance;

public:
	static Singleton* GetInstance();
	void tell() {};
};

