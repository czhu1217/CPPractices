#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int ar[3][230];
int n, ans = 1;
string st;

int main()
{
   
for(int i=0;i<5;i++){
    getline(cin, st);
    n = st.length();
    for (int j = 0; j < n; j++)
    {
        ar[1][j] = 1;
    }
    int pre, prepre;
    for (int l = 2; l <= n; l++)
    {
        pre = (l-1)%3;
        prepre = (l-2)%3;
        for (int j = 0; j < n - l+1; j++)
        {
            if (st[j] == st[j + l - 1] && l == 2)
            {
                ar[2][j + 1] = 2;

            }
            else if (st[j] == st[j + l - 1])
            {
                ar[l%3][j + l - 1] = ar[prepre][j + l - 2] + 2;
            }
            else
            {
              
                ar[l%3][j + l - 1] = max(ar[pre][j + l - 2], ar[pre][j + l - 1]);
            }

        }

    }
    cout << ar[n%3][n - 1] << "\n";
}
    
    return 0;
}

using namespace std;

/// method #2: interval dp
const int MM = 260;
int dp[260][260], N; 
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int ww=1; ww<=5; ww++){
        cin >> s; N = s.size();
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; i++) dp[i][i] = 1; /// init length 0
        for(int len = 1; len < N; len++){ /// loop from length 1
            for(int l = 0; l+len < N; l++){
                int r = l + len;
                if(s[l] == s[r]) dp[l][r] = dp[l+1][r-1] + 2;
                else dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
        }
        cout << dp[0][N-1] << "\n";
    }
}