#include <iostream>
#include <vector>

using namespace std;

bool trust(int i, vector <vector <int>> countryTop, vector <vector <int>> autoTop)
{
    bool ans = false;
    int a = 0, max_cT = 0, max_aT = 0;
    for (int m = 0; m < countryTop[i].size(); ++m)
    {
        for (int n = 0; n < countryTop.size(); ++n)
        {
            max_cT = countryTop[n][m] > max_cT ? countryTop[n][m] : max_cT;
            max_aT = autoTop[n][m] > max_aT ? autoTop[n][m] : max_aT;
        }
        if (countryTop[i][m] == max_cT && autoTop[i][m] == max_aT)
            a++;
        max_cT = 0; max_aT = 0;
    }
    if (a > 0.3 * countryTop.size())
        ans = true;
    return ans;
}

int main()
{
    int N, M; cin >> N >> M;
    vector <vector <int>> countryTop(N, vector <int> (M));
    vector <int> worldTop(N);
    int s = 0;
    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            cin >> countryTop[n][m];
            s += countryTop[n][m];
        }
        worldTop[n] = s;
        s = 0;
    }
    vector <vector <int>> autoTop(N, vector <int> (M));
    for (int n = 0; n < N; ++n)
        for (int m = 0; m < M; ++m)
            cin >> autoTop[n][m];
    
    int max_n = 0;
    for (int n = 0; n < N; ++n)
    {
        if (trust(n, countryTop, autoTop))
        {
            cout << "YES\n";
            cout << n + 1 << endl;
            return 0;
        }
        max_n = worldTop[n] > worldTop[max_n] ? n : max_n;
    }
    cout << "NO\n";
    cout << max_n + 1 << endl;
    return 0;
}