#include <memory>

void test4(void* p)
{
//	delete p;
}


void *test3()
{
	void *p = (void*)new int(0);
	return p;
}

std::unique_ptr<int> test2()
{
	auto p = test3();
	test4(p);

	return std::unique_ptr<int>(new int());
}

void test()
{
	std::unique_ptr<int> a(new int[20]);
	auto aa = test2();
//#	int *b = new int[10]();
}

int main()
{
	test();
	return 0;
}
