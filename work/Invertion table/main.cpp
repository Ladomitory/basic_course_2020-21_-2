#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> s;
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vector <int> ans;
    for (int j = s.size() - 1; j >= 0; --j)
    {
        int c, cc = s[j];
        s[j] = j + 1;
        for (int i = j + 1; i < s.size(); ++i)
        {
            c = s[i];
            s[i] = cc;
            cc = c;
            c = '\0';
        }
        s.push_back(cc);
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i];
    cout << endl;
    return 0;
}