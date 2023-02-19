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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int i = 0;
        bool rev = false;
        vector<int> res;
        stack<int> s;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                i+=1;
                if(i%2!=0){
                    rev = true;
                }
                else{
                    rev = false;
                }
                while(!s.empty()){
                    res.push_back(s.top());
                    s.pop();
                }
                ans.push_back(res);
                res.clear();  
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(temp->left){
                        q.push(temp->left);
                }
                if(temp->right){
                        q.push(temp->right);
                } 
                if(rev){
                    s.push(temp->val);
                }
                else{
                    res.push_back(temp->val);
                }
            }
        }
        return ans;
    }
};