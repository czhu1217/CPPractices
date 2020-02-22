#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;
ll N;
string n, h;
ll a[27], pro[27];
map<string, bool> m;
bool flag = false;
ll cnt = 0;
vector<string> ans;
int main(){
    cin >> n >> h;
    for(ll i=0;i<n.size();i++){
        a[n[i]-'a']++;
    }
    for(ll i=0;i<h.size();i++){
    
        flag = false;
        if(i<n.size()-1){
            pro[h[i]-'a']++;
            continue;
        }
        if(i!=n.size()-1) pro[h[i-n.size()]-'a']--;
        pro[h[i]-'a']++;
        for(ll i=0;i<26;i++){
            if(a[i]!=pro[i]){
                flag = true;
                break;
            }
        }
        if(!flag){
            if(find(ans.begin(),ans.end(),h.substr(i-n.size()+1, n.size()))!=ans.end()) continue;
            cnt++;
            ans.push_back(h.substr(i-n.size()+1, n.size()));
        }
    }
    cout << cnt << endl;
    return 0;


}