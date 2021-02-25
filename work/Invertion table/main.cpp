#include <iostream>
#include <vector>

using namespace std;

int main()
{

    //coding
    int n; 
    cin >> n;
    vector <int> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vector <int> ans(n, 0);
    int a;
    for (int i = 0; i < n; ++i)
    {
        a = 0;
        for (int j = 0; j < n; ++j)
        {
            if (s[j] == i + 1)
            {
                ans[i] = a;
                break;
            }
            else if (s[j] > i + 1)
                ++a;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << endl;

    //decoding
    int m; cin >> m;
    vector <int> t(m);
    for (int i = 0; i < m; ++i)
        cin >> t[i];
    vector <int> anss;
    for (int j = m - 1; j >= 0; --j)
    {
        if (j == m - 1)
        {
            anss.push_back(j + 1);
            continue;
        }
        int c = -1;
        int cc = j + 1;
        for (int i = t[j]; i < anss.size(); ++i)
        {
            c = anss[i];
            anss[i] = cc;
            cc = c;
        }
        anss.push_back(cc);
    }
    for (int i = 0; i < m; ++i)
        cout << anss[i] << ' ';
    cout << endl;
    return 0;
}