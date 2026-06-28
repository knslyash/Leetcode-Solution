class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr)
            return;

        path.push_back(root->val);

        // Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val)
                ans.push_back(path);
        } else {
            dfs(root->left, targetSum - root->val, path, ans);
            dfs(root->right, targetSum - root->val, path, ans);
        }

        path.pop_back();  
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, path, ans);

        return ans;
    }
};