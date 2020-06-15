//bob's prime factor
#include <bits/stdc++.h>
using namespace std;
int n; bool isp[200005];
int main(){
    memset(isp, 1, sizeof isp);
    isp[0]=0; isp[1]=0;

    for(int i=2;i<200005;i++){
        if(isp[i]){
            for(int j=i*2;j<200005;j+=i){ 
                isp[j]=0;
            }
        }
    }
    // for(int i=1;i<=10;i++) cout << isp[i] << " ";
    // cout << "\n";
    cin >> n;
    int ans = 1, id; bool p=0;
    for(int i=1, v;i<=n;i++){
        cin >> v;
        if(isp[v]){
            if(v>ans){
                id = v;
                ans = v;
                continue;
            }
        }
        for(int j=2;j<=sqrt(v);j++){
            if(v%j==0){
                if(isp[v/j]&&v/j>ans){
                    ans = v/j;
                    id = v;
                }
                break;
            }
        }
    }
    cout << id << "\n";
    return 0;
}
