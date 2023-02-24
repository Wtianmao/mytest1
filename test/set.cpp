#include <iostream>  
#include <set>  
#include <map>  
using namespace std;  
  
int main()  
{  
    set<int> s;  
    s.insert(1);  
    s.insert(2);  
    s.insert(5);  
    s.insert(2);  
    s.insert(8);  
    s.insert(2);  
    s.insert(0);  
    s.insert(3);  
    s.insert(1);  
    cout<<"set 中 1 出现的次数是 ："<<s.count(1)<<endl;  
    cout<<"set 中 4 出现的次数是 ："<<s.count(4)<<endl;  


    for(auto iter = s.begin() ; iter != s.end() ; ++iter)  
    {  
        cout<<*iter<<" ";  
    } 

    map<int, int> m;
    m[1] = 140;
    m[3] = 130;
    m[4] = 120;
    m[5] = 110;
    m[6] = 105;
    m[9] = 106;
    m[8] = 107;
    m[7] = 108;
    m[2] = 9;

    for(auto iterm = m.begin() ; iterm != m.end() ; ++iterm)  
    {  
        cout<<iterm->first<<" ";  
    } 
    return 0;  
}
