#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3005;
int a[MM];ll taro[MM][MM], jiro[MM][MM], n;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        if(n%2) taro[i][i] = a[i];
        else jiro[i][i] = a[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j+i-1<=n;j++){
            int k = j+i-1;
            //taro's turn
            if((n%2==0&&(i%2==0))||((n%2)&&(i%2)))
                taro[j][k] = max(a[j]-jiro[j+1][k], a[k]-jiro[j][k-1]);
            //jiro's turn
            else
                jiro[j][k] = max(a[j]-taro[j+1][k], a[k]-taro[j][k-1]);
        }
    }
    cout << taro[1][n] << "\n";
    return 0;
}