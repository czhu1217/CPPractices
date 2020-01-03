#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int N;
string str;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        bool flag = false;
        int num, brac=0;
        cin >> str;
        if(str.size()==0){
            printf("YES\n");
        }
        else{
        for(int j=0;j<str.size();j++){
            if(str[j]=='('){
                
                brac+=1;
                // printf("add %d %d\n", j, brac);
            } 
            else if(str[j]==')'){
                
                brac-=1;
                // printf("subtract %d %d\n", j, brac);
            } 
            if(brac<0){
                flag=true;
                break;
            }
        }
        // cout << "br " << brac <<endl;
        if(flag||(brac!=0)) printf("NO\n");
        else printf("YES\n");
        }
       
    }
     return 0;
}