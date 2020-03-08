
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int MM = 1e5+5;
string s, t; int n, r[2*MM], dif[2*MM];ll dp1[MM], dp2[MM], ans;
void manacher(ll ans[]){
    memset(r, 0, sizeof(r));
    memset(dif, 0, sizeof(dif));
    int p=0, mx = 0; r[0] = 1; dif[0] ++; dif[1]--;
    for(int i=1;i<=2*n;i++){
        if(mx>i)
            r[i] = min(r[2*p-i], mx-i);
            else r[i] = 1;
            while(i>=r[i]&&t[i+r[i]]==t[i-r[i]]) r[i]++;
            if(i+r[i>mx]){
                p=i; mx = i+r[i];
            }
            dif[i]+=dif[i-1]+1; dif[i+r[i]]--;

    }

    for(int i=1; i<=2*n; i+=2) ans[(i+1)/2] = dif[i];
}
int main(){
    cin >> s; n = s.size();
    for(int i=0;i<s.size();i++){
        t.push_back('#');
        t.push_back(s[i]);
    }
    t.push_back('#');
    manacher(dp1);
    reverse(t.begin(),t.end());
    manacher(dp2);
    for(int i=1;i<=n;i++){
        dp1[i] += dp1[i-1];
        ans += dp1[i]*dp2[n-i];

    }
    cout << ans << endl;
    return 0;


}