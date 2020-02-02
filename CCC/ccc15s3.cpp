#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;
int g, p;
set<int> a;
int main(){
    cin >> g >> p;
    for(int i=1;i<=g;i++) a.insert(i);
    for(int i=0, x;i<p;i++){
        scanf("%d", &x);
        if(*a.begin() > x){
            cout << i << endl;
            return 0;
        }
        set<int>::iterator it = prev(a.upper_bound(x));
        a.erase(it);
        
    }
    cout << p << endl;
    return 0;
}