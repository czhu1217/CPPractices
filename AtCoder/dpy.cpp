//grid 2
//mod division
//number mod inversion
//n choose k
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, int>> v;
const int MM = 2e5+5, mod = 1e9+7;
int h, w, n; ll f[MM], inv[MM], dp[3003];
ll quick_pow(ll x, int exp){
    if(exp==0)return 1;
    ll t = quick_pow(x, exp/2);
    t = t*t%mod;
    return (exp&1)?t*x%mod:t;
}
ll comb(int n, int k){return f[n]*inv[k]%mod*inv[n-k]%mod;}
int main(){
    cin >> h >> w >> n;f[0]=inv[0]=1;
    for(int i=1;i<=h+w;i++) f[i] = f[i-1]*i%mod;
    inv[h+w]=quick_pow(f[h+w], mod-2);
    for(int i=h+w-1;i>=1;i--){
        inv[i] = (i+1)*inv[i+1]%mod;
    }
    for(int i=1, ai, bi;i<=n;i++){
        scanf("%d%d", &ai, &bi);
        v.push_back({ai-1, bi-1});
    }
    v.push_back({h-1, w-1});
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        int x = v[i].first, y=v[i].second;
        dp[i] = comb(x+y, x);
        for(int j=0;j<i;j++){
            int xj = v[j].first, yj = v[j].second;
            if(yj<=y)dp[i]=(dp[i]-dp[j]*comb(x-xj+y-yj, x-xj)%mod+mod)%mod;

        }

    }
    cout << dp[n] << "\n";
    return 0;

}