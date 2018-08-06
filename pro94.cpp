/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        if(root == NULL) 
            return a;
        else{
            
            vector<int> left = inorderTraversal(root -> left);
            left.push_back(root -> val);
            vector<int> right = inorderTraversal(root -> right);//注意是加在左子树上
            
            a.insert(a.end(),left.begin(),left.end());
            a.insert(a.end(),right.begin(),right.end());
        }
        return a;
    }

};