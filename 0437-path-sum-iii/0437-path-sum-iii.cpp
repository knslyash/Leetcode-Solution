class Solution {
public:
    int dfs(TreeNode* root, long long target) {
        if (root == nullptr)
            return 0;

        int ans = 0;

        if (root->val == target)
            ans++;

        ans += dfs(root->left, target - root->val);
        ans += dfs(root->right, target - root->val);

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return 0;

        return dfs(root, targetSum)
             + pathSum(root->left, targetSum)
             + pathSum(root->right, targetSum);
    }
};