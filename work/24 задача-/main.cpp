#include <iostream>
#include <string>

using namespace std;

int mlo(string str)
{
    int ans = 1, m = 1;
    for (int i = 1; i < str.length(); ++i)
    {
        if (str[i] != str[i - 1])
            ++m;
        else
        {
            ans = max(ans, m);
            m = 1;
        }        
    }
    return ans;
}

int main()
{
    string str;
    getline(cin, str);
    cout << mlo(str);
    return 0;
}