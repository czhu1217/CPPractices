//Good Writing
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long int lld;
int q, n;
lld k, l, prel;
string st = "Good writing is good writing is good writing.", fir = "Good writing is good ";
string sec = " writing is good ", la = " is good writing.";
lld calc(int n)
{
    if(n<0){
        return 0;
    }
    lld ans;
    ans = st.size();
    for (int i = 0; i < n; i++)
    {
        ans = ans * 2 + fir.size() + sec.size() + la.size();
    }
    return ans;
}
int main()
{

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n >> k;
       
        while (true)
        {
            l = calc(n);
            prel = calc(n-1);
            // printf("%lld %lld\n",k,l );
            if(n==0){
                cout << st[k-1] << "\n" ;
                break;
            }
            if(k>l){
                cout << "." << "\n";
                break;
            }
            if (k <= fir.size())
            {
                // printf("1\n");
                cout << fir[k - 1] << "\n";
                break;
            }
            else if (l - k < la.size())
            {
                // printf("2\n");
                cout << la[la.size()-(l-k)-1] << "\n";
                break;
            }
            else if(k-fir.size()-prel>0&&k-fir.size()-prel<=17){
                // printf("3\n");
                cout << sec[k-fir.size()-prel-1] << "\n";
                break;
            }
            if(k<=fir.size()+prel){
           
                n--;
                k -= fir.size();
            }
            else{
                n--;
                k -= fir.size()+prel+sec.size();
            }
            
        }
    }
    return 0;
}