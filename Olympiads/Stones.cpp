#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long N, K,a[103], mi=0x3f, lim;
bool dp[100005];
int main(){
    cin >> N >> K;
    memset(dp, true, sizeof(dp));
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    for(int i=K;i>0;i--){
        for(int j=1;j<=N;j++){
            if(i+a[j]<=K&&dp[i+a[j]]){
                dp[i] = false;
                break;
            }
        }
        }
    for(int i=1;i<=N;i++){
        if(dp[a[i]]){
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
    return 0;

}
