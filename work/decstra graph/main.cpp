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
    vector <int> queue;
    vector <int> map(matric.size(), 0);
    queue.push_back(e);
    int v = -1;
    while (!queue.empty())
    {
        e = queue[0]; queue.erase(queue.begin());
        if (v == -1)
            (*minway)[e] = 0;
        else
            (*minway)[e] = min((*minway)[v] + matric[v][e], (*minway)[e]);
        for (int i = 0; i < matric.size(); ++i)
            if (matric[e][i] > 0 && (*minway)[i] < (*minway)[e] + matric[e][i])
                queue.push_back(i);
        v = e;
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
    vector <int> minway(n, INT_MAX);

    int e = -2;
    while (e != -1 && e < n)
    {
        cout << "Start node\n";
        cin >> e;
        algdec(e, matric, &minway);
        print_vec(minway);
    }
    cout << "end" << endl;
    return 0;
}