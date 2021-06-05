#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
int L[MM][MM];
string a, bi;
int main(){
    cin >> a >> bi;
    int n = a.size(), m = bi.size();
  
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= n ; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
  
            else if (a[i - 1] == bi[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
  
    cout << max(a.size(), bi.size()) - L[n][m] << "\n";
    return 0;
}
  