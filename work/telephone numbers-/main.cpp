#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void print_vec(int n, int m, vector <vector <int> > v)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
			cout << v[i][j] << " ";
		cout << endl;
    }
}

map <int, string> alf {{2, "ABC"}, {3, "DEF"}, {4, "GHI"}, {5, "JKL"}, {6, "MN"}, {7, "PRS"}, {8, "TUV"}, {9, "WXY"}, {0, "OQZ"}};

int main()
{
    string name;
    cin >> name;
    
    string num;
    cin >> num;
    
    int n1 = name.size() + 1;
    int n2 = num.size() + 1;

    vector <vector <int> > arr(n1, vector <int> (n2));
    
    for (int i = 0; i < n1; ++i)
        arr[i][0] = i;
 
    for (int i = 0; i < n2; ++i)
        arr[0][i] = i;
 
    for (int i = 1; i < n1; ++i)
        for (int j = 1; j < n2; ++j)
        {
            if (alf[num[i - 1] - '0'].find(name[j - 1]) != string::npos)
                arr[i][j] = min(min(arr[i - 1][j] + 1, arr[i][j - 1] + 1), arr[i - 1][j - 1]);
	        else
	            arr[i][j] = min(arr[i - 1][j] + 1, arr[i][j - 1] + 1);
        }

    cout << "array with table" << endl;
    print_vec(n1, n2, arr);
    
    int i = n1 - 1, j = n2 - 1;
    

    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] - arr[max(0, i - 1)][j] == 1)
        {
            cout << "insert " << num[i - 1] << " before " << j << endl;
            cout << "\t" << name;

            name.insert(j, 1, num[i - 1]);
            --i;
              
            cout << " -> " << name << endl;
        } 
        else if (arr[i][j] - arr[i][max(j - 1, 0)] == 1)
        {
            cout << "delete " << name[j - 1] << " at " << j - 1 << endl;
            cout << "\t" << name;

            name.erase(j - 1, 1);
            --j; 

            cout << " -> " << name << endl;
        }
        else
        {
            --i;
            --j;
        }

    }

    cout << "resule " << name << endl;
	cout << "ans " << arr[n1 - 1][n2 - 1] << endl;
    return 0;
}