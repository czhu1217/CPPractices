#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int n, a[MM], b[MM], c[MM];
string s;
void update(int x[], int y[], int i){
    int nx = x[n], ny = y[n];
    
    }
int main(){
    cin >> s; n = s.size();
    for(int i=1;i<=n;i++){
        a[i] = a[i-1]; b[i] = b[i-1]; c[i] = c[i-1];
        if(s[i-1]=='A') a[i]++;
        else if (a[i-1]=='B')b[i]++;
        else a[i]++;

    }
    int na = a[n], nb = b[n], nc = c[n];
    for(int i=1;i<=n;i++){
        if(i>=na+nb){
            update(a, b, i);
            update(b, a, i);
        }
        if(i>=na+nc){
            update(a, c, i); update(c, a, i);
        }
        if(i>=nb+nc){
            update(b, c, i); update(c, b, i);
        }
    }

}