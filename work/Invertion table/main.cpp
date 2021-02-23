#include <iostream>
#include <vector>

using namespace std;

int main()
{
/*
    //coding
    int n; 
    cin >> n;
    vector <int> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vector <int> ans(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int a = 0;
        for (int j = 0; j < n; ++j)
        {
            if (s[j] == ++i)
            {
                ans[i] = a;
                break;
            }
            else if (s[j] > ++i)
                ++a;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
*/
    //decoding
    int m; cin >> m;
    vector <int> t(m);
    for (int i = 0; i < m; ++i)
        cin >> t[i];
    vector <int> anss;
    for (int j = m - 1; j >= 0; --j)
    {
        int c, cc = t[j];
        t[j] = j + 1;
        cout << j + 1;
        for (int i = j + 1; i < m; ++i)
        {
            c = t[i];
            t[i] = cc;
            cc = c;
            c = '\0';
        }
        t.push_back(cc);
    }
    for (int i = 0; i < m; ++i)
        cout << anss[i] << '\t';
    cout << endl;
    return 0;
}