#include <iostream>
#include <vector>

using namespace std;

void encoding(int n, int m, vector <vector <int>> map)
{
    vector <vector <int>> ans(n + m);
    int counter = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == 1)
                counter++;
            else if (counter != 0)
            {
                ans[i].push_back(counter);
                counter = 0;
            }
            else
                continue;
        }
        if (counter != 0)
        {
            ans[i].push_back(counter);
            counter = 0;
        }
    }

    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (map[i][j] == 1)
                counter++;
            else if (counter != 0)
            {
                ans[n + i].push_back(counter);
                counter = 0;
            }
            else
                continue;
        }
         if (counter != 0)
        {
            ans[n + j].push_back(counter);
            counter = 0;
        }
    }

    cout << "Code:" << endl;
    cout << "Str:" << endl;
    for (int x = 0; x < n + m; ++x)
    {
        if (x == n)
            cout << "Stb:" << endl;
        for (int y = 0; y < ans[x].size(); ++y)
            cout << ans[x][y] << ' ';
        cout << endl;
    }

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int>> map(n, vector <int> (m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> map[i][j];
    
    vector <vector <int>> code;
    encoding(n, m, map);
    return 0;
}
