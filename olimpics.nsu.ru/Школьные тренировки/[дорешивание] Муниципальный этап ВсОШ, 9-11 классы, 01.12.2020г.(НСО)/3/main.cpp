#include <iostream>

using namespace std;

/*
def mf(a, b):
    ans = 1
    for i in range(b, a + 1):
        ans *= i;
    return ans;
    */
int fact(int a, int b)
{
    int ans = 1;
    for (int i = a; i < b + 1; ++i)
    {
        ans *= i;
    }
    return ans;
}

int C(int n, int k)
{
    int ans = fact(n - k + 1, n) / fact(1, k);
    return ans;
}

int main()
{
    int ans = 1;
    int x, y, xx, yy;
    for (int i = 0; i < 3; ++i)
    {
        cin >> x >> y;
        ans *= C(min(x, y) + max(x, y) - 1, min(x, y));
    }
    cout << ans << endl;
}