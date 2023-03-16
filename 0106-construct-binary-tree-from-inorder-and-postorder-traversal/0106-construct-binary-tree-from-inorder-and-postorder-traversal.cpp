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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int &postInd, int inStart, int inEnd, map<int, int> &nodeToIndex){
        if(postInd<0 || inStart>inEnd){
            return NULL;
        }
        int pos = nodeToIndex[postorder[postInd]];
        TreeNode* root = new TreeNode(postorder[postInd]);
        postInd--;
        root->right = solve(postorder, inorder, postInd, pos+1, inEnd, nodeToIndex);
        root->left = solve(postorder, inorder, postInd, inStart, pos-1, nodeToIndex);   
        return root;
    }
        
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> nodeToIndex;
        for(int i=0; i<inorder.size(); i++){
            nodeToIndex[inorder[i]] = i;
        }
        int postInd = postorder.size()-1;
        TreeNode* root = solve(postorder, inorder, postInd, 0, inorder.size()-1, nodeToIndex);
        return root;
    }
};