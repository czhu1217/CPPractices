//https://dmoj.ca/problem/ccc16s5
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
typedef long long ll;
using namespace std;
ll N, T, mask, mask2, mask3;
// bool a[10000000];
char c;
map<string, bool> idk;
    map<string, int> m;



string s, ori, ans;
int main()
{
    cin >> N >> T;
    cin >> s;
    int i=0;
    ll cnt = 0, mx = 0;
    ll lg = log2(T);
    while(i<T){
        lg = (ll)log2(T-i);
        i += pow(2, lg);
       
        for(int i=0;i<s.length();i++){
            ll l = (i-lg-1);
            if(l<0) l = s.length()+l;
            ll r = i+lg+1;

            if(r>=s.length()) r = r - s.length()+1;
            // cout << l << " " << r << endl;

            if(s[l]=='0'&&s[r]=='0') ans[i] = '0';

            else if(s[l]=='1'&&s[r]=='1') ans[i] = '0';
            else ans[i] = '1';
        }
        for(int i=0;i<s.length();i++){
            s[i] = ans[i];
        }

    }
    cout << s << endl;
  

    return 0;

}
