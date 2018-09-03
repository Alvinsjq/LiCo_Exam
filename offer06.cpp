#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};


// empty() 堆栈为空则返回真
// pop() 移除栈顶元素
// push() 在栈顶增加元素
// size() 返回栈中元素数目
// top() 返回栈顶元素

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        stack<int> stack;
        ListNode *p = head;
        while(p!=NULL){
        	stack.push(p->val);
        	p = p -> next;
        }
        while(!stack.empty()){
        	v.push_back(stack.top());
        	stack.pop();
        }
        return v;
    }
};