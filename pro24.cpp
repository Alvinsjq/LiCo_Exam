#include<iostream>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       ListNode *dump = new ListNode(0);
       ListNode *pre = dump;
       dump -> next = head;
       ListNode *p = head;
       while(p && p -> next){
       		ListNode *q = p -> next;
       		ListNode *r = q -> next;
       		pre -> next = q;
       		q -> next = p;
       		p -> next = r;
       		pre = p;
       		p = r;
       }
       return dump -> next;
    }
};


int main(){

	Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *p = l1;
    l1 -> next = new ListNode(2);
    l1 = l1->next;
    l1 -> next = new ListNode(3);
    l1 = l1->next;

    l1 -> next = NULL;


	ListNode *head = s.swapPairs(p);
	while(head!=NULL){
		cout<<head -> val<<endl;
		head = head -> next;
	}


}