#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    ifstream datafile("C:\\Users\\radomir\\proga\\informatic\\basic course 2020-21  2\\work\\telphone numbers\\database.txt");
    
    map <int, string> mp;
    int n; string s;
    for (int i = 0; i < 10; ++i)
    {
        datafile >> n;
        datafile >> s;
        
    }
    
    return 0;
}