#include <bits/stdc++.h>
using namespace std; 
int a[102];
vector<int> v;
int main(){
    a[0] = 2, a[1] = 1, a[2] = 3;
    sort(a, a+3);
    for(int i=0;i<=2;i++) cout << a[i] << "\n";
    
    return 0;

}