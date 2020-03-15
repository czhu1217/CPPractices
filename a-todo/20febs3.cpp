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
vector<vector<int>> adj;
vector<int> a;
int n;
int main(){
    cin >> n;
    adj.resize(n+1);
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1, x, y;i<=n;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }



}