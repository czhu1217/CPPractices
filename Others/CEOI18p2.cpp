#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MM = 2e5+5;
ll n, x, a[MM], len1[MM], len2[MM], ans = 0, j;
int lis[MM], lds[MM];
int len = 0;

int main()
{
	cin >> n >> x;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        if(len==0||a[i]>lis[len]){
            lis[++len] = a[i]; len1[i] = len; continue;
        }
        if(a[i]+x>lis[len]) len1[i] = len+1;
        else len1[i] = lower_bound(lis+1, lis+len+1, a[i]+x)-lis;
        *lower_bound(lis+1, lis+len+1, a[i]) = a[i];

    }
    len = 0;
    for(ll i=n;i>0;i--){
        if(len==0||a[i]<lds[len]){
            lds[++len] = a[i]; len2[i] = len; continue;
        }
        j = lower_bound(lds+1, lds+1+len, a[i], greater<int>())-lds;
        len2[i] = j; lds[j] = a[i];

    }
    for(ll i=1;i<=n;i++){
        ans = max(ans, len1[i]+len2[i]-1);
    }
    cout << ans << "\n";
    return 0;
   
}