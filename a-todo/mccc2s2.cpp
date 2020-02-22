#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
int N;
vector<char> ans;
string s;
map<int, char> m;
char head;
int main(){
    cin >> N;
    cin >> s;
    head = s[0];
    for(int i=0;i<s.size();i++){
        if(s[i]<=head){
            m[-i] = s[i];
            head = s[i];
        } 
        else m[i] = s[i];
    }
    for(auto e :m){
        cout << e.second ;
    }
    cout<< endl;
    return 0;
}