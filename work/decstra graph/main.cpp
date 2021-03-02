#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print_vec(vector <vector <int> > v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j] == INT_MAX)
            {
                cout << "∞ ";
                continue;
            }
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector <vector <int> > matic(n, vector <int> (n, INT_MAX));
    vector <int> queue; //queue.erase(queue.begin()); queue.push_back(elem);
    
}