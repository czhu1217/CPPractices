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
using namespace std;
int N;
char a[2005];
string s;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    int l=1, r = N;
    while(l<=r){
        if(a[l]>a[r]){
            s += a[r];
            r--;
        }
        else if(a[l]<a[r]){
            s += a[l];
            l++;
        }
        else{
            int lt = l, rt = r;
            while(a[lt]==a[rt]){
                lt++;
                rt--;
            }
            if(a[lt]<a[rt]){
                s += a[l];
                l++;
            }
            else{
                s += a[r];
                r--;
            }
        }
    }
    cout << s << "\n";
    return 0;


}