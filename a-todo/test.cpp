#include <bits/stdc++.h>
using namespace std;
 
const int MAX=1e7+5;
vector<array<int,2>> sv(MAX);
 
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i=2;i<MAX;i++){
		if(sv[i][0])continue; // has a factor
		for(int j=i+i;j<MAX;j+=i){
			if(sv[j][0]==0)sv[j][0]=i;
			else if(sv[j][1]==0)sv[j][1]=i;
		}
	}
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<pair<int,int>> ans(n);
	for(int i=0;i<n;i++){
		auto [x,y]=sv[a[i]];
		if(a[i]%2==0){
			while(a[i]%2==0)a[i]/=2;
			if(a[i]>1)ans[i]={2,a[i]};
			else ans[i]={-1,-1};
		}
		else{
			if(x&&y&&gcd(x+y,a[i])==1)ans[i]={x,y};
			else ans[i]={-1,-1};
		}
	}
	for(int i=0;i<n;i++)cout<<ans[i].first<<" \n"[i==n-1];
	for(int i=0;i<n;i++)cout<<ans[i].second<<" \n"[i==n-1];
}