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
typedef long long ll;
map<ll, ll> a;
vector<ll> v;
int main(){
    ll po = pow(2, 32);
    ll mo = po%2654435761;
    cout << mo;

    int N, M; cin >> N >> M;
    for(int i=1;i<=N;i++){
        ll temp = 0;
        ll t; scanf("%lld", &t);
        while((temp+t)%2654435761!=0){
            temp += po;
        }
        v.push_back((temp+t)/2654435761);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll ans=0;
    for(int i=0;i<M;i++){
        ans += v[i];

    }
    cout << ans << "\n";
    return 0;
    

}