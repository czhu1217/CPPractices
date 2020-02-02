#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
string s;
int m, cur = 0;
bool flag;
long long ans;
struct combo{
    string st; 
    int t;
    friend bool operator<(combo &a, combo &b){
        return a.st.size() > b.st.size();
    }

} ;
vector<combo> cb;
int main(){
    cin >> s >> m;
    combo temp;
    temp.st = "R"; temp.t = 0;
    cb.push_back(temp);
    temp.st = "L"; temp.t = 0;
    cb.push_back(temp);
    temp.st = "U"; temp.t = 0;
    cb.push_back(temp);
    temp.st = "D"; temp.t = 0;
    cb.push_back(temp);

    for(int i=1;i<=m;i++){
        combo b;
        cin >> b.st >> b.t;
        cb.push_back(b);
    }
    sort(cb.begin(), cb.end());
    while(cur<s.size()){
        for(auto e:cb){
        flag = true;
        for(int i=0;i<e.st.size();i++){
            if(e.st[i]!=s[cur+i]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans += e.t + e.st.size();
            cur += e.st.size();
            break;
        }
    }
    }
    
    cout << ans << "\n";
    return 0;


}