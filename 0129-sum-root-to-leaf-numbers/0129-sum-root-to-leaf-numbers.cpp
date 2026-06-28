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
    int ans=0;
    int n=0;
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        n=n*10+root->val;
        if(root->right==NULL && root->left==NULL){
            ans+=n;
        }else{
            sumNumbers(root->left);
            sumNumbers(root->right);
        }
        n=n/10;
        return ans;
    }
};