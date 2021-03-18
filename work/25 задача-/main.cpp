#include <iostream>
#include <cmath>
using namespace std;

pair<int, int> dcheck(int n)
{
  int q = 0;
  int firstD = -1, secondD = -1;
  for(int i = 2; i <= sqrt(n); ++i)
  {
    if(n % i == 0)
    {
      if(q == 0 && n != i * i)
      {
        firstD = i;
        secondD = n / firstD;
        q++;
      }
      else return make_pair(-1, -1);
    }
  }
  return make_pair(firstD, secondD);
}

int main() 
{
  pair<int, int> ans;
  for(int i = 174457; i <= 174505; ++i)
  {
    ans = dcheck(i);
    if(ans.second != -1) cout << ans.first << " " << ans.second << endl;
  }
  return 0;
}