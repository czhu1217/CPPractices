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
typedef long long ll;
vector<pair<int, int>> v;
int h, w, n;
int main(){
    cin >> h >> w >> n;
    for(int i=1, ai, bi;i<=n;i++){
        scanf("%d%d", &ai, &bi);
        v.push_back({ai, bi});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        
    }

}