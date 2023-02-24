#include <memory>
#include <thread>
#include <iostream>
#include <unistd.h>

using namespace std;

void test(shared_ptr<int> w, int j)
{
	int i = 20;
	while(i--)
	{
//auto p = w.lock();
		(*w)++;
		sleep(1);
		cout << j << " " << *w << endl;
	}
}

int main()
{
	shared_ptr<int> a(new int);

	thread t1(test, shared_ptr<int>(a), 1);
	thread t2(test, shared_ptr<int>(a), 2);
	thread t3(test, shared_ptr<int>(a), 3);

	t1.join();
	t2.join();
	t3.join();

	cout << *a << endl;

	return 0;
}

