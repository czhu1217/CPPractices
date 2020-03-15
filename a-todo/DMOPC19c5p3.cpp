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
#include <numeric>
typedef long long ll;
using namespace std;
int r, c, topr, topc, leftr, leftc, dr, dc, gc, sr, sc, dsc, dsr, xi, yi;
ll ans = 0;
int gcd(int u, int v){
    while(v!=0){
        int r = u%v;
        u = v;
        v = r;
    }
    return u;
}
int main(){
    cin >> r >> c;
    for(dr = 0; dr<r;dr++){
        for(dc = 1; dc < c;dc++){
            sr  = dc/gcd(dr, dc);
            sc = dr/gcd(dr, dc);
            int cntr, cntc;
            cntr = dr+sr;
            cntc = dc+sc;
            while(cntr<=r&&cntc<=c){
                ans += (r-cntr)*(c-cntc);
                cntr += sr;
                cntc += sc;
            }
        }
    }
    cout << ans << "\n";
    return 0;

    
}