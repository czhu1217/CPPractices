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
#include <fstream>
using namespace std;
typedef long long ll;
int N, M;
int a[100005][2];
vector<int> line[100005];
int hold[100005];
bool taken[100005];
int cnt=0;
int ans[100005];
int tot = 0;
queue<int> qu;
bool move(int x){
    if(hold[a[x][1]]==0){
        hold[a[x][1]] = x;
        return true;
    }
    if(hold[a[x][1]]>x){
        int nxt = hold[a[x][1]];
        hold[a[x][1]] = x;
        return move(nxt);
    }
    return false;
}
int main(){
    memset(hold, 0, sizeof(hold));
     ifstream cin("cereal.in");
     ofstream cout("cereal.out");
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> a[i][0] >> a[i][1];
        line[a[i][0]].push_back(i);
    }
    for(int i=N;i>0;i--){
        if(hold[a[i][0]]==0){
            hold[a[i][0]] = i;
            ans[i] = ++tot;
        }
        else{
            int cur = hold[a[i][0]];
            hold[a[i][0]] = i;
            if(move(cur)){
                ans[i] = ++tot;
            }
            else ans[i] = tot;

        }
    }
    for(int i=1;i<=N;i++){
        cout << ans[i] << "\n";
    }
    return 0;
}