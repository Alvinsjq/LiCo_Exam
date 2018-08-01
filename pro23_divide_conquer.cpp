#include <iostream>
#include <vector>


using namespace std;


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){
	}
};


Class Solution{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.empty()) return NULL;
       int end = lists.size()-1;//设置尾部指针
       while(end > 0){//当尾部指针还未到达0时，说明分支算法还未结束
       		int begin = 0;
       		while(begin < end){//当一波分治未结束时
	       		lists[begin] = mergeTwoLists(lists[begin],lists[end]);
	       		begin ++;
	       		end --;
       		}
       }
       return lists[0];
    }

private:
	//该算法就是leetcode21的solution
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
}











