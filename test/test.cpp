#include <iostream>
#include <thread>
#include <atomic>
#include <functional>
#include <unistd.h>
using namespace std;
 
//std::atomic<int> m_value = 0;//错误初始化
 
//atomic_int m_value = 0;    // 准确初始化
std::atomic<int> m_value(0); // 准确初始化
 
void increment()
{
    for (int i = 0; i < 5; ++i)
    {
        this_thread::sleep_for(chrono::milliseconds(50));
        m_value++;
        cout << i <<"increment number: " << m_value << ", theadID: " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}
 
void decrement()
{
    for (int i = 0; i < 5; ++i)
    {
        m_value--;
	cout << "decrement" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << i << "decrement number: " << m_value  << ", theadID: " << this_thread::get_id() << endl;
    }
}
 
int main()
{
    thread t1(increment);
    thread t2(decrement);
 
    t1.join();
    t2.join();
 
    return 0;
}
