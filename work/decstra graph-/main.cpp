#include <iostream>
#include <vector>

#include <climits>

using namespace std;

void print_vec(vector <int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == INT_MAX)
        {
            cout << "∞ ";
            continue;
        }
        cout << v[i] << ' ';
    }
    cout << endl;
    return;
}

void algdec(int e, vector <vector <int> > matric, vector <int> *minway)
{
    vector <pair <int, int> > queue;
    vector <int> map(matric.size(), 0);
    pair <int, int> a;
    a.first = e;
    a.second = -1;
    queue.push_back(a);
    int v;
    while (!queue.empty())
    {
        e = queue[0].first;
        v = queue[0].second;
        queue.erase(queue.begin());
        if (v == -1)
            (*minway)[e] = 0;
        else
            (*minway)[e] = min((*minway)[v] + matric[v][e], (*minway)[e]);
        for (int i = 0; i < matric.size(); ++i)
            if (i != e && matric[e][i] > 0 && (*minway)[i] > (*minway)[e] + matric[e][i])
            {
                a.first = i;
                a.second = e;
                queue.push_back(a);
            }

    }
    return;
}

int main()
{
    int n;
    cout << "Size\n";
    cin >> n;
    vector <vector <int> > matric(n, vector <int> (n));
    cout << "Matric\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matric[i][j];

    int e = -2;
    cout << "Start node\n";
    cin >> e;       
    while (e != -1 && e < n)
    {
        vector <int> minway(n, INT_MAX);
        algdec(e, matric, &minway);
        print_vec(minway);
        cout << "Start node\n";
        cin >> e;
    } 
    cout << "end" << endl;
    return 0;
}