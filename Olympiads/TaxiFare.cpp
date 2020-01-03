#include <iostream>
#include <algorithm>
using namespace std;
long long N, K; long long a, b;
int main(){
    cin >> N >> K >> a >> b;
    printf("%lld", min(K, N)*a + max((N-K), (long long)0)*b );
    return 0;
}