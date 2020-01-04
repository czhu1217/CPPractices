#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long n, a, b, t;
        cin >> n >> a >> b >> t;
        if (n * a >= t)
        {
            n -= floor((n * a - t) / (a + b));
            cout << n << endl;
        }
        else
            cout << -1 << endl;
        
    }
    return 0;
}