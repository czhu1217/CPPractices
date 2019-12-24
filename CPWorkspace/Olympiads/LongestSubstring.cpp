#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int i, j, x, y;
int main(){
    string st;
    getline(cin,st);

    for(i=0;i<st.size();i++){
        if(st[i]=='A'){
            x = i;
            break;
        } 
        
    }
    for(int j=st.size()-1;j>0;j--){
       
        if(st[j]=='Z') {
            y=j;
            break;
        }
    }
    cout << y - x +1<< "\n";
    return 0;



}