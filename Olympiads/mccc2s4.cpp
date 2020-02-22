#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
typedef long long ll;
int N;
int a[100004];
set<int> period;
void fac(){
    int lim = ceil(sqrt(N));
    for(int i=1; i<=lim;i++){
        if(N%i==0){
            period.insert(i);
            if(i!=1)
            period.insert(N/i);
        }
    }
}
map<int, int> m;
int cnt, mn = 0x3f, mx=0, uniq=0;
int main(){
    cin >> N;
    fac();
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    for(auto e:period){

        cnt = 0;
        for(int i=1; i<=e;i++){
            map<int, int> ma;
            mx = 0;
            for(int j=i;j<=N;j+=e){
                ma[a[j]]++;
                if(ma[a[j]]>mx)mx = ma[a[j]];
            }
            cnt += N/e-mx;
        }
        if(cnt<mn)mn = cnt;

    }
    cout << cnt << endl;
    return 0;
    
}