#include <iostream>
#include <algorithm>
#include <vector>
#include <string> //stoi
#include <climits>

using namespace std;

void print_vec(vector <vector <int> > vec)
{
    cout << "\n";
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[i][j] == INT_MAX) cout << "∞ ";
            else cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    vector <vector <int> > vec(n, vector <int> (n));
    string temp;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (temp == "inf" || temp == "-1") vec[i][j] = INT_MAX;
            else vec[i][j] = stoi(temp);
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);

    print_vec(vec);
    return 0;
}
