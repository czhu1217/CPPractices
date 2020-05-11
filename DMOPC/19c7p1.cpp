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
#include <unordered_map>
typedef long long ll;
using namespace std;
int a, b, c, d;
int main(){
    cin >> a >> b >> c >> d;
    int cnt=2*a+4*b+3*c;int left;
    if(b==0&&a<c-1){
        cout << "invalid" << "\n"; return 0;
    }
    if(a<c&&b!=0){
        cout << "invalid" << "\n"; return 0;
    }
    left = (a+b+c+1)*4-cnt;
    if(left!=d){
        cout << "invalid" << "\n";
    }
    else{
        cout << "C" << a+b+c+1 << "H" << d << "\n";
    }



}