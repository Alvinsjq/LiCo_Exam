#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};

class Solution{

public:
    void DeleteNode(ListNode **head, ListNode *tobeDelete){
        if(!head || !tobeDelete)
            return;
        if(tobeDelete -> next != nullptr){
            ListNode *next = tobeDelete -> next;
            tobeDelete -> val = next -> val;
            tobeDelete -> next = next -> next;

            delete next;
            next = nullptr;
        }else if(*head == tobeDelete){
            delete tobeDelete;
            tobeDelete = nullptr;
            *head = nullptr;
        }else{
            ListNode *p = *head;
            while(p->next != tobeDelete){
                p = p -> next;
            p -> next = nullptr;
            delete tobeDelete;
            tobeDelete = nullptr;
        }


    }

};
