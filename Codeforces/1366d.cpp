#include <bits/stdc++.h> 
using namespace std;
const int MM = 1e7+2;
int b[MM]; //stores d1
int c[MM]; //stores d2;
int mp[MM]; //stores the minimum prime factor of a number;
 bool p[MM]; // recprds if a number is prime
vector<int> v; //stores all the prime numbers

void sieve(){
    memset(p, 1, sizeof p);
    p[0]=p[1]=0;
    for(int i=2;i<MM;i++){
        if(p[i]){
            v.push_back(i);
            mp[i]=i; //the minimum prime factor of i is i;

        }
        for(int e:v){
            if(i*e>=MM)break; //out of the range
            mp[i*e]=e; // the minimum prime factor of i*e is e since evry e is smaller than i
            p[i*e]=0; // i*e is not a prime number

        }
    }
}
int main(){
    sieve();
    for(int i=1;i<MM;i++){b[i]=-1; c[i]=-1;}
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int r;
        cin >> r;
        int pi = mp[r];
        assert(r%pi==0);
        int t1 = r, h=1;
        while(t1%pi==0){
            t1 /= pi;
            h *= pi;
        }
        if(t1!=1){
            b[i]=t1; c[i]=h;
        }
    }
    for(int i=1;i<=n;i++) cout << b[i] << " ";
    cout << "\n";
    for(int i=1;i<=n;i++) cout << c[i] << " ";
    return 0;

}