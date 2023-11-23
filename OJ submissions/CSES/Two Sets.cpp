#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace __gnu_pbds;
template<class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl "\n"
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll oo = 1e17;
const int mod = 1e9 + 7;
const int N = 1e7;
void solve() {
    ll n;
    cin >> n;
    ll x = (n * (n + 1));
    if (x % 4) {
        cout << "NO" << endl;
        return;
    }
    x = x / 4;
    unordered_map<int, bool> mp;
    vector<int> v;
    ll csum = 0;
    int cur = n;
    while (csum < x) {
        if (csum + cur <= x) {
            v.pb(cur);
            mp[cur] = 1;
            csum += cur--;
        }
        else {
            v.pb(x - csum);
            mp[x - csum] = 1;
            break;
        }
    }
    cout << "YES" << endl;
    cout << v.size() << endl;
    write(v);
    cout << n - v.size() << endl;
    for (int i = 1; i <= n; i++)
        if (!mp[i])
            cout << i << ' ';
    cout << endl;
}
//#define ONLINE_JUDGE
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " <<
         std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count()
         << " seconds" << endl;
    return 0;
}