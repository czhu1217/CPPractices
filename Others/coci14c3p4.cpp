
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
const int MN = 5e5+5, MP = 655;
int bit[MP];
int ans[MN][2];
int n; int cnt1mx[MP], cnt1[MP], cnt2[MP];
pair<pi, int> v[MN];
int query(int pos){
    int sum=0;
    for(int i=pos;i>0;i-=i&-i){
        sum+=bit[i];
    }
    return sum;
}

void update(int pos, int v){
    for(int i=pos; i<MP;i+=i&-i){
        bit[i]+=v ;
    }
}
int main(){
    memset(bit, 0, sizeof bit);
    memset(cnt1, 0, sizeof cnt1); memset(cnt2, 0, sizeof cnt2);
    cin >> n;
    for(int i=1, a, b;i<=n;i++){
        cin >> v[i].f.f >> v[i].f.s;
        v[i].f.f++; v[i].f.s++;
        v[i].s = i;
    }
    sort(v+1, v+1+n);
    // cout << 0 << "\n";
    vector<int> t; int cnt=0;
    for(int i=1;i<=n;i++){

        if(i!=1&&v[i].f.f!=v[i-1].f.f){
            for(auto e:t) update(e, 1);
            t.clear(); cnt=0;
        }
        if(v[i].f.s==1)cnt++;
        if(v[i].f.f==1)cnt1[v[i].f.s]++;
        ans[v[i].s][0] = n-query(v[i].f.s-1);
        if(v[i].f.s == 651) ans[v[i].s][0] -= cnt;
        if(v[i].f.f==651) ans[v[i].s][0] -= cnt1[v[i].f.s];

        // cout << v[i].f.f << " " << v[i].f.s << " " << query(v[i].f.s) << "\n";
        t.pb(v[i].f.s);
    }
    t.clear();
    for(int i=1;i<=n;i++){
        v[i].f.f = 654 - v[i].f.f; v[i].f.s = 654-v[i].f.s;
    }
    memset(bit, 0, sizeof bit);
    sort(v+1, v+1+n);
    for(int i=1;i<=n;i++){
        if(i!=1&&v[i].f.f!=v[i-1].f.f){
            for(auto e:t) update(e, 1);
            t.clear();
        }
        ans[v[i].s][1] = query(v[i].f.s-1)+1;
        //  cout << v[i].f.f << " " << v[i].f.s << " " << query(v[i].f.s) << "\n";
        t.pb(v[i].f.s);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i][1] << " " << ans[i][0] << "\n";
    }

    return 0;
}