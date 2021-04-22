#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<ll, ll> pi;
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second

ll n, m, k, a, b;
map<ll, ll> c, r;
int main(){
    cin >> n >> m >> k;
    FOR(i, 1, k){
        cin >> a >> b;
        r[a] ^= 1;
        c[b] ^= 1;
    }
    vector<ll> v1, v2;
    for(auto e:r){
        if(e.s){
            v1.pb(e.f);
        }
    }
    for(auto e:c){
        if(e.s){
            v2.pb(e.f);
        }
    }
    cout << max(v1.size(), v2.size()) << "\n";
    while(v1.size()&&v2.size()){
        cout << v1.back() << " " << v2.back() << "\n";
        v1.pop_back(); v2.pop_back();
    }
    while(!v1.empty()){
        cout << v1.back() << " " << 1 << "\n";
        v1.pop_back();
        cout << v1.back() << " " << 1 << "\n";
        v1.pop_back();

    }
        while(!v2.empty()){
        cout << 1<< " " << v2.back() << "\n";
        v2.pop_back();
        cout << 1 << " " << v2.back() << "\n";
        v2.pop_back();

    }
    return 0;
}