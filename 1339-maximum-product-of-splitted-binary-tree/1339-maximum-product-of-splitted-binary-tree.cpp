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
    int sumTree(TreeNode* root){
        if(root==NULL)
            return 0;
        root->val += (sumTree(root->left) + sumTree(root->right));
        return root->val;
    }
    
    void solve(TreeNode* root, long long int sum, long long int &pro){
        if(root==NULL)
            return;
        long long int temp = sum-root->val;
        pro = max(pro, root->val*temp);
        solve(root->left, sum, pro);
        solve(root->right, sum, pro);
    }
    
    int maxProduct(TreeNode* root) {
        long long int sum = sumTree(root);
        long long int pro = 0;
        solve(root->left, sum, pro);
        solve(root->right, sum, pro);
        return pro%1000000007;
    }
};