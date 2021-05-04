#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

void Complexity(int N, int M, vector <vector <bool>> matric)
{
    vector <unsigned int> complexity(N, -1);
    queue <unsigned int> q;
    
}

int main()
{
    unsigned int N, M;
    cin >> N >> M;
    vector <vector <bool>> matric(N, vector <bool> (N, false));
    unsigned int k_i, theme_j;
    for (unsigned int i = 0; i < N; ++i)
    {
        cin >> k_i;
        for (unsigned int j = 0; j < k_i; ++j)
        {
            cin >> theme_j;
            matric[i][theme_j - 1] = true;
        }
    }
    return 0;
}