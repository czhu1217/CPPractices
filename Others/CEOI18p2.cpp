//global warming
//longest increasing subsequence and logest descreasing subsequence
//lis and lds
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long ll;
int N, x; 
const int MM = 2e5+2;
int a[MM], bit[MM], lisLen[MM], ldsLen[MM];
vector<int> lis, lds;
int ans = INT_MAX;
int main(){
    cin >> N >> x;
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
        if(lis.empty()||a[i]>lis.back()){ lis.push_back(a[i]); lisLen[i] = lis.size();}
        else{
            lisLen[i] = lower_bound(lis.begin(), lis.end(), a[i])-lis.begin()+1;
            *(lower_bound(lis.begin(), lis.end(), a[i])) = a[i];
        }

    }
    for(int i=N;i>0;i--){
        if(lds.empty()||a[i]<lds.back()){ lds.push_back(a[i]); ldsLen[i] = lds.size();}
        else{
            ldsLen[i] = lower_bound(lds.begin(), lds.end(), a[i])-lds.begin();
            *(lower_bound(lds.begin(), lds.end(), a[i])) = a[i];
        }
    }
    for(int i=1;i<=N;i++){
        ans = max(ldsLen[i]+query(a[i]+x));
    }
    cout << ans << "\n";





}


