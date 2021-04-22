#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
vector<int>v;
int n, x, nn, xx;
int main(){
    cin >> n >> x;
    nn = n;
    x = n-x;
     xx = x;
    int k = 0;
    v.pb(k); n--;
    while(x>1){
        x--;
        k ^= 1;
        v.pb(k);
        n--;
    }
    FOR(i, 1, n) v.pb(k);
    if(k^0) x--;
    if(x!=0){
        cout << -1 << "\n"; return 0;
        }
    else{
        for(int i=0;i<v.size()-1;i++) cout << v[i] << " ";
        cout << v.back();
    }
    cout << "\n";

    return 0;
}