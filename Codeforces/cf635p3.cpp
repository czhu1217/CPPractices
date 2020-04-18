#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define pii pair<ll int, ll int>
#define vi vector<ll int>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define sz(x) (ll int)x.size()
#define hell 1000000000000000000
#define rep(i, a, b) for (ll int i = a; i < b; i++)
#define lbnd lower_bound
#define ubnd upper_bound
#define bs binary_search
// #define mp          make_pair
#define MAX 200005
#define CHAR_SIZE 26
using namespace std;

#define N 200010

vector<ll> adj[N];
ll vis[N] = {0};
ll depth[N];
ll cc[N];
ll dfs(ll node, ll d)
{
    ll cnt = 1;
    vis[node] = 1;
    depth[node] = d;
    for (auto i : adj[node])
        if (!vis[i])
        {
            cnt += dfs(i, d + 1);
        }
    cc[node] = cnt;
    return cnt;
}
void solve(ll cno)
{
    ll n, i, j, k, l, m, q;
    ll a, b, c, d, x;
    cin >> n >> q;
    for (i = 0; i < n - 1; i++)
    {
        cin >> j >> k;
        j--;
        k--;
        adj[j].pb(k);
        adj[k].pb(j);
    }
    dfs(0, 0);

    ll arr[n];
    ll sum = 0;
    for (i = 0; i < n; i++)
    {
        arr[i] = cc[i] - depth[i] - 1;
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    for (i = 0; i < n - q; i++)
    {
        sum += arr[i];
    }
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS = 1;
    // cin>>TESTS;
    ll i = 1;
    while (TESTS--)
    {
        solve(i);
        i++;
    }
    return 0;
}