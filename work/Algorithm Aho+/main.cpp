#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void)
{
    ifstream ifile("C:\\Users\\radomir\\proga\\informatic\\basic course 2020-21  2\\work\\Algorithm Aho\\input.txt");
    string s1, s2;
    int n, m, i, j;
    ifile >> s2;
    ifile >> s1;
    ifile.close();
    n = s1.size() + 1;
    m = s2.size() + 1;
    vector <vector <int>> start(n, vector<int>(m));
    for (i = 0; i < n; i++)
    {
        start[i][0] = i;
    }
    for (i = 1; i < m; i++)
    {
        start[0][i] = i;
    }
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            if (s1[i - 1] != s2[j - 1])
            {
                start[i][j] = min(start[i - 1][j], start[i][j - 1]) + 1;
            } 
            else
            {
                start[i][j] = min(min(start[i - 1][j], start[i][j - 1]), start[i - 1][j - 1]);
            }
        }
    }
    cout << start[n - 1][m - 1] << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << start[i][j] << ' ';
        }
        cout << endl;
    }
    j = m - 1;
    i = n - 1;
    while (i > 0 && j > 0) 
    {
        if (start[i][j] > start[i][j - 1])
        {
            cout << "delete " << s2[j - 1] << endl;
            j--;
        }
        else
        {
            if (start[i - 1][j] < start[i][j])
            {
                cout << "insert " << s1[i - 1] << endl;
                i--;
            }
            else
            {
                i--;
                j--;
                cout << "skip " << endl;
            }
        }
    }
    if (i == 0)
    {
        while (j != 0)
        {
            cout << "delete " << s2[j - 1] << endl;
            j--;
        }
    }
    if (j == 0)
    {
        while (i != 0)
        {
            cout << "insert " << s1[i - 1] << endl;
            i--;
        }
    }
    return 0;
}