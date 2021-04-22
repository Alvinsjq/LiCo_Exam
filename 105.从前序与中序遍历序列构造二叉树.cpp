/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.29%)
 * Likes:    921
 * Dislikes: 0
 * Total Accepted:    163.4K
 * Total Submissions: 235.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */

// @lc code=start
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length1 = preorder.size();
        int length2 = inorder.size();
        if(length1 != length2)
        {
            return nullptr;
        }
        return buildTreeFuc(preorder, 0, length1-1, 
                            inorder, 0, length2-1);
    }

    TreeNode* buildTreeFuc(vector<int>& preorder, int s1, int e1,
                        vector<int>& inorder, int s2, int e2) {
        if(s1 > e1 || s2 > e2)
        {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode();
        root->val = preorder[s1];
        int mid = s2;
        while(inorder[mid] != preorder[s1])
        {
            mid++; // 定位到mid
        }
        root->left = buildTreeFuc(preorder, s1+1, s1+(mid-s2), 
                                 inorder, s2, mid-1);
        root->right = buildTreeFuc(preorder, s1+(mid-s2)+1, e1, 
                                 inorder, mid+1, e2);
        return root;
    }


};
// @lc code=end

