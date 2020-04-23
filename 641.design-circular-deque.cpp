/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 *
 * https://leetcode.com/problems/design-circular-deque/description/
 *
 * algorithms
 * Medium (49.81%)
 * Total Accepted:    13.8K
 * Total Submissions: 26.8K
 * Testcase Example:  '["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]\n[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * Design your implementation of the circular double-ended queue (deque).
 * 
 * Your implementation should support following operations:
 * 
 * 
 * MyCircularDeque(k): Constructor, set the size of the deque to be k.
 * insertFront(): Adds an item at the front of Deque. Return true if the
 * operation is successful.
 * insertLast(): Adds an item at the rear of Deque. Return true if the
 * operation is successful.
 * deleteFront(): Deletes an item from the front of Deque. Return true if the
 * operation is successful.
 * deleteLast(): Deletes an item from the rear of Deque. Return true if the
 * operation is successful.
 * getFront(): Gets the front item from the Deque. If the deque is empty,
 * return -1.
 * getRear(): Gets the last item from Deque. If the deque is empty, return
 * -1.
 * isEmpty(): Checks whether Deque is empty or not. 
 * isFull(): Checks whether Deque is full or not.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to
 * be 3
 * circularDeque.insertLast(1);            // return true
 * circularDeque.insertLast(2);            // return true
 * circularDeque.insertFront(3);            // return true
 * circularDeque.insertFront(4);            // return false, the queue is full
 * circularDeque.getRear();              // return 2
 * circularDeque.isFull();                // return true
 * circularDeque.deleteLast();            // return true
 * circularDeque.insertFront(4);            // return true
 * circularDeque.getFront();            // return 4
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [0, 1000].
 * The number of operations will be in the range of [1, 1000].
 * Please do not use the built-in Deque library.
 * 
 * 
 */
class MyCircularDeque {
private:
    int m_head;
    int m_tail;
    int m_maxsize;
    int m_size;
    int* m_que;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        m_head = 0;
        m_tail = 0;
        m_size = 0;
        m_maxsize = k;
        m_que = new int[k];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
            return false;
        if(m_head - 1 < 0)
            m_head = m_maxsize - 1;
        else
            m_head--;
        m_que[m_head] = value;
        m_size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
            return false;
        
	m_que[m_tail] = value;

	if(m_tail + 1 >= m_maxsize)
            m_tail = 0;
	else
	    m_tail++;
        
	m_size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
            return false;
        if(m_head + 1 == m_maxsize)
            m_head = 0;
        else 
            m_head++;
        m_size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
            return false;
        if(m_tail - 1 < 0)
            m_tail = m_maxsize - 1;
        else 
            m_tail--;
        m_size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())
            return -1;
        else
            return m_que[m_head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty())
            return -1;
        else{
	    int index = m_tail - 1;
 	    if(index < 0)
		    index = m_maxsize - 1;
            return m_que[index];
	}
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
       return m_size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return m_size == m_maxsize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
