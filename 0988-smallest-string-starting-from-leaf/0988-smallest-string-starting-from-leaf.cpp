class Solution {
public:
    string ans = "";
    string temp = "";

    void dfs(TreeNode* root) {
        if (!root)
            return;

        temp.push_back('a' + root->val);

        if (!root->left && !root->right) {
            string curr = temp;
            reverse(curr.begin(), curr.end());

            if (ans.empty() || curr < ans)
                ans = curr;
        }

        dfs(root->left);
        dfs(root->right);

        temp.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};