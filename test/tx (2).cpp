#include <iostream>
#include <memory>
using namespace std;

int main()
{
	auto p = make_shared<int>(42);
	int* iPtr = p.get();
	{
   		   shared_ptr<int>(iPtr);
	}

	int value = *p;
	cout << value << endl;
	return 0;
}
