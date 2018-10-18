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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //注意1 当链表为空 或者 最后第0个的时候
        if(pListHead == nullptr || k==0)
            return nullptr;

        ListNode *flag = pListHead;
        ListNode *p = NULL;
        for(unsigned int i=1;i<k;i++)
            if(flag -> next != nullptr)
                flag = flag -> next;
            else
            ////当k-1步还没走完就到头了额，也就说明链表长度没有k那么长的话
                return nullptr;
        p = pListHead;
        while(flag ->next != nullptr){
            flag = flag -> next;
            p = p -> next;
        }
        return p;
    }
};

int main(){
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *head = a;
    a -> next = new ListNode(2);
    a = a-> next;
    a -> next = new ListNode(3);
    a = a-> next;
     a -> next = new ListNode(4);
    a = a-> next;
     a -> next = new ListNode(5);
    a = a-> next;
    a -> next = nullptr;

    ListNode *res = s.FindKthToTail(head,2);
    cout<<res -> val<<endl;
    return 0;

}
