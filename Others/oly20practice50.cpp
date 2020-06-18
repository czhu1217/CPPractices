
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
#include <climits>
#define f first
#define s second
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
int n; pi v[1002];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v[i].second >> v[i].first;
    }
    sort(v+1, v+n+1);
    reverse(v+1, v+n+1);
    int cur = v[1].f;
    for(int i=1;i<=n;i++){
        if(cur>v[i].f) cur = v[i].f;
        cur -= v[i].s;
        if(cur<0){
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << cur << "\n";
    return 0;

}