#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
#include <stdio.h>
const int MM = 1e6 + 5;
int Q, l, r;
int pre[26][MM];
string s;
char lt;
int main()
{
    cin.sync_with_stdio(0);cin.tie(0);
    getline(cin, s);
    for (int i = 1; i <= s.length(); i++)
    {
        lt = s[i - 1];
  
        if (lt != ' ')
        {
            for (int j = 0; j < 26; j++)
            {
                
                if (j != (lt - 'a'))
                {
                    pre[j][i] = pre[j][i - 1];
                }
                else
                {
                     pre[j][i] = pre[j][i-1]+1;
                }
    
            }
        }
        else{
            for(int j=0;j<26;j++){
                pre[j][i] = pre[j][i - 1];
            }
        }


    }
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> l >> r >> lt;
        cout << pre[lt - 'a'][r] - pre[lt - 'a'][l - 1] <<"\n";
    }

    return 0;
}
