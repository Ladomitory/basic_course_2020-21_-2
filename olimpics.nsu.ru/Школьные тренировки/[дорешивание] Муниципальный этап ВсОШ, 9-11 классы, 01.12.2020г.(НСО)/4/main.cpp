#include <iostream>
#include <vector>

using namespace std;

unsigned int Complexity();

int main()
{
    unsigned int N, M; 
    cin >> N >> M;
    vector <vector <unsigned int>> association(N);
    unsigned int k_i, theme_j;
    for (unsigned int i = 0; i < N; ++i)
    {
        cin >> k_i;
        for (unsigned int j = 0; j < k_i; ++j)
        {
            cin >> theme_j;
            association[i].push_back(theme_j);
        }
    }
    vector <unsigned int> complexity(N, 0);

    return 0;
}