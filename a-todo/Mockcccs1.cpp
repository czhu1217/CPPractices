#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
bool inwar = false;
int a[1002], b[1002];
int N, cnt=0;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a[i];

    }
    for(int i=1;i<=N;i++){
        cin >> b[i];
    }
    for(int i=1;i<=N;i++){
        if(a[i]==b[i]&&!inwar){
            cnt++;
            inwar = true;
        }
        else if(a[i]!=b[i]&&inwar){
            inwar = false;
        }
    }
    cout << cnt << endl;
    return 0;

}