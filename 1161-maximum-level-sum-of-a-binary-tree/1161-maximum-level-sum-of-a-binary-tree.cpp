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
    int maxLevelSum(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        
        if(root==NULL){
            return 1;
        }
        q.push(root);
        while(q.size()){
            int n=q.size();
            int s=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                s+=curr->val;
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }


            }
            ans.push_back(s);
        }

        return max_element(ans.begin(),ans.end())-ans.begin()+1;
    }
};