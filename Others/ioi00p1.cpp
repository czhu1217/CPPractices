//palindrome
//longest palindromic subsequence
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long ll;
const int MM = 5002;
short n, dp1[MM], dp2[MM], dp3[MM]; char a[MM];
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        dp2[i]=1;
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j = i+len-1;
            if(a[i]==a[j]&&len==2)
                dp1[i]=2;
            else if(a[i]==a[j])
                dp1[i] = dp3[i+1]+2;
            else
                dp1[i] = max(dp2[i], dp2[i+1]);
        }
        swap(dp1, dp2); swap(dp1, dp3);
    }
    cout << n-dp2[1] << "\n";
    return 0;
}