#include <iostream>
#include <memory>

using namespace std;
class B
{
public:
	B(){cout << "new B" << endl;};
	~B(){cout << "delete B" << endl;};
};

class A
{
public:
	A(){
		b = new B();
		cout << "new A" << endl;
	};
	~A(){
		delete b;
		cout << "delete A" << endl;
	};
private:
	B *b;
};

unique_ptr<A> fun()
{
	cout << "fun" << endl;
	return unique_ptr<A>(new A);
}

void gt(unique_ptr<A> &t)
{
	cout << "gt" << endl;
	t.reset();
	cout << "gt end" << endl;
}

void test()
{
	cout << "test" << endl;
	unique_ptr<A> t = fun();
	gt(t);
	cout << "test end" << endl;
}

int main()
{
	cout << "main" << endl;
	test();
	cout << "main end" << endl;
	return 1;
}
