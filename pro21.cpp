#include <iostream>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2; // list 1 is empty
        if (!l2) return l1; // list 2 is empty

        ListNode *dummy = new ListNode(0);
        ListNode *currentTail = dummy; // current tail of the new list
        while (l1 && l2){
            if (l1->val <= l2->val){
                currentTail->next = l1;
                currentTail = l1;
                if (l1->next)
                    l1 = l1->next;
                else{
                    l1->next = l2;
                    return dummy->next;
                    }
            }else {
                    currentTail->next = l2;
                    currentTail = l2;
                    if (l2->next)
                        l2 = l2->next;
                    else{
                        l2->next = l1;
                        return dummy->next;
                    }
            }
        }
    }
};


int main(){

    Solution s;

    ListNode *l1 = new ListNode(1);
    ListNode *_l1 = l1;
    l1->next = new ListNode(2);
    l1 = l1->next;
    l1->next = new ListNode(4);
    l1 = l1->next;
    l1->next = NULL;


    ListNode *l2 = new ListNode(1);
    ListNode *_l2 = l2;
    l2->next = new ListNode(3);
    l2 = l2->next;
    l2->next = new ListNode(4);
    l2 = l2->next;
    l2->next = NULL;

    ListNode *l3 = s.mergeTwoLists(_l1,_l2);
    while(l3!=NULL){
        cout<<l3->val<<endl;
        l3 = l3->next;
    }


    return 0;
}



