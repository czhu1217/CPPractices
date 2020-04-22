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
const int MM = 2e5+5;
int main(){
    int T; cin >> T;
    while(T--){
        int a[MM];
        int N; cin >> N;
        vector<int> p, n;
        for(int i=1;i<=N;i++){
            scanf("%d", &a[i]);
        }
        p.push_back({a[1]});
        for(int i=2;i<=N;i++){

                if(!p.empty()&&(double)a[i]/p.back()>0){
                    p.back() = max(p.back(), a[i]);
                }
                else p.push_back(a[i]);

            
        }
       
                ll sum=0;
                for(auto e:p)sum +=e;
                printf("%lld\n", sum);

        
    }
    return 0;

}