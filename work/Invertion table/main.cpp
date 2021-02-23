#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //coding
    int n; 
    vector <int> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vector <int> ans;
    for (int i = 0; i < n; ++i)
    {
        
    }

    //decoding
    int n; cin >> n;
    vector <int> t(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    vector <int> ans;
    for (int j = n - 1; j >= 0; --j)
    {
        int c, cc = t[j];
        t[j] = j + 1;
        cout << j + 1;
        for (int i = j + 1; i < n; ++i)
        {
            c = t[i];
            t[i] = cc;
            cc = c;
            c = '\0';
        }
        t.push_back(cc);
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i];
    cout << endl;
    return 0;
}