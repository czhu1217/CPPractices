//polygon area given coordinates
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
int N; int a[102][2];
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a[i][0] >> a[i][1];
    }
    double ans=0.0, x1, x2, y1, y2;
    for(int i=1;i<N;i++){
         x1 = a[i][0]; x2 = a[i+1][0];
         y1 = a[i][1]; y2 = a[i+1][1];
         ans += (x1*y2-x2*y1);
    }
    x1 = a[N][0]; x2 = a[1][0];
    y1 = a[N][1]; y2 = a[1][1];
    ans += (x1*y2-x2*y1);
    cout << ceil(fabs(ans/2.0)) << endl;
    return 0;
    
}