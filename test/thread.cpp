#include <string.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <memory>
using namespace std;

void my_print(const int &i, std::unique_ptr<char[]> pbuf)
{
    cout << i << endl;
    int j = i;
    while(j--)
    {
    	cout << pbuf.get() << endl;
	sleep(1);
    }
    return;
}

void test()
{
    int var = 5;
    int &m_var = var;
    char m_buf[] = "this is a test!";

    std::unique_ptr<char[]> recv_data(new char[sizeof(m_buf)]);
    memcpy(recv_data.get(), m_buf, sizeof(m_buf));
    thread m_thread(my_print, m_var,std::move(recv_data));
    m_thread.detach();
}

int main()
{
    test();
    cout << "Hello World!" << endl;

    sleep(10);
    return 0;
}

