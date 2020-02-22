#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
int N, M, t;
string a, b;
char ans[10000005];
int main(){
    cin >> N >> M;
    cin >> a >> b;
    cin >> t;
    for(int i=0;i<a.size();i++){
        ans[a.size()-i-1+max(0,min((t-i), (int)b.size()))] = a[i];
    }
    for(int i=0;i<b.size();i++){
        ans[a.size()+i-max(0,min((t-i), (int)a.size()))] = b[i];
    }
    for(int i=0;i<b.size()+a.size();i++){
        cout << ans[i];    }
        cout << endl;
    return 0;
}