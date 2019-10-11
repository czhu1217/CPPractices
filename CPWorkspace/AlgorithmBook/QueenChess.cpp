#include <iostream>
using namespace std;
int row[8];
int a, b;

bool place(int r, int c){

    for(int i=0;i<c;i++){
        if(row[i]==r||(r-row[i])*(r-row[i])==(c-i)*(c-i))
            return false;
    }

    return true;

}

int backtrack(int c){
    if(c==8&&row[b]==a){
        for (int i = 0; i < 8; i++)
        {
            cout << "(" << i+1 << ", " << row[i]+1 << ") " ;
        }
        cout << endl;
        return 0;
        
    }
    for(int r=0;r<8;r++){
        if(place(r, c)){
            row[c] = r;
            backtrack(c+1);

        }

    }

    return 0;

}

int main(){
    cin >> a >> b;
    a--;
    b--;
    backtrack(0);
    return 0;

}