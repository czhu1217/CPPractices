#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long ll;
int main(){
    char c; string st;
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            c = s[i];
            if(c=='A'||c=='a'){
                printf("Hi! ");
            }
            else if(c=='e'||c=='E'){
                printf("Bye! ");

            }
            else if(c=='i'||c=='I'){
                printf("How are you? ");

            }
            else if(c=='o'||c=='O'){
                printf("Follow me! ");
            }
            else if(c=='u'||c=='U'){
                printf("Help! ");
            }
            else if(c>='0'&&c<='9'){
                printf("Yes! ");
            }
            
        }
            printf("\n");

    }
    return 0;
}