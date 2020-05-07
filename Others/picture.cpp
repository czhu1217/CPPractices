//line sweep
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
const int MM = 10000;
struct event{
    int x, lo, hi, v;
    bool operator<(const event &e){
        return (x<e.x)||(x==e.x&&v>e.v);
    }
};
int N, ans, cnt[2*MM]; vector<event> cur, pre;
void sweep(){
    sort(cur.begin(), cur.end());
    for(event e:cur){
        if(e.v>0){
            for(int i=e.lo; i<e.hi;i++){
                if(++cnt[i]==1)ans++;
            }
        }
        else{
            for(int i=e.lo; i<e.hi;i++){
                if(--cnt[i]==0)ans++;
            }
        }
    }
}
int main(){
    cin >> N;
    for(int i=1, a, b, c, d; i<=N;i++){
        cin >> a >> b >> c >> d;
        a+=MM; b+=MM; c+=MM; d+=MM;
        cur.push_back({a, b, d, 1});
        cur.push_back({c, b, d, -1});
        pre.push_back({b, a, c ,1});
        pre.push_back({d, a, c, -1});
    }
    sweep(); swap(cur, pre); sweep();
    cout << ans << "\n";
    return 0;

}
