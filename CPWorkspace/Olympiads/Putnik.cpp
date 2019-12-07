#include <bits/stdc++.h>

using namespace std;

const int MM = 1505;
int arr[MM][MM], N, dp[MM][MM], ans = 0x3f3f3f3f;

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    for (int l = 1; l < N; l++){
        for (int r = 1; r < N; r++){
            int c = max(l, r) + 1;
            dp[l][c] = dp[l][r] + arr[r][c];
            dp[c][r] = dp[l][r] + arr[l][c];
        }
    }
    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++){
            ans = min(ans, min(dp[i][N], dp[N][i]));
        }
    }
    cout << ans << "\n";
    return 0;
}

//bruce helped me yay