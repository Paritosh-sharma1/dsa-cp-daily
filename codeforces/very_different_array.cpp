#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n), b(m);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Precompute differences
        vector<ll> pref(n + 1, 0), suff(n + 1, 0);

        // pref[k] = sum of matching first k a[i] with largest b
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + abs(a[i] - b[m - 1 - i]);
        }

        // suff[k] = sum of matching last k a[i] with smallest b
        for (int i = 0; i < n; i++) {
            suff[i + 1] = suff[i] + abs(a[n - 1 - i] - b[i]);
        }

        ll ans = 0;

        // try all k
        for (int k = 0; k <= n; k++) {
            ll cur = pref[k] + suff[n - k];
            ans = max(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}