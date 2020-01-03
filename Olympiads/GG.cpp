#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
int ar[100005], N, x, y, Q;
string st;
int main(){
    cin >> st >> Q;
    if(st[0]=='G'){
        ar[0]=1;
    }
    else{
        ar[0]=0;
    }
    for(int i=1;i<st.length();i++){
        if(st[i]=='G'){
            ar[i] = ar[i-1]+1;
           
        }
        else{
            ar[i]=ar[i-1];
        }
    }
    for(int i=0;i<Q;i++){
        cin >> x >> y;
        if(x!=0){
            cout << ar[y] - ar[x-1] << endl;
        }
        else{
            cout << ar[y] << endl;
        }
    }
    return 0;

}

