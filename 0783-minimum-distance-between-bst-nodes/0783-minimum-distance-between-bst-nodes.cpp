/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=INT_MAX;
    TreeNode* pre;
    void getmin(TreeNode* root){
        if(!root) return;
        getmin(root->left);
        if(pre){
            ans=min(ans,root->val-pre->val);
        }
        pre=root;
        getmin(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        getmin(root);
        return ans;
    }
};