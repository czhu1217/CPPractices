

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
#include <climits>
#define f first
#define s second
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 2e5+1;
int n, a[MM], cnt[MM], fre[MM]; bool done[MM];
int ans, res, cur, pre;
int main(){
    scanf("%d", &n);

    for(int i=1;i<=n;i++)scanf("%d", &a[i]);
    ans=n;
    for(int i=2;i*i<=n;i++){
        memset(cnt, 0, sizeof cnt);
        memset(fre, 0, sizeof fre);
        for(int j=1;j<=i*i;j++){
            cnt[a[j]]++;
        }
        for(int j=1;j<=n;j++){
            if(cnt[j]){
                fre[cnt[j]]++;
            }
        }
        if(fre[i]==i){ ans++;}
        for(int j=i*i+1; j<=n;j++){
            cur = a[j], pre = a[j-i*i];
            fre[cnt[cur]]--;
            cnt[cur]++;
            fre[cnt[cur]]++;
            fre[cnt[pre]]--;
            cnt[pre]--;
            fre[cnt[pre]]++;
            if(fre[i]==i){
                // cout << i << "\n"; 
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}