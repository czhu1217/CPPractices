#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
typedef  long long ll;
ll pre[200005], bit[200005]; ll ans[200002];
struct tup{ 
    ll i, l, r, v;
    bool operator<(tup &e){
        return v<e.v;
    }
} qu[200005];
ll N, Q;
pair<ll, int> a[200002];
ll query(int pos){
    ll sum=0;
    for(int i=pos;i>0;i-=i&-i){
        sum+=bit[i];
    }
    return sum;
}

void update(int pos, ll v){
    for(int i=pos; i<=N;i+=i&-i){
        bit[i]+=v ;
    }
}
int main(){
    cin >> N >> Q;
    for(int i=1, x;i<=N;i++){
        cin >> x;
        a[i] = {x, i};
    }
    for(int i=1;i<=Q;i++){
        cin >> qu[i].l >> qu[i].r >> qu[i].v;
        qu[i].i = i;
    }
    pre[0] = 0;
    for(int i=1;i<=N;i++){
        pre[i] = a[i].first + pre[i-1];
    }
   
    sort(qu+1, qu+Q+1);
    sort(a+1, a+N+1);
    int j=1;

    for(int i=1;i<=Q;i++){
        while(a[j].first<qu[i].v&&j<=N){
            update(a[j].second, a[j].first);
            j++;
        }
        ans[qu[i].i] =  pre[qu[i].r] - pre[qu[i].l-1] - 2*(query(qu[i].r) - query(qu[i].l-1));
    }
    for(int i=1;i<=Q;i++){
        cout << ans[i] << "\n";
    }
    return 0;

    
}