#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
typedef  long long ll;
int q;
string s;
int rt = 0;
vector<pair<int, int>> adj[10005];
int dfs(string str){
    for(int i=0;i<str.size();)
}
int main(){
    cin >> s >> q;
    int cnt = 2;
    for(int i=0;i<q;i++){
        char c;cin >> c;

        if(c=='C'){
            int temp;char t;cin >> temp >> t;
            adj[temp].push_back({cnt, t});
            cnt++;
        }
        else{
            string comp; cin >> comp;
            cout << dfs(comp);

        }
    }
    for(int i=1;i<q;i++){
        cout << i << endl;
        for(auto e:adj[i]){
            cout << e.first << " " << e.second << "\n";
        }
        cout << endl;
    }
    return 0;

}