#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int ar[260][260];
int n, ans = 1;
string st;

int main()
{
   
for(int i=0;i<5;i++){
    getline(cin, st);
    n = st.length();
    for (int j = 0; j < n; j++)
    {
        ar[j][j] = 1;
    }
    for (int l = 2; l <= n; l++)
    {
        for (int j = 0; j < n - l+1; j++)
        {
            if (st[j] == st[j + l - 1] && l == 2)
            {
                ar[j][j + 1] = 2;

            }
            else if (st[j] == st[j + l - 1])
            {
                ar[j][j + l - 1] = ar[j + 1][j + l - 2] + 2;
            }
            else
            {
                ar[j][j + l - 1] = max(ar[j][j + l - 2], ar[j + 1][j + l - 1]);
            }
        }
    }
    cout << ar[0][n - 1] << "\n";
}
    
    return 0;
}