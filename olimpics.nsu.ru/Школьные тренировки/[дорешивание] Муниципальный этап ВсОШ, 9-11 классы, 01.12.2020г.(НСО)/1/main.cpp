#include <iostream>

using namespace std;

unsigned short int len(unsigned int n)
{
    unsigned short int ans = 0;
    while (n > 0)
    {
        n /= 10;
        ans++;
    }
    return ans;
}

int main()
{
    unsigned short int D; cin >> D; //number in garland
    unsigned int N; cin >> N; //number of birthday
    
    int ans = -1;
    unsigned int lenght = len(N), a = 0, d = 1;
    for (int l = lenght; l > 0; --l)
    {
        for (int i = 0; i < l; ++i)
        {
            a += D * d;
            d *= 10;            
        }
        
        ans += N / a;
        N = N % a;
        a = 0; d = 1;
    }
    cout << ans;
    return 0;
}