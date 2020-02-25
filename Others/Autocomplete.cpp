
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
int T, N , trie[1000001][26];
int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
         cin >> N;
        // int trie[1000001][26];
         memset(trie, 0, sizeof(trie));
        int rt = 0, cnt = 0, ans = 0;
        for(int j=1;j<=N;j++){
            string s;
            cin >> s;
            int pre = 0; rt = 0; bool flag = false;
           
            for(int k=0;k<s.size(); k++){
                if(!flag){
                    pre++;
                }
                if(trie[rt][s[k]-'a']==0){
                    trie[rt][s[k]-'a'] = ++cnt;
                    flag = true;
                }
                rt = trie[rt][s[k]-'a'];
            }
            ans += pre;
           
        }
         printf("Case #%d: %d\n", i, ans);

    }
    return 0;

}