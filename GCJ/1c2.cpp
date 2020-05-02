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
typedef long long ll; bool used[27];
ll q[10005]; string r[10005]; ll dig[65], upper[27], lower[27]; char ans[10]; vector<ll> pro;
bool case3=1;
void solve(){
    case3=1;
    memset(ans, -1, sizeof ans);
    memset(used, 0, sizeof used);
    for(ll i=0;i<=26;i++){
        upper[i] = 10;
        lower[i]=0;
    }
    ll U; cin >> U;
    for(ll i=1, t;i<=10000;i++){
        cin >> t >> r[i];
        for(ll j=0;j<r[i].size();j++){
            used[r[i][j]-'A']=1;
        }
        lower[r[i][0]-'A']=1;
        if(t!=-1){
            case3=0;
            ll cnt=0;
            while(t){
                dig[cnt] = t%10; t = t/10;
                cnt++;
            }
            if(cnt>r[i].size())continue;
            upper[r[i][0]-'A'] = min(upper[r[i][0]-'A'], dig[cnt-1]);
        
        }
    }
    int cnt2=1;
    for(ll i=0;i<26;i++){
        if(!case3){
        if(used[i]&&upper[i]==10)ans[0] = 'A'+i;

        else if(used[i])
        ans[upper[i]] = 'A'+i;
        }
        else{
            if(used[i]&&lower[i]==0&&ans[0]<=0)ans[0] = 'A'+i;
            else if(used[i]){ ans[cnt2]='A'+i; cnt2++;}

        }
    }
}
int main(){
    ll T; cin >> T;
    for(ll t=1;t<=T;t++){
        printf("Case #%lld: ", t);
        solve();
        for(ll i=0;i<=9;i++){
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}