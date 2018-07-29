#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *p1 = l1, *p2 = l2;
        ListNode *q = new ListNode(0);
        ListNode *curr = q;
        int temp = 0;
        while(p1!=NULL || p2!=NULL){
            int x = (p1 != NULL) ? p1->val : 0;
            int y = (p2 != NULL) ? p2->val : 0; //如果有哪个已经为空的时候，返回0代替
            int t = temp+x+y;  //计算中间值t，该值是两个链表对应位置与进位参数之和
            temp = t/10;       //temp为进位值
            curr -> next = new ListNode(t%10);//那么实际值自然就是对中间值的取余
            curr = curr -> next;
            if(p1!=NULL) p1 = p1->next;   //如果还未到头那就继续
            if(p2!=NULL) p2 = p2->next;
        }
        if( temp > 0){
            curr->next = new ListNode(temp); //如果最后进位值还大于0，那就为他再添一个
        }
        return q->next;

    }
};


int main(){

    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(1);

    ListNode *_l1 = l1;
    l1 -> next = new ListNode(9);
    l1 = l1 ->next;


    Solution s;

    ListNode *q = s.addTwoNumbers(_l1,l2);

    while(q!=NULL){
        cout<<q->val<<endl;
        q = q ->next;
    }



}
