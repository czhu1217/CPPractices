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
void solve(){
    queue<pair<int, int>> q; int a[200005]; int par[200005];
    map<int, vector<pair<int, int>>> v;
    int n; cin >> n;
    int len=n+1;
    v[len].push_back({1, n});
    int cnt=1;
    while(len>0){
        if(v[len].empty()){len--;continue;}
        sort(v[len].begin(), v[len].end());
        for(auto e:v[len]){
            int mid = (e.first+e.second)/2;
            a[mid]=cnt;
            int len1 = mid-e.first, len2 = e.second-mid;
            if(len2>0) v[len2].push_back({mid+1, e.second});
            if(len1>0) v[len1].push_back({e.first, mid-1});
        cnt++;

        }
        len--;

    }
    for(int i=1;i<=n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}