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
ll N, K, Q;
ll find(ll n){
    if(n==1)return 1;
    if(n<=1+K)return 1;
    ll rem = n%K;
    if(rem==1||rem==0) return n/K;
    else return n/K+1;
}
int main(){
     cin >> N >> K >> Q;
     for(ll i=1;i<=Q;i++){
         ll cnt=0;
         ll x, y;
        cin >> x >> y;
        if(K==1){
             cout << abs(x-y) << "\n";
             continue;
         }
        while(x!=y){
            if(x>y) x = find(x);
            else y = find(y);
            cnt++;
        }
        cout << cnt << endl;
     }
     return 0;

}