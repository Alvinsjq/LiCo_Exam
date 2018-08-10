#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    ListNode *list;
    TreeNode* sortedArrayToBST(int left, int right) {
        if(left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode *leftTree = sortedListToBST(left, mid - 1);
        TreeNode *parent = new TreeNode(list -> val);
        list = list -> next;
        parent -> left = leftTree;
        parent -> right = sortedListToBST(mid + 1, right);
        return parent;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
       ListNode *p = head;
       int n = 0;
       while(p -> next != NULL){
            n++;
       }
       list = head;
       return sortedArrayToBST(0,n);
    }





};

int main(){
    Solution s;

    TreeNode * result = s.sortedArrayToBST(v);
    s.printInorder(result);

}



