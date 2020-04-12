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
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;
int T;
int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: ", t);
        vector<char> v; bool imp=0;
        string anspre, anssuf, ansmid;
        int N;
        scanf("%d", &N);
        bool flg = true;
        for(int i=1;i<=N;i++){
            string s; string pre, suf;
            cin >> s;
            int cur=0;
            for(cur=0;cur<s.length();cur++){
                if(s[cur]=='*') break;
                pre += s[cur];
            }
            for(int i=0;i<min(anspre.length(), pre.length());i++){
                if(anspre[i]!=pre[i]){
                    flg = false;
                    break;
                }
            }
            if(flg){
                anspre.length()>=pre.length()?anspre=anspre:anspre = pre;
            }

            int back =s.length()-1;
            for(;back>=0;back--){
                if(s[back]=='*')break;
                suf += s[back];
            }
            for(int j=0;j<min(suf.size(), anssuf.size());j++){
                if(anssuf[j]!=suf[j]){
                    flg=false;break;
                }
            }
            if(flg){
                anssuf.size()>=suf.size()?anssuf=anssuf:anssuf=suf;
            }
            for(;cur<=back;cur++){
                if(s[cur]!='*')ansmid += s[cur];
            }
            
            
        }
        if(flg){
            cout << anspre << ansmid;
        
        for(int j=anssuf.size()-1;j>=0;j--){
            printf("%c", anssuf[j]);
        }
        printf("\n");
        }
        else printf("*\n");

    }
        return 0;

}
