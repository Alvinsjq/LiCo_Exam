#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }

    void printInorder(TreeNode *root){
        if(root != NULL){
            printInorder(root -> left);
            cout<<root -> val<<endl;
            printInorder(root -> right);
        }
    }

private:

    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if(left > right) return NULL;
        int mid = (left+right)/2;
        TreeNode *p = new TreeNode(nums[mid]);
        p -> left = sortedArrayToBST(nums, left, mid - 1);
        p -> right = sortedArrayToBST(nums, mid + 1, right);
        return p;
    }


};

int main(){
    Solution s;
    std::vector<int> v;
    int i;
    for(i = 0;i < 13;i += 2){
        v.push_back(i);
    }

    TreeNode * result = s.sortedArrayToBST(v);
    s.printInorder(result);

}



