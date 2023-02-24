#include <iostream>
#include <string.h>

using namespace std;

int fun(char *aa)
{
	strcpy(aa, "bb");
	return 0;
}

#define aaa "1234"
int main()
{
	fun(const_cast<char*>(aaa));

	return 0;
}
