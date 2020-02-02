#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
int t, d, p, cnt=0;
int main(){
    cin >> t >> d >> p;
    if(t<-40) cnt++;
    if(d >= 15) cnt++;
    if(p>50) cnt++;
    if(cnt >= 2) cout << "YES\n";
    else{
        cout << "NO\n";
    }
    return 0;
}