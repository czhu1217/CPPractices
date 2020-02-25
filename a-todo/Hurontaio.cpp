#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
string a, b;
ll hash1[100005], hash2[100005];
ll p[100005];
int base = 131;
map<string, bool> m;
int getHash(int l, int r){

}
int main(){
    p[0] = 1;
    for(int i=1;i<100005;i++) p[i] = p[i-1]*base;
    cin >> a >> b;
    for(int i=1;i<=a.size();i++){
        hash1[i] = hash1[i-1]*base + a[i-1];
    }
    for(int i=1;i<=b.size();i++){
        hash2[i] = hash2[i-1]*base + b[i-1];
    }
    int ans = 0;
    for(int i=1;i<=min(a.size(),b.size());i++){
        if()

    }
   

}