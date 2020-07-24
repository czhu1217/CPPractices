//patrik
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
#include <stack>
typedef long long ll;
using namespace std;
typedef pair<int, int> pi;
stack<int> st;
long n;
ll ans = 0;

int main(){
    cin >> n;
    for(int i=0, x;i<n;++i){
        int cnt = 1;
        cin >> x;
        while((!st.empty())&&(st.top()<x)){
            ans++;
            st.pop();
        }
        if(!st.empty()){
            ans++;
        }
        st.push(x);
        cout << ans << "\n";

    }
    
    cout << ans << "\n";
    return 0;
}