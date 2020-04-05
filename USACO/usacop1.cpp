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
int N, M, s, e;
deque<pair<int, int>> qu;
map<int, int> jump;
int ans = 1;
int tot = 0;
bool capable = true;

int main(){
    ifstream cin("socdist.in");
    ofstream cout("socdist.out");
    cin >> N >> M;
    for(int i=1, l, r;i<=M;i++){
        cin >> l >> r;
        qu.push_back({l, r});
        if(r>e)e=r;
    }
    sort(qu.begin(), qu.end());  
    int lo = 1, hi = e/(N-1), mid;
    N--;
    while(lo<=hi){
        mid = (lo+hi)/2;
        capable = true;
        int d = mid;
        int cur = qu[0].first;
        int it=0;
        for(int i=1;i<=N;i++){
            int dt = d;
            while(cur+dt>qu[it].second){
                it++;
                if(it>=qu.size()){
                capable = false;
                break;
                }
                int jump = qu[it].first-cur;
                cur = qu[it].first;
                dt = max(0, dt-jump);
            }
            cur += dt;
 
            if(!capable) break;

        }
        if(capable){
            lo = mid+1;
            ans = mid;
        }
        else{
            hi = mid-1;
        }
    }
    cout << ans << "\n";
    return 0;


}