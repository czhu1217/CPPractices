#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int n, l; ll pas, no_pas; vector<int> st, ed;
int main(){
    cin >> n >> l;
    int u, v;
    for(int i=1;i<=n;i++){
        cin >> u >> v;
        st.push_back(u);ed.push_back(v);
        pas += abs(u-v);

    }
    st.push_back(l);
    ed.push_back(0);
    sort(st.begin(), st.end()); sort(ed.begin(), ed.end());
    for(int i=0;i<st.size();i++){
        no_pas += abs(st[i]-ed[i]);
    }
    cout << pas+no_pas << "\n";
    return 0;

}