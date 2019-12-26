#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
int N, counter=0;
set<string> mp;
string st;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        counter = 0;
        cin >> st;
        for(int i=0;i<st.size();i++){
            for(int j=i;j<st.size();j++){
                string t = st.substr(i, j-i+1);
                cout << t << endl;
                mp.insert(t);
            }
        }
        printf("im here");
        for(auto e:mp){
            counter++;
        }
        printf("%d\n", counter);
     
    }
       return 0;
}
