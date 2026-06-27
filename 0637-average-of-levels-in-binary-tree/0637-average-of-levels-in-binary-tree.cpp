class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        long long sum = 0;
        int count = 0;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                ans.push_back((double)sum / count);

                sum = 0;
                count = 0;

                if (!q.empty())
                    q.push(NULL);
            }
            else {
                sum += node->val;
                count++;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};