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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> res;
        // res.push_back(root->val);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                ans.push_back(res);
                res.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            res.push_back(front->val);
            if(front->left){
                q.push(front->left);
                // res.push_back(front->left->val);
            }
            if(front->right){
                q.push(front->right);
                // res.push_back(front->right->val);
            }
        }
        return ans;
    }
};