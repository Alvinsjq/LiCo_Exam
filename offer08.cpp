#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; //指向父节点
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
    	if(pNode == NULL)
    		return NULL;
    	//1. 有右子树，则找到右子树的最左节点
        if(pNode -> right){
        	TreeLinkNode *pRight = pNode -> right;
        	while(pRight && pRight -> left){
        		pRight = pRight -> left;
        	}
        	return pRight;
        }else if(pNode -> next != NULL){
        	TreeLinkNode *Parent = pNode -> next;
        	 //2. 无右子树，但是父节点的左子树,直接返回其父节点
       		if(Parent -> left == pNode)
        		return Parent; 
        	else {
        		//3. 无右子树，但是父节点的右子树，
				while(Parent != NULL && Parent -> right == pNode){
	        		pNode = Parent;
	        		Parent = Parent -> next;
	        	}
	        	return Parent;
        	}
        }
        return NULL;
    }
};