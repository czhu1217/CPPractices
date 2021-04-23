#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<long long, long long> pi;
#define FOR(i, a, b) for (long long i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
ll n, ans;
vector<ll> v;
int main(){
    cin >> n;
    for(long long i=2;i*i<=n;i++){
        ll cnt = 0;
        while(n%i==0){
            cnt++;
            n /= i;
        }
        v.pb(cnt);
    }
    if(n>1) v.pb(1);
     for(auto e:v){
            // cout << e << " ";
            long long t = sqrt(2*e);
            while(t*(t+1)>2*e) t--;
            // cout << t << "\n";

            ans += t;
        }
        // cout << "\n";
		cout << ans << '\n';
    return 0;
}