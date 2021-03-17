#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void next(int n, vector <int> :: iterator it)
{
    int flag = -1;
    for (int i = n - 2; i >= 0; --i)
    {
        if(*(it + i) < *(it + i + 1))
        {
            flag = i; 
            break;
        }
    }
    if (flag < 0)
        return;
    for (int j = n - 1; j > flag; --j)
    {
        if (*(it + j) > *(it + flag))
        {
            int m = *(it + j);
            *(it + j) = *(it + flag);
            *(it + flag) = m;
            break; 
        }
    }
    sort((it + flag + 1), (it + n - 1));

    return;
}

int main()
{
    int n;
    cin >> n;
    vector <int> M(n);
    for (int i = 0; i < n; i++)
        cin >> M[i];

    vector <int> :: iterator it = M.begin();

    next(n, it);

    for (int i = 0; i < n; i++)
        cout << *(it + i) << " ";
    cout << endl;
    return 0;
}