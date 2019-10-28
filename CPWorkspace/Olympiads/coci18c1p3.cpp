#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, p, ans;
vector<long long> l(1), r(1);
bool check(int lmt){
    int cnt = 0;
    for(int i=0, j=0;i<n&&j<m;){
        if(abs(l[i]-r[j])<=lmt){
            i++;
            j++;
            cnt++;
        }
        else if(l[i]<r[j]) i++;
        else j++;
    }
    return cnt == min(n, m);
}
int main(){
    scanf("%d %d", &n,&m);
    l.resize(n);
    r.resize(m);
    p = min(n, m);
    for(int i=0;i<n;i++){
        scanf("%d", &l[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d", &r[i]);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int lo=0, hi = 1e9;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)){
            ans = mid;
            hi = mid -1;
        }
        else{
            lo = mid+1;
        }
    }
    printf("%d\n", ans);




    return 0;
}