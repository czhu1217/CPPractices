#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
long long int a, b, x;
long long int ans;
using namespace std;
int main(){
    cin >> a >> b >> x;
    if(a%x!=0) a = a/x +1;
    else a = a/x;
     b = (long long int)(b/x);
    if(b-a<=0){
        cout << 0 << "\n";
        return 0;
    }
    ans = b-a+1;
    cout << ans << "\n";
    return 0;

}