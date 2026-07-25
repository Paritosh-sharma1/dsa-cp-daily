#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

void solve() {
    int n, k;
    long long d;
    cin >> n >> k >> d;

    vector<long long> arr(n);
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }

    int l = 0;
    int odd_count = 0;
    long long max_sum = LLONG_MIN;
    
    // multiset stores the eligible prefix sums: pref[i-1]
    multiset<long long> active_prefixes;
    active_prefixes.insert(0); // pref[0] corresponds to starting at index 0

    for (int r = 0; r < n; r++) {
        if (abs(arr[r]) % 2 == 1) {
            odd_count++;
        }

        // Shrink the odd-count window from the left if it exceeds K
        while (odd_count > k) {
            // Remove the prefix corresponding to dropping the element before 'l'
            // pref[l] is the prefix sum *before* arr[l] is added
            auto it = active_prefixes.find(pref[l]);
            if (it != active_prefixes.end()) {
                active_prefixes.erase(it);
            }
            
            if (abs(arr[l]) % 2 == 1) {
                odd_count--;
            }
            l++;
        }

        // Search for the optimal pref[i-1] >= pref[r+1] - d
        long long target = pref[r + 1] - d;
        auto it = active_prefixes.lower_bound(target);

        if (it != active_prefixes.end()) {
            long long current_subarray_sum = pref[r + 1] - *it;
            max_sum = max(max_sum, current_subarray_sum);
        }

        // Insert the current prefix sum so it can be used as a left boundary for future iterations
        active_prefixes.insert(pref[r + 1]);
    }

    if (max_sum == LLONG_MIN) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << max_sum << endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 