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
#include <unordered_map>
using namespace std;
int N, H, I, M;
vector<pair<int, int>> adj[100004];
int val[100004];
set<pair<int, int>> se;
int main(){
    cin >> N >> I >> H >> M;
    for(int i=1;i<=N;i++){
        val[i] = H;
    }
    for(int i=1;i<=M;i++){
        int x, y;
        cin >> x >> y;
        se.insert({x, y});
    }
    for(auto e:se){
        int mx = val[e.second];
        int l = min(e.first, e.second);
        int r = max(e.first, e.second);
        val[e.first] = min(val[e.first], val[e.second]);
        for(int i=l+1;i<r;i++){
            val[i] = min(val[e.first]-1, val[i]-1);
        }
    }
    for(int i=1;i<=N;i++){
        cout << val[i] << "\n";
    }
    return 0;



}