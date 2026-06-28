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
    vector<string> ans;
        string path;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        int n=path.size();        
        path+=to_string(root->val);
        if(root->right==NULL && root->left==NULL){
            ans.push_back(path);
            
        }else{
            path+="->";
            binaryTreePaths(root->left);
            binaryTreePaths(root->right);
        }
        path.resize(n);
        return ans;
    }
};