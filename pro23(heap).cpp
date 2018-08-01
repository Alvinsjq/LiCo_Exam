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
	void makeHeap(vector<ListNode*> &heap){
		int para_last = (heap.size()-1)/2;
		for (int i = para_last; i >= 0  ; i--){
			minHeap(heap, i);
		}
	}

	void minHeap(vector<ListNode*> &heap, int i){
		int left = 2*i; // 找到父节点i的子节点
		int right = left + 1;
		int least = i;   // 假设最小值节点为i

		//得到最小值所在的vector索引
		if(left < heap.size() && heap[left]->val < heap[i]->val)
			least = left;
		if(right < heap.size() && heap[right]->val < heap[least]->val)
			least = right;

		if(least!=i){
			swap(heap[i],heap[least]);
			minHeap(heap, least);// 如果该交换打乱了下面的顺序，那就要继续为以下的进行堆排序。
		}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
        
		if(lists.empty()) return NULL;
		vector<ListNode*> heap;//最小堆
		ListNode *result = new ListNode(0);

		//将每个链表的头节点插入heap
		for (int i = 0; i < lists.size(); ++i){
			if(lists[i]!=NULL)
				heap.push_back(lists[i]);
		}

		makeHeap(heap);//建立初始的最小堆
		ListNode *p = result;
		while(!heap.empty()){
			// 将堆顶插入到p中
			ListNode *top = heap[0];
            cout<<top->val<<endl;
			p -> next = top;
			p = p -> next;

			ListNode* next = top -> next;
			if(next!=NULL){
				//如果该链表还有元素，那就将其接上堆顶
				heap[0] = next;
			}else{
				//如果该链表没有元素，那就将堆最后的一个元素插入堆顶
				swap(heap[0],heap[heap.size()-1]);
				//并删除堆中最后一个元素
				heap.pop_back();
			}
			//重新调整堆
			minHeap(heap,0);
		}
		return result -> next;
    }
}











