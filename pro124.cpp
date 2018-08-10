#include <iostream>
#include <climits>
using namespace std;


struct TreeNode {
    int val;
   	TreeNode *left;
  	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {

private:
	int maxSum = INT_MIN;
	int findmax(TreeNode* root){
		if(root == NULL)
			return 0;
		int left = findmax(root -> left);
		int right = findmax(root -> right);
		maxSum = max(root -> val + left + right, maxSum);
		ret = root -> val + max(left, right);
		return ret > 0 ? ret : 0;
	}

public:
    int maxPathSum(TreeNode* root) {
       maxSum = INT_MIN;
       findmax(root);
       return maxSum;
    }
};

int main(){
	cout<<INT_MIN;
	return 0;
}