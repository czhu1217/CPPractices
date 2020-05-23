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
typedef pair<int, int> pi;
#define f first
#define s second
const int MM = 5e5+5;
int a[MM], freql[MM], freqr[MM], lft[MM], rt[MM];
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    freql[0]=freqr[n+1]=lft[0]=rt[n+1]=0;
    for(int i=1;i<=n;i++){
        freql[i] = freql[i-1];
        if(a[i]>lft[i-1]){
            lft[i] = a[i];
            freql[i]=1;
        }
        else if(a[i]==lft[i-1]){
            lft[i]=lft[i-1]; freql[i] = freql[i-1]+1;
        }
        else lft[i] = lft[i-1];
    }
    for(int i=n;i>0;i--){
        rt[i] = rt[i+1];
        freqr[i] = freqr[i+1];
        if(a[i]>rt[i+1]){
            rt[i]= a[i]; freqr[i]=1;
        }
        else if(a[i]==rt[i+1]) freqr[i] = freqr[i+1]+1;
    }

    for(int i=1;i<=q;i++){
        int a, b; cin >> a >> b;
        if(lft[a-1]>rt[b+1]){
            cout << lft[a-1] << " " << freql[a-1] << "\n";
        }
        else if(lft[a-1]<rt[b+1]) cout << rt[b+1] << " " << freqr[b+1] << "\n";
        else{
            cout << rt[b+1] << " " << freqr[b+1]+freql[a-1] << "\n";
        }
    }
    return 0;
}