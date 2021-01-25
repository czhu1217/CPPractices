#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

const int MM = 3003;
string s, ti;
int dp[MM][MM]; string ans;
void fun(int i,int j){
	if(i<=0 || j<=0)return ;
	if(s[i-1]==ti[j-1]){
		ans=s[i-1]+ans;
		fun(i-1,j-1);
	}
	else if(dp[i-1][j] == dp[i][j]){
		fun(i-1,j);
	}
	else fun(i,j-1);
}

int main() {
    cin >> s >> ti;
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=ti.size();j++){
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(s[i-1]==ti[j-1]) dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
        }
    }
    int x = s.size(), y = ti.size();
    fun(s.size(),ti.size());
    cout << ans << "\n";
    return 0;
}