#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
int n;
vector<pair<int, int>> pi;
ll ans = 0;
int main(){
    cin >> n;
    for(int i=0, x, y;i<n;i++){
        cin >> x >> y;
        pi.push_back({x, y});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(pi[i].first==pi[j].first){
                    if(pi[k].second==pi[i].second){
                        ll area = abs(pi[i].second-pi[j].second)*abs(pi[k].first-pi[i].first);
                        if(area>ans)ans = area;
    
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;


}