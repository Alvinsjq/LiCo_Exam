#include <iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr)
            return pHead;
    	ListNode *r = pHead;
    	ListNode *q = pHead;
    	while(pHead->next!= NULL){
    		q = pHead->next;

    		if(q->next != NULL){
    			pHead->next = q->next;
    		    q->next = r;
    		}else{
    			q->next = r;
    			pHead->next = NULL;
    		}
		    r = q;
    	}
    	//cout<<r->val<<endl;
    	return r;
    }
};


int main(){

	Solution s;

	ListNode *pHead = new ListNode(0);
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);

	pHead->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

    ListNode* r = s.ReverseList(NULL);

    while(r != NULL){
        cout<<r -> val<<endl;
        r = r->next;
    }

	return 0;
}
