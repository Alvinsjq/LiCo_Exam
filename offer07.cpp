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
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	int len_pre = pre.size();
    	int len_vin = vin.size();
    	return rc(pre,vin,0,len_pre-1,0,len_vin-1);
    }

    TreeNode* rc(vector<int> pre,vector<int> vin, int prel, int prer, int vinl, int vinr) {
    	
			//1. 构建root节点，root在pre的第一个
    		//cout<<pre[prel]<<endl;
	    	TreeNode *root = new TreeNode(pre[prel]);
	    	root -> left = NULL;
	    	root -> right = NULL;


	    	if(prel > prer || vinl >vinr) return NULL; //很重要

	    	//2. 获取对应的索引
	    	int x = 0;
	    	for(int i=vinl;i<=vinr;i++){
	    		if(vin[i]==root->val){
	    			x = i;
	    			break;
	    		}
	    	}

	    	int len_of_left = x-vinl;
	    	int len_of_rig = vinr-x;
	    	//3. 获取左子树
	    	root -> left = rc(pre,vin,prel+1,prel+len_of_left,vinl,x-1);
	    	//4. 获取右子树
	    	root -> right = rc(pre,vin,prel+len_of_left+1,prer,x+1,vinr);
	    	return root;
    }
};

int main(){
	vector<int> pre;
	vector<int> vin;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(7);
	pre.push_back(3);
	pre.push_back(5);
	pre.push_back(6);
	pre.push_back(8);

	vin.push_back(4);
	vin.push_back(7);
	vin.push_back(2);
	vin.push_back(1);
	vin.push_back(5);
	vin.push_back(3);
	vin.push_back(8);
	vin.push_back(6);

	Solution s;

	TreeNode * root = s.reConstructBinaryTree(pre,vin);



}