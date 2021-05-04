#include <iostream>
#include <map>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    map <int, unsigned int> mx;
    map <int, unsigned int> my;
    int x, y;
    for (unsigned int i; i < n; ++i)
    {
        cin >> x >> y;
        if (mx.count(x))
            ++mx[x];
        else
            mx[x] = 1;
        if (my.count(y))
            ++my[y];
        else
            my[y] = 1;
    }
    int maxx = 0;
    
    map <int, unsigned int>::iterator itx;
    for (itx = mx.begin(); itx != mx.end(); ++itx)
        if (itx->second > maxx)
            maxx = itx->second;
    int maxy;
    map <int, unsigned int>::iterator ity;
    for (ity = my.begin(); ity != my.end(); ++ity)
        if (ity->second > maxy)
            maxy = ity->second;
    
    cout << max(maxx, maxy);
    return 0;
}