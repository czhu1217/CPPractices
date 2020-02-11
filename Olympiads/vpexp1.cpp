#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
int x, N;
int a[5], b[5], mn1 = 1000, mn2 = 1000, ans1=0, ans2=0;
int main(){
    for(int i=0, x;i<5;i++){
        cin >> x;ans1 += x;
        if(x<mn1)mn1 = x;
    
    }
    for(int i=0, x;i<5;i++){
        cin >> x;
        ans2 += x;
        if(x<mn2)mn2=x;
    }
    ans1 -= mn1; ans2 -= mn2;
    cout << max(ans1, ans2) << endl;
    return 0;

    
}
