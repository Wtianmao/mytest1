#include <iostream>
#include <mutex>
#include <sys/types.h>
#include <unistd.h>
#include <thread>

std::mutex mtx;

void test(int i)
{	
	while(1)
	{
		mtx.lock();
		std::cout << i << "son unter lock \n";
		sleep(1);
		mtx.unlock();
	}
}

int main()
{
	mtx.lock();

	int pid = fork();
	if (pid == 0)
	{
		std::cout << "is son\n";
		mtx.unlock();
		std::thread t1i(test, 1);
		t1i.join();
	}
	else
	{
		std::cout << "is father\n";
		mtx.unlock();
		std::thread t2i(test, 2);
		t2i.join();
	}
	return 0;
}


