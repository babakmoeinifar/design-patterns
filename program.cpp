#include <iostream>
#include "Singleton.h"

int main() {
	Singleton::GetInstance()->tell();

	return 0;
}

//Like a mouse cursor. We can have just ONE cursor