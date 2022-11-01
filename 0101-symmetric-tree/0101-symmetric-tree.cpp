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
    bool solve(TreeNode* root1, TreeNode* root2){
        if(root1==NULL and root2==NULL){
            return true;
        }
        if((root1==NULL and root2!=NULL) or (root1!=NULL and root2==NULL)){
            return false;
        }
        if(root1->val!=root2->val){
            return false;
        }
        
        bool res1 = solve(root1->left, root2->right);
        bool res2 = solve(root1->right, root2->left);
        return res1&&res2;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};