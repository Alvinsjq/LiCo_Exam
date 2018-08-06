#include <iostream>
#include <limits.h>


using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
*1. 若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
*2. 任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
*3. 任意节点的左、右子树也分别为二叉查找树。
*4. 没有键值相等的节点（no duplicate nodes）。
*/

class Solution {
public:
    TreeNode *pre;
    bool isValidBST(TreeNode* root) {
    /*调用法一*/
        //return valid(root, INT_MIN, INT_MAX);
    /*调用法二*/
        pre = NULL;
        return isInOrder(root);
    }

private: 
    /**
        这个方法主要是看各个节点是不是在一定范围，而范围是由根节点和左右子树确定的。
    */
    bool valid(TreeNode *p, int low, int high){
        if(p == NULL) 
            return true;
        // 但得考虑树中包含最大与最小值
        return p -> val > low && p -> val < high &&
        valid(p -> left, low, p -> val) &&
        valid(p -> right, p -> val, high);
    }

private:

    //但其实一开始就是想着直接利用排序二叉树的特点，也就是先序遍历它的话能得到一个有序的序列
    //由于该树不存在相同的数值，因此是个严格递增的数列

    bool isInOrder(TreeNode *p){
        if(p == NULL) return true;
        if(isInOrder(p -> left)){
            if(pre != NULL && pre -> val >= p -> val) 
                return false;
            pre = p;
            return isInOrder(p -> right);
        }
        return false;
    }

};



