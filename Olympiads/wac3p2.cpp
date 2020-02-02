#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
long long d, h,ave, lft;
long long ans;
int main(){
    cin >> d;
    for(int i=0;i<d;i++){
        scanf("%lld", &h);
        ave = h/3;
        lft = h%3;
        if(lft == 2){
            ans =  (ave+1)*(ave+1)*ave;
        }
        else if(lft==1){
            ans =  (ave+1)*ave*ave;
        }
        else{
            ans = ave*ave*ave;
        }
        cout << ans << "\n";
    }
}