//very very very sketch
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <deque>
#include <unordered_map>
#include<string>
typedef long long ll;
using namespace std;
vector<pair<int, int>> v;
int decomp(string s){
    if(s[s.size()-1]==' ') s=s.substr(0,s.size()-1);
    // cout << s << endl;
    int cnt=0, anscnt=0; bool tog=false; int open, close; int anss;
    int ans[2];
    if(s.size()==7){
        ans[0] = s[3]-'0';ans[1]=s[5]-'0';
    }
    else if(s.size()==1)return s[0]-'0';
    else if(s[3]-'0'>=0&&s[3]-'0'<=9){
        ans[0] = s[3]-'0';
        ans[1] = decomp(s.substr(5, s.size()-1-5));
    }
    else{
    for(int i=0;i<s.size();i++){
        if(s[i]==')')cnt--;
        if(s[i]=='(')cnt++;
        if(i>3&&cnt==1) {close=i;break;}

    }
    ans[0] = decomp(s.substr(3, close-3+1)); ans[1] = decomp(s.substr(close+2, s.size()-2-close-2+1));
    }
    if(s[1] == '+') anss= ans[0]+ans[1];
    if(s[1]=='-')anss= ans[0]-ans[1];
    if(s[1]=='*')anss= ans[0]*ans[1];
    if(s[1]=='q')anss= ans[0]/ans[1];
    if(s[1]=='r')anss= ans[0]%ans[1];
    // cout << anss << endl;
    return anss;
}

int main(){
    string c;
    while(getline(cin, c)){
    cout << decomp(c) << "\n";
    }
    return 0;



}