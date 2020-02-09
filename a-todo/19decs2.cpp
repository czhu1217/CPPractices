//https://dmoj.ca/problem/usaco19decsilvp2
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
typedef long long ll;
using namespace std;
ll wcnt=0, cnt=0, tcnt = 0, ans=0;
ll N,L, t;
vector<ll> lft, rt, op;
struct cow{ 
    ll w, x, d;
    friend bool operator<(cow &a, cow &b){ 
        return a.x<b.x;
    }

} a[50002];
// vector<cow> a[50002];
int main(){
    cin >> N >> L;
    for(ll i=0;i<N;i++){
        cin >> a[i].w >> a[i].x >> a[i].d;
        cnt += a[i].w;

    }
    sort(a, a+N);
    for(auto e:a){
        if(e.d==-1){
            lft.push_back(e.x);
        }
        else rt.push_back(e.x);
    }
    vector<pair<ll, ll>> v;
    for(ll i=0;i<lft.size(); i++){
        v.push_back({lft[i], a[i].w});
    }
    for(ll i=0;i<rt.size(); i++){
        v.push_back({L-rt[i], a[lft.size()+i].w});
    }
    sort(v.begin(), v.end());
    for(auto e:v){
        
        wcnt += e.second;
        t = e.first;
        if(wcnt*2>=cnt) break;

    }

    queue<ll> q;
    for(ll i = 0; i <N;i++){
        if(a[i].d==-1){
            while((!q.empty())&&(a[i].x-a[q.front()].x)>t*2) q.pop();
            ans += q.size();

        }
        else q.push(i);
    }
    cout << ans << "\n";
    return 0;

}