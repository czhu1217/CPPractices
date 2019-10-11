#include <iostream>
using namespace std;
int t(bool ap[]){
    ap[0]=true;

}
int main(){
    bool test[2];
    for(int i=0;i<2;i++){
        test[i] = false;
    }
    
    cout << test[0] << endl;
    return 0;
}