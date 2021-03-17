#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    int n;
    int s = 0, mr = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            s += a;
        else
            s += b;        
        if (abs(a - b) % 3 != 0 && abs(a - b) < mr)
            mr = abs(a - b);
    }
    if (s % 3 != 0)
        cout << s << endl;
    else
        cout << s - mr << endl;
}