#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    int T; cin >> T;
    while(T--){
        int M; string s; int P, Q, K, D;
        map<string, vector<pair<int, int>>> mp;
        ll ans=0;
        int N; cin >> N;
        for(int i=1;i<=N;i++){
            cin >> M;
            for(int j=1;j<=M;j++){
                cin >> s;
                cin >> P >> Q;
                mp[s].push_back({P, Q});
            }
        }
        cin >> K;
        for(int i=1;i<=K;i++){
            cin >> s >> D;
            sort(mp[s].begin(), mp[s].end());
            for(auto e:mp[s]){
                if(D==0)break;
                ans += e.first*min(e.second, D);
                D = max(0, D-e.second);
            }
        }
        cout << ans << "\n";



    }
    return 0;

}