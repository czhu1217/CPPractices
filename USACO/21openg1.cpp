#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 2e5+5;
ll MN;
ll n, a[MM], ans;
vector<int> v[MM];
vector<pi> q;
ll last[MM], bit[MM];
// updating the bit array
void update(int idx, int val, int n)
{
    for (; idx <= n; idx += idx&-idx)
        bit[idx] += val;
}
  
// querying the bit array
int query(int idx, int n)
{
    int sum = 0;
    for (; idx>0; idx-=idx&-idx)
        sum += bit[idx];
    return sum;
}
int main(){
    memset(last, -1, sizeof last);
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        v[a[i]].pb(i);
        MN = max(a[i], MN);
    }
    ll cnt=0;
    for(int k=1;k<=MN;k++){
        ll tmp=0;
        if(v[k].size()<1) continue;
        if(v[k].size()==1){
            q.pb({n, v[k][0]});
        }
        else{
            for(int i=0;i<v[k].size()-1;i++){
                q.pb({v[k][i+1], v[k][i]});
            }
            q.pb({n, v[k][v[k].size()-1]});
        }
        
    }
    sort(q.begin(), q.end());
    // for(auto e:q){
    //     cout << e.s << " " << e.f << "\n";
    // }
    // cout << "\n";
    for (int i=1; i<=n; i++)
    {

        if (last[a[i]] !=-1)
            update (last[a[i]], -1, n);
        last[a[i]] = i;
        update(i, 1, n);
        while (cnt < q.size() && q[cnt].f == i)
        {
            // cout << "cnt " << cnt << " " << i << " " << q[cnt].f << "\n";
            ans += 
                     query(q[cnt].f , n)-
                     query(q[cnt].s-1, n)-1;
            cnt++;
            // cout << q[cnt].s << " " << q[cnt].f << "\n";
            // cout << ans << "\n";
        }
    }
    cout << ans << "\n";
    return 0;
};