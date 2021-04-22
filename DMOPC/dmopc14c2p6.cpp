#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 1e5+5;
int n, q, a[MM]; pair<pi, pi> p[MM];
pi ai[MM]; ll bit[MM];
ll ans[MM];
int query(int pos){
    int sum=0;
    for(int i=pos;i>0;i-=i&-i){
        sum+=bit[i];
    }
    return sum;
}

void update(int pos, int v){
    for(int i=pos; i<=n;i+=i&-i){
        bit[i]+=v ;
    }
}

int main(){
    cin >> n;
    FOR(i, 1, n){ cin >> a[i]; ai[i] = {a[i], i};}
    sort(ai+1, ai+1+n); reverse(ai+1, ai+1+n);
    int it = 1;
    cin >> q;
    FOR(i, 1, q){
        cin >> p[i].s.f >> p[i].s.s >> p[i].f.f;
        p[i].f.s = i;
    }
    sort(p+1, p+1+q);
    reverse(p+1, p+1+q);
    int l, r;
    FOR(i, 1, q){
        l = p[i].s.f; r = p[i].s.s;
        l++;r++;
        while(ai[it].f>=p[i].f.f&&it<=n){
            update(ai[it].s, ai[it].f);
            it++;
        }
        ans[p[i].f.s] = query(r) - query(l-1);

    }
    FOR(i, 1, q) cout << ans[i] << "\n";



    return 0;
}