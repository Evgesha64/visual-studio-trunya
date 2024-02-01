#include "mainLib.h"

MyClass::MyClass() {
	a = 0;
	b = 5;
	c = 10;
};

void MyClass::setMain(int a)
{
	this->a = a;
}

void MyClass::getMain()
{
	std::cout << a << "  " << b << "  " << c;
}