#include <iostream>
#include <map>


using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *copy = new RandomListNode(0);
        RandomListNode *p = head;
        RandomListNode *q = copy;
        map<RandomListNode*, RandomListNode*> Map;
        while(p != NULL){
        	q -> next = new RandomListNode(p -> label);
        	Map[p] = q -> next;
        	q = q -> next;
        	p = p -> next;
        }
        p = head;
        q = copy;
        while(p != NULL){
        	q -> next -> random = Map[p -> random];
        	p = p -> next;
        	q = q -> next;
        }
        return copy -> next;
    }
};









