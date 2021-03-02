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

void algdec(int e, vector <vector <int> > matric, vector <int> *map, vector <int> *minway)
{
    vector <int> queue;
    queue.push_back(e);
    int v = -1;
    while (!queue.empty())
    {
        e = queue[0]; queue.erase(queue.begin());
        if (v == -1)
            (*minway)[e] = 0;
        else
            (*minway)[e] = min((*minway)[v] + matric[v][e], (*minway)[e]);
        (*map)[e] = 1;
        for (int i = 0; i < matric.size(); ++i)
            if ((*map)[i] != 1)
                queue.push_back(i);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector <vector <int> > matric(n, vector <int> (n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matric[i][j];
    vector <int> map(n, 0);
    vector <int> minway(n, INT_MAX);
    vector <int> queue; //queue.erase(queue.begin()); queue.push_back(elem);
    algdec(0, matric, &map, &minway);
    int u;
    cin >> u;
    while (u != -1)
    {
        cout << minway[u] << endl;
        cin >> u;
    }
    return 0;
}