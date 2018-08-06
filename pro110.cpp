#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) return true;

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);
        bool isbalance = abs(maxDepth(root -> left) - maxDepth(root -> right)) <= 1;
        // 法一 O(n^2)
        return left && right && isbalance;
        // 法二 O(n)
        return maxDep(root)!= -1;
    }

private:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int ld = maxDepth(root -> left);
        int rd = maxDepth(root -> right);
        
        return ld > rd ? ld + 1 : rd + 1;
    }

private:
    int maxDep(TreeNode* root){
        if(root == NULL)
            return 0;
        int L = maxDep(root -> left);
        if(L == -1) return -1;
        int R = maxDep(root -> right);
        if(R == -1) return -1;
        return abs(L - R) >= 1 ? -1 : max(L,R) + 1; 
    }
};








