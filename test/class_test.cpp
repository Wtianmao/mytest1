#include <iostream>

class A
{
	public:
		virtual void f1() = 0;
};

class B : public A
{
	public:
		void f1()
		{
			std::cout << "f1" << std::endl;
		};
};

void fa(A &a1)
{
	a1.f1();
}

int main()
{
	A *a = new B();
	fa(*a);
	return 0;
}
