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
    void solve(TreeNode* root, long long ans, int &res){
        if(root==NULL){
            // // cout<<ans<<endl;
            // int mid = ans;
            // res+=mid;
            // // cout<<res<<endl;
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans = (ans*10) + root->val;
            int mid = ans;
            res+=mid;
            return;
        }
        ans = (ans*10) + root->val;
        solve(root->left, ans, res);
        solve(root->right, ans, res);
    }
    
    int sumNumbers(TreeNode* root) {
        long long ans = 0;
        int res = 0;
        solve(root, ans, res);
        return res;
    }
};