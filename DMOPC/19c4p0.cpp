#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string a, b;
int cnt = 0;
int main()
{
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            cnt++;
    }
    if(cnt==1) printf("LARRY IS SAVED!\n");
    else printf("LARRY IS DEAD!\n");
    return 0;
}
