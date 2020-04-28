
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
string s[3][27] = {
		{"o.", "o.", "oo", "oo", "o.", "oo", "oo", "o.", ".o", ".o", "o.", "o.", "oo", "oo", "o.", "oo", "oo", "o.", ".o", ".o", "o.", "o.", ".o", "oo", "oo", "o."},
		{"..", "o.", "..", ".o", ".o", "o.", "oo", "oo", "o.", "oo", "..", "o.", "..", ".o", ".o", "o.", "oo", "oo", "o.", "oo", "..", "o.", "oo", "..", ".o", ".o"},
		{"..", "..", "..", "..", "..", "..", "..", "..", "..", "..", "o.", "o.", "o.", "o.", "o.", "o.", "o.", "o.", "o.", "o.", "oo", "oo", ".o", "oo", "oo", "oo"}
};
int main(){

    string st; getline(cin, st);
    for(int i=0;i<3;i++){
        for(int j=0;j<st.size();j++){
            if(st[j]!=' ')
            cout << s[i][st[j]-'A'];
            else cout << "..";
        }
        printf("\n");
    }
    return 0;
}