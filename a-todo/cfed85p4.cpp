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
#include <climits>
using namespace std;
typedef long long ll;
int cnt[100005];
vector<pair<int, int>> v;
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int N, l, r;
        scanf("%d %d %d", &N, &l, &r);
        for(int i=1;i<=N;i++){
            v.push_back({0, i});
        }
        for(;l<=r;l++){
            printf("%d ", v.front().second);
            v.front().first++;

        }
    }
}