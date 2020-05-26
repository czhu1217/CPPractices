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
#include <climits>
#define f first
#define s second
using namespace std;
typedef long long ll;
int a, b;
void solve(){
    cin >> a >> b;
    if(a>b)swap(a, b);
    cout << max(a*2, b)*max(a*2, b) << "\n";

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}