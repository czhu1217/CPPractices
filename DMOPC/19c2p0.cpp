#include <iostream>
#include <string>
using namespace std;
string a[200];
int sze;
int main(){
    string s;
    for(int i=0;i<200;i++){
        getline(cin, s);
     
        
        if(s=="!"){
            sze = i;
            break;

        } 
        a[i] = s;
        // cout << a[i] << endl;

    }
    for(int i=0;i<sze;i++){
        printf("{\"text\" : \"");
        cout << a[i] << "\", \"icon\": \"RUN\"}," << "\n";
    }
    return 0;
    
}