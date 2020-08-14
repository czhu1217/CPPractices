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
#include <climits>
#include <string>
using namespace std;
typedef long long ll;
int main(){
    string t; string s;
    cin >> s;
    for(int i=1;i<2000;i++){
        t += to_string(i);
    }
    // cout << t << "\n";
    for(int i=0;i<t.length()-s.length();i++){
        if(t.substr(i, s.size())==s){
            cout << i+1 << "\n";
            break;
        }
    }
    return 0;
}