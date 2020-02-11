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
bool a[10000000], ans[10000000];
char c;



int main()
{
    cin >> N >> T;
    string s;
    cin >> s;
    for(int i=0;i<N;i++){
        a[i] = s[i]-'0';
    }


    for(int i=60;i>=0;i--){
        if((T>>i)&1){
            ll l = (1LL<<i)%N;
            ll r = (N-l)%N;
            for(int j=0;j<N;j++){
                ans[j] = a[(j+l)%N]^a[(j+r)%N];
            }
            swap(a, ans);
        }

    }

    for(ll i=0;i<N;i++){
        cout << a[i];
    }
  

    return 0;

}