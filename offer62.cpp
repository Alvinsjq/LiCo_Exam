#include <iostream>
using namespace std;

struct LinkNode{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        //Ñ­»·Á´±í
        if(n<1) return -1;
        int i = 0;

        LinkNode * p = new LinkNode(i);
        LinkNode *first = p;
        for(i=1;i<n;i++){
            LinkNode * q = new LinkNode(i);
            p -> next = q;
            p = q;
            if(i == n-1)
                p -> next = first;
        }
        while(first->next != first){
            for(int j=1;j<=m-2;j++)
                first = first -> next;
            LinkNode *del = first ->next;

            first -> next = del ->next;
            delete del;
            first = first -> next;
        }
        return first -> val;
    }

    int LastRemaining_Math(int n, int m){
        if(n<1 ||m<1)
            return -1;
        // f(n,m) = 0 ; n = 1
        // f(n,m) = (f(n-1,m) + m) % n ; n > 1
        int fn = 0;
        for(int i=2;i<=n;i++)
            fn = (fn + m) % i;
        return fn;
    }

};


int main(){
    Solution  s;
    cout<<s.LastRemaining_Math(5,3)<<endl;
    cout<<s.LastRemaining_Solution(5,3)<<endl;

}


