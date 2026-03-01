Link : https://leetcode.com/problems/count-subarrays-with-cost-less-than-or-equal-to-k/




class Solution {
public:

    struct StackWithMinMax {
        stack<int> s, minS, maxS;

        void push(int x) {
            s.push(x);
            if (minS.empty()) {
                minS.push(x);
                maxS.push(x);
            } else {
                minS.push(min(x, minS.top()));
                maxS.push(max(x, maxS.top()));
            }
        }

        void pop() {
            s.pop();
            minS.pop();
            maxS.pop();
        }

        bool empty() {
            return s.empty();
        }

        int top() {
            return s.top();
        }

        int getMin() {
            return minS.top();
        }

        int getMax() {
            return maxS.top();
        }
    };

    struct QueueWithMinMax {
        StackWithMinMax s1, s2;

        void push(int x) {
            s2.push(x);
        }

        void pop() {
            if (s1.empty()) {
                while (!s2.empty()) {
                    int val = s2.top();
                    s2.pop();
                    s1.push(val);
                }
            }
            s1.pop();
        }

        int getMax() {
            if (s1.empty()) return s2.getMax();
            if (s2.empty()) return s1.getMax();
            return max(s1.getMax(), s2.getMax());
        }

        int getMin() {
            if (s1.empty()) return s2.getMin();
            if (s2.empty()) return s1.getMin();
            return min(s1.getMin(), s2.getMin());
        }
    };

    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long cnt = 0;
        int l = 0;

        QueueWithMinMax q;

        for (int i = 0; i < n; i++) {
            q.push(nums[i]);

            while (!q.s1.empty() || !q.s2.empty()) {
                long long length = i - l + 1;
                long long cost = 1LL * (q.getMax() - q.getMin()) * length;

                if (cost > k) {
                    q.pop();
                    l++;
                } else {
                    break;
                }
            }

            cnt += (i - l + 1);
        }

        return cnt;
    }
};