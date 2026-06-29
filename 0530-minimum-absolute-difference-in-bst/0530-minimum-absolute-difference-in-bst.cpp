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
    TreeNode* prev=NULL;
    void getmin(TreeNode* root){
        if(!root){
            return ;
        }
        
        getmin(root->left);
        if(prev)
            ans=min(ans,abs(root->val-prev->val));
        prev=root;
        getmin(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        getmin(root);
        return ans;
    }
};