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
#define f first;
#define s second;
int T, N;
map<int , int> m;
map<int, bool> vis;
vector<pair<int, int>> v;
int cnt = 0;
int main(){
    cin >> T >> N;
    for(int i=1, x;i<=N;i++){
        cin >> x;
        if(x<0){
            v.push_back({-x, -1});
        }
        else v.push_back({x, 1});
    }
    sort(v.begin(), v.end());
    int cur = 0;
    for(auto e:v){
        int dis;
            dis = abs(cur-e.first*e.second);
        if(T-dis>=0){
            T -= dis;
            cur = e.first*e.second;
            cnt++;
        }
        else break;
    }
    cout << cnt << "\n";
    return 0;

}