#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

// Predicate: Can we keep at least (N - K) elements such that no adjacent gap > mid?
bool check(long long mid, const vector<long long>& A, int n, int target_kept) {
    // dp[i] stores the max elements we can chain together ending at index i
    vector<int> dp(n, 1);
    
    // Monotonic deque to maintain the maximum dp[] value in our valid window
    deque<int> dq; 
    
    int L = 0;
    int max_kept = 1;
    
    for (int i = 0; i < n; i++) {
        // 1. Shrink the window from the left if the gap exceeds 'mid'
        while (L < i && A[i] - A[L] > mid) {
            // If the element falling out of the window is at the front of our deque, remove it
            if (!dq.empty() && dq.front() == L) {
                dq.pop_front();
            }
            L++;
        }
        
        // 2. The best previous element to link to is at the front of the deque
        if (!dq.empty()) {
            dp[i] = dp[dq.front()] + 1;
        } else {
            dp[i] = 1; // Start a brand new chain here
        }
        
        max_kept = max(max_kept, dp[i]);
        
        // 3. Maintain the monotonic decreasing property based on DP values
        // We want the highest DP values at the front.
        while (!dq.empty() && dp[dq.back()] <= dp[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    // If we managed to chain together enough elements, this 'mid' is valid!
    return max_kept >= target_kept;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int target_kept = n - k;
    long long low = 0;
    long long high = A[n - 1] - A[0];
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (check(mid, A, n, target_kept)) {
            ans = mid;        
            high = mid - 1;   // Try to find a smaller valid gap
        } else {
            low = mid + 1;    // Gap is too tight, we couldn't keep enough elements
        }
    }

    cout << ans << endl;
}

int main() {
    fastio();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}