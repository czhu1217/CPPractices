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
int L,N; pair<int, int> a[100005];
int main(){
    cin >> L;
    cin >> N;
    int ans = 0;
    int mx = 0, mi;
    for(int i=1;i<=N;i++){
        scanf("%d%d", &a[i].first, &a[i].second);
        if(a[i].second>mx)mx = a[i].second;
    }
    sort(a+1, a+1+N);
    int end = 0;
    for(int i=1;i<=N;i++){
        ans = max(ans, a[i].first-end);
        end = max(end, a[i].second);
    }
   mx = L-mx;
    ans = max(ans,  mx);
    cout << ans << "\n";
    return 0;

}