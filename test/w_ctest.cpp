#include <iostream>

int main()
{
	int i = 0;
	do
	{
		if (i < 20)
		{
			i++;
			std::cout << i << std::endl;
			continue;
		}
	}while(i<10);

	return 0;
}
