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
string s;
ll mi = 0, cnt, pre, bcnt;
int main(){
    cin >> s;
    string temp;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B'){
            temp += s[i];
        }
        else{
            s = s.substr(i);
            break;
        }
    }
    // cout << s << endl;
    s = s + temp;
    // cout << s << endl;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B'){
            cnt ++;
            bcnt++;
        }
        else cnt = 0;
        if(cnt>mi) mi = cnt;
    }
    cout << bcnt - mi << endl;
    return 0;

}