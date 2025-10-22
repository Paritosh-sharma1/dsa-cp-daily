Link: https://leetcode.com/problems/all-possible-full-binary-trees/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    unordered_map<int, vector<TreeNode*>> dp;

    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        if (n == 1) return { new TreeNode(0) };

        if (dp.count(n)) return dp[n];

        vector<TreeNode*> res;

        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;

            vector<TreeNode*> leftTrees = allPossibleFBT(left);
            vector<TreeNode*> rightTrees = allPossibleFBT(right);

            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return dp[n] = res;
    }
};
