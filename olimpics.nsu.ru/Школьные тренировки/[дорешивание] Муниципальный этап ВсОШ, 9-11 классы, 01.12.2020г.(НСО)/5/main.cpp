#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximum(vector <int> array)
{
    int ans = array[0];
    for (int i = 1; i < array.size(); ++i)
        if (ans < array[i])
            ans = array[i];
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector <int> x;
    vector <int> y;
    vector <int> xType;
    vector <int> yType;
    vector <int> counter;
    int X, Y, c;

    for (int i = 0; i < n; ++i)
    {
        cin >> X;
        cin >> Y;
        x.push_back(X);
        y.push_back(Y);

        if (find(xType.begin(), xType.end(), X) == xType.end())
            xType.push_back(X);
        if (find(yType.begin(), yType.end(), Y) == yType.end())
            yType.push_back(Y);
    }

    for (int i = 0; i < xType.size(); ++i)
    {
        c = 0;
        for (int j = 0; j < x.size(); ++j)
        {
            if (xType[i] == x[j])
                ++c;
        }
        counter.push_back(c);
    }
    for (int i = 0; i < yType.size(); ++i)
    {
        c = 0;
        for (int j = 0; j < x.size(); ++j)
            if (yType[i] == y[j])
                ++c;
        counter.push_back(c);
    }
    int ans = maximum(counter);
    cout << ans << endl;
}