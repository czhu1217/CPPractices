#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 2005;
int n, m, x, y, z;
vector<pi> v[3];
bool a[MM];bool pos;
int main(){
    cin >> n >> m;
    FOR(i, 1, m){
        cin >> x >> y >> z;
        v[z].pb({x, y});
    }
    for(auto e:v[2]){
        FOR(i, e.f, e.s){
            a[i] = 1;
        }
    }
    for(auto e:v[1]){
        pos = 0;
        FOR(i, e.f, e.s){
            if(!a[i]){
                pos = 1;
            }
        }
        if(!pos){
            cout << "Impossible\n";
            return 0;
        }
    }
    FOR(i, 1, n){
        if(a[i]) cout << 2 << " ";
        else cout << 1 << " ";
    }
    cout << "\n";

    return 0;
}